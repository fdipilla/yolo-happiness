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
#include <curses.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include "ship.h"
#include "globals.h"
#include "colores.h"
#include "menu.h"

int LEN(const char *str){
    const char *s;
    
    for(s = str; *s; ++s);
    return (s - str);
}


void dibujar(char dc, int x, int y){
    if ( x > alturaMaxima || y > anchoMaximo) return;
    
    mvwaddch(ventana, x, y, dc);
    refresh();
}


void dibujarString(char *string, int x, int y){
    int i;
    for (i = 0;i < LEN(string); i++)
        dibujar(string[i], x, y + i);
}

void dibujarJugador( int x ){
    int i,y;
    
    char *nave[3] = {
         "   --\n"
        ,"-==||\n"
        ,"   --\n"
    };
    
    for (i = 0; i < (sizeof(nave)/sizeof(nave[0])) ; i++){
        y = (anchoMaximo - 6);
        while (*nave[i]){
            dibujar(*nave[i], x + i, y++);
            nave[i]++;
        }
    }
    
}


void  dubujarBarraEstado() {
    char string[20] = {'\0'};
    int i, len;
    
    sprintf(string, "Puntos: %i Vidas: ", puntos );
    dibujarString(string, 0,0);
    
    len = LEN(string);
    
    
    for (i = 0; i < vidas; i++) {
        attron(ROJO_VIDAS);
            
        dibujarString(" ", 0, ++len);
        
        attroff(ROJO_VIDAS);
        
        dibujarString(" ", 0, ++len);
        
    }
    
    
}

void dibujarObjeto(objeto o) {
    int r, c;
    attron(o.color);
    for ( r = o.x; r < o.x + o.alto; r++){
        for (c = o.y; c < o.y + o.ancho; c++){
            dibujar(o.hechoDe, r, c);
        }
    }
    attroff(o.color);
}


int colorRandom() {
    switch (rand() % 3) {
    case 0:
        return ROJO;
        break;
    case 1:
        return AZUL;
        break;
    default:
        return VERDE;
        break;
    }
}


void crearInvador(struct _objeto *invasor){
    (*invasor).ancho = 3;
    (*invasor).alto = 2;
    (*invasor).speed = 1;
    (*invasor).hechoDe = 'I';
    (*invasor).x = rand() % alturaMaxima;
    (*invasor).y = -2;
    (*invasor).color = colorRandom();
}

int seLaPuso(objeto a, objeto b){
    if (
        ( (b.y >= a.y && b.y <= a.y + a.ancho) || (a.y >= b.y && a.y <= b.y + b.ancho)) &&
        ( (b.x >= a.x && b.x <= a.x + a.alto) || (a.x >= b.x && a.x <= b.x + b.alto)) &&
        ( a.color == b.color )
        ) return 1;
    return 0;
}




void *repetir () {
    int i;
    
    while (1) {
        
        clear();
        dibujarJugador(posicionJugador);
        
        
        for (i = 0; i < numeroInvasores; i++){
            dibujarObjeto(invasores[i]);
            invasores[i].y += invasores[i].speed;
            if (invasores[i].y > anchoMaximo){
                crearInvador(&invasores[i]);
                vidas--;
            }
            
            
            int j;
            for (j = 0; j < balasSimultaneas; j++){
                if (balas[j].speed && seLaPuso(invasores[i], balas[j])){
                    crearInvador(&invasores[i]);
                    balas[j].speed = balas[j].y = 0;
                    puntos++;
                }
            }
            
        }
        

        for (i = 0; i < balasSimultaneas; i++){
            if (!balas[i].speed) continue;
            dibujarObjeto(balas[i]);
            balas[i].y -= balas[i].speed;
            
            if (balas[i].y < -balas[i].ancho)
                balas[i].speed = 0;
        }
        
        
        if (vidas <= 0) break;
        
        dubujarBarraEstado();
        
        if (puntos > invasoresSiguienteNivel){
            invasoresSiguienteNivel *= 2;
            nivel++;
            
            numeroInvasores += nivel;
            invasores = realloc(invasores, numeroInvasores * sizeof(objeto));
            
            for (i = 0; i < numeroInvasores; i++){
                crearInvador(&invasores[i]);
            }
            
            int r, c;
            for (r = 0; r < alturaMaxima; r++)
                for (c = 0; c < anchoMaximo; c++)
                    dibujar('~', r,c);
            
            dibujarString("Siguente nivel: ", alturaMaxima / 2, anchoMaximo / 2 - 5);
            
            refresh();
            usleep(1000000);
            
        }
        
        
        
        usleep(50000);
    }
    
    clear();
    dibujarString("Perdiste: ", alturaMaxima / 2 - 1, anchoMaximo / 2 - 4);
    char string[10] = {'\0'};
    sprintf(string, "%i", puntos);
    
    dibujarString(string, alturaMaxima / 2, anchoMaximo / 2 - LEN(string) / 2);
    
}




