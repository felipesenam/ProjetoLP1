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
#include "domestico.hpp"
#include "exotico.hpp"
#include "nativo.hpp"
#include "anfibio.hpp"
#include "anfibioDomestico.hpp"
#include "anfibioExotico.hpp"
#include "anfibioNativo.hpp"
#include "ave.hpp"
#include "aveDomestica.hpp"
#include "aveExotica.hpp"
#include "aveNativa.hpp"
#include "mamifero.hpp"
#include "mamiferoDomestico.hpp"
#include "mamiferoExotico.hpp"
#include "mamiferoNativo.hpp"
#include "reptil.hpp"
#include "reptilDomestico.hpp"
#include "reptilExotico.hpp"
#include "reptilNativo.hpp"

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
	Animal* cadAnimal(const std::string&, Classe, Classificacao, bool, bool, const std::string&, Tratador*, Veterinario*, const std::string& = "");
	bool remAnimal(int);
	void redoAnimal(Animal*&, const std::string&);

	int listClass(Classe classe, Classificacao classificacao);
	int listRespn(Funcionario* funcionario);

	Animal* buscarAnim(int);

	/****** VETERINARIOS ******/
	Veterinario* cadVetr(const std::string&, Status, const std::string&, int);
	std::map<int, Funcionario*>::iterator findCRMV(const std::string& CRMV);

	/******* TRATADORES *******/
	Tratador* cadTrat(const std::string&, Status, Seguranca, int);
	
	/****** FUNCIONARIOS ******/
	Funcionario* cadFunc(Funcionario*);
	Funcionario* buscaFunc(int);
	bool remFunc(int id);
	

	/********** MENUS *********/
	void run();
	void gerCad();
	void listAnimal();
};
