#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"

void initialiser_camera(background *back)
{
back->camera.x=0;
back->camera.y=0;
back->camera.w=800;
back->camera.h=600;
}

void initialiser_background(background *back)
{
back->positionecran.x=0;
back->positionecran.y=0;
back->image = IMG_Load("background_ex.png");
back->imageM = SDL_LoadBMP("background_ex_masque.bmp");
}


void affichage_background(SDL_Surface *ecran,background *back)
{
SDL_BlitSurface(back->image , &back->camera , ecran ,NULL);
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



int CollisionParfaite_droite(personnage perso,background back,int r,int g,int b)
{
SDL_Color couleur_obstacle;
int X,Y,W,H;
X=perso.pospersonnage.x;
Y=perso.pospersonnage.y;
W=perso.pospersonnage.w;
H=perso.pospersonnage.h;
SDL_Rect pos[8];
pos[0].x=X;
pos[0].y=Y;
pos[1].x=X+W/2;
pos[1].y=Y;
pos[2].x=X+W;
pos[2].y=Y;
pos[3].x=X;
pos[3].y=Y+H/2;
pos[4].x=X;
pos[4].y=Y+H;
pos[5].x=X+W/2;
pos[5].y=Y+H;
pos[6].x=X+W;
pos[6].y=Y+H;
pos[7].x=X+W;
pos[7].y=Y+H/2;
int collision=0;
int i=5;
while((i<8) && (collision==0))
{
couleur_obstacle=GetPixel(back.imageM,pos[i].x+back.camera.x,pos[i].y);
printf("%d ,%d ,%d \n",couleur_obstacle.r,couleur_obstacle.g,couleur_obstacle.b);
if((couleur_obstacle.r==r) && (couleur_obstacle.g==g) && (couleur_obstacle.b==b))
collision=1;
i++;
}
return collision;
}

int CollisionParfaite_gauche(personnage perso,background back,int r,int g,int b)
{
SDL_Color couleur_obstacle;
int X,Y,W,H;
X=perso.pospersonnage.x;
Y=perso.pospersonnage.y;
W=perso.pospersonnage.w;
H=perso.pospersonnage.h;
SDL_Rect pos[8];
pos[0].x=X;
pos[0].y=Y;
pos[1].x=X+W/2;
pos[1].y=Y;
pos[2].x=X+W;
pos[2].y=Y;
pos[3].x=X;
pos[3].y=Y+H/2;
pos[4].x=X;
pos[4].y=Y+H;
pos[5].x=X+W/2;
pos[5].y=Y+H;
pos[6].x=X+W;
pos[6].y=Y+H;
pos[7].x=X+W;
pos[7].y=Y+H/2;
int collision=0;
int i=3;
while((i<6) && (collision==0))
{
couleur_obstacle=GetPixel(back.imageM,pos[i].x,pos[i].y);
if((couleur_obstacle.r==r) && (couleur_obstacle.g==g) && (couleur_obstacle.b==b))
collision=1;
i++;
}
return collision;
}

int CollisionParfaite_sol(personnage perso,background back,int r,int g,int b)
{
SDL_Color couleur_obstacle;
int X,Y,W,H;
X=perso.pospersonnage.x;
Y=perso.pospersonnage.y;
W=perso.pospersonnage.w;
H=perso.pospersonnage.h;
SDL_Rect pos[8];
pos[0].x=X;
pos[0].y=Y;
pos[1].x=X+W/2;
pos[1].y=Y;
pos[2].x=X+W;
pos[2].y=Y;
pos[3].x=X;
pos[3].y=Y+H/2;
pos[4].x=X;
pos[4].y=Y+H;
pos[5].x=X+W/2;
pos[5].y=Y+H;
pos[6].x=X+W;
pos[6].y=Y+H;
pos[7].x=X+W;
pos[7].y=Y+H/2;
int collision=0;
int i=4;
while((i<7) && (collision==0))
{
couleur_obstacle=GetPixel(back.imageM,pos[i].x,pos[i].y);
if((couleur_obstacle.r==r) && (couleur_obstacle.g==g) && (couleur_obstacle.b==b))
collision=1;
i++;
}
return collision;
}
/*
void scrolling(int dep,int saut,int h,SDL_Rect *camera,personnage *perso)
{
	if (dep == 2)
    {
        camera->x -= 10;

        if (camera->x < 0)
        {
            camera->x = 0;
        }
    }
    else if (dep == 1)
    {
        camera->x += 10;

        if (camera->x + 800 >= 12725) // if (map.startX + SCREEN_WIDTH >= map.maxX)
        {
            camera->x = 12725 - 800;  //map.startX = map.maxX - SCREEN_WIDTH;
        }
    }

} */
void scrolling(int dep,int saut,int h,background *back,personnage *perso,int *curseur_active,int *curseur_x)
{
	switch(dep)
	{
				
		case 1: 
			if (back->camera.x<6363)
                		back->camera.x=back->camera.x+5;
			if (((perso->pospersonnage.x<300)||((back->camera.x>=6363))&&(perso->pospersonnage.x<1100)))
				perso->pospersonnage.x=perso->pospersonnage.x+5;
			if(perso->pospersonnage.x>=*curseur_x)
			*curseur_active=0;
	
		break;
		case 2:
			if (back->camera.x>0)
                		back->camera.x=back->camera.x-5;
	    		if (((back->camera.x!=0)&&(perso->pospersonnage.x>=150))||((back->camera.x==0)&&(perso->pospersonnage.x==50)))
				perso->pospersonnage.x=perso->pospersonnage.x-5;
			if(perso->pospersonnage.x<=*curseur_x)
			*curseur_active=0;
		break;

	}
}

