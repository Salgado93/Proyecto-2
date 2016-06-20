#include<iostream>
#include "empleado.h"
#include <string>
#include <sstream>
using namespace std;
using std::string;
using std::stringstream;
Empleado::Empleado(string nombre,string apellido,string id):nombre(nombre),apellido(apellido),id(id){
}
Empleado::~Empleado(){
}
string Empleado::toString()const{
	stringstream ss;
	ss << nombre << " " << apellido;
	return ss.str();
}


