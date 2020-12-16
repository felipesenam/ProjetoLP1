
#include "exotico.hpp"

/**
 * @brief Construtor parametrizado da classificação exotico
 * @param territorio :: Especifica o territorio do qual o animal Exotico pertence
*/
Exotico::Exotico(const std::string& territorio):
territorio(territorio)
{}

/**
 * @brief Destrutor padrão
*/
Exotico::~Exotico()
{}

/**
 * @brief Retorna o territorio do animal exotico
 * @return territorio
*/
std::string Exotico::getTerritorio() const
{
	return this->territorio;
}
