

typedef struct pmap{

	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_rect pos_pperso;
}pmap;

	void initialiser_pmap(pamp *pamp);
	void afficher_pamp(pmap *pamp,SDL_Surface *ecran);