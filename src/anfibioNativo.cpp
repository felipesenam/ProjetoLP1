
#include "anfibioNativo.hpp"

/**
 * @brief Construtor parametrizado do Anfibio Nativo
 * @param especie :: Especifica a espécie do Anfibio Nativo
 * @param id :: Especifica o id do Anfibio Nativo
 * @param ameacadaExtincao :: Informa se o Anfibio Nativo está em risco de extinção
 * @param perigoso :: Informa se o Anfibio Nativo é perigoso
 * @param NF :: Nota fiscal do Anfibio Nativo
 * @param licenca ::  Especifica a licença emitida pelo IBAMA
*/
AnfibioNativo::AnfibioNativo(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Anfibio(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

/**
 * @brief Destrutor padrão
*/
AnfibioNativo::~AnfibioNativo()
{}

/**
 * @brief Imprime os dados do Anfibio Nativo
 * @param o :: Stream de saída dos dados
*/
void AnfibioNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Anfíbio" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl
		<< "LICENÇA: " << this->licenca << std::endl;
}