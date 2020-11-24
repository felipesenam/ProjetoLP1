
#include "mamiferoExotico.hpp"

MamiferoExotico::MamiferoExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Mamifero(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

MamiferoExotico::~MamiferoExotico()
{}

void MamiferoExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}