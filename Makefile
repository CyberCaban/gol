default: 
	gcc main.c

window:
	gcc -c ./lib/elements.c
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe window.o -lraylib -lgdi32 -lwinmm elements.o

exec: 
	gcc -c ./lib/elements.c
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe window.o -lraylib -lgdi32 -lwinmm elements.o
	./w.exe