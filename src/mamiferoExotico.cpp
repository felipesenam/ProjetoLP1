
#include "mamiferoExotico.hpp"

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
MamiferoExotico::MamiferoExotico(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Mamifero(especie, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
MamiferoExotico::~MamiferoExotico()
{}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
void MamiferoExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (EXÓTICOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Exótico" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}