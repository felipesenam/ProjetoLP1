
#include "ave.hpp"

Ave::~Ave()
{}

Ave::Ave(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Ave " << this->id << " [" << this << "] foi criado." << std::endl);
}

Ave::Ave()
{}

void Ave::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (DOMÉSTICAS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Ave" << std::endl
		<< "CLASSIFICAÇÃO: Doméstico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}