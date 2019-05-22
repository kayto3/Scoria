#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
//#include "personnage.h"

typedef struct
{
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Surface *imageM;
SDL_Rect camera;
}background;

typedef struct
{
SDL_Surface *mvt_avant[8];
SDL_Surface *mvt_back[8];
}mouvement2;

typedef struct
{
SDL_Surface *personnage;
SDL_Rect pospersonnage;
int vx;
int vy;
mouvement2 mvt;
int i,j;
}personnage;

void initialiser_background(background *back);
void initialiser_camera(background *back);
void affichage_background(SDL_Surface *ecran,background *back);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int CollisionParfaite_droite(personnage perso,background back,int r,int g,int b);
int CollisionParfaite_gauche(personnage perso,background back,int r,int g,int b);
int CollisionParfaite_sol(personnage perso,background back,int r,int g,int b);
void scrolling(int dep,int saut,int h,background *back,personnage *perso,int *curseur_active,int *curseur_x);


#endif // BACKGROUND_H_INCLUDED
