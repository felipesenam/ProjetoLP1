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
	Funcionario(std::string, short, Status);
	~Funcionario();
	std::string getNome() const;
	short getId() const;
	void setNome(std::string nome);
	void setStatus(Status status); 

protected:
	std::string nome;
	short id;
	Status status;
};