
#include "nativo.hpp"

/**
 * @brief Construtor parametrizado da classificação Nativo
 * @param licenca :: Especifica a licença emitida pelo IBAMA
*/
Nativo::Nativo(std::string licenca):
licenca(licenca)
{}

/**
 * @brief Destrutor padrão
*/
Nativo::~Nativo()
{}

/**
 * @brief Retorna a licença do animal nativo
 * @return licenca
*/
std::string Nativo::getLicenca() const
{
	return this->licenca;
}
