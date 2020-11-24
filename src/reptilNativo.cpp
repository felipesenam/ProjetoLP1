
#include "reptilNativo.hpp"

ReptilNativo::ReptilNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Reptil(especie, id, ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}

ReptilNativo::~ReptilNativo()
{}

void ReptilNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Réptil" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}