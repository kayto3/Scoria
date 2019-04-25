#ifndef Ennemi_H_INCLUDED
#define Ennemi_H_INCLUDED

typedef struct
{
SDL_Surface *mvt_avant[8];
SDL_Surface *mvt_back[8];
}mouvement;

typedef struct
{
SDL_Surface *ennemi;
SDL_Rect posennemi;
int direc;
int i;
int j;
int posMax;
int posMin;
int actif;
mouvement mvt;
}enemy;

void initialiser_ennemi (enemy *ennemi);
void Remplissage_animation (mouvement *mvt);
void affichage_ennemi(SDL_Surface *ecran,enemy *ennemi);
void Deplacement_annime (mouvement *mvt,enemy *ennemi,background *back,SDL_Surface *ecran,personnage *perso);
void ennemi_camera(int dep,background *back,enemy *ennemi);
int collision_entite(personnage perso,enemy ennemi,background back);

#endif // Ennemi_H_INCLUDED
