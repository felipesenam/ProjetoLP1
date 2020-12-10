#pragma once

#include <iostream>
#include "lib.hpp"

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
	Status getStatus() const;
	void setNome(std::string nome);
	void setStatus(Status status); 

	virtual void print(std::ostream&) = 0;
	friend std::ostream& operator<<(std::ostream& o, Funcionario& funcionario);

	virtual void save(std::ofstream& o) = 0;
	friend std::ofstream& operator<<(std::ofstream& o, Funcionario& funcionario);

	void forceId(int id);

protected:
	std::string nome;
	short id;
	Status status;
};