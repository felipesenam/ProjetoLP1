#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

#include "funcionario.hpp"
#include "lib.hpp"

enum Classe
{
	anfibio,
	reptil,
	ave,
	mamifero
};

enum Classificacao
{
	nativo,
	exotico,
	domestico
};

enum Seguranca
{
	verde,
	azul,
	vermelho
};

class Tratador : public Funcionario
{
public:
	Tratador();
	Tratador(const std::string&, short, Status, Seguranca);
	~Tratador();

	Seguranca getSeguranca() const;
	void setSeguranca(Seguranca);

	void print(std::ostream&);

	void save(std::ofstream&);

	bool aptto(Classe, bool);

private:
	Seguranca seguranca;
};