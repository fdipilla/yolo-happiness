game:
	gcc ship.c menu.c globals.h colores.c -o yolo-happiness -lcurses -lpthread
clean:
	rm yolo-happiness
debug:
	gcc ship.c menu.c globals.h colores.c -o yolo-happiness -lcurses -lpthread -g
