#ifndef objet_H_INCLUDED
#define objet_H_INCLUDED

typedef struct
{
SDL_Surface *image;
SDL_Rect pos;
int actif;
}objet;

typedef struct
{
SDL_Surface *image;
SDL_Rect pos;
}score;

void initialiser_objet(objet *obj,int x,int y);
void affichage_objet(SDL_Surface *ecran,objet *obj);
void initialiser_score(score *scor,int x,int y);
void objet_camera(int dep,background *back,objet *obj,personnage perso);
int collision_obj(personnage perso,objet obj,background back);
void maj_score(SDL_Surface *ecran,score *scor,int scoree);

#endif // objet_H_INCLUDED
