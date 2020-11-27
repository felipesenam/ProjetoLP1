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

	petfera->cadVetr("Charles Bulcão", Status::ativo, "239487083");
	petfera->cadTrat("Felipe Sena", Status::ativo, Seguranca::vermelho);

	petfera->cadAnimal("Sapo-cururu",           Classe::anfibio, Classificacao::domestico, false, false, "2900784", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)));
	petfera->cadAnimal("Salamandra",            Classe::anfibio, Classificacao::nativo,    false, false, "2900783", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "8324793-BR");
	petfera->cadAnimal("Rã-venenosa-granulada", Classe::anfibio, Classificacao::exotico,   false,  true, "2900782", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "Austrália");
	
	petfera->cadAnimal("Papagaio",          Classe::ave, Classificacao::domestico, false, false, "2800784", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)));
	petfera->cadAnimal("Arara Azul",        Classe::ave, Classificacao::nativo,     true, false, "2800783", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "8324793-BR");
	petfera->cadAnimal("Falcão-peregrino",  Classe::ave, Classificacao::exotico,   false, false, "2800782", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "EUA");
	
	petfera->cadAnimal("Cachorro",   Classe::mamifero, Classificacao::domestico, false, false, "2700784", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)));
	petfera->cadAnimal("Lobo Guará", Classe::mamifero, Classificacao::nativo,     true,  true, "2700783", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "1452898-BR");
	petfera->cadAnimal("Lobo Cinza", Classe::mamifero, Classificacao::exotico,   false,  true, "2700782", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "Alaska");

	petfera->cadAnimal("Iguana",    Classe::reptil, Classificacao::domestico, false, false, "2600784", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)));
	petfera->cadAnimal("Sucuri",    Classe::reptil, Classificacao::nativo,    false,  true, "2600783", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "93847923-BR");
	petfera->cadAnimal("Crocodilo", Classe::reptil, Classificacao::exotico,   false,  true, "2600782", dynamic_cast<Tratador*>(petfera->buscaFunc(2)), dynamic_cast<Veterinario*>(petfera->buscaFunc(1)), "Africa");

	petfera->run();

	return 0;
}