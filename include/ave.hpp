#pragma once

#include "animal.hpp"

class Ave: public Animal
{
public:
	Ave();
	Ave(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Ave();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};