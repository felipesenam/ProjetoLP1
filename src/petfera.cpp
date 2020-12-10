
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
	for(auto& f : this->funcionarios)
	{
		delete f.second;
	}
	for(auto& a : this->animais)
	{
		delete a;
	}
}

void PetFera::load()
{
	std::ifstream file("pet_fera.persistency.txt");
	std::string line, data;

	
	while(!getline(file, line).eof() && line != "")
	{
		std::istringstream oss(line);
		int id;
		std::string nome, CRMV;
		Status status;

		getline(oss, data, ';');
		id = atoi(data.c_str());
		getline(oss, nome, ';');
		getline(oss, data, ';');
		status = static_cast<Status>(atoi(data.c_str()));
		getline(oss, CRMV, ';');

		cadVetr(nome, status, CRMV, id);
	}

	while(!getline(file, line).eof() && line != "")
	{
		std::istringstream oss(line);
		int id;
		std::string nome;
		Status status;
		Seguranca seg;

		getline(oss, data, ';');
		id = atoi(data.c_str());
		getline(oss, nome, ';');
		getline(oss, data, ';');
		status = static_cast<Status>(atoi(data.c_str()));
		getline(oss, data, ';');
		seg = static_cast<Seguranca>(atoi(data.c_str()));

		cadTrat(nome, status, seg, id);
	}

	while(!getline(file, line).eof() && line != "")
	{
		std::istringstream oss(line);
		int id;
		Classificacao classificacao;
		bool ameacadaExtincao = false, perigoso = false;
		std::string NF, especie, extra;
		Classe classe;
		Tratador* tratador = nullptr;
		Veterinario* veterinario = nullptr;

		getline(oss, data, ';');
		id = atoi(data.c_str());
		getline(oss, especie, ';');
		getline(oss, data, ';');
		classe = static_cast<Classe>(atoi(data.c_str()));
		getline(oss, data, ';');
		classificacao = static_cast<Classificacao>(atoi(data.c_str()));
		getline(oss, data, ';');
		ameacadaExtincao = atoi(data.c_str());
		getline(oss, data, ';');
		perigoso = atoi(data.c_str());
		getline(oss, NF, ';');
		getline(oss, data, ';');
		tratador = dynamic_cast<Tratador*>(buscaFunc(atoi(data.c_str())));
		getline(oss, data, ';');
		veterinario = dynamic_cast<Veterinario*>(buscaFunc(atoi(data.c_str())));
		getline(oss, extra, ';');

		cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra)->forceId(id);
	}
}

void PetFera::save()
{
	std::ofstream file("pet_fera.persistency.txt");

	for(const auto& veterinario : this->funcionarios)
	{
		if(dynamic_cast<Veterinario*>(veterinario.second) != nullptr)
			file << *veterinario.second << std::endl;
	}
	file << std::endl;
	
	for(const auto& tratador : this->funcionarios)
	{
		if(dynamic_cast<Tratador*>(tratador.second) != nullptr)
			file << *tratador.second << std::endl;
	}
	file << std::endl;
	
	for(const auto& animal : this->animais)
	{
		file << *animal << std::endl;
	}
}

