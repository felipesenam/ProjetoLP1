#pragma once

#include "mamifero.hpp"
#include "domestico.hpp"

class MamiferoDomestico: public Mamifero, public Domestico
{
public:
	MamiferoDomestico(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF);
	~MamiferoDomestico();
	
	void print(std::ostream&);

	void save(std::ofstream& file);
};