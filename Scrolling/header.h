#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
SDL_Surface *personnage;
SDL_Rect pospersonnage;
}personnage;

typedef struct
{
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Surface *imageM;
}background;



void initialiser_personnage(personnage *perso);
void initialiser_background(background *back);
void initialiser_camera(SDL_Rect *camera);
void affichage_personnage(SDL_Surface *ecran,personnage *perso);
void affichage_background(SDL_Surface *ecran,background *back,SDL_Rect *camera);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int CollisionParfaite_droite(personnage perso,background back,int r,int g,int b);
int CollisionParfaite_gauche(personnage perso,background back,int r,int g,int b);
void choix_commande(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep);
void deplacement_personnage(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep);
void gravity(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x);
void initialiser_camera(SDL_Rect *camera);
void scrolling(int dep,int saut,int h,SDL_Rect *camera,personnage *perso);
void limit_fps(int limit);


#endif // HEADER_H_INCLUDED
