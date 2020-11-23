#pragma once

#include <string>

class Exotico
{
public:
	Exotico(std::string);
	~Exotico();
	std::string getTerritorio();
protected:
	std::string territorio;
	
};

