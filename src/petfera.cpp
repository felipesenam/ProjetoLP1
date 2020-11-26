
#include "petfera.hpp"

/**
 * @brief Construtor padrão
*/
PetFera::PetFera()
{}

/**
 * @brief Destrutor padrão
 * @details Desaloca toda a memória alocada por funcionários e animais
*/
PetFera::~PetFera()
{
	for(auto f : this->funcionarios)
	{
		delete f;
	}
	for(auto a : this->animais)
	{
		delete a;
	}
}

/**
 * @brief Interface de cadastro de um Animal
 * @details Recolhe os dados necessários para realizar o cadastro de um animal
*/
void PetFera::cadAnimal()
{
	Classificacao classificacao;
	char ameacadaExtincao, perigoso, cClassificacao, cClasse;        
	std::string NF, especie, extra;
	Classe classe;
	int idt, idv;
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

	do
	{
		std::cout << "Informe a espécie do animal: " << std::endl;
		getline(std::cin, especie);
		RETURNIF(especie, "0", VOIDRETURN);
		if (especie != "")
		{
			break;
		}
		else
		{
			WARN("Este campo não pode ser deixado em branco" << std::endl);
		}
	} while (1);
	
	do
	{
		std::cout << "Insira a classe do animal: A (Anfibio) | B (Ave) | M (Mamífero) | R (Réptil)" << std::endl;
		std::cin >> cClasse; ffBuffer();
		RETURNIF(cClasse, '0', VOIDRETURN);
		if (isany(cClasse, "AaBbMmRr"))
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
		std::cout << "Insira a classificação para manejo: N (Nativo) | E (Exotico) | D (Domestico)" << std::endl;
		std::cin >> cClassificacao; ffBuffer();
		RETURNIF(cClassificacao, '0', VOIDRETURN);
		if (isany(cClassificacao, "Dd"))
		{
			break;
		}
		else if (isany(cClassificacao, "NnEe"))
		{
			if(cClassificacao == 'N' || cClassificacao == 'n')
			{
				do
				{
					std::cout << "Informe a licença de transporte:" << std::endl;
					getline(std::cin, extra);
					RETURNIF(extra, "0", VOIDRETURN);
					if (extra != "")
					{
						break;
					}
					else
					{
						WARN("Este campo não pode ser deixado em branco" << std::endl);
					}
				} while (1);
			}
			else
			{
				do
				{
					std::cout << "Informe o território de origem do animal:" << std::endl;
					getline(std::cin, extra);
					RETURNIF(extra, "0", VOIDRETURN);
					if (extra != "")
					{
						break;
					}
					else
					{
						WARN("Este campo não pode ser deixado em branco" << std::endl);
					}
				} while (1);
			}
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);

	classificacao = nativo;
	if (cClassificacao == 'E' || cClassificacao == 'e')
	{
		classificacao = exotico;
	}
	else if (cClassificacao == 'D' || cClassificacao == 'd')
	{
		classificacao = domestico;
	} 

	classe = anfibio;
	if (cClasse == 'B' || cClasse == 'b')
	{
		classe = ave;
	}
	else if (cClasse == 'R' || cClasse == 'r')
	{
		classe = reptil;
	}
	else if (cClasse == 'M' || cClasse == 'm')
	{
		classe = mamifero;
	}

	do
	{
		std::cout << "O animal possui algum grau de extinção? S (Sim) | N (Não)" << std::endl;
		std::cin >> ameacadaExtincao; ffBuffer();
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
		std::cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << std::endl;
		std::cin >> perigoso; ffBuffer();
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
		std::cout << "Insira o ID do tratador do animal" << std::endl;
		std::cin >> idt; ffBuffer();
		RETURNIF(idt, 0, VOIDRETURN);
		if ((tratador = dynamic_cast<Tratador*>(buscaFunc(idt))) != nullptr)
		{
			if(tratador->aptto(classe, perigoso))
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
				WARN("Este tratador não está apto a tratar deste animal" << std::endl);
			}
		}
		else
		{
			WARN("Funcionário não encontrado ou não se encaixa na posição de tratador" << std::endl);
		}
	} while (1);

	do
	{
		std::cout << "Insira o ID do veterinário do animal" << std::endl;
		std::cin >> idv; ffBuffer();
		RETURNIF(idv, 0, VOIDRETURN);
		if ((veterinario = dynamic_cast<Veterinario*>(buscaFunc(idv))) != nullptr)
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

	std::cout << "Insira a Nota Fiscal, se houver: " << std::endl;
	getline(std::cin, NF);
	RETURNIF(NF, "0", VOIDRETURN);

	cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);

	PAUSE;
}

