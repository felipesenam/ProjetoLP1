
#include "interface.hpp"

void run()
{
	
	std::string opt;
	do
	{
		CLS;
		std::cout << fGREEN << "Pet Fera" << fRESET << " - Menu principal" << std::endl << std::endl;

		std::cout << "C. Cadastrar novo animal." << std::endl;
		std::cout << "R. Remover um animal" << std::endl;
		std::cout << "A. Alterar dados de um animal" << std::endl;
		std::cout << "L. Listar animal ou classe" << std::endl;
		std::cout << "D. Listar animais sob responsabilidade" << std::endl;


		std::cout << std::endl << "X. Sair" << std::endl;

		std::cin >> opt;

		if(opt == "C" || opt == "c")
		{

		}
		else if(opt == "R" || opt == "r")
		{

		}
		else if(opt == "A" || opt == "a")
		{

		}
		else if(opt == "L" || opt == "l")
		{

		}
		else if(opt == "D" || opt == "d")
		{

		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}


	}while(1);
}