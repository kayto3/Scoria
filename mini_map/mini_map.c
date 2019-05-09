#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "mini_map.h"
void initialiser_mini_map(mini_map *m)
{
	m->map=IMG_Load("mini_map.png");
	m->pointer=IMG_Load("pointer.png");
	m->pos_map.x=400;
	m->pos_map.y=500;

	m->pos_pointer.x=400;
	m->pos_pointer.y=500;	

}
void afficher_map(SDL_Surface *ecran,mini_map *m)
{
	SDL_BlitSurface(m->map,NULL,ecran,&m->pos_map);
        SDL_Flip(ecran);
}
void afficher_pointer(SDL_Surface *ecran,mini_map *m)
{
	SDL_BlitSurface(m->pointer,NULL,ecran,&m->pos_pointer);
        SDL_Flip(ecran);
}

void main_mini_map(SDL_Surface *ecran,int dep)
{
int continuer=0;
mini_map m;

	initialiser_mini_map(&m);
	afficher_map(ecran,&m);
	afficher_pointer(ecran,&m);	
	if (dep==1)
	{
		m.pos_pointer.x=m.pos_map.x+1;
	}
	if (dep==2)
	{	
		m.pos_pointer.x=m.pos_map.x+1;
	}
	SDL_Flip(ecran);



}