/**
 * @brief Realiza o cadastro de um Animal
 * @details Recebe os dados cadastrais de um animal e o insere no catálogo de animais da PetFera
 * @param especie :: Especifica a espécie do animal
 * @param classe :: Informa a classe na qual o animal se encaixa (anfíbio, ave, mamífero ou réptil)
 * @param classificacao :: Informa a classificação do animal (doméstico, nativo ou exótico)
 * @param ameacadaExtincao :: Informa se o animal está em risco de extinção
 * @param perigoso :: Informa se o animal é perigoso
 * @param NF :: Nota fiscal do animal
 * @param tratador :: Informa o tratador ao qual o animal está associado
 * @param veterinario :: Informa o veterinário ao qual o animal está associado
 * @param extra :: Caso o animal seja do tipo nativo ou exótico, serão exigidos dados extras que dizem respeito ao porte legal e país de origem do mesmo.
 * @return Retorna um apontador ao animal recém-cadastrado
*/
Animal* PetFera::cadAnimal(std::string especie, Classe classe, Classificacao classificacao, char ameacadaExtincao, char perigoso, std::string NF, Tratador* tratador, Veterinario* veterinario, std::string extra)
{
	Animal* animal = nullptr;

	if(classificacao == domestico)
	{
		if(classe == anfibio)
		{
			animal = new Anfibio(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == ave)
		{
			animal = new Ave(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == mamifero)
		{
			animal = new Mamifero(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == reptil)
		{
			animal = new Reptil(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF);
		}
	}
	else if(classificacao == exotico)
	{
		if(classe == anfibio)
		{
			animal = new AnfibioExotico(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == ave)
		{
			animal = new AveExotico(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == mamifero)
		{
			animal = new MamiferoExotico(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == reptil)
		{
			animal = new ReptilExotico(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
	}
	else if(classificacao == nativo)
	{
		if(classe == anfibio)
		{
			animal = new AnfibioNativo(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == ave)
		{
			animal = new AveNativo(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == mamifero)
		{
			animal = new MamiferoNativo(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == reptil)
		{
			animal = new ReptilNativo(especie, animais.size() + 1, ameacadaExtincao, perigoso, NF, extra);
		}
	}

	this->animais.push_back(animal);

	animal->setTratador(tratador);       // Futuramente pode vir a ser passado pelo construtor
	animal->setVeterinario(veterinario); // Futuramente pode vir a ser passado pelo construtor

	return animal;
}

/**
 * @brief Interface de remoção de um Animal
 * @details Recolhe os dados necessários para que o animal seja removido do catálogo
*/
void PetFera::remAnimal()
{
	Animal* animal = nullptr;
	int idRem;
	do
	{
		std::cout << "Insira o ID do animal a ser removido." << std::endl;
		std::cin >> idRem; ffBuffer();
		RETURNIF(idRem, 0, VOIDRETURN);
		if((animal = buscarAnim(idRem)) != nullptr)
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

/**
 * @brief Remove um Animal da loja
 * @details Recebe o id de um animal da PetFera e o retira do catálogo
 * @param id :: Informa o número de identificação do animal
 * @return Retorna um valor booleano referente ao sucesso da operação
*/
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

/**
 * @brief Interface de alteração dos dados cadastrais do Animal
*/
void PetFera::altAnimal()
{
	short idAlter;
	do
	{
		std::cout << "Insira o id do animal a ser alterado: ";
		std::cin >> idAlter; ffBuffer();
		RETURNIF(idAlter, '0', VOIDRETURN);
		if (this->buscarAnim(idAlter) == nullptr)
		{
			std::cout << "Erro! ID não encontrado" << std::endl;
		}
		else
		{
			break;
		}
	}while(1);

	std::string strClassificacao_;
	char ameacadaExtincao;
	char perigoso;
	std::string NF;

	do
	{
		std::cout << "O animal possui algum grau de extinção? S (sim) / N (não)" << std::endl;
		std::cin >> ameacadaExtincao; ffBuffer();
		RETURNIF(ameacadaExtincao, '0', VOIDRETURN);
		if (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N')
			std::cout << "Opção inválida" << std::endl;
	} while (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N' );
	std::cin.clear();

	do
	{
		std::cout << "O animal é considerado perigoso ou venenoso? S (sim) / N (não) " << std::endl;
		std::cin >> perigoso; ffBuffer();
		RETURNIF(perigoso, '0', VOIDRETURN);
		if (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N')
			std::cout << "Opção inválida" << std::endl;
	} while (perigoso != 's' && perigoso != 'S'
		&& perigoso != 'n' && perigoso != 'N' );
	std::cin.clear();

	std::cout << "Insira a Nota Fiscal, se houver: " << std::endl;
	std::cin >> NF; ffBuffer();
	RETURNIF(NF, "0", VOIDRETURN);
	std::cin.clear();

	for(auto a = animais.begin(); a != animais.end(); ++a)
	{
		if((*a)->getId() == idAlter)
		{
			(*a)->setAmeacadaExtincao(ameacadaExtincao);
			(*a)->setPerigoso(perigoso);
			(*a)->setNF(NF);
		}
	}
	std::cout << "Dados alterados com sucesso!" << std::endl;

	PAUSE;
}

/**
 * @brief Menu de listagem de animais
 * @details Providencia um menu com algumas das operações de listagem de animais
*/
void PetFera::listAnimal()
{
	std::string opt;
	do
	{
		CLS;
		printMenu("Pet Fera", "Imprimir Animais", fGREEN);

		std::cout << "A. Imprimir todos os animais" << std::endl;
		std::cout << "E. Imprimir um animal especifico" << std::endl;
		std::cout << "C. Listar todos os animais de uma classe" << std::endl;

		std::cout << std::endl << "X. Voltar" << std::endl;

		std::cin >> opt; ffBuffer();

		if(opt == "A" || opt == "a")
		{
			printTitle("Imprimir todos os animais", fGREEN);
			this->listAll();
		}
		else if(opt == "E" || opt == "e")
		{
			printTitle("Imprimir um animal especifico", fGREEN);
			this->listId();
		}
		else if(opt == "C" || opt == "c")
		{
			printTitle("Listar todos os animais de uma classe", fGREEN);
			this->listClass();
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
	}while(1);
}

/**
 * @brief Lista todos os animais cadastrados
*/

void PetFera::listAll()
{

	if (this->animais.size() == 0)
	{
		std::cout << "Não há animais cadastrados." << std::endl;
	}
	else
	{
		for (auto animal : this->animais)
		{
			std::cout << (*animal) << std::endl;
		}
	}
	PAUSE;
}

/**
 * @brief Lista um animal pelo numero do ID
*/
void PetFera::listId()
{
	short id;
	std::cout << "Informe o id do animal a ser impresso: " << std::endl;
	std::cin>>id;
	if (buscarAnim(id)==nullptr)
	{
		WARN("Animal não encontrado" << std::endl);
	}
	else
	{
		for (auto a : this->animais)
		{
			if (a->getId()==id)
				std::cout<< (*a) << std::endl;
		}
		PAUSE;
	}

}

/**
 * @brief Lista os animais de determinada classe (AINDA NÃO IMPLEMENTADO)
*/
void PetFera::listClass()
{
	Classe classe;
	Classificacao classificacao;
	char cClassificacao, cClasse;
	
	if (this->animais.size() == 0)
	{
		std::cout << "Não há animais cadastrados." << std::endl;
		return;
	}
	do
	{
		std::cout << "Insira a classe do animal: A (Anfibio) | B (Ave) | M (Mamífero) | R (Réptil)" << std::endl;
		std::cin >> cClasse; ffBuffer();
		RETURNIF(cClasse, '0', VOIDRETURN);
		if (isany(cClasse, "AaBbMmRr"))
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
		std::cout << "Insira a classificação para manejo: N (Nativo) | E (Exotico) | D (Domestico)" << std::endl;
		std::cin >> cClassificacao; ffBuffer();
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

	classificacao = nativo;
	if (cClassificacao == 'E' || cClassificacao == 'e')
	{
		classificacao = exotico;
	}
	else if (cClassificacao == 'D' || cClassificacao == 'd')
	{
		classificacao = domestico;
	} 

	classe = anfibio;
	if (cClasse == 'B' || cClasse == 'b')
	{
		classe = ave;
	}
	else if (cClasse == 'R' || cClasse == 'r')
	{
		classe = reptil;
	}
	else if (cClasse == 'M' || cClasse == 'm')
	{
		classe = mamifero;
	}

	if(classificacao == domestico)
	{
		if(classe == anfibio)
		{
			printTitle("Lista de anfíbios domésticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<Anfibio*>(a);
				if(animal && !dynamic_cast<Nativo*>(a) && !dynamic_cast<Exotico*>(a))
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == ave)
		{
			printTitle("Lista de aves domésticas", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<Ave*>(a);
				if(animal && !dynamic_cast<Nativo*>(a) && !dynamic_cast<Exotico*>(a))
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == mamifero)
		{
			printTitle("Lista de mamíferos domésticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<Mamifero*>(a);
				if(animal && !dynamic_cast<Nativo*>(a) && !dynamic_cast<Exotico*>(a))
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == reptil)
		{
			printTitle("Lista de répteis domésticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<Reptil*>(a);
				if(animal && !dynamic_cast<Nativo*>(a) && !dynamic_cast<Exotico*>(a))
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
	}
	else if(classificacao == exotico)
	{
		if(classe == anfibio)
		{
			printTitle("Lista de anfíbios exóticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<AnfibioExotico*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == ave)
		{
			printTitle("Lista de aves exóticas", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<AveExotico*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == mamifero)
		{
			printTitle("Lista de mamíferos exóticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<MamiferoExotico*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == reptil)
		{
			printTitle("Lista de répteis exóticos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<ReptilExotico*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
	}
	else if(classificacao == nativo)
	{
		if(classe == anfibio)
		{
			printTitle("Lista de anfíbios nativos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<AnfibioNativo*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == ave)
		{
			printTitle("Lista de aves nativas", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<AveNativo*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == mamifero)
		{
			printTitle("Lista de mamíferos nativos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<MamiferoNativo*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
		else if (classe == reptil)
		{
			printTitle("Lista de répteis nativos", fGREEN);
			for(auto a : animais)
			{
				Animal* animal = dynamic_cast<ReptilNativo*>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
				}
			}
		}
	}
	WARN("- Fim -" << std::endl);
	PAUSE;
}

/**
 * @brief Lista os animais sob responsabilidade de algum Funcionario
*/
void PetFera::listRespn()
{
	Funcionario* funcionario = nullptr;
	short id;
	do
	{
		std::cout << "Informe o ID do funcionário" << std::endl;
		std::cin >> id; ffBuffer();
		RETURNIF(id, 0, VOIDRETURN);
		if(buscaFunc(id) == nullptr)
		{
			WARN("Funcionário não encontrado." << std::endl);
		}
		else
		{
			break;
		}
	}while(1);
	funcionario = buscaFunc(id);
	std::cout << "Listando animais sob responsabilidade de " << funcionario->getNome() << ": " << std::endl << std::endl;
	for(auto a : animais)
	{
		if(a->getTratador() == funcionario || a->getVeterinario() == funcionario)
		{
			std::cout << (*a) << std::endl;
		}
	}
	PAUSE;
}


/**
 * @brief Menu de gerenciamento de cadastro
 * @details Providencia um menu com todas as operações de funcionários da PetFera
*/
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

		std::cin >> opt; ffBuffer();

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
 * @brief Busca um Animal no catálogo
 * @param id :: id referente ao animal
 * @return Retorna um ponteiro para o animal ou nullptr caso não seja encontrado
*/
Animal* PetFera::buscarAnim(int id)
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

/**
 * @brief Interface de cadastro de um Veterinario
 * @details Recolhe os dados necessários para realizar o cadastro de um veterinario
*/
void PetFera::cadVetr()
{
	std::string nome, CRMV;

	std::cout << "Insira o nome do veterinário: " << std::endl;
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		std::cin >> CRMV; ffBuffer();
		RETURNIF(CRMV, "0", VOIDRETURN);
		if(findCRMV(CRMV) == funcionarios.end())
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

/**
 * @brief Realiza o cadastro de um Veterinario
 * @details Recebe os dados cadastrais de um veterinário e o torna funcionário da PetFera
 * @param nome :: Informa o nome do veterinário
 * @param status :: Informa o status do veterinário (ativo | inativo)
 * @param CRMV :: Informa o CRMV do veterinário
 * @return Retorna um apontador ao veterinário recém-cadastrado
*/
Veterinario* PetFera::cadVetr(std::string nome, Status status, std::string CRMV)
{
	Veterinario* vet = new Veterinario(nome, funcionarios.size() + 1, status, CRMV);
	funcionarios.push_back(vet);

	return vet;
}

/**
 * @brief Altera os dados cadastrais de um Veterinario
*/
void PetFera::altVetr()
{
	short id;
	std::string nome;
	std::cout << "Informe o ID do funcionário a ser alterado:" << std::endl;
	std::cin >> id; ffBuffer();
	RETURNIF(id, 0, VOIDRETURN);

	std::cout << "Insira o nome do veterinário: " << std::endl;
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN)
	for(auto v = funcionarios.begin(); v != funcionarios.end(); ++v)
	{
		if((*v)->getId() == id)
		{
			(*v)->setNome(nome);
			return;
		}
	}
}

/**
 * @brief Realiza a busca de um Veterinario pelo CRMV
 * @param CRMV :: CRMV referente ao veterinário
 * @return Retorna um iterador do vetor de funcionários referente ao veterinário
*/
std::vector<Funcionario*>::iterator PetFera::findCRMV(std::string CRMV)
{
	Veterinario* veterinario;
	for(auto i = funcionarios.begin(); i != funcionarios.end(); ++i)
	{
		veterinario = dynamic_cast<Veterinario*>(*i);
		if(veterinario != nullptr && veterinario->getCRMV() == CRMV)
		{
			return i;
		}
	}
	return funcionarios.end();
}

/**
 * @brief Interface de cadastro de um Tratador
 * @details Recolhe os dados necessários para realizar o cadastro de um tratador
*/
void PetFera::cadTrat()
{
	Seguranca seg;
	std::string nome, seguranca;

	std::cout << "Insira o nome do tratador: " << std::endl;
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		std::cin >> seguranca; ffBuffer();
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

/**
 * @brief Realiza o cadastro de um Tratador
 * @details Recebe os dados cadastrais de um tratador e o torna funcionário da PetFera
 * @param nome :: Informa o nome do tratador
 * @param status :: Informa o status do tratador (ativo | inativo)
 * @param seg :: Informa o nível de segurança indicando quais animais ele pode tratar
 * @return Retorna um apontador ao tratador recém-cadastrado
*/
Tratador* PetFera::cadTrat(std::string nome, Status status, Seguranca seg)
{
	Tratador *tratador = new Tratador(nome, funcionarios.size() + 1, status, seg);
	funcionarios.push_back(tratador);

	return tratador;
}

/**
 * @brief Altera os dados cadastrais de um Tratador
*/
void PetFera::altTrat()
{
	short id;
	std::string nome;
	std::string seguranca;
	Seguranca seg;
	std::cout << "Informe o ID do funcionário a ser alterado:" << std::endl;
	std::cin >> id; ffBuffer();
	RETURNIF(id, 0, VOIDRETURN);

	std::cout << "Insira o nome do tratador: " << std::endl;
	getline(std::cin, nome);
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		std::cin >> seguranca; ffBuffer();
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
			std::cout << "Informe um nível de segurança válido." << std::endl;
		}
	} while(1);

	for(auto t = funcionarios.begin(); t != funcionarios.end(); ++t)
	{
		if((*t)->getId() == id)
		{
			(*t)->setNome(nome);
			static_cast<Tratador*>(*t)->setSeguranca(seg);
			return;
		}
	}
}

/**
 * @brief Cadastra um Funcionario
 * @details Realiza o cadastro de um funcionário preexistente
 * @param funcionario :: Ponteiro para um funcionário
 * @return Retorna um apontador para o funcionário recém-cadastrado
*/
Funcionario* PetFera::cadFunc(Funcionario* funcionario)
{
	funcionarios.push_back(funcionario);

	return funcionario;
}

/**
 * @brief Busca um Funcionario na PetFera
 * @param id :: id referente ao funcionário
 * @return  Retorna um ponteiro para o funcionário ou nullptr caso não seja encontrado
*/
Funcionario* PetFera::buscaFunc(int id)
{
	for(auto f : funcionarios)
	{
		if(f->getId() == id)
		{
			return f;
		}
	}
	return nullptr;
}

/**
 * @brief Remove um Funcionario da loja
 * @details Recolhe os dados necessários para que o funcionário seja removido do catálogo
 * @return Retorna um valor booleano referente ao sucesso da operação
*/
bool PetFera::remFunc()
{
	short id;
	std::cout << "Informe o ID do funcionário:" << std::endl;
	std::cin >> id; ffBuffer();
	RETURNIF(id, 0, false);
	for(auto t = funcionarios.begin(); t != funcionarios.end(); ++t)
	{
		if((*t)->getId() == id)
		{
			std::cout << "O funcionário " << (*t)->getNome() << " foi desvinculado da loja." << std::endl;
			delete (*t);
			funcionarios.erase(t);
			PAUSE;
			return true;
		}
	}

	return false;
}

/**
 * @brief Lista todos os funcionários da PetFera
*/
void PetFera::listFunc()
{
	std::cout << Color(fCYAN) << "Veterinários:" << Color(fRESET) << std::endl;
	for(auto f : funcionarios)
	{
		if(dynamic_cast<Veterinario*>(f))
		{
			std::cout << f << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << Color(fCYAN) << "Tratadores:" << Color(fRESET) << std::endl;
	for(auto f : funcionarios)
	{
		if(dynamic_cast<Tratador*>(f))
		{
			std::cout << f << std::endl;
		}
	}
	std::cout << std::endl;

	PAUSE;
}

/**
 * @brief Menu principal
 * @details Providencia um menu com algumas das operações realizadas na PetFera
*/
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

		std::cin >> opt; ffBuffer();

		if(opt == "C" || opt == "c")
		{
			printTitle("Cadastrar Animal", fGREEN);
			this->cadAnimal();
			std::cout << "Operação realizada com sucesso." << std::endl;
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
			this->listAnimal();
		}
		else if(opt == "D" || opt == "d")
		{
			printTitle("Listar animais sob responsabilidade", fGREEN);
			this->listRespn();
		}
		else if(opt == "G" || opt == "g")
		{
			this->gerCad();
		}
		else if(opt == "F" || opt == "f")
		{
			printTitle("Lista de funcionários", fGREEN);
			this->listFunc();
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}


	}while(1);
}
