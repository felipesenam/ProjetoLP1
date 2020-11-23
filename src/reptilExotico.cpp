#include "reptilExotico.hpp"

	ReptilExotico::ReptilExotico(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
	Reptil(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Exotico(territorio)
	{}
	ReptilExotico::~ReptilExotico()
	{}