
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
AnfibioNativo::AnfibioNativo(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca):
Anfibio(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{
	Debug("AnfibioNativo " << this->id << " [" << this << "] foi criado." << std::endl);
}

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
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "LICENÇA: " << this->licenca << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void AnfibioNativo::save(std::ofstream& file)
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
