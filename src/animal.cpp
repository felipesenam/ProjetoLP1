
#include "animal.hpp"

Animal::~Animal()
{}

Animal::Animal(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, string NF) :
	especie(especie), classe(classe), id(id), classificacao(classificacao), ameacadaExtincao(ameacadaExtincao),
	perigoso(perigoso),NF(NF)
{
	Debug("Animal " << this->id << " [" << this << "] foi criado." << endl);
}

Animal::Animal()
{}

std::string Animal::getEspecie()
{
	return this->especie;
}

void Animal::setEspecie(std::string especie)
{
	this->especie = especie;
}

Classe Animal::getClasse()
{
	return this->classe;
}

void Animal::setClasse(Classe classe)
{
	this->classe=classe;
}

short Animal::getId() const
{
	return this->id;
}

Classificacao Animal::getClassificacao() const
{
	return this->classificacao;
}

void Animal::setClassificacao(Classificacao classificacao)
{
	this->classificacao = classificacao;
}

void Animal::setAmeacadaExtincao(char ameacadaExtincao)
{
	this->ameacadaExtincao=ameacadaExtincao;
}

void Animal::setPerigoso(char perigoso)
{
	this->perigoso=perigoso;
}

void Animal::setNF(string NF)
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

ostream& operator<< (ostream& saida, Animal& a)
{
	cout 
		<< "id: " << a.id << endl
		<< "Classificação: " << a.classificacao << endl
		<< "Classe: "<< a.classe << endl
		<< "extinção? " << a.ameacadaExtincao << endl
		<< "perigoso? " << a.perigoso << endl
		<< "NF: "<< a.NF << endl;
	return saida;
}
