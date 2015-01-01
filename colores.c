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

#include "colores.h"
#include <curses.h>

void inicializar_colores () 
{
    init_pair(COLOR_ROJO, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_ROJO_VIDAS, COLOR_BLACK, COLOR_RED);
    init_pair(COLOR_AZUL, COLOR_BLUE, COLOR_BLACK);
    
}


