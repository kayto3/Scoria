#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "personnage.h"
#include "menu.h"
#include "enigme.h"
#include "Ennemi.h"
// INITIALISER 
void Initialiser_Menu(SDL_Surface **ecran,SDL_Surface **imageDeFond,SDL_Surface **bouton1,SDL_Surface **bouton2,SDL_Surface **bouton3,SDL_Surface **bouton4,SDL_Surface **bouton_selection1,SDL_Surface **bouton_selection2,SDL_Surface **bouton_selection3,SDL_Surface **bouton_selection4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4,SDL_Rect *posBouS1,SDL_Rect *posBouS2,SDL_Rect *posBouS3,SDL_Rect *posBouS4,Mix_Music **music,Mix_Chunk **son)
{
    //POS Fond 
    positionFond->x = 0;
    positionFond->y = 0;
    //POS BOUTON NORMAL
    posBou1->x=25;
    posBou1->y=150;
    posBou2->x=25;
    posBou2->y=250;
    posBou3->x=25;
    posBou3->y=350;
    posBou4->x=25;
    posBou4->y=450;
    //POS BOUTON SELECTION
    posBouS1->x=100;
    posBouS1->y=150;
    posBouS2->x=100;
    posBouS2->y=250;
    posBouS3->x=100;
    posBouS3->y=350;
    posBouS4->x=100;
    posBouS4->y=450;

    //image
    *imageDeFond = IMG_Load("background.png");
    *bouton1 = IMG_Load("bouton1.png");
    *bouton2 = IMG_Load("bouton2.png");
    *bouton3 = IMG_Load("bouton3.png");
    *bouton4 = IMG_Load("bouton4.png");
    *bouton_selection1 = IMG_Load("bouton5.png");
    *bouton_selection2 = IMG_Load("bouton6.png");
    *bouton_selection3 = IMG_Load("bouton7.png");
    *bouton_selection4 = IMG_Load("bouton8.png");
    /*FIN IMAGE*/
    //son
    *music=Mix_LoadMUS("Menu Theme.mp3");
    *son=Mix_LoadWAV("chunk.wav");
}

void Affichage_initial(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4)
{
    


        SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
        SDL_BlitSurface(bouton1, NULL, ecran, posBou1);
        SDL_BlitSurface(bouton2, NULL, ecran, posBou2);
        SDL_BlitSurface(bouton3, NULL, ecran, posBou3);
        SDL_BlitSurface(bouton4, NULL, ecran, posBou4);

}

void Affichage_Decale(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Surface *bouton_selection1,SDL_Surface *bouton_selection2,SDL_Surface *bouton_selection3,SDL_Surface *bouton_selection4,SDL_Rect *positionFond,SDL_Rect *posBou1,SDL_Rect *posBou2,SDL_Rect *posBou3,SDL_Rect *posBou4,SDL_Rect *posBouS1,SDL_Rect *posBouS2,SDL_Rect *posBouS3,SDL_Rect *posBouS4,int curseur)
{
    
if(curseur==1)
        {

            SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
            SDL_BlitSurface(bouton_selection1, NULL, ecran, posBouS1);
            SDL_BlitSurface(bouton2, NULL, ecran, posBou2);
            SDL_BlitSurface(bouton3, NULL, ecran, posBou3);
            SDL_BlitSurface(bouton4, NULL, ecran, posBou4);

          

        }
        if(curseur==2 )
        {
            SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
            SDL_BlitSurface(bouton1, NULL, ecran, posBou1);
            SDL_BlitSurface(bouton_selection2, NULL, ecran, posBouS2);
            SDL_BlitSurface(bouton3, NULL, ecran, posBou3);
            SDL_BlitSurface(bouton4, NULL, ecran, posBou4);

        }
        if(curseur==3)
        {

            SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
            SDL_BlitSurface(bouton1, NULL, ecran, posBou1);
            SDL_BlitSurface(bouton2, NULL, ecran, posBou2);
            SDL_BlitSurface(bouton_selection3, NULL, ecran, posBouS3);
            SDL_BlitSurface(bouton4, NULL, ecran, posBou4);

           

        }
        if(curseur==4 )
        {
            SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
            SDL_BlitSurface(bouton1, NULL, ecran, posBou1);
            SDL_BlitSurface(bouton2, NULL, ecran, posBou2);
            SDL_BlitSurface(bouton3, NULL, ecran, posBou3);
            SDL_BlitSurface(bouton_selection4, NULL, ecran, posBouS4);
        } 

}





