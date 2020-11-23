#include "mamiferoNativo.hpp"

MamiferoNativo::MamiferoNativo (std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca): Mamifero(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}
MamiferoNativo::~MamiferoNativo()
{}