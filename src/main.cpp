#include <iostream>

#include "petfera.hpp"

int main(/*int argc, char* argv[]*/)
{
	std::unique_ptr<PetFera> petfera(new PetFera());

	Veterinario* veterinario = new Veterinario("Charles Bulcão", 2, Status::ativo, "239487083");
	Tratador* tratador = new Tratador("Felipe Sena", 1, Status::ativo, Seguranca::vermelho);

	petfera->cadVetr(veterinario);
	petfera->cadTrat(tratador);

	petfera->run();

	return 0;
}