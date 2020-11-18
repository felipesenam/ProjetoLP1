
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
	Classificacao classificacao;
	char ameacadaExtincao, perigoso, cClassificacao;        
	std::string NF, especie;
	int idt, idv;
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

	cout << "Informe a espécie do animal: " << endl;
	cin >> especie; ffBuffer();
	RETURNIF(especie, "0", VOIDRETURN);

	do
	{
		cout << "Insira a classificação para manejo: N (Nativo) | E (Exotico) | D (Domestico)" << endl;
		cin >> cClassificacao; ffBuffer();
		RETURNIF(cClassificacao, '0', VOIDRETURN);
		if (isany(cClassificacao, "NnEeDd"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);

	do
	{
		cout << "O animal possui algum grau de extinção? S (Sim) | N (Não)" << endl;
		cin >> ameacadaExtincao; ffBuffer();
		RETURNIF(ameacadaExtincao, '0', VOIDRETURN);
		if (isany(ameacadaExtincao, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);

	do
	{
		cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << endl;
		cin >> perigoso; ffBuffer();
		RETURNIF(perigoso, '0', VOIDRETURN);
		if (isany(perigoso, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);

	do
	{
		cout << "Insira o ID do tratador do animal" << endl;
		cin >> idt; ffBuffer();
		RETURNIF(idt, 0, VOIDRETURN);
		if ((tratador = buscaTrat(idt)) != nullptr)
		{
			char opt;
			std::cout << "Associar " << tratador->getNome() << " como tratador deste animal? S - Sim | N - Não" << std::endl;
			std::cin >> opt; ffBuffer();
			RETURNIF(opt, 0, VOIDRETURN);
			if(opt == 'S' || opt == 's')
			{
				break;	
			}
		}
		else
		{
			WARN("Funcionário não encontrado ou não se encaixa na posição de tratador" << std::endl);
		}
	} while (1);

	do
	{
		cout << "Insira o ID do veterinário do animal" << endl;
		cin >> idv; ffBuffer();
		RETURNIF(idv, 0, VOIDRETURN);
		if ((veterinario = buscaVetr(idv)) != nullptr)
		{
			char opt;
			std::cout << "Associar " << veterinario->getNome() << " como veterinario deste animal? S - Sim | N - Não" << std::endl;
			std::cin >> opt; ffBuffer();
			RETURNIF(opt, 0, VOIDRETURN);
			if(opt == 'S' || opt == 's')
			{
				break;	
			}
		}
		else
		{
			WARN("Funcionário não encontrado ou não se encaixa na posição de veterinário" << std::endl);
		}
	} while (1);

	cout << "Insira a Nota Fiscal, se houver: " << endl;
	cin >> NF; ffBuffer();
	RETURNIF(NF, "0", VOIDRETURN);

	classificacao = nativo;
	if (cClassificacao == 'E' || cClassificacao == 'e')
	{
		classificacao = exotico;
	}
	else if (cClassificacao == 'D' || cClassificacao == 'd')
	{
		classificacao = domestico;
	} 

	cadAnimal(especie, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario);

	PAUSE;
}
Animal* PetFera::cadAnimal(std::string especie, Classificacao classificacao, char ameacadaExtincao, char perigoso, string NF, Tratador* tratador, Veterinario* veterinario)
{
	Animal* animal = new Animal(especie, ++this->idAnimal, classificacao, ameacadaExtincao, perigoso, NF);
	this->animais.push_back(animal);

	animal->setTratador(tratador);       // Futuramente pode vir a ser passado pelo construtor
	animal->setVeterinario(veterinario); // Futuramente pode vir a ser passado pelo construtor

	return animal;
}

void PetFera::remAnimal()
{
	Animal* animal = nullptr;
	int idRem;
	do
	{
		cout << "Insira o ID do animal a ser removido." << std::endl;
		cin >> idRem; ffBuffer();
		RETURNIF(idRem, 0, VOIDRETURN);
		if((animal = buscarId(idRem)) != nullptr)
		{
			char opt;
			std::cout << "Remover " << animal->getEspecie() << "? S (Sim) | N (Não)" << std::endl;
			std::cin >> opt; ffBuffer();
			RETURNIF(opt, 0, VOIDRETURN);
			if(opt == 'S' || opt == 's')
			{
				break;	
			}
		}
		else
		{
			WARN("Animal não encontrado." << std::endl);
		}
	} while (1);

	remAnimal(idRem);
	
	PAUSE;
}
bool PetFera::remAnimal(int id)
{
	for(auto a = this->animais.begin(); a != this->animais.end(); ++a)
	{
		if ((*a)->getId() == id)
		{
			delete (*a);
			this->animais.erase(a);
			return true;
		}
	}
	return false;
}

void PetFera::altAnimal() //PRECISA REFORMULAR
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
	Classificacao classificacao;
	char ameacadaExtincao;
	char perigoso;
	string NF;

	do
	{
		cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
		cin>>strClassificacao_;
		RETURNIF(strClassificacao_, "0", VOIDRETURN);
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
		RETURNIF(ameacadaExtincao, '0', VOIDRETURN);
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
		RETURNIF(perigoso, '0', VOIDRETURN);
		if (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N')
			cout<<"Opção inválida"<<endl;
	} while (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N' );
	std::cin.clear();

	cout<< "Insira a Nota Fiscal, se houver: "<<endl;
	cin>>NF;
	RETURNIF(NF, "0", VOIDRETURN);
	std::cin.clear();
	classificacao=nativo;

	if (strClassificacao_=="E" || strClassificacao_=="e")
	{
		classificacao = exotico;
	}
	else if (strClassificacao_=="D" || strClassificacao_=="d")
	{
		classificacao = domestico;
	} 

	for(auto a = animais.begin(); a != animais.end(); ++a)
	{
		if((*a)->getId() == idAlter){
			(*a)->setClassificacao(classificacao);
			(*a)->setAmeacadaExtincao(ameacadaExtincao);
			(*a)->setPerigoso(perigoso);
			(*a)->setNF(NF);

		}
	}
	std::cout<<"Dados alterados com sucesso!"<<std::endl;

	PAUSE;
}

void PetFera::listClass() //PRECISA REFORMULAR
{
	if (this->animais.size() == 0)
	{
		cout << "Não há animais cadastrados." << endl;
	}
	else
	{
		for (auto& animal : this->animais)
		{
			cout << (*animal) << endl;
		}
	}
	PAUSE;
}

void PetFera::listRespn() //PRECISA REFORMULAR
{

}

void PetFera::gerCad()
{
	std::string opt;
	do
	{
		CLS;
		printMenu("Pet Fera", "Gerenciar cadastros", fGREEN);

		std::cout << "V. Cadastrar veterinário." << std::endl;
		std::cout << "A. Alterar dados de um veterinário." << std::endl;
		std::cout << "T. Cadastrar tratador." << std::endl;
		std::cout << "U. Alterar dados de um tratador." << std::endl;
		std::cout << "R. Remover funcinário." << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;

		std::cout << std::endl << "X. Voltar" << std::endl;

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

void PetFera::cadVetr()
{
	std::string nome, CRMV;

	std::cout << "Insira o nome do veterinário: " << std::endl;
	cin.ignore();
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		std::cin >> CRMV;
		RETURNIF(CRMV, "0", VOIDRETURN);
		if(findCRMV(CRMV) == veterinarios.end())
		{
			break;
		}
		else
		{
			WARN("Já existe um veterinário com este número de CRMV cadastrado." << std::endl);
		}
	} while (1);

	cadVetr(nome, Status::ativo, CRMV);

}
Veterinario* PetFera::cadVetr(std::string nome, Status status, std::string CRMV)
{
	Veterinario* vet = new Veterinario(nome, ++this->funcionarios, status, CRMV);
	veterinarios.push_back(vet);

	return vet;
}
Veterinario* PetFera::cadVetr(Veterinario* vet)
{
	veterinarios.push_back(vet);
	++this->funcionarios;

	return vet;
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

void PetFera::cadTrat()
{
	Seguranca seg;
	std::string nome, seguranca;

	std::cout << "Insira o nome do tratador: " << std::endl;
	cin.ignore();
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		std::cin >> seguranca;
		RETURNIF(seguranca, "0", VOIDRETURN);
		if(seguranca == "VERDE" || seguranca == "verde" || seguranca == "Verde" )
		{
			seg = verde;
			break;
		}
		else if(seguranca == "AZUL" || seguranca == "azul" || seguranca == "Azul")
		{
			seg = azul;
			break;
		}
		else if(seguranca == "VERMELHO" || seguranca == "Vermelho" || seguranca == "vermelho")
		{
			seg = vermelho;
			break;
		}
		else
		{
			WARN("Informe um nível de segurança válido." << std::endl);
		}
	} while(1);

	cadTrat(nome, Status::ativo, seg);
}
Tratador* PetFera::cadTrat(std::string nome, Status status, Seguranca seg)
{
	Tratador *tratador = new Tratador(nome, ++this->funcionarios, status, seg);
	tratadores.push_back(tratador);

	return tratador;
}
Tratador* PetFera::cadTrat(Tratador* tratador)
{
	tratadores.push_back(tratador);
	++this->funcionarios;

	return tratador;
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
					seg = verde;
					break;
				}
				else if(seguranca == "AZUL" || seguranca == "azul" || seguranca == "Azul")
				{
					seg = azul;
					break;
				}
				else if(seguranca == "VERMELHO" || seguranca == "Vermelho" || seguranca == "vermelho")
				{
					seg = vermelho;
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
Veterinario* PetFera::buscaVetr(int id)
{
	for(auto v : veterinarios)
	{
		if(v->getId() == id)
		{
			return v;
		}
	}
	return nullptr;
}
Tratador* PetFera::buscaTrat(int id)
{
	for(auto t : tratadores)
	{
		if(t->getId() == id)
		{
			return t;
		}
	}
	return nullptr;
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
			std::cout << "O funcionário " << (*v)->getNome() << " foi desvinculado da loja." << std::endl;
			delete (*v);
			veterinarios.erase(v);
			PAUSE;
			return true;
		}
	}
	for(auto t = tratadores.begin(); t != tratadores.end(); ++t)
	{
		if((*t)->getId() == id)
		{
			std::cout << "O funcionário " << (*t)->getNome() << " foi desvinculado da loja." << std::endl;
			delete (*t);
			tratadores.erase(t);
			PAUSE;
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
		if (i->getSeguranca() == verde){
			Color(fGREEN);
			Seguranca_="Aves";
		}
		else if (i->getSeguranca() == azul){
			Color(fBLUE);
			Seguranca_="Aves, Mamíferos e Répteis";
		}
		else if (i->getSeguranca() == vermelho){
			Color(fRED);
			Seguranca_="Animais venenosos ou perigosos";
		}
		std::cout << Seguranca_ << std::endl;
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
