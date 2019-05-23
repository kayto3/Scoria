#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"
#include "menu.h"
int main()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *bouton1 = NULL, *bouton2 = NULL, *bouton3 = NULL, *bouton4 = NULL;
    SDL_Surface  *bouton_selection1 = NULL,*bouton_selection2 = NULL,*bouton_selection3 = NULL,*bouton_selection4 = NULL;
    SDL_Rect positionFond, posBou1,posBou2,posBou3,posBou4,posBouS1,posBouS2,posBouS3,posBouS4;
    SDL_Event event;
    Mix_Music *music;
    Mix_Chunk *son;
	int continuer=1,curseur=0, sound=2,fullscreen=0;
	int niv=1;
	int frame_limit=0;
    ecran = SDL_SetVideoMode(1920, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("logo.bmp"), NULL);
    SDL_WM_SetCaption("Scoria Escape", NULL); 
	frame_limit=SDL_GetTicks()+33;
	limit_fps(frame_limit);
	frame_limit=SDL_GetTicks()+33;
//initialiser menu
Initialiser_Menu(&ecran,&imageDeFond,&bouton1,&bouton2,&bouton3,&bouton4,&bouton_selection1,&bouton_selection2,&bouton_selection3,&bouton_selection4,
&positionFond,&posBou1,&posBou2,&posBou3,&posBou4,&posBouS1,&posBouS2,&posBouS3,&posBouS4,&music,&son);
    Mix_PlayMusic(music,-1); 
    while (continuer)
    {
	niv=1;
        //Affichage_initial
	Affichage_initial(ecran,imageDeFond,bouton1,bouton2,bouton3,bouton4,&positionFond,&posBou1,&posBou2,&posBou3,&posBou4);
	Mix_VolumeMusic(MIX_MAX_VOLUME / sound);
        SDL_WaitEvent(&event);
        if(curseur<1)
            curseur=4;
        if(curseur>4)
            curseur=1;
        // imput_Menu
        input_Menu(event,&curseur,&continuer,ecran,son,&sound,&fullscreen,&niv);

        //Affchage_Decale
	Affichage_Decale(ecran,imageDeFond,bouton1,bouton2,bouton3,bouton4,bouton_selection1,bouton_selection2,bouton_selection3,bouton_selection4,
	&positionFond,&posBou1,&posBou2,&posBou3,&posBou4,&posBouS1,&posBouS2,&posBouS3,&posBouS4,curseur);
        SDL_Flip(ecran);
    }
	Free_Menu(ecran,imageDeFond,bouton1,bouton2,bouton3,bouton4,bouton_selection1,bouton_selection2,bouton_selection3,bouton_selection4);
    return 0;
}
