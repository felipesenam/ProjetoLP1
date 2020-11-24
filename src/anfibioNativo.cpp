
#include "anfibioNativo.hpp"

AnfibioNativo::AnfibioNativo(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Anfibio(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

AnfibioNativo::~AnfibioNativo()
{}

void AnfibioNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Anfíbio" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}