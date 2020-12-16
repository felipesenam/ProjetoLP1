
#include "reptilNativo.hpp"

/**
 * @brief Construtor parametrizado do Reptil Nativo
 * @param especie :: Especifica a espécie do Reptil Nativo
 * @param id :: Especifica o id do Reptil Nativo
 * @param ameacadaExtincao :: Informa se o Reptil Nativo está em risco de extinção
 * @param perigoso :: Informa se o Reptil Nativo é perigoso
 * @param NF :: Nota fiscal do Reptil Nativo
 * @param licenca ::  Especifica a licença emitida pelo IBAMA
*/
ReptilNativo::ReptilNativo (const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca):
Reptil(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Nativo (licenca)
{
	Debug("ReptilNativo " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
ReptilNativo::~ReptilNativo()
{}

/**
 * @brief Imprime os dados do Reptil Nativo
 * @param o :: Stream de saída dos dados
*/
void ReptilNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE RÉPTEIS (NATIVOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Réptil" << std::endl
	 << "CLASSIFICAÇÃO: Nativo" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "LICENÇA: " << this->licenca << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl;
}

void ReptilNativo::save(std::ofstream& file)
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
