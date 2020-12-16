
#include "animal.hpp"

/**
 * @brief Destrutor padrão
*/
Animal::Animal()
{}

/**
 * @brief Construtor parametrizado do Animal
 * @details Construtor parametrizado do Animal
 * @param especie :: Especifica a espécie do Animal
 * @param id :: Especifica o id do Animal
 * @param ameacadaExtincao :: Informa se o Animal está em risco de extinção
 * @param perigoso :: Informa se o Animal é perigoso
 * @param NF :: Nota fiscal do Animal
*/
Animal::Animal(const std::string& especie, Classe classe, Classificacao classificacao, short id, bool ameacadaExtincao, bool perigoso, const std::string& NF):
especie(especie), classe(classe), classificacao(classificacao), id(id), ameacadaExtincao(ameacadaExtincao), perigoso(perigoso), NF(NF)
{}

/**
 * @brief Destrutor padrão
*/
Animal::~Animal()
{}

/**
 * @brief Retorna a especie do Animal
 * @return especie
*/
std::string Animal::getEspecie() const
{
	return this->especie;
}

/**
 * @brief Seta a especie do Animal
 * @param especie :: especie do animal
*/
void Animal::setEspecie(const std::string& especie)
{
	this->especie = especie;
}

Classe Animal::getClasse() const
{
	return this->classe;
}
void Animal::setClasse(Classe classe)
{
	if(this->getTratador()->aptto(classe, this->perigoso))
	{
		this->classe = classe;
	}
	else
	{
		WARN("O tratador deste animal não está apto a tratar desta classe." << std::endl);
	}
}

Classificacao Animal::getClassificacao() const
{
	return this->classificacao;
}
void Animal::setClassificacao(Classificacao classificacao)
{
	this->classificacao = classificacao;
}

/**
 * @brief Retorna o id do Animal
*/
short Animal::getId() const
{
	return this->id;
}

bool Animal::getAmeacadaExtincao() const
{
	return this->ameacadaExtincao;
}
/**
 * @brief Informa se o animal sofre alguma ameaça de extinção
 * @param ameacadaExtincao :: Informa se o animal sofre alguma ameaça de extinção
*/
void Animal::setAmeacadaExtincao(bool ameacadaExtincao)
{
	this->ameacadaExtincao = ameacadaExtincao;
}

bool Animal::getPerigoso() const
{
	return this->perigoso;
}
/**
 * @brief Informa se o animal é perigoso ou venenoso
 * @param perigoso :: Informa se o animal é perigoso ou venenoso
*/
void Animal::setPerigoso(bool perigoso)
{
	if(this->getTratador()->aptto(this->classe, perigoso))
	{
		this->perigoso = perigoso;
	}
	else
	{
		WARN("O tratador deste animal não está apto a tratar de animais perigosos." << std::endl);
	}
}

std::string Animal::getNF() const
{
	return this->NF;
}

/**
 * @brief seta a Nota Fiscal do animal
 * @param NF :: Nota Fiscal do animal
*/
void Animal::setNF(const std::string& NF)
{
	this->NF = NF;
}

/**
 * @brief Retorna o tratador do qual o animal foi vinculado
 * @return tratador
*/
std::shared_ptr<Tratador> Animal::getTratador() const
{
	return this->tratador;
}

/**
 * @brief Retorna o veterinario do qual o animal foi vinculado
 * @return veterinario
*/
std::shared_ptr<Veterinario> Animal::getVeterinario() const
{
	return this->veterinario;
}

/**
 * @brief Define o tratador do animal
 * @param tratador :: tratador do animal
*/
void Animal::setTratador(std::shared_ptr<Tratador>& tratador)
{
	this->tratador = tratador;
}

/**
 * @brief Define o veterinario do animal
 * @param veterinario :: veterinario do animal
*/
void Animal::setVeterinario(std::shared_ptr<Veterinario>& veterinario)
{
	this->veterinario = veterinario;
}

/**
 * @brief Sobrecarga do operador <<
 * @details Sobrecarga do operador << para imprimir o animal passado por parãmetro
 * @param o :: ostream
 * @param animal :: animal a ser impresso
 * @return o
*/
std::ostream& operator<<(std::ostream& o, Animal& animal)
{
	animal.print(o);
	return o;
}

std::ofstream& operator<<(std::ofstream& o, Animal& animal)
{
	animal.save(o);
	return o;
}

void Animal::forceId(int id)
{
	this->id = id;
}
