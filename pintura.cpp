#include "obra.h"
#include "pintura.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Pintura::Pintura(string nombre, string codigo,string fechaIngreso,double precio,string lienzo,string tecnica,string pintura,string genero)
	:Obra(nombre, codigo, fechaIngreso,precio), lienzo(lienzo), tecnica(tecnica), pintura(pintura),genero(genero){
}
Pintura::~Pintura(){
}
string Pintura::toString()const{
	stringstream ss;
	ss << Obra::toString() << " Pintura " << "Lienzo: " << lienzo << "Tecnica: " << tecnica << "Pintura " << pintura << "Genero: " << genero;
	return ss.str();
}
