#include "obra.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
Obra::Obra(string nombre,string codigo,string fechaIngreso,double precio):nombre(nombre),codigo(codigo),fechaIngreso(fechaIngreso),precio(precio){
}
Obra::~Obra(){
}

string Obra::toString()const{
	stringstream ss;
	ss << "Obra: " << nombre << "Codigo: " << codigo << "Fecha Ingreso: " << fechaIngreso << "Precio: " << precio;
	return ss.str();
}

