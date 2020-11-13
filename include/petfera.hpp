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
	std::map<std::string, Veterinario> veterinarios; //Map permite que um veterinário seja encontrado por referência a um nome
	std::map<std::string, Tratador> tratadores;      //Map permite que um tratador seja encontrado por referência a um nome
	std::vector<Animal*> animais;

public:
	void cadAnimal(); //Interface pública
	void remAnimal(); //Interface pública
	void altAnimal(); //Interface pública
	void listClass(); //Interface pública
	void listRespn(); //Interface pública

	bool addAnimal(Animal* novo); //adiciona o animal no vector
	Animal* remAnimal_(int id); //remove o animal do vector
	Animal* buscarId(int id); // busca o animal pelo id
	//void altAnimal();
	//void listClass();
	//void listRespn();

};