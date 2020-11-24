
#include "reptilExotico.hpp"

ReptilExotico::ReptilExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Reptil(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

ReptilExotico::~ReptilExotico()
{}

void ReptilExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Réptil" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}