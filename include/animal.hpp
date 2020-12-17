#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <memory>

#include "veterinario.hpp"
#include "tratador.hpp"

enum Sexo
{
	indefinido,
	macho,
	femea
};

class Animal
{
protected:
	std::shared_ptr<Tratador> tratador = nullptr;
	std::shared_ptr<Veterinario> veterinario = nullptr;

	std::string especie;
	Classe classe;
	Classificacao classificacao;
	short id;
	bool ameacadaExtincao; // indica se a especie corre risco de extincao
	bool perigoso;         // indica se o animal é perigoso/venenoso
	std::string NF;        // Nota Fical

	std::string idade;
	std::string peso;
	std::string tamanho;
	Sexo sexo = indefinido;
	std::string informacoes;

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
	
	std::shared_ptr<Tratador> getTratador() const;
	void setTratador(std::shared_ptr<Tratador>&);
	
	std::shared_ptr<Veterinario> getVeterinario() const;
	void setVeterinario(std::shared_ptr<Veterinario>&);

	std::string getIdade();
	void setIdade(const std::string&);

	std::string getPeso();
	void setPeso(const std::string&);

	std::string getTamanho();
	void setTamanho(const std::string&);

	Sexo getSexo();
	void setSexo(Sexo);

	std::string getInformacoes();
	void setInformacoes(const std::string&);

	void geral();

	virtual void print(std::ostream& o) = 0;
	friend std::ostream& operator<<(std::ostream& o, Animal& animal);

	virtual void save(std::ofstream& o) = 0;
	friend std::ofstream& operator<<(std::ofstream& o, Animal& animal);

	void forceId(int id);
};