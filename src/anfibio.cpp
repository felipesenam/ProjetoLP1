#include "anfibio.hpp"

Anfibio::~Anfibio()
{}

Anfibio::Anfibio(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, 
	char perigoso, std::string NF) : Animal(especie, classe, id, classificacao, ameacadaExtincao, perigoso, NF)
{
	Debug("Anfibio " << this->id << " [" << this << "] foi criado." << std::endl);
}

Anfibio::Anfibio()
{}