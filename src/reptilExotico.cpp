
#include "reptilExotico.hpp"

/**
 * @brief Construtor parametrizado do Reptil Exotico
 * @param especie :: Especifica a espécie do Reptil Exotico
 * @param id :: Especifica o id do Reptil Exotico
 * @param ameacadaExtincao :: Informa se o Reptil Exotico está em risco de extinção
 * @param perigoso :: Informa se o Reptil Exotico é perigoso
 * @param NF :: Nota fiscal do Reptil Exotico
 * @param territorio :: Especifica o territorio do qual o Reptil Exotico pertence
*/
ReptilExotico::ReptilExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Reptil(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

/**
 * @brief Destrutor padrão
*/
ReptilExotico::~ReptilExotico()
{}

/**
 * @brief Imprime os dados do Reptil Exotico
 * @param o :: Stream de saída dos dados
*/
void ReptilExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Réptil" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl
		<< "TERRITORIO: " << this-> territorio << std:: endl;
}