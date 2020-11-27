#pragma once

#include <iostream>
#include <vector>
#include <limits>

#include "funcionario.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "animal.hpp"

#include "nativo.hpp"
#include "exotico.hpp"

#include "anfibio.hpp"
#include "ave.hpp"
#include "mamifero.hpp"
#include "reptil.hpp"

#include "anfibioNativo.hpp"
#include "aveNativo.hpp"
#include "mamiferoNativo.hpp"
#include "reptilNativo.hpp"

#include "anfibioExotico.hpp"
#include "aveExotico.hpp"
#include "mamiferoExotico.hpp"
#include "reptilExotico.hpp"

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
	Animal* cadAnimal(std::string, Classe, Classificacao, bool, bool, std::string, Tratador*, Veterinario*, std::string = "");

	void remAnimal();
	bool remAnimal(int);

	void altAnimal();
	void listAll();
	void listClass();
	void listId();
	void listRespn();
	
	Animal* buscarAnim(int);

	/****** VETERINARIOS ******/
	void cadVetr();
	Veterinario* cadVetr(std::string, Status, std::string);
	void altVetr();
	std::vector<Funcionario*>::iterator findCRMV(std::string CRMV);

	/******* TRATADORES *******/
	void cadTrat();
	Tratador* cadTrat(std::string, Status, Seguranca);
	void altTrat();

	/****** FUNCIONARIOS ******/
	Funcionario* cadFunc(Funcionario*);
	Funcionario* buscaFunc(int);
	bool remFunc();
	void listFunc();

	/********** MENUS *********/
	void run();
	void gerCad();
	void listAnimal();
};