int main (){
    char tecla;
    int i;

    
    vidas = 3;
    invasoresSiguienteNivel = 25;
    nivel = 1;
    puntos = 0;
    
    
    srand(time(NULL));
    
    ventana = initscr();
    
    start_color();
    
    inicializar_colores();
    
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(ventana, alturaMaxima, anchoMaximo);
    
    clear();
    refresh();
    
    menu();

    posicionJugador = alturaMaxima / 2;
    
    balasSimultaneas = 10;
    balas = malloc(balasSimultaneas * sizeof(objeto));
    
    for (i = 0; i < balasSimultaneas; i++){
        balas[i].x = 0;
        balas[i].y = 0;
        balas[i].ancho = 4;
        balas[i].alto = 1;
        balas[i].speed = 0;
        balas[i].hechoDe = '-';
        balas[i].color = ROJO;
    }
    
    
    numeroInvasores = 5;
    invasores = malloc(numeroInvasores * sizeof(objeto));
    for(i = 0; i < numeroInvasores; i++){
        crearInvador(&invasores[i]);
    }

    
    pthread_t pth;
    pthread_create(&pth, NULL, repetir, "dibujar");
    
    while (1) {
        tecla = getch();
        if (tecla == 'q') break;
        if (tecla == 'j') posicionJugador = posicionJugador + 2;
        if (tecla == 'k') posicionJugador = posicionJugador - 2;
        
        if (tecla == 'a') {
            for ( i = 0; i < balasSimultaneas; i++){
                if (!balas[i].speed){
                    balas[i].x = posicionJugador;
                    balas[i].y = anchoMaximo;
                    balas[i].ancho = 4;
                    balas[i].alto = 1;
                    balas[i].speed = 3;
                    balas[i].hechoDe = '-';
                    balas[i].color = ROJO;
                    break;
                }
            }
        }
        if (tecla == 's') {
            for ( i = 0; i < balasSimultaneas; i++){
                if (!balas[i].speed){
                    balas[i].x = posicionJugador;
                    balas[i].y = anchoMaximo;
                    balas[i].ancho = 4;
                    balas[i].alto = 1;
                    balas[i].speed = 3;
                    balas[i].hechoDe = '-';
                    balas[i].color = AZUL;
                    break;
                }
            }
        }
        if (tecla == 'd') {
            for ( i = 0; i < balasSimultaneas; i++){
                if (!balas[i].speed){
                    balas[i].x = posicionJugador;
                    balas[i].y = anchoMaximo;
                    balas[i].ancho = 4;
                    balas[i].alto = 1;
                    balas[i].speed = 3;
                    balas[i].hechoDe = '-';
                    balas[i].color = VERDE;
                    break;
                }
            }
        }
        if (posicionJugador > alturaMaxima - 1) posicionJugador = alturaMaxima - 1;
        if (posicionJugador < 0) posicionJugador = 0;
        
    }
    
    
    salir();

}


void salir() {
    endwin();
    exit(0);
}
