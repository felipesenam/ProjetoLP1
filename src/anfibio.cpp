
#include "anfibio.hpp"

Anfibio::Anfibio(const std::string& especie, Classe classe, Classificacao classificacao, short id, char ameacadaExtincao, char perigoso, const std::string& NF):
	Animal(especie, classe, classificacao, id, ameacadaExtincao, perigoso, NF)
{}

Anfibio::~Anfibio()
{}