void menuoption(SDL_Surface *ecran,Mix_Chunk *son,int *sound,int *fullscreen)
{
    int continuer=1,curseur=0;
	
    SDL_Surface *minus=NULL,*plus=NULL,*niv_vol_1=NULL,*niv_vol_2=NULL,*niv_vol_3=NULL,*on=NULL,*off=NULL,*on_s=NULL,*off_s=NULL,*barre=NULL,*retour=NULL,*imageDeFond=NULL;
    SDL_Event event;

    SDL_Rect positionFond,positionplus,positionminus,positionbarre,positionretour,position_off,position_on;

    positionFond.x = 0;
    positionFond.y = 0;
    positionplus.x=405;
    positionplus.y=165;
    positionminus.x=180;
    positionminus.y=170;
    positionbarre.x=300;
    positionbarre.y=185;
    positionretour.x=550;
    positionretour.y=450;
    position_off.x=250;
    position_off.y=300;
    position_on.x=350;
    position_on.y=300;


    imageDeFond = IMG_Load("background_settings.png");
    barre=IMG_Load("barre.png");
    minus= IMG_Load("minus.png");
    on_s= IMG_Load("on_s.png");
    off_s = IMG_Load("off_s.png");
    plus= IMG_Load("plus.png");
    niv_vol_1=IMG_Load("niv_vol_1.png");
    niv_vol_2= IMG_Load("niv_vol_2.png");
    niv_vol_3 =IMG_Load("niv_vol_3.png");
    on= IMG_Load("on.png");
    off= IMG_Load("off.png");
    retour=IMG_Load("retour.png");
    
    while (continuer)
    {
       
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_BlitSurface(plus, NULL, ecran, &positionplus);
        SDL_BlitSurface(minus, NULL, ecran, &positionminus);
        SDL_BlitSurface(barre, NULL, ecran, &positionbarre);
        SDL_BlitSurface(retour, NULL, ecran, &positionretour);

        if(*fullscreen==1)
        {
            SDL_BlitSurface(on_s, NULL, ecran, &position_on);
            SDL_BlitSurface(off, NULL, ecran, &position_off);

        }
        else
        {
            SDL_BlitSurface(on, NULL, ecran, &position_on);
            SDL_BlitSurface(off_s, NULL, ecran, &position_off);

        }
        if(*sound==1)
            SDL_BlitSurface(niv_vol_3, NULL, ecran, &positionbarre);
        else if(*sound==2)
            SDL_BlitSurface(niv_vol_2, NULL, ecran, &positionbarre);
        else if(*sound==3)
            SDL_BlitSurface(niv_vol_1, NULL, ecran, &positionbarre);
        

        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                Mix_PlayChannel(-1,son,0);
                continuer=0;
                break;
            }

        case SDL_MOUSEBUTTONDOWN:
            if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==1))
            {
            if(*sound<3)
	   *sound=*sound+1;

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(curseur==2))
            {
            if(*sound>1)
           *sound=*sound-1;
            
            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(curseur==3))
            {
                Mix_PlayChannel(-1,son,0);
           *fullscreen=1;
        ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN  );
	     }
             else if((event.button.button == SDL_BUTTON_LEFT)&&(curseur==4))
            {
                Mix_PlayChannel(-1,son,0);
           *fullscreen=0;
        ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
    	
            }
             else if((event.button.button == SDL_BUTTON_LEFT)&&(curseur==5))
            {
           continuer=0;
            }
            break;
            
             case SDL_MOUSEMOTION:

            if ((event.motion.x>180)&&(event.motion.x<380)&& (event.motion.y>170)&&(event.motion.y<230))
            {
                curseur=1;

            }

            else if ((event.motion.x>405)&&(event.motion.x<650)&& (event.motion.y>165)&&(event.motion.y<225))
            {
                curseur=2;
            }
            else if ((event.motion.x>350)&&(event.motion.x<550)&& (event.motion.y>300)&&(event.motion.y<360))
            {
                curseur=3;
            }
            else if ((event.motion.x>250)&&(event.motion.x<450)&& (event.motion.y>300)&&(event.motion.y<360))
            {
                curseur=4;
            }
             else if ((event.motion.x>550)&&(event.motion.x<750)&& (event.motion.y>450)&&(event.motion.y<510))
            {
                curseur=5;
            }

            break;	
        }

        SDL_Flip(ecran);
    }
    SDL_FreeSurface(imageDeFond);

}


