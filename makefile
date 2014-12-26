game:
	gcc ship.c menu.c globals.h colores.c -o ship -lcurses -lpthread
clean:
	rm ship
debug:
	gcc ship.c menu.c globals.h colores.c -o ship -lcurses -lpthread -g
