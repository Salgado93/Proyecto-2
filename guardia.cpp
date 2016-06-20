#include "empleado.h"
#include "guardia.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
Guardia::Guardia(string nombre, string apellido,string id,double tarifaDia,int turnos)
	:Empleado(nombre, apellido,id),tarifaDia(tarifaDia),turnos(turnos){
}
double Guardia::getTarifa()const{
	return tarifaDia;
}
double Guardia::getTurnos()const{
	return turnos;
}
double Guardia::ingresos()const{
	return getTarifa()*getTurnos();	
}

string Guardia::toString()const{
	stringstream ss;
	ss << "Guardia: " << Empleado::toString();
	return ss.str();
}