void input_Menu(SDL_Event event,int *curseur,int *continuer,SDL_Surface *ecran,Mix_Chunk *son,int *sound,int *fullscreen)
{
switch(event.type)
        {
        case SDL_QUIT:
            *continuer=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==3))
            {
                Mix_PlayChannel(1,son,0);
		menuoption(ecran,son,sound,fullscreen);
            }
	else if((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==4))
	    {
                Mix_PlayChannel(1,son,0);
		*continuer=0;
            }
         break;

        case SDL_MOUSEMOTION:

            if ((event.motion.x>25)&&(event.motion.x<225)&& (event.motion.y>150)&&(event.motion.y<210))
            {
               *curseur=1;

            }

            else if ((event.motion.x>25)&&(event.motion.x<225)&& (event.motion.y>250)&&(event.motion.y<310))
            {
                *curseur=2;
            }
            else if ((event.motion.x>25)&&(event.motion.x<225)&& (event.motion.y>350)&&(event.motion.y<410))
            {
                *curseur=3;
            }
            else if ((event.motion.x>25)&&(event.motion.x<225)&& (event.motion.y>450)&&(event.motion.y<510))
            {
                *curseur=4;
            }
            

            break;


        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                Mix_PlayChannel(1,son,0);
                *continuer=0;
                break;
            case SDLK_UP :
                *curseur=*curseur-1;
                break ;
            case SDLK_DOWN :
                *curseur=*curseur+1;
                break;
            case SDLK_RETURN:
                if ((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==3))
            {
                Mix_PlayChannel(1,son,0);
		menuoption(ecran,son,sound,fullscreen);
            }
	else if((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==4))
	    {
                Mix_PlayChannel(1,son,0);
		*continuer=0;
            }
	else if((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==1))
	    {
                Mix_PlayChannel(1,son,0);
		niveau1(ecran);
		
            }
               
                break;
            }


        }

}

void niveau1(SDL_Surface *ecran)
{
int continuer =1,resultat=0,nv=3;
personnage perso;
background back;
SDL_Surface *image=NULL;
int frame_limit=0;
int saut=0;
int h=0;
int curseur_active=0;
int dep=0;
int curseur_x;
SDL_Rect position_vie;
//ennemi
enemy ennemi;
mouvement mvt;
ennemi.actif=0;
int i=0,j=0;
image=IMG_Load("Fichier 12_1.png");
position_vie.x=10;
position_vie.y=10;
SDL_Event event;
frame_limit=SDL_GetTicks()+33;
limit_fps(frame_limit);
frame_limit=SDL_GetTicks()+33;
//initialiser
initialiser_camera(&back);
initialiser_personnage(&perso);
initialiser_ennemi (&ennemi);
initialiser_background(&back);
Remplissage_animation (&mvt);
Remplissage_animation_perso(&perso);
SDL_EnableKeyRepeat(20,20);
while (continuer)
{
SDL_PollEvent(&event);
choix_commande(&event,&continuer,&perso,&back,&saut,&h,&curseur_active,&curseur_x,&dep);
deplacement_souris(&event,&continuer,&perso,&back,&saut,&h,&curseur_active,&curseur_x,&dep);
deplacement_perso(&perso,dep,saut);
gravity(&perso,&back,&saut,&h);
scrolling(dep,saut,h,&back,&perso,&curseur_active,&curseur_x);
ennemi_camera(dep,&back,&ennemi,perso);
//affichage
        affichage_background(ecran,&back);
	SDL_BlitSurface(image,NULL,ecran,&position_vie);
	Anime_perso(dep,ecran,&perso);
//affichage ennemi
	if(ennemi.actif==0)
	Deplacement_annime(&mvt,&ennemi,&back,ecran,&perso);
	SDL_Flip(ecran);
if((collision_entite(perso,ennemi,back)==1) && (ennemi.actif==0))
ennemi.actif=enigme(&nv,ecran);
if (perso.pospersonnage.y >= 600)
{
nv --;
initialiser_camera(&back);
initialiser_personnage(&perso);
initialiser_background(&back);
initialiser_ennemi (&ennemi);
if (nv == 2)
image = IMG_Load("Fichier 11_1.png");
else if(nv == 1)
image = IMG_Load("Fichier 10_1.png");
else if(nv == 0)
continuer=0;
}
dep=0;
}
SDL_FreeSurface(back.image);
SDL_FreeSurface(perso.personnage);
}

//Free Menu
void Free_Menu(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *bouton1,SDL_Surface *bouton2,SDL_Surface *bouton3,SDL_Surface *bouton4,SDL_Surface *bouton_selection1,SDL_Surface *bouton_selection2,SDL_Surface *bouton_selection3,SDL_Surface *bouton_selection4)
{
SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(bouton1);
    SDL_FreeSurface(bouton2);
    SDL_FreeSurface(bouton3);
    SDL_FreeSurface(bouton4);
    SDL_FreeSurface(bouton_selection1);
    SDL_FreeSurface(bouton_selection2);
    SDL_FreeSurface(bouton_selection3);
    SDL_FreeSurface(bouton_selection4);
}
