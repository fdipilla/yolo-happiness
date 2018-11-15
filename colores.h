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

#ifndef GAME_COLORS
#define GAME_COLORS

#define COLOR_ROJO 1
#define COLOR_ROJO_VIDAS 2
#define COLOR_AZUL 3
#define COLOR_VERDE 4

#define ROJO COLOR_PAIR(COLOR_ROJO)
#define ROJO_VIDAS COLOR_PAIR(COLOR_ROJO_VIDAS)
#define AZUL COLOR_PAIR(COLOR_AZUL)
#define VERDE COLOR_PAIR(COLOR_VERDE)

void inicializar_colores();

#endif
