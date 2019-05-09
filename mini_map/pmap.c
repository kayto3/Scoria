void initialiser_pmap(pamp *pamp){

	pamp->afficher_pmap=NULL;
	pamp->afficher_pmap=IMG_Load("background.png");

	pamp->pos_pmap.x=700;
	pamp->pos_pmap.y=20;


	pamp->afficher_pperso=NULL;
	pamp->afficher_pperso=IMG_Load("pperso.png");

	pamp->pos_pperso.x=700;
	pamp->pos_pperso.y=40;


}

void afficher_pamp(pmap *pamp,SDL_Surface *ecran){


	SDL_BlitSurface(pamp->afficher_pmap,NULL,ecran,pamp->pos_pmap.x);

	SDL_BlitSurface(pamp->afficher_pperso,NULL,ecran,pamp->pos_pperso.x);
	if (mouvment==1)
		pamp->pos_pperso.x+=2;
	if (mouvment==2)
		pamp->pos_pperso.x-=2;

}
