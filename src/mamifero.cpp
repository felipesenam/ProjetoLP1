
#include "mamifero.hpp"

Mamifero::~Mamifero()
{}

Mamifero::Mamifero(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Mamifero " << this->id << " [" << this << "] foi criado." << std::endl);
}

Mamifero::Mamifero()
{}

void Mamifero::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (DOMÉSTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Doméstico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}