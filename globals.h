/*
 * Fabrizio Di Pilla <fabriziodipilla@gmail.com >
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


/*
 * No solo uso globles, sino que tengo un archivo lleno de ellas.
 */

#include <curses.h>

typedef struct _objeto {
    int x, y, ancho, alto, speed;
    char hechoDe;
} objeto;


#ifndef GAME_GLOBALS
#define GAME_GLOBALS

int alturaMaxima, anchoMaximo, posicionJugador;

int balasSimultaneas;
objeto *balas;

int numeroInvasores;
objeto *invasores;

int vidas, puntos, invasoresSiguienteNivel, nivel;

WINDOW *ventana;

#endif




