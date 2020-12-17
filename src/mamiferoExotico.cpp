
#include "mamiferoExotico.hpp"

/**
 * @brief Construtor parametrizado do Mamifero Exotico
 * @param especie :: Especifica a espécie do Mamifero Exotico
 * @param id :: Especifica o id do Mamifero Exotico
 * @param ameacadaExtincao :: Informa se o Mamifero Exotico está em risco de extinção
 * @param perigoso :: Informa se o Mamifero Exotico é perigoso
 * @param NF :: Nota fiscal do Mamifero Exotico
 * @param territorio :: Especifica o territorio do qual o Mamifero Exotico pertence
*/
MamiferoExotico::MamiferoExotico(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio):
Mamifero(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
MamiferoExotico::~MamiferoExotico()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruído." << std::endl);
}

/**
 * @brief Imprime os dados do Mamífero Exotico
 * @param o :: Stream de saída dos dados
*/
void MamiferoExotico::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (EXÓTICOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Mamífero" << std::endl
	 << "CLASSIFICAÇÃO: Exótico" << std::endl
	 << "TERRITORIO: " << this->territorio << std:: endl
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

void MamiferoExotico::save(std::ofstream& file)
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
	 << this->territorio << ";"
	 << this->idade << ";"
	 << this->peso << ";"
	 << this->tamanho << ";"
	 << this->sexo << ";"
	 << this->informacoes;
}
