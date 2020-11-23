#include "exotico.hpp"

Exotico::Exotico(std::string territorio):territorio(territorio){}
Exotico::~Exotico(){}
std::string Exotico::getTerritorio(){
	return this->territorio;
}