
#include "nativo/nativo.hpp"

Nativo::Nativo(std::string licenca):
licenca(licenca)
{}

Nativo::~Nativo()
{}

std::string Nativo::getLicenca() const
{
	return this->licenca;
}