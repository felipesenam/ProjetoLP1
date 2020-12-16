#pragma once

#include "anfibio.hpp"
#include "domestico.hpp"

class AnfibioDomestico: public Anfibio, public Domestico
{
public:
	AnfibioDomestico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF);
	~AnfibioDomestico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};
