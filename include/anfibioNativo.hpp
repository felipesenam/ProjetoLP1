#pragma once

#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo: public Anfibio, public Nativo
{
public:
	AnfibioNativo(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~AnfibioNativo();

	void print(std::ostream&);

	void save(std::ofstream& file);
};