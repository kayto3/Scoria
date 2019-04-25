#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"


void initialiser_personnage(personnage *perso)
{
perso->pospersonnage.x=100;
perso->pospersonnage.y=100;
perso->i=0;
perso->j=0;
perso->personnage = IMG_Load("Animation_Personnage/walk_1_right.png");
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
		*h=perso->pospersonnage.y-250;
		if(*h<0)
		*h=0;
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
		perso->pospersonnage.x=perso->pospersonnage.x+5;
		if(perso->pospersonnage.x>=*curseur_x)
		*curseur_active=0;
		break;
		case 2:
		perso->pospersonnage.x=perso->pospersonnage.x-5;
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

void Remplissage_animation_perso(personnage *perso)
{
 perso->mvt.mvt_avant [0]=IMG_Load("Animation_Personnage/walk_2_right.png");
 perso->mvt.mvt_avant [1]=IMG_Load("Animation_Personnage/walk_5_right.png");
 perso->mvt.mvt_avant [2]=IMG_Load("Animation_Personnage/walk_6_right.png");
 perso->mvt.mvt_avant [3]=IMG_Load("Animation_Personnage/walk_7_right.png");
 perso->mvt.mvt_avant [4]=IMG_Load("Animation_Personnage/walk_8_right.png");
 perso->mvt.mvt_avant [5]=IMG_Load("Animation_Personnage/walk_10_right.png");
 perso->mvt.mvt_avant [6]=IMG_Load("Animation_Personnage/walk_12_right.png");
 perso->mvt.mvt_back [0]=IMG_Load("Animation_Personnage/walk_2_left.png");
 perso->mvt.mvt_back [1]=IMG_Load("Animation_Personnage/walk_5_left.png");
 perso->mvt.mvt_back [2]=IMG_Load("Animation_Personnage/walk_6_left.png");
 perso->mvt.mvt_back [3]=IMG_Load("Animation_Personnage/walk_7_left.png");
 perso->mvt.mvt_back [4]=IMG_Load("Animation_Personnage/walk_8_left.png");
 perso->mvt.mvt_back [5]=IMG_Load("Animation_Personnage/walk_10_left.png");
 perso->mvt.mvt_back [6]=IMG_Load("Animation_Personnage/walk_12_left.png");
}

void Anime_perso(int dep,SDL_Surface *ecran,personnage *perso)
{
if(dep==1)
{	
	SDL_BlitSurface(perso->mvt.mvt_avant[perso->i],NULL,ecran,&perso->pospersonnage);
	perso->personnage = IMG_Load("Animation_Personnage/walk_1_right.png");	
	//SDL_Flip(ecran);	
	//affichage_background(ecran,back);
	perso->i++;
	if (perso->i==6)
	perso->i=0;
	
}
else	if (dep==2)
	{	
		SDL_BlitSurface(perso->mvt.mvt_back[perso->j],NULL,ecran,&perso->pospersonnage);
		perso->personnage = IMG_Load("Animation_Personnage/walk_1_left.png");
		//SDL_Flip(ecran);
		//affichage_background(ecran,back);
		perso->j++;
		if (perso->j==6)
		perso->j=0;
		
	}
else	if (dep==0)
	SDL_BlitSurface(perso->personnage , NULL , ecran, &perso->pospersonnage);
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

