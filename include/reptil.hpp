#pragma once

#include "animal.hpp"

class Reptil: public Animal
{
public:
	Reptil(const std::string&, Classe, Classificacao, short, char, char, const std::string&);
	virtual ~Reptil();
};