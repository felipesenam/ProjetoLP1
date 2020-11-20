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
	std::vector<Veterinario*> veterinarios;
	std::vector<Tratador*> tratadores;
	std::vector<Animal*> animais;

	short funcionarios = 0;
	short idAnimal = 0;

public:
	PetFera();
	~PetFera();

	void cadAnimal(); //Interface pública
	Animal* cadAnimal(std::string, Classe, Classificacao, char, char, string, Tratador*, Veterinario*);

	void remAnimal();       //Interface pública
	bool remAnimal(int); // Remove o animal do vector

	void altAnimal(); //Interface pública
	void listClass(); //Interface pública
	void listRespn(); //Interface pública
	
	void gerCad();    //Interface pública

	bool addAnimal(Animal*); // Adiciona o animal no vector
	
	Animal* buscarId(int);     // Busca o animal pelo id
	//void altAnimal();
	//void listClass();
	//void listRespn();

	void cadVetr();
	Veterinario* cadVetr(std::string, Status, std::string);
	Veterinario* cadVetr(Veterinario*);
	bool altVetr();
	std::vector<Veterinario*>::iterator findCRMV(std::string CRMV);

	void cadTrat();
	Tratador* cadTrat(std::string, Status, Seguranca);
	Tratador* cadTrat(Tratador*);
	bool altTrat();

	Veterinario* buscaVetr(int);
	Tratador* buscaTrat(int);

	bool remFunc();
	void listFunc();

	void run();
};