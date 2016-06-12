#include "obra.h"
#include "escultura.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Escultura::Escultura(string nombre, string codigo,string fechaIngreso,double precio,double peso,string material,string tecnica)
	:Obra(nombre, codigo, fechaIngreso,precio), peso(peso), material(material), tecnica(tecnica){
}
Escultura::~Escultura(){
}
string Escultura::toString()const{
	stringstream ss;
	ss << Obra::toString() << " Escultura " << "Peso: " << peso << "Material: " << material << "Tecnica: " << tecnica;
	return ss.str();
}
