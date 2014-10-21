game:
	gcc ship.c -o ship -lcurses -lpthread
clean:
	rm ship
debug:
	gcc ship.c -o ship -lcurses -lpthread -g
