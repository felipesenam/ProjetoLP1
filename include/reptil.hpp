#pragma once

#include "animal.hpp"

class Reptil: public Animal
{
public:
	Reptil();
	Reptil(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Reptil();

	void print(std::ostream&);

	void save(std::ofstream& file);
	void load(std::ifstream& file);
};