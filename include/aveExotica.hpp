#pragma once

#include "ave.hpp"
#include "exotico.hpp"

class AveExotica: public Ave, public Exotico
{
public:
	AveExotica(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio);
	~AveExotica();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};