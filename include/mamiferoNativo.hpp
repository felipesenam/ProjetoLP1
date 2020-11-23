#pragma once

#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo: public Mamifero, public Nativo
{
public:
	MamiferoNativo(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~MamiferoNativo();

	
};