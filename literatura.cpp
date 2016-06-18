#include "obra.h"
#include "literatura.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Literatura::Literatura(string nombre, string codigo,string fechaIngreso,double precio, string autor, string genero, string epoca)
	:Obra(nombre, codigo, fechaIngreso,precio), autor(autor), genero(genero), epoca(epoca){
}
Literatura::~Literatura(){
}
string Literatura::toString()const{
	stringstream ss;
	ss << "Literatura: " << Obra::toString() << " Autor: " << autor << " Genero: " << genero << " Epoca: " << epoca << " Ingreso: " << Obra::getFecha();
	return ss.str();
}
