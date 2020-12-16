#pragma once

#include "animal.hpp"

class Anfibio: public Animal
{
public:
	Anfibio(std::string, Classe, Classificacao, short, char, char, std::string);
	virtual ~Anfibio();
};