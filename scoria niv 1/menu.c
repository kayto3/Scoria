#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "background.h"
#include "personnage.h"
#include "menu.h"
#include "enigme.h"
#include "Ennemi.h"
#include "mini_map.h"
#include "objet.h"
#include "enigme2.h"
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.

//LOGO
void Remplissage_animation_logo(logo *logo)
{
	logo->poslogo.x=0;
	logo->poslogo.y=-300;
	logo->image[0]=IMG_Load("logo/logo01.jpg");
	logo->image[1]=IMG_Load("logo/logo02.jpg");
	logo->image[2]=IMG_Load("logo/logo03.jpg");
	logo->image[3]=IMG_Load("logo/logo04.jpg");
	logo->image[4]=IMG_Load("logo/logo05.jpg");
	logo->image[5]=IMG_Load("logo/logo06.jpg");
	logo->image[6]=IMG_Load("logo/logo07.jpg");
	logo->image[7]=IMG_Load("logo/logo08.jpg");
	logo->image[8]=IMG_Load("logo/logo09.jpg");
	logo->image[9]=IMG_Load("logo/logo10.jpg");
	logo->image[10]=IMG_Load("logo/logo11.jpg");
	logo->image[11]=IMG_Load("logo/logo12.jpg");
	logo->image[12]=IMG_Load("logo/logo13.jpg");
	logo->image[13]=IMG_Load("logo/logo14.jpg");
	logo->image[14]=IMG_Load("logo/logo15.jpg");
	logo->image[15]=IMG_Load("logo/logo16.jpg");
}
void affichage_logo(SDL_Surface *ecran,logo logo)
{
int i=0;
	for(i=0;i<16;i++)
	{
	logo.poslogo.y=-300;
	SDL_BlitSurface(logo.image[i],NULL,ecran,&logo.poslogo);
	SDL_Flip(ecran);
	SDL_Delay(80);
	}
}

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


void input_Menu(SDL_Event event,int *curseur,int *continuer,SDL_Surface *ecran,Mix_Chunk *son,int *sound,int *fullscreen,int *niv)
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
	else if((event.button.button == SDL_BUTTON_LEFT)&&(*curseur==1))
	    {
                Mix_PlayChannel(1,son,0);
		niveau1(ecran,niv);
		if(*niv==2)
		niveau2(ecran,niv);
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
                if (*curseur==3)
            {
                Mix_PlayChannel(1,son,0);
		menuoption(ecran,son,sound,fullscreen);
            }
	else if(*curseur==4)
	    {
                Mix_PlayChannel(1,son,0);
		*continuer=0;
            }
	else if(*curseur==1)
	    {
                Mix_PlayChannel(1,son,0);
		niveau1(ecran,niv);
		if(*niv==2)
		niveau2(ecran,niv);
		
            }
               
                break;
            }


        }

}

