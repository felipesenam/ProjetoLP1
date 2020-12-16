#include <iostream>

#include "petfera.hpp"

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
int main(/*int argc, char* argv[]*/)
{
	std::unique_ptr<PetFera> petfera(new PetFera());

	petfera->load();
	petfera->run();

	return 0;
}
