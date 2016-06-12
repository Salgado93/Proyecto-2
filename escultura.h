#pragma once
#include "obra.h"
#include <string>
using std::string;

class Escultura : public Obra{
	double peso;
	string material;
	string tecnica;
  public:
	Escultura(string, string, string, double, double, string, string);
	virtual ~Escultura();
	virtual string toString()const;
};
