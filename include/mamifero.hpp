#pragma once

#include "animal.hpp"

class Mamifero: public Animal
{
public:
	Mamifero(std::string, Classe, Classificacao, short, char, char, std::string);
	virtual ~Mamifero();
};