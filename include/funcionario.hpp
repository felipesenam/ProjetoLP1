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
	virtual ~Funcionario();
	std::string getNome() const;
	short getId() const;
	void setNome(std::string nome);
	void setStatus(Status status); 

	virtual void print(std::ostream&) = 0;
	friend std::ostream& operator<<(std::ostream& o, Funcionario* funcionario);

protected:
	std::string nome;
	short id;
	Status status;
};