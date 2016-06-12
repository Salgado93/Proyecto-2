#pragma once
#include "obra.h"
#include <string>
using std::string;

class Literatura : public Obra{
	string autor;
	string genero;
	string epoca;
  public:
	Literatura(string, string, string, double, string, string, string);
	virtual ~Literatura();
	virtual string toString()const;
};
