#pragma once

#include "animal.hpp"

class Mamifero: public Animal
{
public:
	Mamifero();
	Mamifero(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF);
	~Mamifero();
	
};