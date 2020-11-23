#pragma once

#include "animal.hpp"

class Reptil: public Animal
{
public:
	Reptil();
	Reptil(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF);
	~Reptil();
	
};