yolo-happiness
==============

Un space shooter basico usando ncurses.

#### Estado
:large_orange_diamond: : en desarrollo.

Trato que en el branch master siempre haya una version jugable del juego.


#### Uso
Los controles son **J** para subir y **K** para bajar.

Para disparar podes usar **A** que va a disparar un misil rojo,  **S** que va a disparar un misil azul y  **D** que va a disparar un misil verde.

Los enemigos son de tres colores y solo pueden ser eliminados si se les dispara con un misil del mismo color.

#### Compilacion
Para compilar en Debian hacen falta estos paquetes ncurses-devel ncurses, que se pueden instalar con:

`# apt-get install ncurses-devel ncurses`

O en algunos sistemas tambien  puede ser:

`# apt-get install libncurses5-dev`

Despues con un `make` salis andando


#### Screenshots
![ScreenShot](/screenshot.png)

![ScreenShot](/screenshot-2.png)

#### Agradecimientos
[Cristian Cabrera](https://github.com/surrealcristian/) quien tuvo la idea de los distintos colores de disparos/objetivos.
