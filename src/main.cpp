#include <iostream>
#include "animal.hpp"

int main(/*int argc, char* argv[]*/)
{

	std::cout << "Projeto LP1" << std::endl;

	Animal cachorro(1,nativo,false,"125");

	cachorro.printAnimal();

	return 0;
}