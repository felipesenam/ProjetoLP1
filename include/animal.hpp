#pragma once

#include <string>
#include <ostream>
#include <iostream>

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
	Animal(short id, classificacao classificacao_, bool perigoso, string NF);
	~Animal();
	short getId();
	classificacao getClassificacao();
	void printAnimal();
protected:
	short id;
	classificacao classificacao_;
	bool ameacadaExtincao; // indica se o animal corre risco de extincao
	bool perigoso; // indica se o animal é perigoso/venenoso
	string NF= NULL; //Nota Fical
};