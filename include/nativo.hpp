#pragma once

#include <string>

class Nativo
{
public:
	Nativo(const std::string&);
	virtual ~Nativo();

	std::string getLicenca() const;
protected:
	std::string licenca;
};