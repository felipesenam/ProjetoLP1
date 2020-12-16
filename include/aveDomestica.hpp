#pragma once

#include "ave.hpp"
#include "domestico.hpp"

class AveDomestica: public Ave, public Domestico
{
public:
	AveDomestica(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~AveDomestica();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};