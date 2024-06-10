LIBS = -lraylib -lgdi32 -lwinmm
OBJ = window.o elements.o 

default: 
	gcc main.c

window:
	gcc -c ./lib/elements.c
	gcc -I ./lib -c window.c
	gcc -L ./lib -o w.exe $(OBJ) $(LIBS) 

exec: 
	make window
	./w.exe