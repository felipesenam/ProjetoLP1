#include "ave.hpp"

Ave::~Ave()
{}

Ave::Ave(std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, 
	char perigoso, std::string NF): Animal(especie, classe, id, classificacao, ameacadaExtincao, perigoso, NF)
{
	Debug("Ave " << this->id << " [" << this << "] foi criado." << std::endl);
}

Ave::Ave()
{}