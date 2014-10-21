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


static void dibujar(char *que[], int cuantoMide, int x, int y) {
    int i,y_secundaria;
    
    for (i = 0; i < cuantoMide ; i++){
        y_secundaria = y;
        while (*que[i]){
            draw(*que[i], x + i, y_secundaria++);
            que[i]++;
        }
    }
    
}


static void dubijarLogo() {
    int i,y,x,y_secundaria;
    int altoLogo;
    
    char *yolo_happiness[4] = {
        " __ __ _____ __    _____     _____ _____ _____ _____ _____ _____ _____ _____ _____\n "
        ,"|  |  |     |  |  |     |___|  |  |  _  |  _  |  _  |     |   | |   __|   __|   __|\n"
        ,"|_   _|  |  |  |__|  |  |___|     |     |   __|   __|-   -| | | |   __|__   |__   |\n"
        ,"  |_| |_____|_____|_____|   |__|__|__|__|__|  |__|  |_____|_|___|_____|_____|_____|\n"
    };
    
    
    altoLogo = sizeof(yolo_happiness)/sizeof(yolo_happiness[0]);
    
    y = (anchoMaximo / 2) - LEN(yolo_happiness[0]) / 2;
    x = alturaMaxima / 2;
    
    dibujar(yolo_happiness, altoLogo, x,y);
}


static void dibujarAyuda() {
    int i,y,x,y_secundaria;
    int altoTexto;
    
    char *ayuda[1] = { " Presione 'q' para iniciar el juego" };
    
    altoTexto = sizeof(ayuda)/sizeof(ayuda[0]);
    
    y = (anchoMaximo / 2) - LEN(ayuda[0]) / 2;
    x = (alturaMaxima / 2) - 5 ;
    
    dibujar(ayuda, altoTexto, x, y);
}

static void dibujarControles() {
    int i,y,x,y_secundaria;
    int altoTexto;
    
    char *ayuda[1] = { " Presione 'J' para ir para arriba, 'K' para ir para abajo y 'Espacio' para disparar" };
    
    altoTexto = sizeof(ayuda)/sizeof(ayuda[0]);
    
    y = (anchoMaximo / 2) - LEN(ayuda[0]) / 2;
    x = (alturaMaxima / 2) + 10 ;
    
    dibujar(ayuda, altoTexto, x, y);
}



static void dubijarInto() {

    dibujarAyuda();
    dubijarLogo();
    dibujarControles();
}



void menu () {
    char tecla;
    
    dubijarInto();
    
    while ((tecla = getch()) != 'q') { ; }
    
}
