#pragma once

#include "animal.hpp"

class Anfibio: public Animal
{
public:
	Anfibio();
	Anfibio(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Anfibio();
	
	void print(std::ostream&);
	
};