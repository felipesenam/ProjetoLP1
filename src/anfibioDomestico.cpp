
#include "anfibioDomestico.hpp"

/**
 * @brief Construtor parametrizado do AnfibioDomestico
 * @details Construtor parametrizado do AnfibioDomestico
 * @param especie :: Especifica a espécie do AnfibioDomestico
 * @param id :: Especifica o id do AnfibioDomestico
 * @param ameacadaExtincao :: Informa se o AnfibioDomestico está em risco de extinção
 * @param perigoso :: Informa se o AnfibioDomestico é perigoso
 * @param NF :: Nota fiscal do AnfibioDomestico
*/
AnfibioDomestico::AnfibioDomestico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF) :
Anfibio(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
AnfibioDomestico::~AnfibioDomestico()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruído." << std::endl);
}

/**
 * @brief Imprime os dados do AnfibioDomestico
*/
void AnfibioDomestico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (DOMÉSTICOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Anfíbio" << std::endl
	 << "CLASSIFICAÇÃO: Doméstico" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AnfibioDomestico::save(std::ofstream& file)
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
