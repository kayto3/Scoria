prog:main.o menu.o background.o personnage.o enigme.o
	gcc main.o menu.o background.o personnage.o enigme.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
background.o:background.c
	gcc -c background.c -g 
personnage.o:personnage.c
	gcc -c personnage.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
