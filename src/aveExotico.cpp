#include "aveExotico.hpp"

	AveExotico::AveExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
	Ave(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Exotico(territorio)
	{}
	AveExotico::~AveExotico()
	{}