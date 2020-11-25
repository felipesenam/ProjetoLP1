#include "funcionario.hpp"

/**
 * @brief Construtor padrão
*/
Funcionario::Funcionario()
{}

/**
 * @brief Construtor parametrizado do Funcionario
 * @param nome :: Especifica a nome do Funcionario
 * @param id :: Especifica o id do Funcionario
 * @param status :: Informa se o Funcionario está ativo ou suspenso na empresa
*/
Funcionario::Funcionario(std::string nome, short id, Status status):nome(nome), id(id), status(status)
{}

/**
 * @brief Destrutor padrão
*/
Funcionario::~Funcionario()
{}

/**
 * @brief Retorna o nome do funcionario
 * @return nome
*/
std::string Funcionario:: getNome() const 
{
	return this->nome;
}

/**
 * @brief Retorna o id do funcionario
 * @return id
*/
short Funcionario::getId() const
{
	return this->id;
}

/**
 * @brief Seta o nome do funcionario
 * @param nome :: nome do funcionario
*/
void Funcionario::setNome(std::string nome)
{
	this->nome=nome;
}

/**
 * @brief Seta o status do funcionario
 * @param status :: status do funcionario
*/
void Funcionario::setStatus(Status status)
{
	this->status=status;
}

/**
 * @brief Sobrecarga do operador <<
 * @details Sobrecarga do operador << para imprimir os dados do funcionario
 * @param o :: ostream
 * @param funcionario :: funcionario a ser impresso
 * @return o
*/
std::ostream& operator<<(std::ostream& o, Funcionario* funcionario)
{
	funcionario->print(o);
	return o;
}