
#include "anfibioExotico.hpp"

/**
 * @brief Construtor parametrizado do Anfibio Exotico
 * @param especie :: Especifica a espécie do Anfibio Exotico
 * @param id :: Especifica o id do Anfibio Exotico
 * @param ameacadaExtincao :: Informa se o Anfibio Exotico está em risco de extinção
 * @param perigoso :: Informa se o Anfibio Exotico é perigoso
 * @param NF :: Nota fiscal do Anfibio Exotico
 * @param territorio :: Especifica o territorio do qual o Anfibio Exotico pertence
*/
AnfibioExotico::AnfibioExotico(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF, std::string territorio):
Anfibio(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{
	Debug("AnfibioExotico " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
AnfibioExotico::~AnfibioExotico()
{}

/**
 * @brief Imprime os dados do Anfibio Exotico
 * @param o :: Stream de saída dos dados
*/
void AnfibioExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE ANFÍBIOS (EXÓTICOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Anfíbio" << std::endl
	 << "CLASSIFICAÇÃO: Exótico" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "TERRITORIO: " << this-> territorio << std:: endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AnfibioExotico::save(std::ofstream& file)
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
