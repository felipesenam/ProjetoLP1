#pragma once

#include "anfibio.hpp"
#include "exotico.hpp"

class AnfibioExotico: public Anfibio, public Exotico
{
public:
	AnfibioExotico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio);
	~AnfibioExotico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};