#pragma once

#include <iostream>

enum Seguranca
{
	Verde,   // Aves
	Azul,    // Aves, mamíferos e répteis
	Vermelho // Venenosos ou perigosos
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