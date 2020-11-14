#pragma once

#include <iostream>

enum Status
{
	ativo,
	inativo
	
};

class Funcionario
{
public:
	Funcionario();
	Funcionario(std::string, short,Status);
	~Funcionario();
	std::string getNome() const;
	short getId() const;

protected:
	Status status;
	std::string nome;
	short id;
	
};