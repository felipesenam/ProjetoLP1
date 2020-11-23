#pragma once

#include "reptil.hpp"
#include "nativo.hpp"

class ReptilNativo: public Reptil, public Nativo
{
public:
	ReptilNativo(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~ReptilNativo();

	
};