void niveau1(SDL_Surface *ecran,int *niv)
{
int continuer =1,resultat=0,nv=3;
personnage perso;
mini_map m;
background back;
/*ENIGME2*/
enigme2 e;
int delta,tab_cons[20];

SDL_Surface *image=NULL;
int frame_limit=0;
int saut=0;
int h=0;
int curseur_active=0;
int dep=0;
int curseur_x;
int stat=0;
//score
score scor;
int scoree=0;
int tempsPrecedent = 0, tempsActuel = 0;
SDL_Rect position_vie;
//ennemi
enemy ennemi,ennemi2;
mouvement mvt;
objet obj1,obj2,obj3;
obj1.actif=0;
obj2.actif=0;
obj3.actif=0;
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
initialiser_ennemi (&ennemi,1800,320,2300,1500);
initialiser_ennemi (&ennemi2,3500,320,3800,3200);
initialiser_objet(&obj1,1010,180);
initialiser_objet(&obj2,2544,180);
initialiser_objet(&obj3,4324,230);
initialiser_score(&scor,10,90);
initialiser_background(&back,*niv);
Remplissage_animation (&mvt);
Remplissage_animation_perso(&perso);
initialiser_mini_map(&m,*niv);
/*init enigme2*/
delta =generation_alea(&e,tab_cons);
//printf("test\n");
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
ennemi_camera(dep,&back,&ennemi2,perso);
objet_camera(dep,&back,&obj1,perso);
objet_camera(dep,&back,&obj2,perso);
objet_camera(dep,&back,&obj3,perso);


//affichage
        affichage_background(ecran,&back);
	SDL_BlitSurface(image,NULL,ecran,&position_vie);
	maj_score(ecran,&scor,scoree);
	
//MINI MAP
	main_mini_map(ecran,dep,&m,&perso,&back);
//rotozoom
Rotozoom(&obj1);

obj1.rotation=rotozoomSurface(obj1.image,obj1.angle,1.0,1); //On transforme la surface image.
Rotozoom(&obj2);
obj2.rotation=rotozoomSurface(obj2.image,obj2.angle,1.0,1); //On transforme la surface image.
Rotozoom(&obj3);
obj3.rotation=rotozoomSurface(obj3.image,obj3.angle,1.0,1); //On transforme la surface image.
	
//affichage objet
	printf("tt\n");
	if((perso.pospersonnage.x-obj1.pos.x < 300) && (obj1.actif==0))
	affichage_objet(ecran,&obj1);
	if((perso.pospersonnage.x-obj2.pos.x < 300) && (obj2.actif==0))
	affichage_objet(ecran,&obj2);
	if((perso.pospersonnage.x-obj3.pos.x < 300) && (obj3.actif==0))
	affichage_objet(ecran,&obj3);
	Anime_perso(dep,ecran,&perso);
printf("perso: %d  /  %d \n",perso.pospersonnage.x+back.camera.x,perso.pospersonnage.y);
//affichage ennemi
	
if(ennemi.actif==0)
	Deplacement_annime(&mvt,&ennemi,&back,ecran,&perso);
	MoveIA(&ennemi2,perso,&stat,200,&mvt,ecran);
	SDL_Flip(ecran);
printf("test\n");
//collision ennemi
if((collision_entite(perso,ennemi,back)==1) && (ennemi.actif==0))
//ennemi.actif=enigme(&nv,ecran);
ennemi.actif=main_enigme2(ecran,&e,delta,tab_cons);
//collision objet
if((collision_obj(perso,obj1,back)==1) && (obj1.actif==0))
{
obj1.actif=1;
scoree++;
}
if((collision_obj(perso,obj2,back)==1) && (obj2.actif==0))
{
obj2.actif=1;
scoree++;
}
if((collision_obj(perso,obj3,back)==1) && (obj3.actif==0))
{
obj3.actif=1;
scoree++;
}
//joueur tombe
if (perso.pospersonnage.y >= 600)
{
nv --;
initialiser_camera(&back);
initialiser_personnage(&perso);
initialiser_background(&back,*niv);
initialiser_ennemi (&ennemi,1800,320,2300,1500);
initialiser_ennemi (&ennemi2,3500,320,3800,3200);
initialiser_objet(&obj1,1010,180);
initialiser_objet(&obj2,2544,180);
initialiser_objet(&obj3,4324,230);
initialiser_score(&scor,10,90);
if (nv == 2)
image = IMG_Load("Fichier 11_1.png");
else if(nv == 1)
image = IMG_Load("Fichier 10_1.png");
else if(nv == 0)
continuer=0;
}
//jouer fin niveau
if(perso.pospersonnage.x>1600)
{
*niv=2;
continuer=0;
}
dep=0;
}
SDL_FreeSurface(back.image);
SDL_FreeSurface(perso.personnage);
}

