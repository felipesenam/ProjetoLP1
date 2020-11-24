#pragma once

#include "../ave.hpp"
#include "exotico.hpp"

class AveExotico: public Ave, public Exotico
{
public:
	AveExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio);
	~AveExotico();
	
	void print(std::ostream&);

};