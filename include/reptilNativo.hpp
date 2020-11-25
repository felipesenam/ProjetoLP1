#pragma once

#include "reptil.hpp"
#include "nativo.hpp"

class ReptilNativo: public Reptil, public Nativo
{
public:
	ReptilNativo(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~ReptilNativo();

	void print(std::ostream&);
	
};