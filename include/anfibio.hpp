#pragma once

#include "animal.hpp"

class Anfibio: public Animal
{
public:
	Anfibio(const std::string&, Classe, Classificacao, short, char, char, const std::string&);
	virtual ~Anfibio();
};