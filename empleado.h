#pragma once
#include <string>
using std::string;
class Empleado{
	string nombre;
	string apellido;
	string id;	
 public:
	Empleado(string,string, string);
	virtual ~Empleado();
	virtual string toString()const;
	virtual double ingresos() const = 0;
	
};
