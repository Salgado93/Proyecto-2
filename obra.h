#pragma once
#include <ctime>
#include <string>
using std::string;

class Obra{
	string nombre;
	string codigo;
	string fechaIngreso;
	double precio;
  public:
	Obra(string,string, string,double=0.0);
	virtual ~Obra();
	virtual string toString()const;
};
