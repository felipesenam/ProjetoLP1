
#include "interface.hpp"

void printTitle(string title, int largura, auto cor) {
	int spaceOnLeft = (largura-title.length())/2;
	int spaceExtra = title.length()%2;
	cout << setfill('*') << setw(largura) << ""<< endl;
	cout << "**" 
		<< setfill(' ') << setw(spaceOnLeft-2) << ""
		<< cor << title <<fRESET 
		<< setfill(' ') << setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << endl;
	cout << setfill('*') << setw(largura) << "" << endl;
}

void printMenu() {
	string title="Pet Fera";
	int spaceOnLeft = (60-title.length())/2;
	int spaceExtra = title.length()%2;
	cout << setfill('*') << setw(60) << ""<< endl;
	cout << "**" 
		<< setfill(' ') << setw(spaceOnLeft-2) << ""
		<< fGREEN << "Pet Fera" <<fRESET 
		<< setfill(' ') << setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << endl;
	title="Menu Principal";
	spaceOnLeft = (60-title.length())/2;
	spaceExtra = title.length()%2;
	cout << "**" 
		<< setfill(' ') << setw(spaceOnLeft-2) << ""
		<< "Menu Principal" 
		<< setfill(' ') << setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << endl;
	cout << setfill('*') << setw(60) << "" << endl;
}

void run()
{
	
	std::string opt;
	do
	{
		CLS;
		printMenu();
		// std::cout << fGREEN << "Pet Fera" << fRESET << " - Menu principal" << std::endl << std::endl;

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