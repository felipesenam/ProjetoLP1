#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

#include "funcionario.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include "animal.hpp"

#include "nativo/nativo.hpp"
#include "exotico/exotico.hpp"

#include "anfibio.hpp"
#include "ave.hpp"
#include "mamifero.hpp"
#include "reptil.hpp"

#include "nativo/anfibioNativo.hpp"
#include "nativo/aveNativo.hpp"
#include "nativo/mamiferoNativo.hpp"
#include "nativo/reptilNativo.hpp"

#include "exotico/anfibioExotico.hpp"
#include "exotico/aveExotico.hpp"
#include "exotico/mamiferoExotico.hpp"
#include "exotico/reptilExotico.hpp"

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
	Animal* cadAnimal(std::string, Classe, Classificacao, char, char, std::string, Tratador*, Veterinario*, std::string);

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
