#pragma once

#include <iostream>

#include "funcionario.hpp"

enum Seguranca
{
	Verde,
	Azul,
	Vermelho
};

class Tratador : public Funcionario{
public:
	Tratador();
	Tratador(std::string, short, Status, Seguranca);
	~Tratador();
	Seguranca getSeguranca() const;
	void setSeguranca(Seguranca);

private:
	Seguranca seguranca;
};