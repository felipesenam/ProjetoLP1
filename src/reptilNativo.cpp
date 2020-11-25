
#include "reptilNativo.hpp"

/**
 * @brief Construtor parametrizado do Reptil Nativo
 * @param especie :: Especifica a espécie do Reptil Nativo
 * @param id :: Especifica o id do Reptil Nativo
 * @param ameacadaExtincao :: Informa se o Reptil Nativo está em risco de extinção
 * @param perigoso :: Informa se o Reptil Nativo é perigoso
 * @param NF :: Nota fiscal do Reptil Nativo
 * @param licenca ::  Especifica a licença emitida pelo IBAMA
*/
ReptilNativo::ReptilNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Reptil(especie, id, ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}

/**
 * @brief Destrutor padrão
*/
ReptilNativo::~ReptilNativo()
{}

/**
 * @brief Imprime os dados do Reptil Nativo
*/
void ReptilNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Réptil" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}