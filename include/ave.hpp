#pragma once

#include "animal.hpp"

class Ave: public Animal
{
public:
	Ave(std::string, Classe, Classificacao, short, char, char, std::string);
	virtual ~Ave();
};