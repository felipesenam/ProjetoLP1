#pragma once

#include <iostream>
#include <iomanip>

#include "funcionario.hpp"
#include "lib.hpp"

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

private:
	Seguranca seguranca;
};