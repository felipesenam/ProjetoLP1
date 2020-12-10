
#include "mamifero.hpp"

/**
 * @brief Destrutor padrão
*/
Mamifero::~Mamifero()
{}

/**
 * @brief Construtor parametrizado do Mamifero
 * @details Construtor parametrizado do Mamifero
 * @param especie :: Especifica a espécie do Mamifero
 * @param id :: Especifica o id do Mamifero
 * @param ameacadaExtincao :: Informa se o Mamifero está em risco de extinção
 * @param perigoso :: Informa se o Mamifero é perigoso
 * @param NF :: Nota fiscal do Mamifero
*/
Mamifero::Mamifero(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF):
Animal(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{
	Debug("Mamifero " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor padrão
*/
Mamifero::Mamifero()
{}

/**
 * @brief Imprime os dados do Anfibio
 * @param o :: Stream de saída dos dados
*/
void Mamifero::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (DOMÉSTICOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Mamífero" << std::endl
	 << "CLASSIFICAÇÃO: Doméstico" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void Mamifero::save(std::ofstream& file)
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
