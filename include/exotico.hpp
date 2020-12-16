#pragma once

#include <string>

class Exotico
{
public:
	Exotico(std::string);
	virtual ~Exotico();

	std::string getTerritorio() const;
protected:
	std::string territorio;
};

