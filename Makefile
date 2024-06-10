default: 
	gcc main.c

window:
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe window.o -lraylib -lgdi32 -lwinmm

exec: 
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe window.o -lraylib -lgdi32 -lwinmm
	./w.exe