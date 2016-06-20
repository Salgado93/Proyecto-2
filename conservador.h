#pragma once
#include "empleado.h"

class Conservador : public Empleado{
	double salario;
 public:
	Conservador(string, string, string,double);
	double getSalario()const;
	virtual double ingresos() const;
	virtual string toString()const;

};
