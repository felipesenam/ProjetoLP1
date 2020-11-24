#pragma once

#include "animal.hpp"

class Ave: public Animal
{
public:
	Ave();
	Ave(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Ave();
	
	void print(std::ostream&);
	
};