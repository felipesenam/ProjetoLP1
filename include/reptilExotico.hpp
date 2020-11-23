#pragma once

#include "reptil.hpp"
#include "exotico.hpp"

class ReptilExotico: public Reptil, public Exotico
{
public:
	ReptilExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio);
	~ReptilExotico();
	
};