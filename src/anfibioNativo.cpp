#include "anfibioNativo.hpp"

AnfibioNativo::AnfibioNativo (std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca): Anfibio(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}
AnfibioNativo::~AnfibioNativo()
{}