#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "Ennemi.h"
#include "Background.h"
void initialiser_ennemi (enemy *ennemi)
{
	ennemi->posennemi.x=100;
	ennemi->posennemi.y=300;
	ennemi->ennemi = IMG_Load("draicox.png");
}

void initialiser_background(background *back)
{
	back->positionecran.x=0;
	back->positionecran.y=0;
	back->image = IMG_Load("background.png");
}

void affichage_ennemi(SDL_Surface *ecran,enemy *ennemi)
{
	SDL_BlitSurface(ennemi->ennemi,NULL,ecran,&ennemi->posennemi);	
}

void affichage_background(SDL_Surface *ecran,background *back)
{
	SDL_BlitSurface(back->image , NULL , ecran , &back->positionecran);
}

int deplacement_alea (int posmax,int posmin)
{
	int pos;
	srand(time(NULL));
	pos=rand()%(posmax-posmin+1)+posmin;
	return pos;
}

int nombreAleatoire()
{
	int aleatoire=rand()%(1);
	return aleatoire;
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
void Deplacement_annime (mouvement *mvt,enemy *ennemi,background *back,SDL_Surface *ecran,int posMax,int posMin)
{
int i=0,j=0;	
while 	(ennemi->posennemi.x<=posMax)
{	
	(ennemi->posennemi.x)+=10;
	SDL_BlitSurface(mvt->mvt_avant[i],NULL,ecran,&ennemi->posennemi);	
	SDL_Flip(ecran);	
	affichage_background(ecran,back);
	SDL_Flip(ecran);
	i++;
	if (i==6)
	i=0;
	
}
if (ennemi->posennemi.x=posMax)
{
	while (ennemi->posennemi.x>posMin)
	{	
	(ennemi->posennemi.x)-=10;
		
		SDL_BlitSurface(mvt->mvt_back[j],NULL,ecran,&ennemi->posennemi);
		SDL_Flip(ecran);
		affichage_background(ecran,back);
		SDL_Flip(ecran);
		j++;
		if (j==	6)
		j=0;
		
	}
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


