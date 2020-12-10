#pragma once

#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo: public Mamifero, public Nativo
{
public:
	MamiferoNativo(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~MamiferoNativo();

	void print(std::ostream&);

	void save(std::ofstream& file);
};