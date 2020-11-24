#pragma once

#include "animal.hpp"

class Reptil: public Animal
{
public:
	Reptil();
	Reptil(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Reptil();

	void print(std::ostream&);
	
};