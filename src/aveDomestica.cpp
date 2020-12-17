
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
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criada." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
AveDomestica::~AveDomestica()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruída." << std::endl);
}

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
	 << "CLASSIFICAÇÃO: Doméstica" << std::endl
	 << "AMEAÇADA DE EXTINÇÃO: " << (this->ameacadaExtincao ? "sim" : "não") << std::endl
	 << "PERIGOSO: " << (this->perigoso ? "sim" : "não") << std::endl
	 << "IDADE: " << this->idade << std::endl
	 << "PESO: " << this->peso << std::endl
	 << "TAMANHO: " << this->tamanho << std::endl
	 << "SEXO: " << (this->sexo == macho ? "macho" : (this->sexo == femea ? "fêmea" : "indefinido")) << std::endl
	 << "VETERINÁRIO RESPONSÁVEL: " << this->getVeterinario()->getNome() << std::endl
	 << "TRATADOR RESPONSÁVEL: " << this->getTratador()->getNome() << std::endl
	 << "NOTA FISCAL: " << this->NF << std::endl
	 << "INFORMAÇÕES ADICIONAIS: " << this->informacoes << std::endl;
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
	 << "-" << ";"
	 << this->idade << ";"
	 << this->peso << ";"
	 << this->tamanho << ";"
	 << this->sexo << ";"
	 << this->informacoes;
}
