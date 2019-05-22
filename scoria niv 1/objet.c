#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "background.h"
#include "personnage.h"
#include "enigme.h"
#include "Ennemi.h"
#include "objet.h"
#include <time.h>
void initialiser_objet(objet *obj,int x,int y)
{
	obj->pos.x=x;
	obj->pos.y=y;
	obj->angle=0;
	obj->image = IMG_Load("Objet.png");
}

void initialiser_score(score *scor,int x,int y)
{
	scor->pos.x=x;
	scor->pos.y=y;
	scor->image = IMG_Load("zero.png");
}

void affichage_objet(SDL_Surface *ecran,objet *obj)
{
	SDL_BlitSurface(obj->rotation,NULL,ecran,&obj->pos);	
}

void objet_camera(int dep,background *back,objet *obj,personnage perso)
{
		if(perso.vx>0)
		{
			if (back->camera.x<6363)
                		obj->pos.x=obj->pos.x-perso.vx;
		}
		else if(perso.vx<0)
		{
			if (back->camera.x>0)
				obj->pos.x=obj->pos.x-perso.vx;
		}
}

int collision_obj(personnage perso,objet obj,background back)
{
if((perso.pospersonnage.x + perso.pospersonnage.w < obj.pos.x) || (perso.pospersonnage.x > obj.pos.x + obj.pos.w) || (perso.pospersonnage.y + perso.pospersonnage.h < obj.pos.y) || (perso.pospersonnage.y > obj.pos.y + obj.pos.h ))
return 0; // pas de collision
else
return 1;
}

void maj_score(SDL_Surface *ecran,score *scor,int scoree)
{
if (scoree == 1)
scor->image=IMG_Load("un.png");
else if (scoree == 2)
scor->image=IMG_Load("deux.png");
else if (scoree == 3)
scor->image=IMG_Load("trois.png");
SDL_BlitSurface(scor->image,NULL,ecran,&scor->pos);
}

void Rotozoom(objet *obj)
{
            obj->angle += 10; //On augmente l'angle pour que l'image tourne sur elle-même.
//if(*angle>=260)
//*angle=0;

}


























