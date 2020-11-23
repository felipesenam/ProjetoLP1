#include "anfibioExotico.hpp"

	AnfibioExotico::AnfibioExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
	Anfibio(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Exotico(territorio)
	{}
	AnfibioExotico::~AnfibioExotico()
	{}