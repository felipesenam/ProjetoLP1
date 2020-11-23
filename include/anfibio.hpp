#pragma once

#include "animal.hpp"

class Anfibio: public Animal
{
public:
	Anfibio();
	Anfibio(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF);
	~Anfibio();
	
};