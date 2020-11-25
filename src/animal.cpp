
#include "animal.hpp"

/**
 * @brief Destrutor padrão
*/
Animal::~Animal()
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
Animal::Animal(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
especie(especie), id(id), ameacadaExtincao(ameacadaExtincao), perigoso(perigoso), NF(NF)
{
	Debug("Animal " << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
Animal::Animal()
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
void Animal::setEspecie(std::string especie)
{
	this->especie = especie;
}

/**
 * @brief Retorna o id do Animal
*/
short Animal::getId() const
{
	return this->id;
}

/**
 * @brief Informa se o animal sofre alguma ameaça de extinção
 * @param ameacadaExtincao :: Informa se o animal sofre alguma ameaça de extinção
*/
void Animal::setAmeacadaExtincao(char ameacadaExtincao)
{
	this->ameacadaExtincao = ameacadaExtincao;
}

/**
 * @brief Informa se o animal é perigoso ou venenoso
 * @param perigoso :: Informa se o animal é perigoso ou venenoso
*/
void Animal::setPerigoso(char perigoso)
{
	this->perigoso = perigoso;
}

/**
 * @brief seta a Nota Fiscal do animal
 * @param NF :: Nota Fiscal do animal
*/
void Animal::setNF(std::string NF)
{
	this->NF = NF;
}

/**
 * @brief Retorna o tratador do qual o animal foi vinculado
 * @return tratador
*/
Tratador* Animal::getTratador()
{
	return this->tratador;
}

/**
 * @brief Retorna o veterinario do qual o animal foi vinculado
 * @return veterinario
*/
Veterinario* Animal::getVeterinario()
{
	return this->veterinario;
}

/**
 * @brief Define o tratador do animal
 * @param tratador :: tratador do animal
*/
void Animal::setTratador(Tratador* tratador)
{
	this->tratador = tratador;
}

/**
 * @brief Define o veterinario do animal
 * @param veterinario :: veterinario do animal
*/
void Animal::setVeterinario(Veterinario* veterinario)
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
std::ostream& operator<< (std::ostream& o, Animal& animal)
{
	animal.print(o);
	return o;
}
