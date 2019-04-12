#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "Robot.h"
#include "Background.h"
void initialiser_robot (Robot *rob)
{
	rob->posrobot.x=1000;
	rob->posrobot.y=400;
	rob->rob=IMG_Load("draicox.png");
}

void initialiser_background (background *back)
{
	back->positionecran.x=0;
	back->positionecran.y=0;
	back->image = IMG_Load("background.png");
}

void affichage_ennemi (SDL_Surface *ecran,Robot *rob)
{
	SDL_BlitSurface(rob->rob,NULL,ecran,&rob->posrobot);	
}

void affichage_background (SDL_Surface *ecran,background *back)
{
	SDL_BlitSurface(back->image , NULL , ecran , &back->positionecran);
}

void Remplissage_TabMVT (mouvement *mvt)
{
 mvt-> mvt_robot [0]=IMG_Load("Portail 1.png");
 mvt-> mvt_robot [1]=IMG_Load("Portail 2.png");
 mvt-> mvt_robot [2]=IMG_Load("Portail 3.png");
 mvt-> mvt_robot [3]=IMG_Load("Portail 4.png");
 mvt-> mvt_robot [4]=IMG_Load("Portail 5.png");
 mvt-> mvt_robot [5]=IMG_Load("Portail 6.png");
}
void Apparition_anime (mouvement *mvt,Robot *rob,background *back,SDL_Surface *ecran)
{
int i;	
for (i=0;i<5;i++)
{	
	SDL_BlitSurface(mvt->mvt_robot[i],NULL,ecran,&rob->posrobot);
	SDL_Flip(ecran);	
	affichage_background(ecran,back);
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


