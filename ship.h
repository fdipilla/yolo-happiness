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

#ifndef SHIP_H
#define SHIP_H
typedef struct _objeto objeto;

int LEN(const char *);
int seLaPuso(objeto , objeto );

void dibujar(char, int, int);
void dibujarString(char *, int , int);
void dibujarJugador(int);
void dubujarBarraEstado();
void dibujarObjeto(objeto);
void crearInvasor( objeto *);
void *repetir ();
int colorRandom();
void salir();

#endif
