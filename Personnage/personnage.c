#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"


void initialiser_personnage(personnage *perso)
{
perso->pospersonnage.x=100;
perso->pospersonnage.y=100;
perso->personnage = IMG_Load("Kayto1.png");
}

void affichage_personnage(SDL_Surface *ecran,personnage *perso)
{
SDL_BlitSurface(perso->personnage , NULL , ecran, &perso->pospersonnage);
}

void choix_commande(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep)
{
// choix action
switch (event->type)
{
	case SDL_QUIT:
	*continuer=0;
	break;
	case SDL_MOUSEBUTTONDOWN:
            if (event->button.button == SDL_BUTTON_LEFT)
            {
                *curseur_active=1;
                *curseur_x=event->motion.x;
            }
	break;
	case SDL_KEYDOWN:
	switch(event->key.keysym.sym)
	{
		case SDLK_ESCAPE:
		*continuer=0;
		break;
		case SDLK_RIGHT:
		if(CollisionParfaite_droite(*perso,*back,0,0,0)==0)
		*dep=1;
		break;
		case SDLK_LEFT:
		if(CollisionParfaite_gauche(*perso,*back,0,0,0)==0)
		*dep=2;
		break;
		case SDLK_SPACE:
		if((*saut==0) && (CollisionParfaite_sol(*perso,*back,255,0,0)!=0))
		{
		*h=perso->pospersonnage.y-150;
		*saut=1;
		}
		break;
	}
	break;
}
}

void deplacement_personnage(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep)
{
// deplacement souris
	if((*curseur_active==1) && (perso->pospersonnage.x<*curseur_x))
	{
	if((CollisionParfaite_droite(*perso,*back,0,0,0)!=0) || (*dep==2))
	*curseur_active=0;
	else
	*dep=1;
	if(perso->pospersonnage.x+5+back->camera.x>=*curseur_x)
	*curseur_active=0;
	}
	else if((*curseur_active==1) && (perso->pospersonnage.x>*curseur_x))
	{
	if((CollisionParfaite_gauche(*perso,*back,0,0,0)!=0) || (*dep==1))
	*curseur_active=0;
	else
	*dep=2;
	if(back->camera.x-perso->pospersonnage.x-5<=*curseur_x)
	*curseur_active=0;
	}
// deplacement clavier
/*
switch(*dep)
	{
		case 1:
		if(perso->pospersonnage.x>=*curseur_x)
		*curseur_active=0;
		break;
		case 2:
		if(perso->pospersonnage.x<=*curseur_x)
		*curseur_active=0;
		break;
	}
*/
}
void gravity(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x)
{
// gestion saut et gravite
	if((*saut==1) && (perso->pospersonnage.y>*h))
	perso->pospersonnage.y=perso->pospersonnage.y-10;
	if((*saut==1) && (perso->pospersonnage.y<=*h))
	*saut=0;
	if((*saut==0) && (CollisionParfaite_sol(*perso,*back,255,0,0)==0))
	perso->pospersonnage.y=perso->pospersonnage.y+10;
	
}

void limit_fps(int limit)
{
int ticks=SDL_GetTicks();
if (limit <ticks)
return;
else if(limit >ticks+33)
SDL_Delay(33);
else
SDL_Delay(limit-ticks);
}

