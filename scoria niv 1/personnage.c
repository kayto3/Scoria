#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"


void initialiser_personnage(personnage *perso)
{
perso->pospersonnage.x=100;
perso->pospersonnage.y=100;
perso->vx=0;
perso->vy=0;
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
Uint8 * keys;
int numkeys;
keys = SDL_GetKeyState(&numkeys);
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
/*
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
		perso->vy=perso->pospersonnage.y;
		}
		if (*saut==1)
		perso->vy -= 40;
		break;
	}
	break;
*/
}

if (keys[SDLK_ESCAPE])
*continuer=0;
if (keys[SDLK_RIGHT])
{
if(CollisionParfaite_droite(*perso,*back,0,0,0)==0)
		*dep=1;
}
if (keys[SDLK_LEFT])
{
if(CollisionParfaite_gauche(*perso,*back,0,0,0)==0)
		*dep=2;
}
if (keys[SDLK_SPACE])
{
if((*saut==0) && (CollisionParfaite_sol(*perso,*back,255,0,0)!=0))
		{
		*h=perso->pospersonnage.y-250;
		if(*h<0)
		*h=0;
		*saut=1;
		perso->vy=perso->pospersonnage.y;
		}
		if (*saut==1)
		perso->vy -= 40;
}
}

void deplacement_souris(SDL_Event *event,int *continuer,personnage *perso,background *back,int *saut,int *h,int *curseur_active,int *curseur_x,int *dep)
{
// deplacement souris
	if((*curseur_active==1) && (perso->pospersonnage.x<*curseur_x))
	{
	if((CollisionParfaite_droite(*perso,*back,0,0,0)!=0) || (*dep==2))
	*curseur_active=0;
	else
	*dep=1;
	if(perso->pospersonnage.x+perso->vx+back->camera.x>=*curseur_x)
	*curseur_active=0;
	}
	else if((*curseur_active==1) && (perso->pospersonnage.x>*curseur_x))
	{
	if((CollisionParfaite_gauche(*perso,*back,0,0,0)!=0) || (*dep==1))
	*curseur_active=0;
	else
	*dep=2;
	if(back->camera.x-perso->pospersonnage.x-perso->vx<=*curseur_x)
	*curseur_active=0;
	}
}

void deplacement_perso(personnage *perso,int dep,int saut)
{
	int lateralspeed = 2;
	int airlateralspeedfacteur = 1;
	int maxhspeed = 10;
	int adherance = 2;
	int impulsion = 6;
	int factsautmaintenu = 3;
// acceleration 
	Uint8 * keys;
	int numkeys;
	keys = SDL_GetKeyState(&numkeys);
	if (keys[SDLK_LSHIFT])
	maxhspeed = 20;
// controle lateral
	if (saut==1) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (dep==2) // (*1)
		perso->vx-=lateralspeed;
	if (dep==1)
		perso->vx+=lateralspeed;
	if ((perso->vy==0) && (dep==0)) // (*3)
		perso->vx/=adherance;
// limite vitesse
	if (perso->vx>maxhspeed) // (*4)
		perso->vx = maxhspeed;
	if (perso->vx<-maxhspeed)
		perso->vx = -maxhspeed;
}
void gravity(personnage *perso,background *back,int *saut,int *h)
{
// gestion saut et gravite
		if(perso->vy<*h)
		perso->vy = *h;
	if((*saut==1) && (perso->pospersonnage.y>perso->vy))
	perso->pospersonnage.y=perso->pospersonnage.y-10;
	if((*saut==1) && (perso->pospersonnage.y<=perso->vy))
	*saut=0;
	if((*saut==0) && (CollisionParfaite_sol(*perso,*back,255,0,0)==0))
	perso->pospersonnage.y=perso->pospersonnage.y+10;
	if((*saut==0) && (CollisionParfaite_sol(*perso,*back,255,0,0)!=0))
	perso->vy=0;
	
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

