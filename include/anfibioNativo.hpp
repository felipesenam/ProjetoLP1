#pragma once

#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo: public Anfibio, public Nativo
{
public:
	AnfibioNativo(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~AnfibioNativo();

	
};