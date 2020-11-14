
#include "petfera.hpp"

PetFera::PetFera()
{}

PetFera::~PetFera()
{}

void PetFera::cadAnimal()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore to the end of line
	short id;
	string strClassificacao_;
	classificacao classificacao_;
	char ameacadaExtincao;
	char perigoso;        
	string NF;
	Animal* criado = nullptr;

	do
	{
		cout<< "Insira o id do animal: "<<endl;
		cin>>id;
		if (this->buscarId(id)!=nullptr)
			cout<< "Erro! ID já cadastrado"<<endl;
	} while (this->buscarId(id)!=nullptr);
	std::cin.clear();

	do
	{
		cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
		cin>>strClassificacao_;
		if (strClassificacao_ != "N" && strClassificacao_ != "n"
			&& strClassificacao_ != "E" && strClassificacao_ != "e"
			&& strClassificacao_ != "D" && strClassificacao_ != "d")
			cout<<"Opção inválida"<<endl;
	} while (strClassificacao_ != "N" && strClassificacao_ != "n"
			&& strClassificacao_ != "E" && strClassificacao_ != "e"
			&& strClassificacao_ != "D" && strClassificacao_ != "d");
	std::cin.clear();

	do
	{
		cout<< "O animal possui algum grau de extinção? S (sim) / N (não)"<<endl;
		cin>>ameacadaExtincao;
		if (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N')
			cout<<"Opção inválida"<<endl;
	} while (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N' );
	std::cin.clear();

	do
	{
		cout<< "O animal é considerado perigoso ou venenoso? S (sim) / N (não) "<<endl;
		cin>>perigoso;
		if (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N')
			cout<<"Opção inválida"<<endl;
	} while (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N' );
	std::cin.clear();

	cout<< "Insira a Nota Fiscal, se houver: "<<endl;
	cin>>NF;
	std::cin.clear();
	classificacao_=nativo;

	if (strClassificacao_=="E" || strClassificacao_=="e")
	{
		classificacao_ = exotico;
	}
	else if (strClassificacao_=="D" || strClassificacao_=="d")
	{
		classificacao_ = domestico;
	} 
	criado = new Animal(id, classificacao_, ameacadaExtincao, perigoso, NF);

	if (this->addAnimal(criado)) {
		cout << "Operação realizada com sucesso." << endl;

	} else {
		cout << "Erro! Operação cancelada." << endl;
	}
	PAUSE;
}

bool PetFera::addAnimal(Animal* novo)
{
	this->animais.push_back(novo);
	return true;
}

void PetFera::remAnimal()
{
	int idRem;
	do
	{
		cout<<"Insira o id do animal a ser removido.";
		cin>>idRem;
	} while (this->buscarId(idRem)==nullptr);

	if (this->remAnimal_(idRem))
	{
		cout << "Operação realizada com sucesso." << endl;
	}
	else
	{
		cout << "Erro! Operação cancelada." << endl;
	}

}

Animal* PetFera::remAnimal_(int id)
{
	int index = 0;
	for (auto& animal : this->animais)
	{
		if (animal->getId()==id)
		{
			Animal* removido = animal;
			this->animais.erase(this->animais.begin()+index);
			return removido;
		}
		index++;
	}
	return nullptr;

}

void PetFera::altAnimal()
{

}

void PetFera::listClass()
{
	if (this->animais.size()==0)
	{
		cout << "Não há animais cadastrados." << endl;
	}
	else
	{
		for (auto& animal : this->animais)
			cout<<(*animal)<<endl;
	}
	PAUSE;
}

void PetFera::listRespn()
{

}

void PetFera::gerCad()
{
	std::string opt;
	do
	{
		CLS;
		printMenu();
		// std::cout << fGREEN << "Pet Fera" << fRESET << " - Menu principal" << std::endl << std::endl;

		std::cout << "V. Cadastrar veterinário." << std::endl;
		std::cout << "R. Remover veterinário." << std::endl;
		std::cout << "A. Alterar dados de um veterinário." << std::endl;
		std::cout << "T. Cadastrar tratador." << std::endl;
		std::cout << "D. Remover tratador." << std::endl;
		std::cout << "U. Alterar dados de um tratador." << std::endl;

		std::cout << std::endl << "X. Sair" << std::endl;

		std::cin >> opt;

		if(opt == "V" || opt == "v")
		{
			this->cadVetr();
		}
		else if(opt == "R" || opt == "r")
		{
			this->remVetr();
		}
		else if(opt == "A" || opt == "a")
		{

		}
		else if(opt == "T" || opt == "t")
		{
			this->cadTrat();
		}
		else if(opt == "D" || opt == "d")
		{
			this->remTrat();
		}
		else if(opt == "U" || opt == "u")
		{

		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}


	}while(1);
}

/**
* @brief Busca o id do animal no vetor
* @param int id referente ao animal
* @return Retorna um ponteiro para o animal
*/
Animal* PetFera::buscarId(int id)
{
	for (auto& animal : this->animais)
	{
		if (animal->getId()==id)
		{
			return animal;
		}
	}
	return nullptr;
}

bool PetFera::cadVetr()
{
	std::string nome, CRMV;

	std::cout << "Insira o nome do veterinário: " << std::endl;
	cin.ignore();
	getline(std::cin, nome);

	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		std::cin >> CRMV;
		if(findCRMV(CRMV) == veterinarios.end())
			break;
		else
			std::cout << "Já existe um veterinário com este número de CRMV cadastrado." << std::endl;
	} while (1);

	Veterinario *vet = new Veterinario(nome,2,ativo, CRMV);
	veterinarios.emplace(nome, vet);

	return true;
}
bool PetFera::remVetr()
{
	std::string CRMV;

	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		std::cin >> CRMV;
		auto iter = findCRMV(CRMV);
		if(iter != veterinarios.end())
		{
			std::cout << iter->first << " foi desvinculado da loja." << std::endl;
			veterinarios.erase(iter);
			break;
		}
		else
			std::cout << "CRMV não encontrado." << std::endl;
	} while (1);

	PAUSE;
	return false;
}
bool PetFera::altVetr()
{

}
std::map<std::string, Veterinario*>::iterator PetFera::findCRMV(std::string CRMV)
{
	for(auto i = veterinarios.begin(); i != veterinarios.end(); ++i)
	{
		if(i->second->getCRMV() == CRMV)
		{
			return i;
		}
	}
	return veterinarios.end();
}


bool PetFera::cadTrat()
{
	std::string nome;
	short id;

	std::cout << "Insira o nome do tratador: " << std::endl;
	cin.ignore();
	getline(std::cin, nome);

	do
	{
		std::cout << "Insira o id do tratador: " << std::endl;
		std::cin >> id;
		if(findIdTratador(id) == tratadores.end())
			break;
		else
			std::cout << "Já existe um tratador com este número de id cadastrado." << std::endl;
	} while (1);

	Tratador *vet = new Tratador(nome, id, ativo, Vermelho );
	tratadores.emplace(id, vet);

	return true;
}
bool PetFera::remTrat()
{
	short idTratador;

	do
	{
		std::cout << "Insira o id do tratador: " << std::endl;
		std::cin >> idTratador;
		auto iter = findIdTratador(idTratador);
		if(iter != tratadores.end())
		{
			std::cout << iter->first << " foi desvinculado da loja." << std::endl;
			tratadores.erase(iter);
			break;
		}
		else
			std::cout << "id não encontrado." << std::endl;
	} while (1);

	PAUSE;
	return false;

}
bool PetFera::altTrat()
{

}
std::map<short, Tratador*>::iterator PetFera::findIdTratador(short id)
{
	for(auto i = tratadores.begin(); i != tratadores.end(); ++i)
	{
		if(i->second->getId() == id)
		{
			return i;
		}
	}
	return tratadores.end();
}


void PetFera::listFunc()
{
	std::cout << "Veterinários:" << std::endl;
	for(auto i : this->veterinarios)
	{
		std::cout << i.first << std::endl;
		std::cout << "CRMV:" << i.second->getCRMV() << std::endl << std::endl;
	}
	std::cout << "Tratadores:" << std::endl;
	for(auto i : this->tratadores)
	{
		std::cout << i.second->getNome() << std::endl;
		std::cout << "id:" << i.second->getId() << std::endl << std::endl;
	}
	PAUSE;
}

void PetFera::run()
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
		std::cout << "G. Gerenciar funcionários" << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;


		std::cout << std::endl << "X. Sair" << std::endl;

		std::cin >> opt;

		if(opt == "C" || opt == "c"){
			printTitle("Cadastrar Animal", 60, fGREEN);
			this->cadAnimal();
			cout << "Operação realizada com sucesso." << endl;
		}
		else if(opt == "R" || opt == "r")
		{
			printTitle("Remover um animal", 60, fRESET);
			this->remAnimal();

		}
		else if(opt == "A" || opt == "a")
		{
			printTitle("Alterar dados de um animal", 60, fRESET);

		}
		else if(opt == "L" || opt == "l")
		{
			printTitle("Listar animal ou classe", 60, fRESET);
			this->listClass();

		}
		else if(opt == "D" || opt == "d")
		{
			printTitle("Listar animais sob responsabilidade", 60, fRESET);
		}
		else if(opt == "G" || opt == "g")
		{
			this->gerCad();
		}
		else if(opt == "F" || opt == "f")
		{
			this->listFunc();
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}


	}while(1);
}