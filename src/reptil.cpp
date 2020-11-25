
#include "reptil.hpp"

/**
 * @brief Destrutor padrão
*/
Reptil::~Reptil()
{}

/**
 * @brief Construtor parametrizado do Reptil
 * @details Construtor parametrizado do Reptil
 * @param especie :: Especifica a espécie do Reptil
 * @param id :: Especifica o id do Reptil
 * @param ameacadaExtincao :: Informa se o Reptil está em risco de extinção
 * @param perigoso :: Informa se o Reptil é perigoso
 * @param NF :: Nota fiscal do Reptil
*/
Reptil::Reptil(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Reptil " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor padrão
*/
Reptil::Reptil()
{}

/**
 * @brief Imprime os dados do Reptil
*/
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