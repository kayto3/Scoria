#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct
{
SDL_Surface *image[16];
SDL_Rect poslogo;
}logo;

void Remplissage_animation_logo(logo *logo);
void affichage_logo(SDL_Surface *ecran,logo logo);

void Initialiser_Menu(SDL_Surface **ecran,SDL_Surface **imageDeFond,SDL_Surface **bouton1,SDL_Surface **bouton2,SDL_Surface **bouton3,SDL_Surface **bouton4,SDL_Surface **bouton_selection1,SDL_Surface **bouton_selection2,SDL_Surface **bouton_selection3,SDL_Surface **bouton_selection4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4,SDL_Rect *posBouS1,SDL_Rect *posBouS2,SDL_Rect *posBouS3,SDL_Rect *posBouS4,Mix_Music **music,Mix_Chunk **son);

void Affichage_initial(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4);

void Affichage_Decale(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Surface *bouton_selection1,SDL_Surface *bouton_selection2,SDL_Surface *bouton_selection3,SDL_Surface *bouton_selection4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4,SDL_Rect *posBouS1,SDL_Rect *posBouS2,SDL_Rect *posBouS3,SDL_Rect *posBouS4,int curseur);

void menuoption(SDL_Surface *ecran,Mix_Chunk *son,int *sound,int *fullscreen);

void input_Menu(SDL_Event event,int *curseur,int *continuer,SDL_Surface *ecran,Mix_Chunk *son,int *sound,int *fullscreen,int *niv);

void Free_Menu(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Surface *bouton_selection1,SDL_Surface *bouton_selection2,SDL_Surface *bouton_selection3,SDL_Surface *bouton_selection4);
void niveau1(SDL_Surface *ecran,int * niv);

void niveau2(SDL_Surface *ecran,int *niv);

#endif // MENU_H_INCLUDED
