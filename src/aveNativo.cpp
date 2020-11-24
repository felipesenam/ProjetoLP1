
#include "aveNativo.hpp"

AveNativo::AveNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Ave(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

AveNativo::~AveNativo()
{}

void AveNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (NATIVAS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Ave" << std::endl
		<< "CLASSIFICAÇÃO: Nativa" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}