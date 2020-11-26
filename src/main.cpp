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

	petfera->cadAnimal("Cachorro", Classe::mamifero, Classificacao::domestico, 'N', 'N', "398472", tratador, veterinario);
	petfera->cadAnimal("Lobo Guará", Classe::mamifero, Classificacao::nativo, 'S', 'N', "398470", tratador, veterinario, "1452898-BR");
	petfera->cadAnimal("Canis Lupus do Ártico", Classe::mamifero, Classificacao::exotico, 'S', 'N', "398340", tratador, veterinario, "Círculo polar ártico");

	petfera->cadAnimal("Iguana", Classe::reptil, Classificacao::domestico, 'N', 'S', "398471", tratador, veterinario);
	petfera->cadAnimal("Lagartixa enorme", Classe::reptil, Classificacao::nativo, 'N', 'S', "398471", tratador, veterinario, "93847923-ML");
	petfera->cadAnimal("Iguana albina", Classe::reptil, Classificacao::exotico, 'N', 'S', "398471", tratador, veterinario, "Malásia");
	
	petfera->cadAnimal("Sapo", Classe::anfibio, Classificacao::domestico, 'S', 'N', "293470", tratador, veterinario);
	petfera->cadAnimal("Sapo venenoso", Classe::anfibio, Classificacao::exotico, 'S', 'N', "293470", tratador, veterinario, "Austrália");
	petfera->cadAnimal("Anfíbio Genérico", Classe::anfibio, Classificacao::nativo, 'N', 'N', "398400", tratador, veterinario, "8324793-BR");

	petfera->run();

	return 0;
}