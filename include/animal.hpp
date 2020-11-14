#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "lib.hpp"

using namespace std;

enum classificacao
{
	nativo,
	exotico,
	domestico
};

class Animal
{
private:
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

public:
	Animal(short id, classificacao classificacao_,char ameacadaExtincao, char perigoso, string NF);
	Animal();
	~Animal();

	short getId() const;
	classificacao getClassificacao() const;

	Tratador* getTratador();
	Veterinario* getVeterinario();
	void setTratador(std::string);
	void setVeterinario(std::string);


	void printAnimal();
	friend ostream& operator<< (ostream& saida, Animal& a);

protected:
	short id;
	classificacao classificacao_;
	char ameacadaExtincao; // indica se a especie corre risco de extincao
	char perigoso;         // indica se o animal é perigoso/venenoso
	string NF= NULL;       // Nota Fical
};