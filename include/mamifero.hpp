#pragma once

#include "animal.hpp"

class Mamifero: public Animal
{
public:
	Mamifero();
	Mamifero(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Mamifero();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};