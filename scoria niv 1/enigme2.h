#ifndef ENIGME2_H_INCLUDED
#define ENIGME2_H_INCLUDED
#include <SDL/SDL_ttf.h>

typedef struct
{
 SDL_Surface *imagefond,*win,*lose;
SDL_Rect pos_fond,pos_resultat;

SDL_Surface *constante[3];
SDL_Rect pos_cons[3];
}enigme2;

int main_enigme2(SDL_Surface *ecran,enigme2 *e,int delta,int tab_cons[]);
void init_enigme2(enigme2 *e,int tab_cons[]);
int  generation_alea(enigme2 *e,int tab_cons[]);
#endif
