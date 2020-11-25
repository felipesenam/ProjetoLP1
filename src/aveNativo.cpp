
#include "aveNativo.hpp"

/**
 * @brief Construtor parametrizado da Ave Nativa
 * @param especie :: Especifica a espécie da Ave Nativa
 * @param id :: Especifica o id da Ave Nativa
 * @param ameacadaExtincao :: Informa se a Ave Nativa está em risco de extinção
 * @param perigoso :: Informa se a Ave Nativa é perigosa
 * @param NF :: Nota fiscal da Ave Nativa
 * @param licenca :: Especifica a licença emitida pelo IBAMA
*/
AveNativo::AveNativo (std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca):
Ave(especie, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

/**
 * @brief Destrutor padrão
*/
AveNativo::~AveNativo()
{}

/**
 * @brief Imprime os dados da Ave Nativa
*/
void AveNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (NATIVAS)
	o
		<< "ESPECIE: " << this->especie << std::endl
		<< "ID: " << this->id << std::endl
		<< "CLASSE: Ave" << std::endl
		<< "CLASSIFICAÇÃO: Nativa" << std::endl
		<< "AMEAÇADA DE EXTINÇÃO: " << this->ameacadaExtincao << std::endl
		<< "PERIGOSO: " << this->perigoso << std::endl
		<< "NOTA FISCAL: " << this->NF << std::endl
		<< "LICENÇA: " << this->licenca << std::endl;
}