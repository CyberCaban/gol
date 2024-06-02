default: 
	gcc main.c

window: 
	gcc window.c -lraylib -lgdi32 -lwinmm -o w

exec:
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe window.o -lraylib -lgdi32 -lwinmm