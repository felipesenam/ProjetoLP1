#pragma once

#include "mamifero.hpp"
#include "exotico.hpp"

class MamiferoExotico: public Mamifero, public Exotico
{
public:
	MamiferoExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio);
	~MamiferoExotico();
	
};