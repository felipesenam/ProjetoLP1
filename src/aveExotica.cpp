
#include "aveExotica.hpp"

/**
 * @brief Construtor parametrizado da Ave Exotica
 * @param especie :: Especifica a espécie da Ave Exotica
 * @param id :: Especifica o id da Ave Exotica
 * @param ameacadaExtincao :: Informa se a Ave Exotica está em risco de extinção
 * @param perigoso :: Informa se a Ave Exotica é perigosa
 * @param NF :: Nota fiscal da Ave Exotica
 * @param territorio :: Especifica o territorio do qual a Ave Exotica pertence
*/
AveExotica::AveExotica(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF, const std::string& territorio):
Ave(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF), Exotico(territorio)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criada." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
AveExotica::~AveExotica()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruída." << std::endl);
}

/**
 * @brief Imprime os dados da Ave Exotica
 * @param o :: Stream de saída dos dados
*/
void AveExotica::print(std::ostream& o)
{
	//AQUI SERÃO APRESENTADOS DADOS RELEVANTES A RESPEITO DE AVES (EXÓTICAS)
	o
	 << "ESPECIE: " << this->especie << std::endl
	 << "ID: " << this->id << std::endl
	 << "CLASSE: Ave" << std::endl
	 << "CLASSIFICAÇÃO: Exótica" << std::endl
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

void AveExotica::save(std::ofstream& file)
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
