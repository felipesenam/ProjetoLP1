#pragma once

#include <iostream>

enum Seguranca
{
	Verde,
	Azul,
	Vermelho
};

class Tratador
{
public:
	Tratador();
	Tratador(std::string, Seguranca);
	~Tratador();

	std::string getNome() const;
	Seguranca getSeguranca() const;

	void setNome(std::string);
	void setSeguranca(Seguranca);

private:
	std::string nome;
	Seguranca seguranca;
};