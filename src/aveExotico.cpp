
#include "aveExotico.hpp"

AveExotico::AveExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Ave(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

AveExotico::~AveExotico()
{}

void AveExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (EXÓTICAS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Ave" << std::endl
		<< "CLASSIFICAÇÃO: Exótica" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}