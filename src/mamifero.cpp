#include "mamifero.hpp"

Mamifero::~Mamifero()
{}

Mamifero::Mamifero(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, 
	char perigoso, std::string NF) : Animal(especie, classe, id, classificacao, ameacadaExtincao, perigoso, NF)
{
	Debug("Mamifero " << this->id << " [" << this << "] foi criado." << std::endl);
}

Mamifero::Mamifero()
{}