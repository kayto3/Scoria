#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"
#include "enigme.h"
#include "Ennemi.h"
#include <time.h>
void initialiser_ennemi (enemy *ennemi,int x,int y,int posMax,int posMin)
{
	ennemi->posennemi.x=x;
	ennemi->posennemi.y=y;
	ennemi->direc=0;
	ennemi->i=0;
	ennemi->j=0;
	ennemi->posMax=posMax;
	ennemi->posMin=posMin;
	ennemi->ennemi = IMG_Load("walk1.png");
}

void affichage_ennemi(SDL_Surface *ecran,enemy *ennemi)
{
	SDL_BlitSurface(ennemi->ennemi,NULL,ecran,&ennemi->posennemi);	
}

void Remplissage_animation (mouvement *mvt)
{
 mvt-> mvt_avant [0]=IMG_Load("walk1.png");
 mvt-> mvt_avant [1]=IMG_Load("walk2.png");
 mvt-> mvt_avant [2]=IMG_Load("walk3.png");
 mvt-> mvt_avant [3]=IMG_Load("walk4.png");
 mvt-> mvt_avant [4]=IMG_Load("walk5.png");
 mvt-> mvt_avant [5]=IMG_Load("walk6.png");
 mvt-> mvt_avant [6]=IMG_Load("walk7.png");

 mvt-> mvt_back [0]=IMG_Load("walk8.png");
 mvt-> mvt_back [1]=IMG_Load("walk9.png");
 mvt-> mvt_back [2]=IMG_Load("walk10.png");
 mvt-> mvt_back [3]=IMG_Load("walk11.png");
 mvt-> mvt_back [4]=IMG_Load("walk12.png");
 mvt-> mvt_back [5]=IMG_Load("walk13.png");
 mvt-> mvt_back [6]=IMG_Load("walk14.png");
}
void Deplacement_annime (mouvement *mvt,enemy *ennemi,background *back,SDL_Surface *ecran,personnage *perso)
{
if(ennemi->posennemi.x>=ennemi->posMax)
ennemi->direc=0;
else if (ennemi->posennemi.x<ennemi->posMin)
ennemi->direc=1;
if(ennemi->direc==1)
{	
	(ennemi->posennemi.x)+=10;
	if(perso->pospersonnage.x-ennemi->posennemi.x < 300)
	SDL_BlitSurface(mvt->mvt_avant[ennemi->i],NULL,ecran,&ennemi->posennemi);	
	//SDL_Flip(ecran);	
	//affichage_background(ecran,back);
	ennemi->i++;
	if (ennemi->i==6)
	ennemi->i=0;
	
}
else	if (ennemi->direc==0)
	{	
	(ennemi->posennemi.x)-=10;
		if(perso->pospersonnage.x-ennemi->posennemi.x < 300)
		SDL_BlitSurface(mvt->mvt_back[ennemi->j],NULL,ecran,&ennemi->posennemi);
		//SDL_Flip(ecran);
		//affichage_background(ecran,back);
		ennemi->j++;
		if (ennemi->j==	6)
		ennemi->j=0;
		
	}
}	

void ennemi_camera(int dep,background *back,enemy *ennemi,personnage perso)
{
		if(perso.vx>0)
		{
			if (back->camera.x<6363)
			{
                		ennemi->posennemi.x=ennemi->posennemi.x-perso.vx;
				ennemi->posMin=ennemi->posMin-perso.vx;
				ennemi->posMax=ennemi->posMax-perso.vx;
			}
		}
		else if(perso.vx<0)
		{
			if (back->camera.x>0)
                		{
				ennemi->posennemi.x=ennemi->posennemi.x-perso.vx;
				ennemi->posMin=ennemi->posMin-perso.vx;
				ennemi->posMax=ennemi->posMax-perso.vx;
				}
		}
}

int collision_entite(personnage perso,enemy ennemi,background back)
{
if((perso.pospersonnage.x + perso.pospersonnage.w < ennemi.posennemi.x) || (perso.pospersonnage.x > ennemi.posennemi.x + ennemi.posennemi.w) || (perso.pospersonnage.y + perso.pospersonnage.h < ennemi.posennemi.y) || (perso.pospersonnage.y > ennemi.posennemi.y + ennemi.posennemi.h ))
return 0; // pas de collision
else
return 1;
}

void MoveIA(enemy *ennemi,personnage perso,int *stat,int positionO,mouvement *mvt,SDL_Surface *ecran)
{

int distance;
ennemi->direc=0;
  if(ennemi->posennemi.x>=perso.pospersonnage.x)
    distance=ennemi->posennemi.x-perso.pospersonnage.x;
  else
    distance=perso.pospersonnage.x-ennemi->posennemi.x;
if(distance<50)
*stat=1;
else 
*stat=0;
    if(distance<200)
      {
        if(ennemi->posennemi.x>=perso.pospersonnage.x)
          ennemi->direc=0;
        else
          ennemi->direc=1;
      }
      else
    {  if(ennemi->posMin>=ennemi->posennemi.x)
          ennemi->direc=1;
      if(ennemi->posMax<=ennemi->posennemi.x)
        ennemi->direc=0;
	}
      if(ennemi->direc==1)
      {
        ennemi->posennemi.x+=5;
	if(perso.pospersonnage.x-ennemi->posennemi.x < 300)
	SDL_BlitSurface(mvt->mvt_avant[ennemi->i],NULL,ecran,&ennemi->posennemi);	
	ennemi->i++;
	if (ennemi->i==6)
	ennemi->i=0;
      }
      if(ennemi->direc==0)
      {
        ennemi->posennemi.x-=5;
		if(perso.pospersonnage.x-ennemi->posennemi.x < 300)
		SDL_BlitSurface(mvt->mvt_back[ennemi->j],NULL,ecran,&ennemi->posennemi);
		ennemi->j++;
		if (ennemi->j==	6)
		ennemi->j=0;
      }
}

/*
int collide(personnage *player,enemy *monster)
{
    //On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
    if ((player->x >= monster->x + monster->w) || (player->x + player->w <= monster->x) || (player->y >= monster->y + monster->h) || (player->y + player->h <= monster->y) )
        return 0;
    //Sinon, il y a collision. Si le joueur est au-dessus du monstre (avec une marge
    //de 10 pixels pour éviter les frustrations dues au pixel perfect), on renvoie 2.
    //On devra alors tuer le monstre et on fera rebondir le joueur.
    else if (player->y + player->h <= monster->y + 10)
    {
        //ENIGME
        return 2;
    }
    
    else
	if (enigme==0)        
	return 1;
}

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
	SDL_Color color;
	Uint32 col=0;
	//Determine position
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	//convertir color
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
*/


