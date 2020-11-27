#pragma once

#include <string>

class Nativo
{
public:
	Nativo(std::string);
	virtual ~Nativo();
	std::string getLicenca() const;
protected:
	std::string licenca; //licença do IBAMA para transporte 
	
};