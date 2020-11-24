
#include "anfibio.hpp"

Anfibio::Anfibio()
{}

Anfibio::Anfibio(std::string especie, short id, char ameacadaExtincao,char perigoso, std::string NF) :
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Anfibio " << this->id << " [" << this << "] foi criado." << std::endl);
}

Anfibio::~Anfibio()
{}

void Anfibio::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (DOMÉSTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Anfíbio" << std::endl
		<< "CLASSIFICAÇÃO: Doméstico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}