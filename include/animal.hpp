#pragma once

#include <string>
#include <ostream>
#include <iostream>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "lib.hpp"

class Animal
{
private:
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

public:
	Animal();
	Animal(std::string especie, short id, char ameacadaExtincao, char perigoso, std::string NF);
	virtual ~Animal();

	std::string getEspecie() const;
	void setEspecie(std::string);

	short getId() const;
	void setAmeacadaExtincao(char ameacadaExtincao);
	void setPerigoso(char perigoso);
	void setNF(std::string NF);

	Tratador* getTratador();
	Veterinario* getVeterinario();
	void setTratador(Tratador*);
	void setVeterinario(Veterinario*);

	virtual void print(std::ostream& o) = 0;
	friend std::ostream& operator<< (std::ostream& o, Animal& animal);

protected:
	std::string especie;
	short id;
	char ameacadaExtincao; // indica se a especie corre risco de extincao
	char perigoso;         // indica se o animal é perigoso/venenoso
	std::string NF;        // Nota Fical
};