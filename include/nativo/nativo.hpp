#pragma once

#include <string>

class Nativo
{
public:
	Nativo(std::string);
	~Nativo();
	std::string getLicenca() const;
protected:
	std::string licenca; //licença do IBAMA para transporte 
	
};