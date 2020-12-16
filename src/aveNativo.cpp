
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
AveNativo::AveNativo (const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca):
Ave(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{}

/**
 * @brief Destrutor padrão
*/
AveNativo::~AveNativo()
{}

/**
 * @brief Imprime os dados da Ave Nativa
 * @param o :: Stream de saída dos dados
*/
void AveNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (NATIVAS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Ave" << std::endl
	 << "CLASSIFICAÇÃO: Nativa" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "LICENÇA: " << this->licenca << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AveNativo::save(std::ofstream& file)
{
	file
	 << this->id                   << ";"
	 << this->especie              << ";"
	 << this->classe               << ";"
	 << this->classificacao        << ";"
	 << this->ameacadaExtincao     << ";"
	 << this->perigoso             << ";"
	 << this->NF                   << ";"
	 << this->tratador->getId()    << ";"
	 << this->veterinario->getId() << ";"
	 << this->licenca;
}
