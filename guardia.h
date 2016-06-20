#pragma once
#include "empleado.h"

class Guardia : public Empleado{
	double tarifaDia;
	int turnos;
 public:
	Guardia(string, string, string,double,int);
	double getTarifa()const;
	double getTurnos()const;
	virtual double ingresos() const;
	virtual string toString()const;

};
