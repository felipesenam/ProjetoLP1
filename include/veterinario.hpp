#pragma once

#include <iostream>
#include "funcionario.hpp"

class Veterinario : public Funcionario
{
public:
	Veterinario();
	Veterinario(std::string, short, Status, std::string);
	~Veterinario();

	// std::string getNome() const;
	std::string getCRMV() const;

	// void setNome(std::string);
	void setCRMV(std::string);

private:
	// std::string nome;
	std::string CRMV;
};