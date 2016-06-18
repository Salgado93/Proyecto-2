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
	mvprintw(15,70,"Inventario Museo El Prado");
	mvprintw(17,70,"1. Agregar Obras");
	mvprintw(18,70,"2. Listar Obras");
	mvprintw(19,70,"3. Eliminar Obras");
	mvprintw(20,70,"4. Salir");
	refresh();
	move(21,70);	
	retVal = getch();
	clear();
	return retVal;
}
int menuAgregar(){
        int retVal;
        mvprintw(17,70,"1. Agregar Escultura");
        mvprintw(18,70,"2. Agregar Literatura");
        mvprintw(19,70,"3. Agregar Pintura");
        mvprintw(20,70,"4. Salir");
	refresh();
        move(21,70);
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
        mvprintw(17,70,"Ingrese El Nombre: ");
        refresh();
        getstr(nombre);
        mvprintw(18,70,"Ingrese El Codigo: ");
        refresh();
        getstr(codigo);
        mvprintw(19,70,"Ingrese El Precio: ");
	refresh();
        scanw("%lf",&precio);
	mvprintw(20,70,"Ingrese El Peso: ");
	refresh();
	scanw("%lf",&peso);
	mvprintw(21,70,"Ingrese El Material: ");
	refresh();
	getstr(material);
	mvprintw(22,70,"Ingrese La Tecnica: ");
	refresh();
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
        mvprintw(17,70,"Ingrese El Nombre: ");
        refresh();
        getstr(nombre);
        mvprintw(18,70,"Ingrese El Codigo: ");
        refresh();
        getstr(codigo);
        mvprintw(19,70,"Ingrese El Precio: ");
        refresh();
        scanw("%lf",&precio);
        mvprintw(20,70,"Ingrese El Lienzo: ");
        refresh();
        getstr(lienzo);
        mvprintw(21,70,"Ingrese La Tecnica: ");
        refresh();
        getstr(tecnica);
        mvprintw(22,70,"Ingrese La Pintura: ");
        refresh();
        getstr(pintura);
	mvprintw(23,70,"Ingrese El Genero: ");
        refresh();
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
        mvprintw(17,70,"Ingrese El Nombre: ");
        refresh();
        getstr(nombre);
        mvprintw(18,70,"Ingrese El Codigo: ");
        refresh();
        getstr(codigo);
        mvprintw(19,70,"Ingrese El Precio: ");
        refresh();
        scanw("%lf",&precio);
        mvprintw(20,70,"Ingrese El Autor: ");
        refresh();
        getstr(autor);
        mvprintw(21,70,"Ingrese El Genero: ");
        refresh();
        getstr(genero);
        mvprintw(22,70,"Ingrese La Epoca: ");
        refresh();
        getstr(epoca);
        Obras.push_back(new Literatura(nombre,codigo,fechaIngreso,precio,autor,genero,epoca));
        clear();
}
void listarObras(vector<Obra*> Obras){
	int espacioVertical=15;
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
	int espacioVertical=15;
	for (int i=0; i<Obras.size(); i++){
        	//cout << i << " " << Obras[i]->toString() << endl;
		mvprintw(espacioVertical,20,"%d %s",i+1,Obras[i]->toString().c_str());
		espacioVertical++;
      	}
	mvprintw(espacioVertical+2,20,"Ingrese El Numero De Obra A Borrar: ");
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
