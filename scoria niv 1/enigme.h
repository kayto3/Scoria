#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

typedef struct
{
    SDL_Surface *imagedefond;
    SDL_Surface *image_masque;
    SDL_Rect pos_fond;
    SDL_Rect pos_masque;

} background_enigme;
typedef struct
{
    SDL_Surface *image_tete;
    SDL_Rect pos_tete;
} tete;
typedef struct
{
    SDL_Surface *lose;
    SDL_Surface *win;
    SDL_Surface *countdown[5];
    SDL_Rect pos_lose;
    SDL_Rect pos_win;
    SDL_Rect pos_countdown;

} userinterface;
typedef struct
{
    int reponse;
    SDL_Surface *image_question;
    SDL_Rect pos_question;
} questions;
//tete
void initialiser_tete(tete *Tete,int random);
void affichage_tete(SDL_Surface *ecran,tete *Tete);
void deplacer_tete(SDL_Surface *ecran,SDL_Surface *image_tete,SDL_Rect *pos_tete,int *direction);
//background
int initialiser_background_enigme(background_enigme *back);
void affichage_background_enigme(SDL_Surface *ecran,background_enigme *back);
//question
int initialiser_question(questions *question);
void afficher_question(SDL_Surface *ecran,questions *question,userinterface *ui);

//fps
void limit_fps(int limit);
//collision
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int CollisionParfaite(tete Tete,background_enigme back);
//ui
void afficher_main(SDL_Surface *ecran,background_enigme *back,tete *Tete,userinterface *ui,int random,int *resultat,int *continuer,int *nbrvie,questions *question);
void initialiser_ui(userinterface *ui);
void afficher_win(SDL_Surface *ecran,userinterface *ui);
void afficher_lose(SDL_Surface *ecran,userinterface *ui);
void afficher_countdown(SDL_Surface *ecran,userinterface *ui);
//input
void input(int *continuer,SDL_Event *event,int *direction);   
int enigme(int *nbrvie,SDL_Surface *ecran);     
#endif

