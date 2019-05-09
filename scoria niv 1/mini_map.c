#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "mini_map.h"
void initialiser_mini_map(mini_map *m)
{
	m->map=IMG_Load("mini.png");
	m->pointer=IMG_Load("mlm.png");
	m->pos_map.x=380;
	m->pos_map.y=0;

	m->pos_pointer.x=480;
	m->pos_pointer.y=10;	
	m->camera.x=380;
	m->camera.y=0;
	m->camera.h=1273;
	m->camera.w=120;

}
void afficher_map(SDL_Surface *ecran,mini_map *m)
{
	SDL_BlitSurface(m->map,NULL,ecran,&m->pos_map);

}
void afficher_pointer(SDL_Surface *ecran,mini_map *m)
{
	SDL_BlitSurface(m->pointer,NULL,ecran,&m->pos_pointer);


}

void main_mini_map(SDL_Surface *ecran,int dep,mini_map *m)
{

	afficher_map(ecran,m);
		
	if (dep==1)
	{
		m->pos_pointer.x=m->pos_pointer.x+10;
	}
	if (dep==2)
	{	
		m->pos_pointer.x=m->pos_pointer.x+10;
	}
afficher_pointer(ecran,m);




}
void scrolling_mini_map(int dep,mini_map *m,int *curseur_active,int *curseur_x)
{
	switch(dep)
	{
				
		case 1: 
			if (m->camera.x<1273)
                		m->camera.x=m->camera.x+5;
			if (((m->pos_pointer.x<60)||((m->camera.x>=1273))&&(m->pos_pointer.x<220)))
				m->pos_pointer.x=m->pos_pointer.x+5;
			if(m->pos_pointer.x>=*curseur_x)
			*curseur_active=0;
	
		break;
		case 2:
			if (m->camera.x>0)
                		m->camera.x=m->camera.x-5;
	    		if (((m->camera.x!=0)&&(m->pos_pointer.x>=30))||((m->camera.x==0)&&(m->pos_pointer.x==10)))
				m->pos_pointer.x=m->pos_pointer.x-5;
			if(m->pos_pointer.x<=*curseur_x)
			*curseur_active=0;
		break;

	}
}
