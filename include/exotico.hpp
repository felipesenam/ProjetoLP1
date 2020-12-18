#pragma once

#include <string>

class Exotico
{
public:
	Exotico(const std::string&);
	virtual ~Exotico();

	std::string getTerritorio() const;
	void setTerritorio(const std::string&);
protected:
	std::string territorio;
};

