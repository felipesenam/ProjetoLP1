
#include "anfibio.hpp"

/**
 * @brief Construtor padrão
*/
Anfibio::Anfibio()
{}

/**
 * @brief Construtor parametrizado do Anfibio
 * @details Construtor parametrizado do Anfibio
 * @param especie :: Especifica a espécie do Anfibio
 * @param id :: Especifica o id do Anfibio
 * @param ameacadaExtincao :: Informa se o Anfibio está em risco de extinção
 * @param perigoso :: Informa se o Anfibio é perigoso
 * @param NF :: Nota fiscal do Anfibio
*/
Anfibio::Anfibio(std::string especie, short id, char ameacadaExtincao,char perigoso, std::string NF) :
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Anfibio " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
Anfibio::~Anfibio()
{}

/**
 * @brief Imprime os dados do Anfibio
*/
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