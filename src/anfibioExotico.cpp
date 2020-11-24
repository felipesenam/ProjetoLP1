
#include "anfibioExotico.hpp"

AnfibioExotico::AnfibioExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Anfibio(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

AnfibioExotico::~AnfibioExotico()
{}

void AnfibioExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Anfíbio" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}