#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "animal.hpp"

class PetFera
{
private:
	std::map<std::string, Veterinario*> veterinarios; //Map permite que um veterinário seja encontrado por referência a um nome
	std::map<std::string, Tratador*> tratadores;      //Map permite que um tratador seja encontrado por referência a um nome
	std::vector<Animal*> animais;

public:
	PetFera();
	~PetFera();

	void cadAnimal(); //Interface pública
	void remAnimal(); //Interface pública
	void altAnimal(); //Interface pública
	void listClass(); //Interface pública
	void listRespn(); //Interface pública
	void gerCad();    //Interface pública

	bool addAnimal(Animal* novo); // Adiciona o animal no vector
	Animal* remAnimal_(int id);   // Remove o animal do vector
	Animal* buscarId(int id);     // Busca o animal pelo id
	//void altAnimal();
	//void listClass();
	//void listRespn();

	bool cadVetr();
	bool remVetr();
	bool altVetr();
	std::map<std::string, Veterinario*>::iterator findCRMV(std::string CRMV);

	bool cadTrat();
	bool remTrat();
	bool altTrat();

	void listFunc();

	void run();
};