
#include "reptil.hpp"

Reptil::~Reptil()
{}

Reptil::Reptil(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Reptil " << this->id << " [" << this << "] foi criado." << std::endl);
}

Reptil::Reptil()
{}

void Reptil::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (DOMÉSTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Réptil" << std::endl
		<< "CLASSIFICAÇÃO: Doméstico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}