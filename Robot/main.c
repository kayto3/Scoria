#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Robot.h"
#include "Background.h"
int main()
{
SDL_Surface *ecran = NULL;
int continuer =1;
Robot rob;
background back;
mouvement mvt;
int i=0;
SDL_Event event;
//initialiser
initialiser_robot (&rob);
initialiser_background(&back);
SDL_Init(SDL_INIT_VIDEO);

Remplissage_TabMVT (&mvt);

ecran=SDL_SetVideoMode(1600,800,32,SDL_HWSURFACE);
affichage_background(ecran,&back);
SDL_Flip(ecran);
while (continuer)
{		
	SDL_PollEvent(&event);	
	//affichage
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			case SDLK_SPACE:	
			{	
			SDL_Flip(ecran);				
			Apparition_anime (&mvt,&rob,&back,ecran);
			}
			}
}
}
switch (event.type)
{
	case (SDL_QUIT) :
	{
	continuer=0 ;
	break;
	}
}
return 0;
}
