#pragma once

#include "mamifero.hpp"
#include "exotico.hpp"

class MamiferoExotico: public Mamifero, public Exotico
{
public:
	MamiferoExotico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio);
	~MamiferoExotico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};