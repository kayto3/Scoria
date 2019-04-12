#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"
int main()
{
SDL_Surface *ecran = NULL;
int continuer =1;
personnage perso;
background back;
SDL_Surface *image=NULL;
SDL_Rect camera;
SDL_Rect position_vie;
image=IMG_Load("Fichier 12_1.png");
position_vie.x=10;
position_vie.y=10;
int frame_limit=0;
int saut=0;
int h=0;
int curseur_active=0;
int dep=0;
int curseur_x;
SDL_Event event;
frame_limit=SDL_GetTicks()+33;
limit_fps(frame_limit);
frame_limit=SDL_GetTicks()+33;
//initialiser
initialiser_camera(&camera);
initialiser_personnage(&perso);
initialiser_background(&back);
SDL_Init(SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE);
while (continuer)
{
SDL_PollEvent(&event);
//affichage
        affichage_background(ecran,&back,&camera);
SDL_BlitSurface(image,NULL,ecran,&position_vie);
	affichage_personnage(ecran,&perso);
	SDL_Flip(ecran);
choix_commande(&event,&continuer,&perso,&back,&saut,&h,&curseur_active,&curseur_x,&dep);
deplacement_personnage(&event,&continuer,&perso,&back,&saut,&h,&curseur_active,&curseur_x,&dep);
gravity(&event,&continuer,&perso,&back,&saut,&h,&curseur_active,&curseur_x);
scrolling(dep,saut,h,&camera,&perso);
dep=0;

SDL_Flip(ecran);
}
SDL_FreeSurface(back.image);
SDL_FreeSurface(perso.personnage);
return 0;
}
