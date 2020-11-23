#include "reptilNativo.hpp"

ReptilNativo::ReptilNativo (std::string especie, Classe classe, short id, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, std::string licenca): Reptil(especie,classe,id,classificacao,ameacadaExtincao, perigoso, NF), Nativo (licenca)
{}
ReptilNativo::~ReptilNativo()
{}