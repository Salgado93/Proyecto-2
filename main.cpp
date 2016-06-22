#include "obra.h"
#include "empleado.h"
#include "guardia.h"
#include "conservador.h"
#include "escultura.h"
#include "literatura.h"
#include "pintura.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <curses.h>
#include <time.h>
#include <fstream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using namespace std;
int menuPrincipal();
int menuAgregar();
int menuEmpleados();
int menuPrecios();
void mostrarPrecios(double,double);
void agregarGuardia(vector<Empleado*>&);
void agregarConservador(vector<Empleado*>&);
void agregarEscultura(vector<Obra*>&);
void agregarPintura(vector<Obra*>&);
void agregarLiteratura(vector<Obra*>&);
void listarObras(vector<Obra*>);
void mostrarIngresos(vector<Empleado*>);
void eliminarObra(vector<Obra*>&);
//y/2 = 20
//x/2 = 84

int main(int argc, char* argv[]){
	initscr();
	cbreak();

	int opcion;
	vector <Obra*> Obras;
	vector <Empleado*>listaEmpleados;
	
	while((opcion = menuPrincipal()) != 54 ){
		if (opcion == 49){
			int opcion;
			while((opcion = menuAgregar()) != 52){
				if(opcion == 49){
					agregarEscultura(Obras);
				}
				if(opcion == 50){
					agregarLiteratura(Obras);
				}
				if(opcion == 51){
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
		if(opcion == 52){
			int opcion;
			while((opcion = menuEmpleados()) != 52){
				if(opcion == 49){
					agregarGuardia(listaEmpleados);
				}
				if(opcion == 50){
					agregarConservador(listaEmpleados);
				}
				if (opcion == 51){
					mostrarIngresos(listaEmpleados);
				}
			}
		}
		if(opcion == 53){
			int opcionPrecios;
			double precio1;
                       	double precio2;
			while((opcionPrecios = menuPrecios()) != 51){
				if(opcionPrecios == 49){
					ifstream reader("Precios.txt");
					if(reader.is_open()){
						reader >> precio1;
						reader >> precio2;
					}
					mostrarPrecios(precio1,precio2);
				}
				if(opcionPrecios == 50){
					ofstream writer("Precios.txt");
					double precio1=0.00;
					double precio2=0.00;
					if(writer.is_open()){
						mvprintw(21,58,"               Precio Obras Permanentes $:              ");
        					refresh();
        					move(22,73);
        					scanw("%lf",&precio1);
        					mvprintw(23,58,"               Precio Guia Con Audio: $                 ");
        					refresh();
        					move(24,73);
						scanw("%lf",&precio2);
						writer << precio1 << endl;
						writer << precio2 << endl;
					}
				}
			}
		}
	}
	for (int i=0; i<Obras.size(); i++){
		delete Obras[i];
	}
	for (int i=0; i<listaEmpleados.size(); i++){
		delete listaEmpleados[i];
	}
	endwin();
	return 0;
}

int menuPrincipal(){
	int retVal;
	mvprintw(10,58,"*-----------------------------------------------*");
	mvprintw(11,58,"|                                               |");
	mvprintw(12,58,"|                MUSEO EL PRADO                 |");
	mvprintw(13,58,"|                                               |");
	mvprintw(14,58,"|-----------------------------------------------|");
	mvprintw(15,58,"|                                               |");
	mvprintw(16,58,"|                                               |");
	mvprintw(17,58,"|                1. Agregar Obras               |");
	mvprintw(18,58,"|                2. Listar Obras                |");
	mvprintw(19,58,"|                3. Eliminar Obras              |");
	mvprintw(20,58,"|                4. Empleados                   |");
	mvprintw(21,58,"|                5. Precios                     |");
	mvprintw(22,58,"|                6. Salir                       |");
	mvprintw(23,58,"|                                               |");
	mvprintw(24,58,"|                                               |");
	mvprintw(25,58,"*-----------------------------------------------*");
	mvprintw(27,58,"Ingrese Opcion: ");
	refresh();
	move(28,58);	
	retVal = getch();
	clear();
	return retVal;
}
int menuAgregar(){
        int retVal;
	mvprintw(10,58,"*-----------------------------------------------*");
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
        mvprintw(23,58,"*-----------------------------------------------*");
        mvprintw(25,58,"Ingrese Opcion: ");		
	refresh();
        move(26,58);
        retVal = getch();
	clear();
	return retVal;
}
int menuPrecios(){
        int retVal;
        mvprintw(10,58,"*-----------------------------------------------*");
        mvprintw(11,58,"|                                               |");
        mvprintw(12,58,"|                  $ PRECIOS $                  |");
        mvprintw(13,58,"|                                               |");
        mvprintw(14,58,"|-----------------------------------------------|");
        mvprintw(15,58,"|                                               |");
        mvprintw(16,58,"|                                               |");
        mvprintw(17,58,"|             1. Ver Precios                    |");
        mvprintw(18,58,"|             2. Cambiar Precios                |");
        mvprintw(19,58,"|             3. Salir                          |");
        mvprintw(20,58,"|                                               |");
        mvprintw(21,58,"|                                               |");
        mvprintw(22,58,"|                                               |");
        mvprintw(23,58,"*-----------------------------------------------*");
        mvprintw(25,58,"Ingrese Opcion: ");
        refresh();
        move(26,58);
        retVal = getch();
        clear();
        return retVal;
}

int menuEmpleados(){
        int retVal;
        mvprintw(10,58,"*-----------------------------------------------*");
        mvprintw(11,58,"|                                               |");
        mvprintw(12,58,"|                    EMPLEADOS                  |");
        mvprintw(13,58,"|                                               |");
        mvprintw(14,58,"|-----------------------------------------------|");
        mvprintw(15,58,"|                                               |");
        mvprintw(16,58,"|                                               |");
        mvprintw(17,58,"|             1. Agregar Guardia                |");
        mvprintw(18,58,"|             2. Agregar Conservador            |");
        mvprintw(19,58,"|             3. Ingresos                       |");
        mvprintw(20,58,"|             4. Salir                          |");
        mvprintw(21,58,"|                                               |");
        mvprintw(22,58,"|                                               |");
        mvprintw(23,58,"*-----------------------------------------------*");
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
        mvprintw(21,58,"               Ingrese El Precio $:              ");
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
        mvprintw(19,58,"               Ingrese El Codigo: " );
        refresh();
	move(20,73);
        getstr(codigo);
        mvprintw(21,58,"               Ingrese El Precio $:");
        refresh();
	move(22,73);
        scanw("%lf",&precio);
        mvprintw(23,58,"               Ingrese El Lienzo: " );
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
        mvprintw(21,58,"               Ingrese El Precio $:              ");
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
        mvprintw(27,58,"               Ingrese La Epoca:                 ");
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
void mostrarPrecios(double precio1,double precio2){
        int espacioVertical=14;
        mvprintw(5,58,"*----------------------------------------------");
        mvprintw(6,58,"|----------------------------------------------|");
        mvprintw(7,58,"|                   Precios                    |");
        mvprintw(8,58,"|----------------------------------------------|");
        mvprintw(9,58,"*----------------------------------------------*");
	mvprintw(12,58,"Ticket Colecciones Permanentes: %4.2f$",precio1);
	mvprintw(13,58,"Ticket Guia Con Audio: %4.2f$",precio2);
        refresh();
        move(espacioVertical,58);
        getch();
        clear();
}

void mostrarIngresos(vector<Empleado*> listaEmpleados){
        int espacioVertical=12;
        mvprintw(5,58,"*----------------------------------------------*");
        mvprintw(6,58,"|----------------------------------------------|");
        mvprintw(7,58,"|                   INGRESOS                   |");
        mvprintw(8,58,"|----------------------------------------------|");
        mvprintw(9,58,"*----------------------------------------------*");
        refresh();
        for (Empleado* e: listaEmpleados){
                mvprintw(espacioVertical,20,"%s Ingresos: %4.2f$",e->toString().c_str(),e->ingresos());
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
void agregarGuardia(vector<Empleado*> &listaEmpleados){
        char nombre[80];
        char apellido[80];
        char identidad[80];
	double tarifa;
        int turnos;
        mvprintw(10,58,"*------------------------------------------------*");
        mvprintw(11,58,"|                                                |");
        mvprintw(12,58,"|                    GUARDIAS                    |");
        mvprintw(13,58,"|                                                |");
        mvprintw(14,58,"*------------------------------------------------*");
        mvprintw(15,58,"                                                  ");
        mvprintw(16,58,"                                                  ");
        mvprintw(17,58,"               Ingrese El Nombre:                 ");
        refresh();
        move(18,73);
        getstr(nombre);
        mvprintw(19,58,"               Ingrese El Apellido:               ");
        refresh();
        move(20,73);
        getstr(apellido);
        mvprintw(21,58,"               Ingrese La Identidad:              ");
        refresh();
        move(22,73);
        getstr(identidad);
        mvprintw(23,58,"               Ingrese La Tarifa Por Turno $:      ");
        refresh();
        move(24,73);
        scanw("%lf",&tarifa);
        mvprintw(25,58,"               Ingrese Cantidad De Turnos:        ");
        refresh();
        move(26,73);
        scanw("%d",&turnos);
        listaEmpleados.push_back(new Guardia(nombre,apellido,identidad,tarifa,turnos));
        clear();
}
void agregarConservador(vector<Empleado*> &listaEmpleados){
        char nombre[80];
        char apellido[80];
        char identidad[80];
        double salario;
        mvprintw(10,58,"*------------------------------------------------*");
        mvprintw(11,58,"|                                                |");
        mvprintw(12,58,"|                 CONSERVADORES                  |");
        mvprintw(13,58,"|                                                |");
        mvprintw(14,58,"*------------------------------------------------*");
        mvprintw(15,58,"                                                  ");
        mvprintw(16,58,"                                                  ");
        mvprintw(17,58,"               Ingrese El Nombre:                 ");
        refresh();
        move(18,73);
        getstr(nombre);
        mvprintw(19,58,"               Ingrese El Apellido:               ");
        refresh();
        move(20,73);
        getstr(apellido);
        mvprintw(21,58,"               Ingrese La Identidad:              ");
        refresh();
        move(22,73);
        getstr(identidad);
        mvprintw(23,58,"               Ingrese Salario Mensual $:         ");
        refresh();
        move(24,73);
        scanw("%lf",&salario);
        listaEmpleados.push_back(new Conservador(nombre,apellido,identidad,salario));
        clear();
}

