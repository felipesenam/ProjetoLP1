#include <iostream>

#include "petfera.hpp"

int main(/*int argc, char* argv[]*/)
{
	std::unique_ptr<PetFera> petfera(new PetFera());

	petfera->run();

	return 0;
}