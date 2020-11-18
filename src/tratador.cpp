
#include "tratador.hpp"

Tratador::Tratador()
{}

Tratador::Tratador(std::string nome, short id, Status status, Seguranca seguranca) :
Funcionario(nome, id, status), seguranca(seguranca)
{}

Tratador::~Tratador()
{}

Seguranca Tratador::getSeguranca() const
{
	return this->seguranca;
}

void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}