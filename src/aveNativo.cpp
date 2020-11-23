#include "aveNativo.hpp"

AveNativo::AveNativo (std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca): Ave(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}
AveNativo::~AveNativo()
{}