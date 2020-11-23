#include "mamiferoExotico.hpp"

	MamiferoExotico::MamiferoExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
	Mamifero(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Exotico(territorio)
	{}
	MamiferoExotico::~MamiferoExotico()
	{}