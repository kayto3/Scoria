#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "Background.h"
typedef struct
{
SDL_Surface* rob;
SDL_Rect posrobot;
}Robot;

typedef struct
{
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Surface *imageM;
}background;

typedef struct
{
SDL_Surface *mvt_robot[7];
}mouvement;

void initialiser_robot (Robot *rob);
void initialiser_background(background *back);
void affichage_ennemi(SDL_Surface *ecran,Robot *rob);
void affichage_background(SDL_Surface *ecran,background *back);
void Remplissage_TabMVT (mouvement *mvt);
void Apparition_anime (mouvement *mvt,Robot *rob,background *back,SDL_Surface *ecran);
#endif // HEADER_H_INCLUDED