void niveau2(SDL_Surface *ecran,int *niv)
{
int continuer =1,resultat=0,nv=3;
personnage perso;
mini_map m;
background back;
/*ENIGME2*/
enigme2 e;
int delta,tab_cons[20];

SDL_Surface *image=NULL;
int frame_limit=0;
int saut=0;
int h=0;
int curseur_active=0;
int dep=0;
int curseur_x;
int stat=0;
//score
score scor;
int scoree=0;
int tempsPrecedent = 0, tempsActuel = 0;
SDL_Rect position_vie;
//ennemi
enemy ennemi,ennemi2;
mouvement mvt;
objet obj1,obj2,obj3;
obj1.actif=0;
obj2.actif=0;
obj3.actif=0;
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
initialiser_ennemi (&ennemi,1800,320,1946,943);
initialiser_ennemi (&ennemi2,3500,320,3700,2576);
initialiser_objet(&obj1,1010,180);
initialiser_objet(&obj2,2544,180);
initialiser_objet(&obj3,4191,180);
initialiser_score(&scor,10,90);
initialiser_background(&back,*niv);
Remplissage_animation (&mvt);
Remplissage_animation_perso(&perso);
initialiser_mini_map(&m,*niv);
/*init enigme2*/
delta =generation_alea(&e,tab_cons);
//printf("test\n");
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
ennemi_camera(dep,&back,&ennemi2,perso);
objet_camera(dep,&back,&obj1,perso);
objet_camera(dep,&back,&obj2,perso);
objet_camera(dep,&back,&obj3,perso);


//affichage
        affichage_background(ecran,&back);
	SDL_BlitSurface(image,NULL,ecran,&position_vie);
	maj_score(ecran,&scor,scoree);
	
//MINI MAP
	main_mini_map(ecran,dep,&m,&perso,&back);
	
//affichage objet
		printf("tt\n");
	if((perso.pospersonnage.x-obj1.pos.x < 300) && (obj1.actif==0))
	affichage_objet(ecran,&obj1);
	if((perso.pospersonnage.x-obj2.pos.x < 300) && (obj2.actif==0))
	affichage_objet(ecran,&obj2);
	if((perso.pospersonnage.x-obj3.pos.x < 300) && (obj3.actif==0))
	affichage_objet(ecran,&obj3);
	Anime_perso(dep,ecran,&perso);

printf("perso: %d  /  %d \n",perso.pospersonnage.x+back.camera.x,perso.pospersonnage.y);
//rotozoom
Rotozoom(&obj1);

obj1.rotation=rotozoomSurface(obj1.image,obj1.angle,1.0,1); //On transforme la surface image.
Rotozoom(&obj2);
obj2.rotation=rotozoomSurface(obj2.image,obj2.angle,1.0,1); //On transforme la surface image.
Rotozoom(&obj3);
obj3.rotation=rotozoomSurface(obj3.image,obj3.angle,1.0,1); //On transforme la surface image.
//affichage ennemi
	
if(ennemi.actif==0)
	Deplacement_annime(&mvt,&ennemi,&back,ecran,&perso);
	MoveIA(&ennemi2,perso,&stat,200,&mvt,ecran);
	SDL_Flip(ecran);
printf("test\n");
//collision ennemi
if((collision_entite(perso,ennemi,back)==1) && (ennemi.actif==0))
//ennemi.actif=enigme(&nv,ecran);
ennemi.actif=main_enigme2(ecran,&e,delta,tab_cons);
//collision objet
if((collision_obj(perso,obj1,back)==1) && (obj1.actif==0))
{
obj1.actif=1;
scoree++;
}
if((collision_obj(perso,obj2,back)==1) && (obj2.actif==0))
{
obj2.actif=1;
scoree++;
}
if((collision_obj(perso,obj3,back)==1) && (obj3.actif==0))
{
obj3.actif=1;
scoree++;
}
//joueur tombe
if (perso.pospersonnage.y >= 600)
{
nv --;
initialiser_camera(&back);
initialiser_personnage(&perso);
initialiser_background(&back,*niv);
initialiser_ennemi (&ennemi,1800,320,1946,943);
initialiser_ennemi (&ennemi2,3500,320,3700,2576);
initialiser_objet(&obj1,1010,180);
initialiser_objet(&obj2,2544,180);
initialiser_objet(&obj3,4191,180);
initialiser_score(&scor,10,90);
if (nv == 2)
image = IMG_Load("Fichier 11_1.png");
else if(nv == 1)
image = IMG_Load("Fichier 10_1.png");
else if(nv == 0)
continuer=0;
}
//jouer fin niveau
if(perso.pospersonnage.x>1600)
{
*niv=3;
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
