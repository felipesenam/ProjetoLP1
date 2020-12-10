
#include "aveExotico.hpp"

/**
 * @brief Construtor parametrizado da Ave Exotica
 * @param especie :: Especifica a espécie da Ave Exotica
 * @param id :: Especifica o id da Ave Exotica
 * @param ameacadaExtincao :: Informa se a Ave Exotica está em risco de extinção
 * @param perigoso :: Informa se a Ave Exotica é perigosa
 * @param NF :: Nota fiscal da Ave Exotica
 * @param territorio :: Especifica o territorio do qual a Ave Exotica pertence
*/
AveExotico::AveExotico(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Ave(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{}

/**
 * @brief Destrutor padrão
*/
AveExotico::~AveExotico()
{}

/**
 * @brief Imprime os dados da Ave Exotica
 * @param o :: Stream de saída dos dados
*/
void AveExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (EXÓTICAS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Ave" << std::endl
	 << "CLASSIFICAÇÃO: Exótica" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "TERRITORIO: " << this-> territorio << std:: endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AveExotico::save(std::ofstream& file)
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
	 << this->territorio;
}
