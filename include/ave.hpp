#pragma once

#include "animal.hpp"

class Ave: public Animal
{
public:
	Ave(const std::string&, Classe, Classificacao, short, char, char, const std::string&);
	virtual ~Ave();
};