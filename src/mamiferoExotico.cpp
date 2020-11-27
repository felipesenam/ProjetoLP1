
#include "mamiferoExotico.hpp"

/**
 * @brief Construtor parametrizado do Mamifero Exotico
 * @param especie :: Especifica a espécie do Mamifero Exotico
 * @param id :: Especifica o id do Mamifero Exotico
 * @param ameacadaExtincao :: Informa se o Mamifero Exotico está em risco de extinção
 * @param perigoso :: Informa se o Mamifero Exotico é perigoso
 * @param NF :: Nota fiscal do Mamifero Exotico
 * @param territorio :: Especifica o territorio do qual o Mamifero Exotico pertence
*/
MamiferoExotico::MamiferoExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Mamifero(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

/**
 * @brief Destrutor padrão
*/
MamiferoExotico::~MamiferoExotico()
{}

/**
 * @brief Imprime os dados do Mamífero Exotico
 * @param o :: Stream de saída dos dados
*/
void MamiferoExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
		<< "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl
		<< "TERRITORIO: " << this-> territorio << std:: endl;
}