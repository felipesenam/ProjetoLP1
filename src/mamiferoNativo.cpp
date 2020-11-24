
#include "mamiferoNativo.hpp"

MamiferoNativo::MamiferoNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Mamifero(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

MamiferoNativo::~MamiferoNativo()
{}

void MamiferoNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}