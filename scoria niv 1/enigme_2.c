
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme2.h"
#include <time.h>
#include <math.h>
void init_enigme2(enigme2 *e,int tab_cons[])
{
	e->win=IMG_Load("enigmes/win.png");
	e->lose=IMG_Load("enigmes/lose.png");
	e->pos_resultat.x=10;
	e->pos_resultat.y=76;
	e->imagefond=IMG_Load("enigmes-2.0.png");
	e->pos_fond.x=0;
	e->pos_fond.y=0;
	int i;
for (i=0;i<3;i++)
{
	switch(tab_cons[i])
{
	 case 1:
        e->constante[i]=IMG_Load("enigmes/1.png");
        
        break;
    case 2:
         e->constante[i]=IMG_Load("enigmes/2.png");
        break;
    case 3:
        e->constante[i]=IMG_Load("enigmes/3.png");
        break;
    case 4:
         e->constante[i]=IMG_Load("enigmes/4.png");
        break;
    case 5:
         e->constante[i]=IMG_Load("enigmes/5.png");
        break;
    case 6:
        e->constante[i]=IMG_Load("enigmes/6.png");
        break;
 case 7:
         e->constante[i]=IMG_Load("enigmes/7.png");
        break;
    case 8:
         e->constante[i]=IMG_Load("enigmes/8.png");
        break;
    case 9:
        e->constante[i]=IMG_Load("enigmes/9.png");
        break;


}
}
e->pos_cons[0].x=50;
e->pos_cons[0].y=80;

e->pos_cons[1].x=230;
e->pos_cons[1].y=80;

e->pos_cons[2].x=430;
e->pos_cons[2].y=80;

}
int  generation_alea(enigme2 *e,int tab_cons[])
{
srand(time(NULL));
	int i,x_rand,rand_num;
for (i=0;i<3;i++)
{
	rand_num = (rand() % (1 - 9 + 1)) + 1;
	tab_cons[i]=rand_num;
	
}
printf("%d|%d|%d\n",tab_cons[0],tab_cons[1],tab_cons[2]);

int delta=(tab_cons[1]*tab_cons[1])-4*tab_cons[0]*tab_cons[2];

return delta;
}

int main_enigme2(SDL_Surface *ecran,enigme2 *e,int delta,int tab_cons[])
{
	int resultat,continuer=1;
	SDL_Event event;
	int curseur=0;
	int reponse=0;
	int i=0;
	init_enigme2	(e,tab_cons);
	for (i=0;i<3;i++)	
	
	while (continuer)
	{
	        SDL_PollEvent(&event);
	SDL_BlitSurface(e->imagefond, NULL, ecran, &e->pos_fond);
	//SDL_Flip(ecran);
	for (i=0;i<3;i++)
	{
			
	SDL_BlitSurface(e->constante[i], NULL, ecran, &e->pos_cons[i]);
	}
	if(delta<=0)
	reponse=-1;
	else if (delta>=0)
	reponse=1;
			
	
	SDL_Flip(ecran);
	
	switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==reponse))
            {
               SDL_BlitSurface(e->win,NULL,ecran,&e->pos_resultat);
		SDL_Flip(ecran);
		resultat=1;
		SDL_Delay(300);
		continuer=0;
            }
	else if((event.button.button == SDL_BUTTON_LEFT)&&(curseur!=reponse))
	    {
                SDL_BlitSurface(e->lose,NULL,ecran,&e->pos_resultat);
		SDL_Flip(ecran);
		resultat=0;
		SDL_Delay(300);
            }
         break;

        case SDL_MOUSEMOTION:

            if ((event.motion.x>169)&&(event.motion.x<269)&& (event.motion.y>221)&&(event.motion.y<295))
            {
               curseur=1;

            }

            else if ((event.motion.x>342)&&(event.motion.x<444)&& (event.motion.y>221)&&(event.motion.y<297))
            {
                curseur=2;
            }
           
            

            break;
	}	
}

return resultat;
}
