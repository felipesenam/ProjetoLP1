#pragma once

#include "ave.hpp"
#include "nativo.hpp"

class AveNativo: public Ave, public Nativo
{
public:
	AveNativo(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~AveNativo();

	void print(std::ostream&);
	
};