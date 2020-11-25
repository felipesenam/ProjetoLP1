
#include "mamiferoNativo.hpp"

/**
 * @brief Construtor parametrizado do Mamifero Nativo
 * @param especie :: Especifica a espécie do Mamifero Nativo
 * @param id :: Especifica o id do Mamifero Nativo
 * @param ameacadaExtincao :: Informa se o Mamifero Nativo está em risco de extinção
 * @param perigoso :: Informa se o Mamifero Nativo é perigoso
 * @param NF :: Nota fiscal do Mamifero Nativo
 * @param licenca ::  Especifica a licença emitida pelo IBAMA
*/
MamiferoNativo::MamiferoNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Mamifero(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

/**
 * @brief Destrutor padrão
*/
MamiferoNativo::~MamiferoNativo()
{}

/**
 * @brief Imprime os dados do Anfibio Nativo
*/
void MamiferoNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (NATIVOS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Mamífero" << std::endl
		<< "CLASSIFICAÇÃO: Nativo" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl;
}