
#include "mamifero.hpp"

/**
 * @brief Destrutor padrão
*/
Mamifero::~Mamifero()
{}

/**
 * @brief Construtor parametrizado do Mamifero
 * @details Construtor parametrizado do Mamifero
 * @param especie :: Especifica a espécie do Mamifero
 * @param id :: Especifica o id do Mamifero
 * @param ameacadaExtincao :: Informa se o Mamifero está em risco de extinção
 * @param perigoso :: Informa se o Mamifero é perigoso
 * @param NF :: Nota fiscal do Mamifero
*/
Mamifero::Mamifero(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Mamifero " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor padrão
*/
Mamifero::Mamifero()
{}

/**
 * @brief Imprime os dados do Anfibio
*/
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