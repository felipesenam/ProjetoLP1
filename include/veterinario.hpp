#pragma once

#include <iostream>
#include <fstream>

#include "funcionario.hpp"

class Veterinario : public Funcionario
{
public:
	Veterinario();
	Veterinario(const std::string&, short, Status, const std::string&);
	~Veterinario();

	std::string getCRMV() const;
	void setCRMV(const std::string&);

	void print(std::ostream&);

	void save(std::ofstream&);

private:
	std::string CRMV;
};