/**
 * @brief Interface de cadastro de um Animal
 * @details Recolhe os dados necessários para realizar o cadastro de um animal
*/
void PetFera::cadAnimal()
{
	Classificacao classificacao;
	bool ameacadaExtincao = false, perigoso = false;
	char cClassificacao, cClasse, cAmeacadaExtincao, cPerigoso;        
	std::string NF, especie, extra;
	Classe classe;
	int idt, idv;
	Tratador* tratador = nullptr;
	Veterinario* veterinario = nullptr;

	do
	{
		std::cout << "Informe a espécie do animal: " << std::endl;
		USERENTRY( getline(std::cin, especie) );
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
		USERENTRY(collect<char>(cClasse));
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
		USERENTRY(collect<char>(cClassificacao));
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
					USERENTRY( getline(std::cin, extra) );
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
					USERENTRY( getline(std::cin, extra) );
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
		USERENTRY(collect<char>(cAmeacadaExtincao));
		RETURNIF(cAmeacadaExtincao, '0', VOIDRETURN);
		if (isany(cAmeacadaExtincao, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);
	ameacadaExtincao = isany(cAmeacadaExtincao, "Ss");
	
	do
	{
		std::cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << std::endl;
		USERENTRY(collect<char>(cPerigoso));
		RETURNIF(cPerigoso, '0', VOIDRETURN);
		if (isany(cPerigoso, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);
	perigoso = isany(cPerigoso, "Ss");

	do
	{
		std::cout << "Insira o ID do tratador do animal" << std::endl;
		USERENTRY(collect<int>(idt));
		RETURNIF(idt, 0, VOIDRETURN);
		if ((tratador = dynamic_cast<Tratador*>(buscaFunc(idt))) != nullptr)
		{
			if(tratador->aptto(classe, perigoso))
			{
				char opt;
				std::cout << "Associar " << tratador->getNome() << " como tratador deste animal? S - Sim | N - Não" << std::endl;
				USERENTRY(collect<char>(opt));
				RETURNIF(opt, '0', VOIDRETURN);
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
		USERENTRY(collect<int>(idv));
		RETURNIF(idv, 0, VOIDRETURN);
		if ((veterinario = dynamic_cast<Veterinario*>(buscaFunc(idv))) != nullptr)
		{
			char opt;
			std::cout << "Associar " << veterinario->getNome() << " como veterinario deste animal? S - Sim | N - Não" << std::endl;
			USERENTRY(collect<char>(opt));
			RETURNIF(opt, '0', VOIDRETURN);
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
	USERENTRY( getline(std::cin, NF) );
	RETURNIF(NF, "0", VOIDRETURN);

	cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);
	this->save();

	FINALLY("Animal adicionado com sucesso" << std::endl);
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
Animal* PetFera::cadAnimal(std::string especie, Classe classe, Classificacao classificacao, bool ameacadaExtincao, bool perigoso, std::string NF, Tratador* tratador, Veterinario* veterinario, std::string extra)
{
	Animal* animal = nullptr;
	short cid = 1;
	if(animais.size() > 0)
	{
		cid = (*--animais.end())->getId() + 1;
	}

	if(classificacao == domestico)
	{
		if(classe == anfibio)
		{
			animal = new Anfibio(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == ave)
		{
			animal = new Ave(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == mamifero)
		{
			animal = new Mamifero(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF);
		}
		else if (classe == reptil)
		{
			animal = new Reptil(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF);
		}
	}
	else if(classificacao == exotico)
	{
		if(classe == anfibio)
		{
			animal = new AnfibioExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == ave)
		{
			animal = new AveExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == mamifero)
		{
			animal = new MamiferoExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == reptil)
		{
			animal = new ReptilExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
	}
	else if(classificacao == nativo)
	{
		if(classe == anfibio)
		{
			animal = new AnfibioNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == ave)
		{
			animal = new AveNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == mamifero)
		{
			animal = new MamiferoNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
		}
		else if (classe == reptil)
		{
			animal = new ReptilNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra);
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
		USERENTRY(collect<int>(idRem));
		RETURNIF(idRem, 0, VOIDRETURN);
		if((animal = buscarAnim(idRem)) != nullptr)
		{
			char opt;
			std::cout << "Remover " << animal->getEspecie() << "? S (Sim) | N (Não)" << std::endl;
			USERENTRY(collect<char>(opt));
			RETURNIF(opt, '0', VOIDRETURN);
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
	this->save();

	FINALLY("Animal removido com sucesso" << std::endl);
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
	Animal* animal;
	for(auto it = this->animais.begin(); it != this->animais.end(); ++it)
	{
		animal = *it;
		if (animal->getId() == id)
		{
			animais.erase(it);
			delete animal;
			return true;
		}
	}
	return false;
}

void PetFera::redoAnimal(Animal*& animal, std::string extra)
{
	std::string especie         = animal->getEspecie();
	Classe classe               = animal->getClasse();
	Classificacao classificacao = animal->getClassificacao();
	short id                    = animal->getId();
	bool ameacadaExtincao       = animal->getAmeacadaExtincao();
	bool perigoso               = animal->getPerigoso();
	std::string NF              = animal->getNF();
	Tratador* tratador          = animal->getTratador();
	Veterinario* veterinario    = animal->getVeterinario();

	remAnimal(id);
	animal = cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);
	animal->forceId(id);
}

/**
 * @brief Interface de alteração dos dados cadastrais do Animal
*/
void PetFera::altAnimal()
{
	Animal* animal = nullptr;
	short idAlter;
	do
	{
		std::cout << "Insira o id do animal a ser alterado: " << std::endl;
		USERENTRY(collect<short>(idAlter));
		RETURNIF(idAlter, 0, VOIDRETURN);
		if ((animal = this->buscarAnim(idAlter)) == nullptr)
		{
			WARN("Animal não encontrado." << std::endl);
		}
		else
		{
			break;
		}
	}while(1);

	std::string opt;
	do
	{
		printTitle(animal->getEspecie(), fGREEN);
		std::cout << *animal << std::endl;
		NEWLINE;

		std::cout << "E. Alterar espécie" << std::endl;
		std::cout << "C. Alterar classe" << std::endl;
		std::cout << "S. Alterar classificacao" << std::endl;
		std::cout << "A. Alterar status de ameaçado de extinção" << std::endl;
		std::cout << "P. Alterar status de perigoso" << std::endl;
		std::cout << "F. Alterar nota fiscal" << std::endl;
		std::cout << "V. Alterar veterinário responsável" << std::endl;
		std::cout << "T. Alterar tratador responsável" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		
		USERENTRY( getline(std::cin, opt) );

		if(opt == "E" || opt == "e")
		{
			std::string especie;
			do
			{
				std::cout << "Informe a espécie do animal: " << std::endl;
				USERENTRY( getline(std::cin, especie) );
				BREAKIF(especie, "0");
				if (especie != "")
				{
					break;
				}
				else
				{
					WARN("Este campo não pode ser deixado em branco" << std::endl);
				}
			}while(1);
			animal->setEspecie(especie);
		}
		else if(opt == "C" || opt == "c")
		{
			char cClasse;
			do
			{
				std::cout << "Insira a classe do animal: A (Anfibio) | B (Ave) | M (Mamífero) | R (Réptil)" << std::endl;
				USERENTRY(collect<char>(cClasse));
				BREAKIF(cClasse, '0');
				if (isany(cClasse, "AaBbMmRr"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);

			animal->setClasse(anfibio);
			if (cClasse == 'B' || cClasse == 'b')
			{
				animal->setClasse(ave);
			}
			else if (cClasse == 'R' || cClasse == 'r')
			{
				animal->setClasse(reptil);
			}
			else if (cClasse == 'M' || cClasse == 'm')
			{
				animal->setClasse(mamifero);
			}

			if(animal->getClassificacao() == domestico)
			{
				redoAnimal(animal, "");
			}
			else if(animal->getClassificacao() == exotico)
			{
				redoAnimal(animal, dynamic_cast<Exotico*>(animal)->getTerritorio());
			}
			else if(animal->getClassificacao() == nativo)
			{
				redoAnimal(animal, dynamic_cast<Nativo*>(animal)->getLicenca());
			}
		}
		else if(opt == "S" || opt == "s")
		{
			std::string extra;
			char cClassificacao;
			do
			{
				std::cout << "Insira a classificação para manejo: N (Nativo) | E (Exotico) | D (Domestico)" << std::endl;
				USERENTRY(collect<char>(cClassificacao));
				BREAKIF(cClassificacao, '0');
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
							USERENTRY( getline(std::cin, extra) );
							BREAKIF(extra, "0");
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
							USERENTRY( getline(std::cin, extra) );
							BREAKIF(extra, "0");
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
			CONTINUEIF(extra, "0");

			animal->setClassificacao(domestico);
			if (cClassificacao == 'E' || cClassificacao == 'e')
			{
				animal->setClassificacao(exotico);
			}
			else if (cClassificacao == 'N' || cClassificacao == 'n')
			{
				animal->setClassificacao(nativo);
			} 

			redoAnimal(animal, extra);
		}
		else if(opt == "A" || opt == "a")
		{
			char cAmeacadaExtincao;
			do
			{
				std::cout << "O animal possui algum grau de extinção? S (Sim) | N (Não)" << std::endl;
				USERENTRY(collect<char>(cAmeacadaExtincao));
				BREAKIF(cAmeacadaExtincao, '0');
				if (isany(cAmeacadaExtincao, "SsNn"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);
			animal->setAmeacadaExtincao(isany(cAmeacadaExtincao, "Ss"));
		}
		else if(opt == "P" || opt == "p")
		{
			char cPerigoso;
			do
			{
				std::cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << std::endl;
				USERENTRY(collect<char>(cPerigoso));
				BREAKIF(cPerigoso, '0');
				if (isany(cPerigoso, "SsNn"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);
			animal->setPerigoso(isany(cPerigoso, "Ss"));
		}
		else if(opt == "F" || opt == "f")
		{
			std::string NF;
			USERENTRY( getline(std::cin, NF) );
			CONTINUEIF(NF, "0");
			animal->setNF(NF);
		}
		else if(opt == "V" || opt == "v")
		{
			Veterinario* veterinario;
			int idv;
			do
			{
				std::cout << "Insira o ID do veterinário do animal" << std::endl;
				USERENTRY(collect<int>(idv));
				BREAKIF(idv, 0);
				if ((veterinario = dynamic_cast<Veterinario*>(buscaFunc(idv))) != nullptr)
				{
					char opt;
					std::cout << "Associar " << veterinario->getNome() << " como veterinario deste animal? S - Sim | N - Não" << std::endl;
					USERENTRY(collect<char>(opt));
					BREAKIF(opt, '0');
					if(opt == 'S' || opt == 's')
					{
						animal->setVeterinario(veterinario);
						break;	
					}
				}
				else
				{
					WARN("Funcionário não encontrado ou não se encaixa na posição de veterinário" << std::endl);
				}
			} while (1);
		}
		else if(opt == "T" || opt == "t")
		{
			Tratador* tratador;
			int idt;
			do
			{
				std::cout << "Insira o ID do tratador do animal" << std::endl;
				USERENTRY(collect<int>(idt));
				BREAKIF(idt, 0);
				if ((tratador = dynamic_cast<Tratador*>(buscaFunc(idt))) != nullptr)
				{
					if(tratador->aptto(animal->getClasse(), animal->getPerigoso()))
					{
						char opt;
						std::cout << "Associar " << tratador->getNome() << " como tratador deste animal? S - Sim | N - Não" << std::endl;
						USERENTRY(collect<char>(opt));
						BREAKIF(opt, '0');
						if(opt == 'S' || opt == 's')
						{
							animal->setTratador(tratador);
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
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
		this->save();
	}while(1);
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
		printMenu("Pet Fera", "Imprimir Animais", fLIGHT_GREEN);
		std::cout << "A. Imprimir todos os animais" << std::endl;
		std::cout << "E. Imprimir um animal especifico" << std::endl;
		std::cout << "C. Listar todos os animais de uma classe" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "A" || opt == "a")
		{
			printTitle("Imprimir todos os animais", fLIGHT_GREEN);
			this->listAll();
		}
		else if(opt == "E" || opt == "e")
		{
			printTitle("Imprimir um animal especifico", fLIGHT_GREEN);
			this->listId();
		}
		else if(opt == "C" || opt == "c")
		{
			printTitle("Listar todos os animais de uma classe", fLIGHT_GREEN);
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
	USERENTRY(collect<short>(id));
	RETURNIF(id, 0, VOIDRETURN);
	if (buscarAnim(id)==nullptr)
	{
		WARN("Animal não encontrado" << std::endl);
	}
	else
	{
		for (auto a : this->animais)
		{
			if (a->getId()==id)
				std::cout << (*a) << std::endl;
		}
	}
	PAUSE;

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
		USERENTRY(collect<char>(cClasse));
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
		USERENTRY(collect<char>(cClassificacao));
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
			printTitle("Lista de anfíbios domésticos", fLIGHT_GREEN);
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
			printTitle("Lista de aves domésticas", fLIGHT_GREEN);
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
			printTitle("Lista de mamíferos domésticos", fLIGHT_GREEN);
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
			printTitle("Lista de répteis domésticos", fLIGHT_GREEN);
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
			printTitle("Lista de anfíbios exóticos", fLIGHT_GREEN);
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
			printTitle("Lista de aves exóticas", fLIGHT_GREEN);
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
			printTitle("Lista de mamíferos exóticos", fLIGHT_GREEN);
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
			printTitle("Lista de répteis exóticos", fLIGHT_GREEN);
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
			printTitle("Lista de anfíbios nativos", fLIGHT_GREEN);
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
			printTitle("Lista de aves nativas", fLIGHT_GREEN);
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
			printTitle("Lista de mamíferos nativos", fLIGHT_GREEN);
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
			printTitle("Lista de répteis nativos", fLIGHT_GREEN);
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
		USERENTRY(collect<short>(id));
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
	std::cout << "Listando animais sob responsabilidade de " << funcionario->getNome() << ": " << std::endl;
	NEWLINE;
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
		printMenu("Pet Fera", "Gerenciar cadastros", fLIGHT_GREEN);
		std::cout << "V. Cadastrar veterinário." << std::endl;
		std::cout << "A. Alterar dados de um veterinário." << std::endl;
		std::cout << "T. Cadastrar tratador." << std::endl;
		std::cout << "U. Alterar dados de um tratador." << std::endl;
		std::cout << "R. Remover funcinário." << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "V" || opt == "v")
		{
			printTitle("Cadastrar veterinário", fLIGHT_GREEN);
			this->cadVetr();
		}
		else if(opt == "R" || opt == "r")
		{
			printTitle("Remover funcionário", fLIGHT_GREEN);
			this->remFunc();
		}
		else if(opt == "A" || opt == "a")
		{
			printTitle("Alterar dados de um veterinário.", fLIGHT_GREEN);
			this->altVetr();
		}
		else if(opt == "T" || opt == "t")
		{
			printTitle("Cadastrar tratador", fLIGHT_GREEN);
			this->cadTrat();
		}
		else if(opt == "U" || opt == "u")
		{
			printTitle("Alterar dados de um tratador.", fLIGHT_GREEN);
			this->altTrat();
		}
		else if(opt == "F" || opt == "f")
		{
			printTitle("Listar funcionários", fLIGHT_GREEN);
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

	do
	{
		std::cout << "Insira o nome do veterinário: " << std::endl;
		USERENTRY( getline(std::cin, nome) );
		RETURNIF(nome, "0", VOIDRETURN);
		if (nome != "")
		{
			break;
		}
		else
		{
			WARN("Este campo não pode ser deixado em branco" << std::endl);
		}
	} while(1);
	do
	{
		std::cout << "Insira o CRMV do veterinário: " << std::endl;
		USERENTRY( getline(std::cin, CRMV) );
		RETURNIF(CRMV, "0", VOIDRETURN);

		std::string validChars = "0123456789"; // Digitos permitidos no CRMV
		int res = strspn(CRMV.c_str(), validChars.c_str());

		if (res == 0 || CRMV.length() < 4 || CRMV.length() > 6) { // Verifica se se o CRMV é válido
			WARN("CRMV inválido!" << std::endl);	
		}
		else
		{
			
			if(findCRMV(CRMV) == funcionarios.end())
			{
				break;
			}
			else
			{
				WARN("Já existe um veterinário com este número de CRMV cadastrado." << std::endl);
				std::cout<<res<<std::endl;
			}
			
		}
				
		} while (1);		

	cadVetr(nome, Status::ativo, CRMV, funcionarios.size() + 1);
	this->save();

	FINALLY("Veterinário vinculado à loja com sucesso." << std::endl);
	PAUSE;
}

/**
 * @brief Realiza o cadastro de um Veterinario
 * @details Recebe os dados cadastrais de um veterinário e o torna funcionário da PetFera
 * @param nome :: Informa o nome do veterinário
 * @param status :: Informa o status do veterinário (ativo | inativo)
 * @param CRMV :: Informa o CRMV do veterinário
 * @return Retorna um apontador ao veterinário recém-cadastrado
*/
Veterinario* PetFera::cadVetr(std::string nome, Status status, std::string CRMV, int id)
{
	Veterinario* vet = new Veterinario(nome, id, status, CRMV);
	funcionarios[id] = vet;

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
	USERENTRY(collect<short>(id));
	RETURNIF(id, 0, VOIDRETURN);

	std::cout << "Insira o nome do veterinário: " << std::endl;
	USERENTRY( getline(std::cin, nome) );
	RETURNIF(nome, "0", VOIDRETURN)
	for(auto v : funcionarios)
	{
		if(v.second->getId() == id)
		{
			v.second->setNome(nome);
			return;
		}
	}
	this->save();

	FINALLY("Cadastro alterado com sucesso." << std::endl);
	PAUSE;
}

/**
 * @brief Realiza a busca de um Veterinario pelo CRMV
 * @param CRMV :: CRMV referente ao veterinário
 * @return Retorna um iterador do vetor de funcionários referente ao veterinário
*/
std::map<int, Funcionario*>::iterator PetFera::findCRMV(std::string CRMV)
{
	Veterinario* veterinario;
	for(auto it = funcionarios.begin(); it != funcionarios.end(); ++it)
	{
		veterinario = dynamic_cast<Veterinario*>(it->second);
		if(veterinario != nullptr && veterinario->getCRMV() == CRMV)
		{
			return it;
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
	do
	{
		std::cout << "Insira o nome do tratador: " << std::endl;
		USERENTRY( getline(std::cin, nome) );
		RETURNIF(nome, "0", VOIDRETURN);
		if (nome != "")
		{
			break;
		}
		else
		{
			WARN("Este campo não pode ser deixado em branco" << std::endl);
		}
	} while(1);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		USERENTRY( getline(std::cin, seguranca) );
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

	cadTrat(nome, Status::ativo, seg, funcionarios.size() + 1);
	this->save();

	FINALLY("Tratador vinculado à loja com sucesso." << std::endl);
	PAUSE;
}

/**
 * @brief Realiza o cadastro de um Tratador
 * @details Recebe os dados cadastrais de um tratador e o torna funcionário da PetFera
 * @param nome :: Informa o nome do tratador
 * @param status :: Informa o status do tratador (ativo | inativo)
 * @param seg :: Informa o nível de segurança indicando quais animais ele pode tratar
 * @return Retorna um apontador ao tratador recém-cadastrado
*/
Tratador* PetFera::cadTrat(std::string nome, Status status, Seguranca seg, int id)
{
	Tratador *tratador = new Tratador(nome, id, status, seg);
	funcionarios[id] = tratador;

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
	USERENTRY(collect<short>(id));
	RETURNIF(id, 0, VOIDRETURN);

	std::cout << "Insira o nome do tratador: " << std::endl;
	USERENTRY( getline(std::cin, nome) );
	RETURNIF(nome, "0", VOIDRETURN);

	do
	{
		std::cout << "Informe o nível de segurança: (" << Color(fGREEN) << "VERDE" << Color(fRESET) << " | " << Color(fBLUE) << "AZUL" << Color(fRESET) << " | " << Color(fRED) << "VERMELHO" << Color(fRESET) << ")" << std::endl;
		USERENTRY( getline(std::cin, seguranca) );
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
		if(t->second->getId() == id)
		{
			t->second->setNome(nome);
			static_cast<Tratador*>(t->second)->setSeguranca(seg);
			return;
		}
	}
	this->save();

	FINALLY("Cadastro alterado com sucesso." << std::endl);
	PAUSE;
}

/**
 * @brief Cadastra um Funcionario
 * @details Realiza o cadastro de um funcionário preexistente
 * @param funcionario :: Ponteiro para um funcionário
 * @return Retorna um apontador para o funcionário recém-cadastrado
*/
Funcionario* PetFera::cadFunc(Funcionario* funcionario)
{
	funcionarios[funcionario->getId()] = funcionario;

	return funcionario;
}

/**
 * @brief Busca um Funcionario na PetFera
 * @param id :: id referente ao funcionário
 * @return  Retorna um ponteiro para o funcionário ou nullptr caso não seja encontrado
*/
Funcionario* PetFera::buscaFunc(int id)
{
	auto find = funcionarios.find(id);
	if(find != funcionarios.end() && find->second->getStatus() == ativo)
	{
		return find->second;
	}
	else
	{
		return nullptr;
	}
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
	USERENTRY(collect<short>(id));
	RETURNIF(id, 0, false);
	for(auto& t : funcionarios)
	{
		if(t.second->getId() == id)
		{
			t.second->setStatus(inativo);
			this->save();

			FINALLY(t.second->getNome() << " foi desvinculado da loja." << std::endl);
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
		if(dynamic_cast<Veterinario*>(f.second))
		{
			std::cout << *f.second << std::endl;
		}
	}
	NEWLINE;
	std::cout << Color(fCYAN) << "Tratadores:" << Color(fRESET) << std::endl;
	for(auto f : funcionarios)
	{
		if(dynamic_cast<Tratador*>(f.second))
		{
			std::cout << *f.second << std::endl;
		}
	}
	NEWLINE;

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
		printMenu("Pet Fera", "Menu Principal", fLIGHT_GREEN);
		std::cout << "C. Cadastrar novo animal." << std::endl;
		std::cout << "R. Remover um animal" << std::endl;
		std::cout << "A. Alterar dados de um animal" << std::endl;
		std::cout << "L. Listar animal ou classe" << std::endl;
		std::cout << "D. Listar animais sob responsabilidade" << std::endl;
		std::cout << "G. Gerenciar funcionários" << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;
		NEWLINE;
		std::cout << "X. Sair" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "C" || opt == "c")
		{
			printTitle("Cadastrar Animal", fLIGHT_GREEN);
			this->cadAnimal();
			std::cout << "Operação realizada com sucesso." << std::endl;
		}
		else if(opt == "R" || opt == "r")
		{
			printTitle("Remover um animal", fLIGHT_GREEN);
			this->remAnimal();
		}
		else if(opt == "A" || opt == "a")
		{
			printTitle("Alterar dados de um animal", fLIGHT_GREEN);
			this->altAnimal();

		}
		else if(opt == "L" || opt == "l")
		{
			this->listAnimal();
		}
		else if(opt == "D" || opt == "d")
		{
			printTitle("Listar animais sob responsabilidade", fLIGHT_GREEN);
			this->listRespn();
		}
		else if(opt == "G" || opt == "g")
		{
			this->gerCad();
		}
		else if(opt == "F" || opt == "f")
		{
			printTitle("Lista de funcionários", fLIGHT_GREEN);
			this->listFunc();
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
	}while(1);
}
