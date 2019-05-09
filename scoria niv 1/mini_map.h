#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef struct 
{
	SDL_Surface *map;
	SDL_Rect pos_map;
	SDL_Surface *pointer;
	SDL_Rect pos_pointer;
	SDL_Rect camera;
}mini_map;
	
void initialiser_mini_map(mini_map *m);
void afficher_map(SDL_Surface *ecran,mini_map *m);
void afficher_pointer(SDL_Surface *ecran,mini_map *m);
void main_mini_map(SDL_Surface *ecran,int dep);
void scrolling_mini_map(int dep,mini_map *m,int *curseur_active,int *curseur_x);

#endif
