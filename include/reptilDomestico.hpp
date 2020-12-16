#pragma once

#include "reptil.hpp"
#include "domestico.hpp"

class ReptilDomestico: public Reptil, public Domestico
{
public:
	ReptilDomestico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF);
	~ReptilDomestico();

	void print(std::ostream&);

	void save(std::ofstream& file);
	void load(std::ifstream& file);
};