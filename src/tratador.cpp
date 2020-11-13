
#include "tratador.hpp"

Tratador::Tratador()
{}
Tratador::Tratador(std::string nome, Seguranca seguranca) : nome(nome), seguranca(seguranca)
{}
Tratador::~Tratador()
{}

std::string Tratador::getNome() const
{
	return this->nome;
}
Seguranca Tratador::getSeguranca() const
{
	return this->seguranca;
}

void Tratador::setNome(std::string nome)
{
	this->nome = nome;
}
void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}