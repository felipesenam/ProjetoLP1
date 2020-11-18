#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "lib.hpp"

using namespace std;

enum Classificacao
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
	Animal();
	Animal(std::string especie, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, string NF);
	~Animal();

	std::string getEspecie();
	void setEspecie(std::string);

	short getId() const;
	Classificacao getClassificacao() const;
	void setClassificacao(Classificacao classificacao);
	void setAmeacadaExtincao(char ameacadaExtincao);
	void setPerigoso(char perigoso);
	void setNF(string NF);

	Tratador* getTratador();
	Veterinario* getVeterinario();
	void setTratador(Tratador*);
	void setVeterinario(Veterinario*);

	friend ostream& operator<< (ostream& saida, Animal& a);

protected:
	std::string especie;
	short id;
	Classificacao classificacao;
	char ameacadaExtincao; // indica se a especie corre risco de extincao
	char perigoso;         // indica se o animal é perigoso/venenoso
	string NF = NULL;      // Nota Fical
};