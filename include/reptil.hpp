#pragma once

#include "animal.hpp"

class Reptil: public Animal
{
public:
	Reptil(std::string, Classe, Classificacao, short, char, char, std::string);
	virtual ~Reptil();
};