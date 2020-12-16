#pragma once

#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo: public Anfibio, public Nativo
{
public:
	AnfibioNativo(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca);
	~AnfibioNativo();

	void print(std::ostream&);

	void save(std::ofstream& file);
};