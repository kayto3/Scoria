prog:Robot.o main.o
	gcc Robot.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
Robot.o:Robot.c
	gcc -c Robot.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
