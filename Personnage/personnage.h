#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
//#include "background.h"

/*
typedef struct
{
SDL_Surface *personnage;
SDL_Rect pospersonnage;
}personnage;
*/
void initialiser_personnage(personnage *perso);
void affichage_personnage(SDL_Surface *ecran,personnage *perso);
void choix_commande(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep);
void deplacement_personnage(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep);
void gravity(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x);
void limit_fps(int limit);


#endif // PERSONNAGE_H_INCLUDED
