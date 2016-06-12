#pragma once
#include "obra.h"
#include <string>
using std::string;

class Pintura : public Obra{
	string lienzo;
	string tecnica;
	string pintura;
	string genero;
  public:
	Pintura(string, string, string, double, string, string, string,string);
	virtual ~Pintura();
	virtual string toString()const;
};
