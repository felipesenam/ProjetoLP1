#pragma once

#include "animal.hpp"

class Anfibio: public Animal
{
public:
	Anfibio();
	Anfibio(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~Anfibio();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};
