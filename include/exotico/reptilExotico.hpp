#pragma once

#include "../reptil.hpp"
#include "exotico.hpp"

class ReptilExotico: public Reptil, public Exotico
{
public:
	ReptilExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio);
	~ReptilExotico();
	
	void print(std::ostream&);
	
};