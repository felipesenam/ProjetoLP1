#pragma once

#include <iostream>

class Veterinario
{
public:
	Veterinario();
	Veterinario(std::string, std::string);
	~Veterinario();

	std::string getNome() const;
	std::string getCRMV() const;

	void setNome(std::string);
	void setCRMV(std::string);

private:
	std::string nome;
	std::string CRMV;
};