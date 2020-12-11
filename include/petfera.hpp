#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <limits>
#include <fstream>
#include <cstring>

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
	std::map<int, Funcionario*> funcionarios;
	std::vector<Animal*> animais;

public:
	PetFera();
	~PetFera();

	void load();
	void save();

	/*** INTERFACES PÚBLICAS **/
	void cadAnimal();
	void remAnimal();
	void altAnimal();

	void listAll();
	void listId();
	void listClass();
	void listRespn();

	void cadVetr();
	void altVetr();

	void cadTrat();
	void altTrat();

	void remFunc();
	void listFunc();

	/********* ANIMAIS ********/
	Animal* cadAnimal(std::string, Classe, Classificacao, bool, bool, std::string, Tratador*, Veterinario*, std::string = "");
	bool remAnimal(int);
	void redoAnimal(Animal*&, std::string);

	int listClass(Classe classe, Classificacao classificacao);
	int listRespn(Funcionario* funcionario);

	Animal* buscarAnim(int);

	/****** VETERINARIOS ******/
	Veterinario* cadVetr(std::string, Status, std::string, int);
	std::map<int, Funcionario*>::iterator findCRMV(std::string CRMV);

	/******* TRATADORES *******/
	Tratador* cadTrat(std::string, Status, Seguranca, int);
	
	/****** FUNCIONARIOS ******/
	Funcionario* cadFunc(Funcionario*);
	Funcionario* buscaFunc(int);
	bool remFunc(int id);
	

	/********** MENUS *********/
	void run();
	void gerCad();
	void listAnimal();
};
