
#include "animal.hpp"

Animal::~Animal()
{}

Animal::Animal(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF):
especie(especie), id(id), ameacadaExtincao(ameacadaExtincao), perigoso(perigoso), NF(NF)
{
	Debug("Animal " << this->id << " [" << this << "] foi criado." << std::endl);
}

Animal::Animal()
{}

std::string Animal::getEspecie() const
{
	return this->especie;
}

void Animal::setEspecie(std::string especie)
{
	this->especie = especie;
}

short Animal::getId() const
{
	return this->id;
}

void Animal::setAmeacadaExtincao(char ameacadaExtincao)
{
	this->ameacadaExtincao = ameacadaExtincao;
}

void Animal::setPerigoso(char perigoso)
{
	this->perigoso = perigoso;
}

void Animal::setNF(std::string NF)
{
	this->NF = NF;
}

Tratador* Animal::getTratador()
{
	return this->tratador;
}
	
Veterinario* Animal::getVeterinario()
{
	return this->veterinario;
}

void Animal::setTratador(Tratador* tratador)
{
	this->tratador = tratador;
}

void Animal::setVeterinario(Veterinario* veterinario)
{
	this->veterinario = veterinario;
}

std::ostream& operator<< (std::ostream& o, Animal& animal)
{
	animal.print(o);
	return o;
}
