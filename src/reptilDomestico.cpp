
#include "reptilDomestico.hpp"

/**
 * @brief Construtor parametrizado do Reptil
 * @details Construtor parametrizado do Reptil
 * @param especie :: Especifica a espécie do Reptil
 * @param id :: Especifica o id do Reptil
 * @param ameacadaExtincao :: Informa se o Reptil está em risco de extinção
 * @param perigoso :: Informa se o Reptil é perigoso
 * @param NF :: Nota fiscal do Reptil
*/
ReptilDomestico::ReptilDomestico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF):
Reptil(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{
	Debug("ReptilDomestico " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
ReptilDomestico::~ReptilDomestico()
{}

/**
 * @brief Imprime os dados do Reptil
 * @param o :: Stream de saída dos dados
*/
void ReptilDomestico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (DOMÉSTICOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Réptil" << std::endl
	 << "CLASSIFICAÇÃO: Doméstico" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void ReptilDomestico::save(std::ofstream& file)
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
	 << "-";
}
