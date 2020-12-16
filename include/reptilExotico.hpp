#pragma once

#include "reptil.hpp"
#include "exotico.hpp"

class ReptilExotico: public Reptil, public Exotico
{
public:
	ReptilExotico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio);
	~ReptilExotico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
	void load(std::ifstream& file);
};