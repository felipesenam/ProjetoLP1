
#include "mamiferoNativo.hpp"

/**
 * @brief Construtor parametrizado do Mamifero Nativo
 * @param especie :: Especifica a espécie do Mamifero Nativo
 * @param id :: Especifica o id do Mamifero Nativo
 * @param ameacadaExtincao :: Informa se o Mamifero Nativo está em risco de extinção
 * @param perigoso :: Informa se o Mamifero Nativo é perigoso
 * @param NF :: Nota fiscal do Mamifero Nativo
 * @param licenca ::  Especifica a licença emitida pelo IBAMA
*/
MamiferoNativo::MamiferoNativo (const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& licenca):
Mamifero(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Nativo(licenca)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
MamiferoNativo::~MamiferoNativo()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruído." << std::endl);
}

/**
 * @brief Imprime os dados do Anfibio Nativo
 * @param o :: Stream de saída dos dados
*/
void MamiferoNativo::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE MAMÍFEROS (NATIVOS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Mamífero" << std::endl
	 << "CLASSIFICAÇÃO: Nativo" << std::endl
	 << "LICENÇA: " << this->licenca << std:: endl
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

void MamiferoNativo::save(std::ofstream& file)
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
	 << this->licenca << ";"
	 << this->idade << ";"
	 << this->peso << ";"
	 << this->tamanho << ";"
	 << this->sexo << ";"
	 << this->informacoes;
}
