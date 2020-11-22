
#include "veterinario.hpp"

Veterinario::Veterinario()
{}
Veterinario::Veterinario(std::string nome, short id , Status status, std::string CRMV) : Funcionario(nome, 
id, status), CRMV(CRMV)
{}
Veterinario::~Veterinario()
{}

std::string Veterinario::getCRMV() const
{
	return this->CRMV;
}

void Veterinario::setCRMV(std::string CRMV)
{
	this->CRMV = CRMV;
}

void Veterinario::print(std::ostream& o)
{
	o << "ID: " << this->getId() << std::endl;
	o << "NOME: " << this->getNome() << std::endl;
	o << "CRMV: " << this->getCRMV() << std::endl;
}