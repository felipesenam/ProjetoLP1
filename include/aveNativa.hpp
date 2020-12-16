#pragma once

#include "ave.hpp"
#include "nativo.hpp"

class AveNativa: public Ave, public Nativo
{
public:
	AveNativa(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca);
	~AveNativa();

	void print(std::ostream&);

	void save(std::ofstream& file);
};