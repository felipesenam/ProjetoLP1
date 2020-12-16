#pragma once

#include "animal.hpp"

class Mamifero: public Animal
{
public:
	Mamifero(const std::string&, Classe, Classificacao, short, char, char, const std::string&);
	virtual ~Mamifero();
};