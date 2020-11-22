#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

#include "funcionario.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "animal.hpp"

class PetFera
{
private:
	std::vector<Funcionario*> funcionarios;
	std::vector<Animal*> animais;

public:
	PetFera();
	~PetFera();


	/********* ANIMAIS ********/
	void cadAnimal();
	Animal* cadAnimal(std::string, Classe, Classificacao, char, char, std::string, Tratador*, Veterinario*);

	void remAnimal();
	bool remAnimal(int);

	void altAnimal();
	void listClass();
	void listRespn();
	void listRespn(Funcionario*);
	
	Animal* buscarAnim(int);

	/****** VETERINARIOS ******/
	void cadVetr();
	Veterinario* cadVetr(std::string, Status, std::string);
	bool altVetr();
	std::vector<Funcionario*>::iterator findCRMV(std::string CRMV);

	/******* TRATADORES *******/
	void cadTrat();
	Tratador* cadTrat(std::string, Status, Seguranca);
	bool altTrat();

	/****** FUNCIONARIOS ******/
	Funcionario* cadFunc(Funcionario*);
	Funcionario* buscaFunc(int);
	bool remFunc();
	void listFunc();

	/********** MENUS *********/
	void run();
	void gerCad();
};
