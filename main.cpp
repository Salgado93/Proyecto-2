#include "obra.h"
#include "escultura.h"
#include "literatura.h"
#include "pintura.h"
#include <iostream>
#include <vector>
#include <curses.h>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

int menuPrincipal();
//y/2 = 20
//x/2 = 84

int main(int argc, char* argv[]){
	initscr();
	cbreak(); //Cerrar con Ctrl z	
	int x,y; //Posicion de pantalla
	mvprintw(15,70,"Inventario Museo El Prado");
	refresh();
	int opcion;
	while((opcion = menuPrincipal()) != 52 ){
		if (opcion == 49){
			clear();
			mvprintw(17,70,"Ingrese El Tipo De Obra");
			refresh();
			move(18,70);
			getch();
			clear();
		}

	}
	endwin();
	return 0;
}

int menuPrincipal(){
	int retVal;
	mvprintw(17,70,"1. Agregar Obras");
	mvprintw(18,70,"2. Listar Obras");
	mvprintw(19,70,"3. Eliminar Obras");
	mvprintw(20,70,"4. Salir");
	move(21,70);
	retVal = getch();
	return retVal;
}
