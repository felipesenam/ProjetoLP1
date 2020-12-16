
#include "mamifero.hpp"

Mamifero::Mamifero(std::string especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, std::string NF):
	Animal(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{}

Mamifero::~Mamifero()
{}
