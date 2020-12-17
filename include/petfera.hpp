#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <memory>

#include "veterinario.hpp"
#include "tratador.hpp"

#include "anfibioDomestico.hpp"
#include "anfibioExotico.hpp"
#include "anfibioNativo.hpp"

#include "aveDomestica.hpp"
#include "aveExotica.hpp"
#include "aveNativa.hpp"

#include "mamiferoDomestico.hpp"
#include "mamiferoExotico.hpp"
#include "mamiferoNativo.hpp"

#include "reptilDomestico.hpp"
#include "reptilExotico.hpp"
#include "reptilNativo.hpp"

class PetFera
{
private:
	std::map<int, std::shared_ptr<Funcionario>> funcionarios;
	std::vector<std::shared_ptr<Animal>> animais;

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
	std::shared_ptr<Animal> cadAnimal(const std::string&, Classe, Classificacao, bool, bool, const std::string&, std::shared_ptr<Tratador>&, std::shared_ptr<Veterinario>&, const std::string& = "");
	bool remAnimal(int);
	void redoAnimal(std::shared_ptr<Animal>&, const std::string&);

	int listClass(Classe classe, Classificacao classificacao);
	int listRespn(std::shared_ptr<Funcionario>& funcionario);

	std::shared_ptr<Animal> buscarAnim(int);

	/****** VETERINARIOS ******/
	std::shared_ptr<Veterinario> cadVetr(const std::string&, Status, const std::string&, int);
	std::map<int, std::shared_ptr<Funcionario>>::iterator findCRMV(const std::string& CRMV);

	/******* TRATADORES *******/
	std::shared_ptr<Tratador> cadTrat(const std::string&, Status, Seguranca, int);
	
	/****** FUNCIONARIOS ******/
	std::shared_ptr<Funcionario> cadFunc(std::shared_ptr<Funcionario>&);
	std::shared_ptr<Funcionario> buscaFunc(int);
	bool remFunc(int id);
	

	/********** MENUS *********/
	void run();
	void gerCad();
	void listAnimal();
};
