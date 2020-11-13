
#include "veterinario.hpp"

Veterinario::Veterinario()
{}
Veterinario::Veterinario(std::string nome, std::string CRMV) : nome(nome), CRMV(CRMV)
{}
Veterinario::~Veterinario()
{}

std::string Veterinario::getNome() const
{
	return this->nome;
}
std::string Veterinario::getCRMV() const
{
	return this->CRMV;
}

void Veterinario::setNome(std::string nome)
{
	this->nome = nome;
}
void Veterinario::setCRMV(std::string CRMV)
{
	this->CRMV = CRMV;
}