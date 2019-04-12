#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"
void initialiser_personnage(personnage *perso)
{
perso->pospersonnage.x=100;
perso->pospersonnage.y=300;
perso->personnage = IMG_Load("Kayto.png");
}

void initialiser_camera(SDL_Rect *camera)
{
camera->x=0;
camera->y=0;
camera->w=1000;
camera->h=800;
}

void initialiser_background(background *back)
{
back->positionecran.x=0;
back->positionecran.y=0;
back->image = IMG_Load("background_ex.png");
back->imageM = SDL_LoadBMP("background_ex_masque.bmp");
}


void affichage_personnage(SDL_Surface *ecran,personnage *perso)
{
SDL_BlitSurface(perso->personnage , NULL , ecran, &perso->pospersonnage);
}


void affichage_background(SDL_Surface *ecran,background *back,SDL_Rect *camera)
{
SDL_BlitSurface(back->image , camera , ecran ,NULL);
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
		if((*saut==0) && (perso->pospersonnage.y>=300))
		{
		*h=perso->pospersonnage.y-300;
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
	}
	else if((*curseur_active==1) && (perso->pospersonnage.x>*curseur_x))
	{
	if((CollisionParfaite_gauche(*perso,*back,0,0,0)!=0) || (*dep==1))
	*curseur_active=0;
	else
	*dep=2;
	}
// deplacement clavier
/* switch(*dep)
	{
		case 1:
		perso->pospersonnage.x=perso->pospersonnage.x+10;
		if(perso->pospersonnage.x>=*curseur_x)
		*curseur_active=0;
		break;
		case 2:
		perso->pospersonnage.x=perso->pospersonnage.x-10;
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
	if((*saut==0) && (perso->pospersonnage.y<300))
	perso->pospersonnage.y=perso->pospersonnage.y+10;
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

        if (camera->x + 1600 >= 1600) // if (map.startX + SCREEN_WIDTH >= map.maxX)
        {
            camera->x = 1600 - 1600;  //map.startX = map.maxX - SCREEN_WIDTH;
        }
    }
	if (saut==1)
    {
        camera->y -= 10;
	//printf("%d \n",camera->y);

        if (camera->y < 0)
        {
            camera->y = 0;
        }
    }
    else if ((saut==0) && (perso->pospersonnage.y<300)) 
    {
        camera->y += 10;
	//printf("%d \n",camera->y);

        if (camera->y + 800 >= 900) // if (map.startY + SCREEN_HEIGHT >= map.maxY);
        {
            camera->y = 0; //map.startY = map.maxY - SCREEN_HEIGHT;
        }
    }

} */

void scrolling(int dep,int saut,int h,SDL_Rect *camera,personnage *perso)
{
	switch(dep)
	{
				
		case 1: 
			if (camera->x<1600)
                		camera->x=camera->x+5;
			if (((perso->pospersonnage.x<300)||((camera->x>=1600))&&(perso->pospersonnage.x<1100)))
				perso->pospersonnage.x=perso->pospersonnage.x+5;
	
		break;
		case 2:
			if (camera->x>0)
                		camera->x=camera->x-5;
	    		if (((camera->x!=0)&&(perso->pospersonnage.x>=150))||((camera->x==0)&&(perso->pospersonnage.x==50)))
				perso->pospersonnage.x=perso->pospersonnage.x-5;
		break;

	}
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
couleur_obstacle=GetPixel(back.imageM,pos[i].x,pos[i].y);
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
void vie()
{
if (collide(&player, &monster[i]) == 1 || life)
            {
                if(personnage.life > 1)
                    personnage.life--;

                else
                {
                    
                    death =1;
                }
                //On joue le son
                playSoundFx(DESTROY);
                
            }
            else if (collide(&player, &lake) == 2)
            {
                //On met le timer à 1 pour tuer le monstre intantanément
                monster[i].timerMort = 1;
                playSoundFx(DESTROY);
            }
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

