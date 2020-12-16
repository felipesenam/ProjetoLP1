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
	Funcionario(const std::string&, short, Status);
	virtual ~Funcionario();

	std::string getNome() const;
	void setNome(const std::string& nome);

	short getId() const;

	Status getStatus() const;
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