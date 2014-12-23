game:
	gcc ship.c menu.c globals.h -o ship -lcurses -lpthread
clean:
	rm ship
debug:
	gcc ship.c menu.c globals.h -o ship -lcurses -lpthread -g
