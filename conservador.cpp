#include "empleado.h"
#include "conservador.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
Conservador::Conservador(string nombre, string apellido,string id,double salario)
	:Empleado(nombre, apellido,id),salario(salario){
}
double Conservador::getSalario()const{
	return salario;
}

double Conservador::ingresos()const{
	return getSalario();	
}
string Conservador::toString()const{
	stringstream ss;
	ss << "Conservador: " << Empleado::toString();
	return ss.str();
}
