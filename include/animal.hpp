#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "lib.hpp"

class Animal
{
protected:
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

	std::string especie;
	Classe classe;
	Classificacao classificacao;
	short id;
	bool ameacadaExtincao; // indica se a especie corre risco de extincao
	bool perigoso;         // indica se o animal é perigoso/venenoso
	std::string NF;        // Nota Fical

public:
	Animal();
	Animal(const std::string& especie, Classe classe, Classificacao classificacao, short id, bool ameacadaExtincao, bool perigoso, const std::string& NF);
	virtual ~Animal();

	std::string getEspecie() const;
	void setEspecie(const std::string&);

	Classe getClasse() const;
	void setClasse(Classe);

	Classificacao getClassificacao() const;
	void setClassificacao(Classificacao);

	bool getAmeacadaExtincao() const;
	void setAmeacadaExtincao(bool ameacadaExtincao);

	bool getPerigoso() const;
	void setPerigoso(bool perigoso);

	short getId() const;
	
	std::string getNF() const;
	void setNF(const std::string& NF);
	
	Tratador* getTratador() const;
	void setTratador(Tratador*);
	
	Veterinario* getVeterinario() const;
	void setVeterinario(Veterinario*);

	virtual void print(std::ostream& o) = 0;
	friend std::ostream& operator<<(std::ostream& o, Animal& animal);

	virtual void save(std::ofstream& o) = 0;
	friend std::ofstream& operator<<(std::ofstream& o, Animal& animal);

	void forceId(int id);
};