
#include "petfera.hpp"

PetFera::PetFera()
{}

PetFera::~PetFera()
{
	for(auto v : this->veterinarios)
	{
		delete v;
	}
	for(auto t : this->tratadores)
	{
		delete t;
	}
	for(auto a : this->animais)
	{
		delete a;
	}
}

void PetFera::cadAnimal()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore to the end of line
	string strClassificacao_;
	classificacao classificacao_;
	char ameacadaExtincao;
	char perigoso;        
	string NF;
	Animal* criado = nullptr;

	// do
	// {
	// 	cout<< "Insira o id do animal: "<<endl;
	// 	cin>>id;
	// 	RETURNIF(id, 0, /*return*/);
	// 	if (this->buscarId(id)!=nullptr)
	// 		cout<< "Erro! ID já cadastrado"<<endl;
	// } while (this->buscarId(id)!=nullptr);
	// std::cin.clear();

	do
	{
		cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
		cin>>strClassificacao_;
		RETURNIF(strClassificacao_, "0", /*return*/);
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
		RETURNIF(ameacadaExtincao, '0', /*return*/);
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
		RETURNIF(perigoso, '0', /*return*/);
		if (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N')
			cout<<"Opção inválida"<<endl;
	} while (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N' );
	std::cin.clear();

	cout<< "Insira a Nota Fiscal, se houver: "<<endl;
	cin>>NF;
	RETURNIF(NF, "0", /*return*/);
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
	criado = new Animal(++this->idAnimal, classificacao_, ameacadaExtincao, perigoso, NF);

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
		cout<<"Insira o id do animal a ser removido."<<std::endl;
		cin>>idRem;
		RETURNIF(idRem, 0, /*return*/);
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
	short idAlter;
	do{
		cout<<"Insira o id do animal a ser alterado:";
		cin>>idAlter;
		RETURNIF(idAlter, '0',);
		if (this->buscarId(idAlter)==nullptr)
			cout<< "Erro! ID não encontrado"<<endl;
	}while(this->buscarId(idAlter)==nullptr);

	string strClassificacao_;
	classificacao classificacao_;
	char ameacadaExtincao;
	char perigoso;        
	string NF;

	do
	{
		cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
		cin>>strClassificacao_;
		RETURNIF(strClassificacao_, "0", /*return*/);
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
		RETURNIF(ameacadaExtincao, '0', /*return*/);
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
		RETURNIF(perigoso, '0', /*return*/);
		if (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N')
			cout<<"Opção inválida"<<endl;
	} while (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N' );
	std::cin.clear();

	cout<< "Insira a Nota Fiscal, se houver: "<<endl;
	cin>>NF;
	RETURNIF(NF, "0", /*return*/);
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

	for(auto a = animais.begin(); a != animais.end(); ++a)
	{
		if((*a)->getId() == idAlter){
			(*a)->setClassificacao(classificacao_);
			(*a)->setAmeacadaExtincao(ameacadaExtincao);
			(*a)->setPerigoso(perigoso);
			(*a)->setNF(NF);

		}
	}
	std::cout<<"Dados alterados com sucesso!"<<std::endl;

	PAUSE;

}

void PetFera::listClass()
{
	if (this->animais.size() == 0)
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
		printMenu("Pet Fera", "Gerenciar cadastros", fGREEN);
		// std::cout << fGREEN << "Pet Fera" << fRESET << " - Menu principal" << std::endl << std::endl;

		std::cout << "V. Cadastrar veterinário." << std::endl;
		std::cout << "A. Alterar dados de um veterinário." << std::endl;
		std::cout << "T. Cadastrar tratador." << std::endl;
		std::cout << "U. Alterar dados de um tratador." << std::endl;
		std::cout << "R. Remover funcinário." << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;

		std::cout << std::endl << "X. Sair" << std::endl;

		std::cin >> opt;

		if(opt == "V" || opt == "v")
		{
			printTitle("Cadastrar veterinário", fGREEN);
			this->cadVetr();
		}
		else if(opt == "R" || opt == "r")
		{
			printTitle("Remover funcionário", fGREEN);
			this->remFunc();
		}
		else if(opt == "A" || opt == "a")
		{
			printTitle("Alterar dados de um veterinário.", fGREEN);
			this->altVetr();
		}
		else if(opt == "T" || opt == "t")
		{
			printTitle("Cadastrar tratador", fGREEN);
			this->cadTrat();
		}
		else if(opt == "U" || opt == "u")
		{
			printTitle("Alterar dados de um tratador.", fGREEN);
			this->altTrat();
		}
		else if(opt == "F" || opt == "f")
		{
			printTitle("Listar funcionários", fGREEN);
			this->listFunc();
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
	RETURNIF(nome, "0", false);

	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		std::cin >> CRMV;
		RETURNIF(CRMV, "0", false);
		if(findCRMV(CRMV) == veterinarios.end())
			break;
		else
			std::cout << "Já existe um veterinário com este número de CRMV cadastrado." << std::endl;
	} while (1);

	Veterinario *vet = new Veterinario(nome, ++this->funcionarios, ativo, CRMV);
	veterinarios.push_back(vet);

	return true;
}

bool PetFera::altVetr()
{
	short id;
	std::string nome;
	std::cout << "Informe o ID do funcionário a ser alterado:" << std::endl;
	std::cin >> id;
	RETURNIF(id, 0, false);

		std::cout << "Insira o nome do veterinário: " << std::endl;
		cin.ignore();
		getline(std::cin, nome);
		RETURNIF(nome, "0", false)
		for(auto v = veterinarios.begin(); v != veterinarios.end(); ++v)
		{
			if((*v)->getId() == id)
			{
				(*v)->setNome(nome);
				return true;
			}
		}		

	return true;
}
std::vector<Veterinario*>::iterator PetFera::findCRMV(std::string CRMV)
{
	for(auto i = veterinarios.begin(); i != veterinarios.end(); ++i)
	{
		if((*i)->getCRMV() == CRMV)
		{
			return i;
		}
	}
	return veterinarios.end();
}

bool PetFera::cadTrat()
{
	Seguranca seg;
	std::string nome, seguranca;

	std::cout << "Insira o nome do tratador: " << std::endl;
	cin.ignore();
	getline(std::cin, nome);
	RETURNIF(nome, "0", false);

	Debug("nome: " << nome << std::endl);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		std::cin >> seguranca;
		RETURNIF(seguranca, "0", false);
		if(seguranca == "VERDE" || seguranca == "verde" || seguranca == "Verde" )
		{
			seg = Verde;
			break;
		}
		else if(seguranca == "AZUL" || seguranca == "azul" || seguranca == "Azul")
		{
			seg = Azul;
			break;
		}
		else if(seguranca == "VERMELHO" || seguranca == "Vermelho" || seguranca == "vermelho")
		{
			seg = Vermelho;
			break;
		}
		else
		{
			std::cout << "Informe um nível de segurança válido." << std::endl;
		}
	} while(1);

	Tratador *tratador = new Tratador(nome, ++this->funcionarios, ativo, seg);
	tratadores.push_back(tratador);

	return true;
}

bool PetFera::altTrat()
{
	short id;
	std::string nome;
	std::string seguranca;
	Seguranca seg;
	std::cout << "Informe o ID do funcionário a ser alterado:" << std::endl;
	std::cin >> id;
	RETURNIF(id, 0, false);

		std::cout << "Insira o nome do tratador: " << std::endl;
		cin.ignore();
		getline(std::cin, nome);
		RETURNIF(nome, "0", false);

			do
			{
				std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
				std::cin >> seguranca;
				RETURNIF(seguranca, "0", false);
				if(seguranca == "VERDE" || seguranca == "verde" || seguranca == "Verde" )
				{
					seg = Verde;
					break;
				}
				else if(seguranca == "AZUL" || seguranca == "azul" || seguranca == "Azul")
				{
					seg = Azul;
					break;
				}
				else if(seguranca == "VERMELHO" || seguranca == "Vermelho" || seguranca == "vermelho")
				{
					seg = Vermelho;
					break;
				}
				else
				{
					std::cout << "Informe um nível de segurança válido." << std::endl;
				}
			} while(1);

		for(auto t = tratadores.begin(); t != tratadores.end(); ++t)
		{
			if((*t)->getId() == id)
			{
				(*t)->setNome(nome);
				(*t)->setSeguranca(seg);
				return true;
			}
		}

	return false;
	
}


bool PetFera::remFunc()
{
	short id;
	std::cout << "Informe o ID do funcionário:" << std::endl;
	std::cin >> id;
	RETURNIF(id, 0, false);
	for(auto v = veterinarios.begin(); v != veterinarios.end(); ++v)
	{
		if((*v)->getId() == id)
		{
			veterinarios.erase(v);
			return true;
		}
	}
	for(auto t = tratadores.begin(); t != tratadores.end(); ++t)
	{
		if((*t)->getId() == id)
		{
			tratadores.erase(t);
			return true;
		}
	}
	return false;
}

void PetFera::listFunc()
{
	std::cout << Color(fYELLOW) << "Veterinários:" << Color(fRESET) << std::endl;
	for(auto i : this->veterinarios)
	{
		std::cout << "ID: " << i->getId() << std::endl;
		std::cout << "NOME: " << i->getNome() << std::endl;
		std::cout << "CRMV: " << i->getCRMV() << std::endl;
		std::cout << std::setfill('*') << std::setw(40) << ""<< std::endl;
	}
	std::cout << std::endl;

	std::cout << Color(fYELLOW) << "Tratadores:" << Color(fRESET) << std::endl;
	for(auto i : this->tratadores)
	{
		std::cout << "ID:" << i->getId() << std::endl;
		std::cout << "NOME: " << i->getNome() << std::endl;
		std::cout << "Nivel de segurança: ";
		std::string Seguranca_;
		if (i->getSeguranca() == Verde){
			Color(fGREEN);
			Seguranca_="Aves";
		}
		else if (i->getSeguranca()==Azul){
			Color(fBLUE);
			Seguranca_="Aves, Mamíferos e Répteis";
		}
		else if (i->getSeguranca()==Vermelho){
			Color(fRED);
			Seguranca_="Animais venenosos ou perigosos";
		}
		std::cout <<Seguranca_<< std::endl;
		Color(fRESET);
		std::cout << std::setfill('*') << std::setw(40) << ""<< std::endl;
	}
	std::cout << std::endl;

	PAUSE;
}

void PetFera::run()
{
	std::string opt;
	do
	{
		CLS;
		printMenu("Pet Fera", "Menu Principal", fGREEN);
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

		if(opt == "C" || opt == "c")
		{
			printTitle("Cadastrar Animal", fGREEN);
			this->cadAnimal();
			cout << "Operação realizada com sucesso." << endl;
		}
		else if(opt == "R" || opt == "r")
		{
			printTitle("Remover um animal", fGREEN);
			this->remAnimal();
		}
		else if(opt == "A" || opt == "a")
		{
			printTitle("Alterar dados de um animal", fGREEN);
			this->altAnimal();

		}
		else if(opt == "L" || opt == "l")
		{
			printTitle("Listar animal ou classe", fGREEN);
			this->listClass();
		}
		else if(opt == "D" || opt == "d")
		{
			printTitle("Listar animais sob responsabilidade", fGREEN);
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