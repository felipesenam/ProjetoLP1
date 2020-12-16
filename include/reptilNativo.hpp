#pragma once

#include "reptil.hpp"
#include "nativo.hpp"

class ReptilNativo: public Reptil, public Nativo
{
public:
	ReptilNativo(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca);
	~ReptilNativo();

	void print(std::ostream&);
	
	void save(std::ofstream& file);
	void load(std::ifstream& file);
};