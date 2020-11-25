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

	Veterinario* veterinario = new Veterinario("Charles Bulcão", 1, Status::ativo, "239487083");
	Tratador* tratador = new Tratador("Felipe Sena", 2, Status::ativo, Seguranca::vermelho);

	petfera->cadFunc(veterinario);
	petfera->cadFunc(tratador);

	petfera->run();

	return 0;
}