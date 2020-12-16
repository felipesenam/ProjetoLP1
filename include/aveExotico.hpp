#pragma once

#include "ave.hpp"
#include "exotico.hpp"

class AveExotico: public Ave, public Exotico
{
public:
	AveExotico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio);
	~AveExotico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};