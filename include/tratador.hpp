#pragma once

#include <iostream>
#include <iomanip>

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
	Tratador(std::string, short, Status, Seguranca);
	~Tratador();
	Seguranca getSeguranca() const;
	void setSeguranca(Seguranca);

	void print(std::ostream&);

	bool aptto(Classe, bool);

private:
	Seguranca seguranca;
};