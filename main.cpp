#include "obra.h"
#include "escultura.h"
#include "literatura.h"
#include "pintura.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <curses.h>
#include <time.h>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
int menuPrincipal();
int menuAgregar();
void agregarEscultura(vector<Obra*>&);
void agregarPintura(vector<Obra*>&);
void agregarLiteratura(vector<Obra*>&);
void listarObras(vector<Obra*>);
void eliminarObra(vector<Obra*>&);
//y/2 = 20
//x/2 = 84

int main(int argc, char* argv[]){
	initscr();
	cbreak();

	int opcion;
	vector <Obra*> Obras;
	
	
	while((opcion = menuPrincipal()) != 52 ){
		if (opcion == 49){
			int opcionAgregar;
			while((opcionAgregar = menuAgregar()) != 52){
				if(opcionAgregar == 49){
					agregarEscultura(Obras);
				}
				if(opcionAgregar == 50){
					agregarLiteratura(Obras);
				}
				if(opcionAgregar == 51){
					agregarPintura(Obras);	
				}
			}
		}
		if(opcion == 50 ){
			listarObras(Obras);
		}
		if (opcion == 51){
			eliminarObra(Obras);
		}
	}
	endwin();
	return 0;
}

int menuPrincipal(){
	int retVal;

	mvprintw(10,58,"|-----------------------------------------------|");
	mvprintw(11,58,"|                                               |");
	mvprintw(12,58,"|                MUSEO EL PRADO                 |");
	mvprintw(13,58,"|                                               |");
	mvprintw(14,58,"|-----------------------------------------------|");
	mvprintw(15,58,"|                                               |");
	mvprintw(16,58,"|                                               |");
	mvprintw(17,58,"|                1. Agregar Obras               |");
	mvprintw(18,58,"|                2. Listar Obras                |");
	mvprintw(19,58,"|                3. Eliminar Obras              |");
	mvprintw(20,58,"|                4. Salir                       |");
	mvprintw(21,58,"|                                               |");
	mvprintw(22,58,"|                                               |");
	mvprintw(23,58,"|-----------------------------------------------|");
	mvprintw(25,58,"Ingrese Opcion: ");
	refresh();
	move(26,58);	
	retVal = getch();
	clear();
	return retVal;
}
int menuAgregar(){
        int retVal;
	mvprintw(10,58,"|-----------------------------------------------|");
        mvprintw(11,58,"|                                               |");
        mvprintw(12,58,"|                 AGREGAR OBRAS                 |");
        mvprintw(13,58,"|                                               |");
        mvprintw(14,58,"|-----------------------------------------------|");
        mvprintw(15,58,"|                                               |");
        mvprintw(16,58,"|                                               |");
        mvprintw(17,58,"|             1. Agregar Escultura              |");
        mvprintw(18,58,"|             2. Agregar Literatura             |");
        mvprintw(19,58,"|             3. Agregar Pintura                |");
        mvprintw(20,58,"|             4. Salir                          |");
        mvprintw(21,58,"|                                               |");
        mvprintw(22,58,"|                                               |");
        mvprintw(23,58,"|-----------------------------------------------|");
        mvprintw(25,58,"Ingrese Opcion: ");		
	refresh();
        move(26,58);
        retVal = getch();
	clear();
	return retVal;
}   
void agregarObra(vector<Obra*> &Obras){
	char codigo[80];
	char nombre[80];
	double precio;
	string fechaIngreso;
	time_t actual;
	time (&actual);
	fechaIngreso = ctime(&actual);
	mvprintw(17,70,"Ingrese El Nombre: ");
	refresh();
	getstr(nombre);
	mvprintw(18,70,"Ingrese El Codigo: ");
	refresh();
	getstr(codigo);
	mvprintw(19,70,"Ingrese El Precio: ");
	scanw("%lf",&precio);
	Obras.push_back(new Obra(nombre,codigo,fechaIngreso,precio));
	clear();
}
void agregarEscultura(vector<Obra*> &Obras){
        char codigo[80];
        char nombre[80];
        string fechaIngreso;
	double precio;
	double peso;
	char material[80];
	char tecnica[80];
        time_t actual;
        time (&actual);
        fechaIngreso = ctime(&actual);
	mvprintw(10,58,"*-----------------------------------------------*");
	mvprintw(11,58,"|                                               |");
	mvprintw(12,58,"|                  ESCULTURAS                   |");
	mvprintw(13,58,"|                                               |");
	mvprintw(14,58,"*-----------------------------------------------*");
	mvprintw(15,58,"                                                 ");
	mvprintw(16,58,"                                                 ");
        mvprintw(17,58,"               Ingrese El Nombre:                ");
        refresh();
	move(18,73);
        getstr(nombre);
        mvprintw(19,58,"               Ingrese El Codigo:                ");
        refresh();
	move(20,73);
        getstr(codigo);
        mvprintw(21,58,"               Ingrese El Precio:                ");
	refresh();
	move(22,73);
        scanw("%lf",&precio);
	mvprintw(23,58,"               Ingrese El Peso:                  ");
	refresh();
	move(24,73);
	scanw("%lf",&peso);
	mvprintw(25,58,"               Ingrese El Material:              ");
	refresh();
	move(26,73);
	getstr(material);
	mvprintw(27,58,"               Ingrese La Tecnica:               ");
	refresh();
	move(28,73);
	getstr(tecnica);
        Obras.push_back(new Escultura(nombre,codigo,fechaIngreso,precio,peso,material,tecnica));
        clear();
}
void agregarPintura(vector<Obra*> &Obras){
        char codigo[80];
        char nombre[80];
        string fechaIngreso;
        double precio;
        char lienzo[80];
        char tecnica[80];
	char pintura[80];
	char genero[80];
        time_t actual;
        time (&actual);
        fechaIngreso = ctime(&actual);
	mvprintw(10,58,"*-----------------------------------------------*");
        mvprintw(11,58,"|                                               |");
        mvprintw(12,58,"|                   PINTURAS                    |");
        mvprintw(13,58,"|                                               |");
        mvprintw(14,58,"*-----------------------------------------------*");
        mvprintw(15,58,"                                                 ");
        mvprintw(16,58,"                                                 ");
        mvprintw(17,58,"               Ingrese El Nombre:                ");
        refresh();
	move(18,73);
        getstr(nombre);
        mvprintw(19,58,"               Ingrese El Codigo: ");
        refresh();
	move(20,73);
        getstr(codigo);
        mvprintw(21,58,"               Ingrese El Precio: ");
        refresh();
	move(22,73);
        scanw("%lf",&precio);
        mvprintw(23,58,"               Ingrese El Lienzo: ");
        refresh();
	move(24,73);
        getstr(lienzo);
        mvprintw(25,58,"               Ingrese La Tecnica: ");
        refresh();
	move(26,73);
        getstr(tecnica);
        mvprintw(27,58,"               Ingrese La Pintura: ");
        refresh();
	move(28,73);
        getstr(pintura);
	mvprintw(29,58,"               Ingrese El Genero: ");
        refresh();
	move(30,73);
        getstr(genero);
        Obras.push_back(new Pintura(nombre,codigo,fechaIngreso,precio,lienzo,tecnica,pintura,genero));
        clear();
}
void agregarLiteratura(vector<Obra*> &Obras){
        char codigo[80];
        char nombre[80];
        string fechaIngreso;
        double precio;
        char autor[80];
        char genero[80];
        char epoca[80];
        time_t actual;
        time (&actual);
        fechaIngreso = ctime(&actual);
	mvprintw(10,58,"*-----------------------------------------------*");
        mvprintw(11,58,"|                                               |");
        mvprintw(12,58,"|                  LITERATURAS                  |");
        mvprintw(13,58,"|                                               |");
        mvprintw(14,58,"*-----------------------------------------------*");
        mvprintw(15,58,"                                                 ");
        mvprintw(16,58,"                                                 ");
        mvprintw(17,58,"               Ingrese El Nombre:                ");
        refresh();
        move(18,73);
        getstr(nombre);
        mvprintw(19,58,"               Ingrese El Codigo:                ");
        refresh();
        move(20,73);
        getstr(codigo);
        mvprintw(21,58,"               Ingrese El Precio:                ");
        refresh();
        move(22,73);
        scanw("%lf",&precio);
        mvprintw(23,58,"               Ingrese El Autor:                 ");
        refresh();
        move(24,73);
        getstr(autor);
        mvprintw(25,58,"               Ingrese El Genero:                ");
        refresh();
        move(26,73);
        getstr(genero);
        mvprintw(27,58,"               Ingrese La Epoca:               ");
        refresh();
        move(28,73);
        getstr(epoca);
        Obras.push_back(new Literatura(nombre,codigo,fechaIngreso,precio,autor,genero,epoca));
        clear();
}
void listarObras(vector<Obra*> Obras){
	int espacioVertical=12;
	mvprintw(5,58,"*----------------------------------------------*");
	mvprintw(6,58,"|----------------------------------------------|");
	mvprintw(7,58,"|             LISTA TOTAL DE OBRAS             |");
	mvprintw(8,58,"|----------------------------------------------|");
	mvprintw(9,58,"*----------------------------------------------*");
	refresh();
	for (Obra* p: Obras){
		mvprintw(espacioVertical,20,"%s",p->toString().c_str());	
		refresh();
		espacioVertical++;
	}
	move(espacioVertical,20);
	getch();
	clear();
}
void eliminarObra(vector<Obra*>&Obras){
	int posicion;
	int espacioVertical=12;
	mvprintw(5,58,"*----------------------------------------------*");
        mvprintw(6,58,"|----------------------------------------------|");
        mvprintw(7,58,"|                ELIMINAR OBRAS                |");
        mvprintw(8,58,"|----------------------------------------------|");
        mvprintw(9,58,"*----------------------------------------------*");
        refresh();
	for (int i=0; i<Obras.size(); i++){
        	//cout << i << " " << Obras[i]->toString() << endl;
		mvprintw(espacioVertical,20,"%d %s",i+1,Obras[i]->toString().c_str());
		espacioVertical++;
      	}
	mvprintw(espacioVertical+2,20,"Ingrese La Obra Que Desea Eliminar: ");
	refresh();
	move(espacioVertical+3,20);
	scanw("%d",&posicion);
	Obras.erase(Obras.begin()+posicion-1);
	mvprintw(espacioVertical+4,20,"Obra Borrada!");
	refresh();
	move(espacioVertical+5,20);
	getch();
	clear();
}
