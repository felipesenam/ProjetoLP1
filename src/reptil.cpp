#include "reptil.hpp"

Reptil::~Reptil()
{}

Reptil::Reptil(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, 
	char perigoso, std::string NF) : Animal(especie, classe, id, classificacao, ameacadaExtincao, perigoso, NF)
{
	Debug("Reptil " << this->id << " [" << this << "] foi criado." << std::endl);
}

Reptil::Reptil()
{}