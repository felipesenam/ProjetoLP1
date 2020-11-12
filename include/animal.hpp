#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "lib.hpp"

using namespace std;

enum classificacao
{
	nativo,
	exotico,
	domestico
};

class Animal
{
public:
	Animal(short id, classificacao classificacao_,char ameacadaExtincao, char perigoso, string NF);
	Animal();
	~Animal();
	short getId();
	classificacao getClassificacao();
	void printAnimal();
	// virtual ostream& imprimeDados(ostream& o) const = 0;
	// friend ostream& operator<< (ostream& o, Animal& a);
protected:
	short id;
	classificacao classificacao_;
	char ameacadaExtincao; // indica se a especie corre risco de extincao
	char perigoso;         // indica se o animal é perigoso/venenoso
	string NF= NULL;       // Nota Fical
};