#pragma once

#include "animal.hpp"

class Ave: public Animal
{
public:
	Ave();
	Ave(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF);
	~Ave();
	
};