#pragma once

#include <string>

class Exotico
{
public:
	Exotico(std::string);
	virtual ~Exotico();
	std::string getTerritorio();
protected:
	std::string territorio;
};

