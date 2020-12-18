#pragma once

#include <string>

class Nativo
{
public:
	Nativo(const std::string&);
	virtual ~Nativo();

	std::string getLicenca() const;
	void setLicenca(const std::string&);
protected:
	std::string licenca;
};