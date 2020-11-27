
#include "ave.hpp"

/**
 * @brief Destrutor padrão
*/
Ave::~Ave()
{}

/**
 * @brief Construtor parametrizado da Ave
 * @details Construtor parametrizado da Ave
 * @param especie :: Especifica a espécie da Ave
 * @param id :: Especifica o id da Ave
 * @param ameacadaExtincao :: Informa se a Ave está em risco de extinção
 * @param perigoso :: Informa se a Ave é perigosa
 * @param NF :: Nota fiscal da Ave
*/
Ave::Ave(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Ave " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor padrão
*/
Ave::Ave()
{}

/**
 * @brief Imprime os dados da Ave
 * @param o :: Stream de saída dos dados
*/
void Ave::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (DOMÉSTICAS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Ave" << std::endl
		<< "CLASSIFICAÇÃO: Doméstico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
		<< "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}