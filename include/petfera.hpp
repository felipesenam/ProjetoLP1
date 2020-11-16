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

	// short idTratador = 1;
	short funcionarios = 0;
	short idAnimal = 0;

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
	bool altVetr();
	std::vector<Veterinario*>::iterator findCRMV(std::string CRMV);

	bool cadTrat();
	bool altTrat();

	bool remFunc();
	void listFunc();

	void run();
};