
#include "aveDomestica.hpp"

/**
 * @brief Construtor parametrizado da AveDomestica
 * @details Construtor parametrizado da AveDomestica
 * @param especie :: Especifica a espécie da AveDomestica
 * @param id :: Especifica o id da AveDomestica
 * @param ameacadaExtincao :: Informa se a AveDomestica está em risco de extinção
 * @param perigoso :: Informa se a AveDomestica é perigosa
 * @param NF :: Nota fiscal da AveDomestica
*/
AveDomestica::AveDomestica(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF):
Ave(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{
	Debug("AveDomestica " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
AveDomestica::~AveDomestica()
{}

/**
 * @brief Imprime os dados da AveDomestica
 * @param o :: Stream de saída dos dados
*/
void AveDomestica::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (DOMÉSTICAS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Ave" << std::endl
	 << "CLASSIFICAÇÃO: Doméstico" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AveDomestica::save(std::ofstream& file)
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
