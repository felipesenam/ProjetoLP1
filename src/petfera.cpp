
#include "petfera.hpp"

/**
 * @brief Construtor padrão
*/
PetFera::PetFera()
{
	Debug(typeid(*this).name() << " [" << this << "] foi criada." << std::endl);
}

/**
 * @brief Destrutor padrão
 * @details Desaloca toda a memória alocada por funcionários e animais
*/
PetFera::~PetFera()
{
	Debug(typeid(*this).name() << " [" << this << "] foi destruída." << std::endl);
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

		this->cadVetr(nome, status, CRMV, id);
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

		this->cadTrat(nome, status, seg, id);
	}

	while(!getline(file, line).eof() && line != "")
	{
		std::istringstream oss(line);
		int id;
		Classificacao classificacao;
		bool ameacadaExtincao = false, perigoso = false;
		std::string NF, especie, extra, idade, peso, tamanho, informacoes;
		Classe classe;
		std::shared_ptr<Tratador> tratador = nullptr;
		std::shared_ptr<Veterinario> veterinario = nullptr;

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
		tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(atoi(data.c_str())));
		getline(oss, data, ';');
		veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(atoi(data.c_str())));
		getline(oss, extra, ';');

		auto a = this->cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);
		a->forceId(id);

		getline(oss, idade, ';');
		a->setIdade(idade);
		getline(oss, peso, ';');
		a->setPeso(peso);
		getline(oss, tamanho, ';');
		a->setTamanho(tamanho);
		getline(oss, data, ';');
		a->setSexo(static_cast<Sexo>(atoi(data.c_str())));
		getline(oss, informacoes, ';');
		a->setInformacoes(informacoes);
	}
}

void PetFera::save()
{
	std::ofstream file("pet_fera.persistency.txt");

	for(const auto& veterinario : this->funcionarios)
	{
		if(std::dynamic_pointer_cast<Veterinario>(veterinario.second) != nullptr)
			file << (*veterinario.second) << std::endl;
	}
	file << std::endl;
	
	for(const auto& tratador : this->funcionarios)
	{
		if(std::dynamic_pointer_cast<Tratador>(tratador.second) != nullptr)
			file << (*tratador.second) << std::endl;
	}
	file << std::endl;
	
	for(const auto& animal : this->animais)
	{
		file << (*animal) << std::endl;
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
	std::string idt, idv;
	std::shared_ptr<Tratador> tratador = nullptr;
	std::shared_ptr<Veterinario> veterinario = nullptr;

	do
	{
		std::cout << "Informe a espécie do animal: " << std::endl;
		USERENTRY( getline(std::cin, especie) );
		IFEQ_WPAUSERETURN(especie, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		IFFOUND_CONTINUE(especie, ";", "O dado informado possui caracteres não permitidos.");

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
		USERENTRY(lib::collect<char>(cClasse));
		IFEQ_WPAUSERETURN(cClasse, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cClasse, "AaBbMmRr"))
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
		USERENTRY(lib::collect<char>(cClassificacao));
		IFEQ_WPAUSERETURN(cClassificacao, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cClassificacao, "Dd"))
		{
			break;
		}
		else if (lib::isany(cClassificacao, "NnEe"))
		{
			if(cClassificacao == 'N' || cClassificacao == 'n')
			{
				do
				{
					std::cout << "Informe a licença de transporte:" << std::endl;
					USERENTRY( getline(std::cin, extra) );
					IFEQ_WPAUSERETURN(extra, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
					IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
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
					IFEQ_WPAUSERETURN(extra, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
					IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
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
		USERENTRY(lib::collect<char>(cAmeacadaExtincao));
		IFEQ_WPAUSERETURN(cAmeacadaExtincao, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cAmeacadaExtincao, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);
	ameacadaExtincao = lib::isany(cAmeacadaExtincao, "Ss");

	do
	{
		std::cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << std::endl;
		USERENTRY(lib::collect<char>(cPerigoso));
		IFEQ_WPAUSERETURN(cPerigoso, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cPerigoso, "SsNn"))
		{
			break;
		}
		else
		{
			WARN("Opção inválida" << std::endl);
		}
	} while (1);
	perigoso = lib::isany(cPerigoso, "Ss");

	do
	{
		std::cout << "Insira o tratador do animal (nome ou ID):" << std::endl;
		USERENTRY( getline(std::cin, idt) );
		IFEQ_WPAUSERETURN(idt, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(lib::stolower(idt)));
			if(tratador == nullptr)
				tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(atoi(idt.c_str())));

		if (tratador != nullptr)
		{
			if(tratador->aptto(classe, perigoso))
			{
				char opt;
				std::cout << "Associar " << tratador->getNome() << " como tratador deste animal? S - Sim | N - Não" << std::endl;
				USERENTRY(lib::collect<char>(opt));
				IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
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
		std::cout << "Insira o veterinário do animal (nome ou ID):" << std::endl;
		USERENTRY( getline(std::cin, idv) );
		IFEQ_WPAUSERETURN(idv, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(lib::stolower(idv)));
		if(veterinario == nullptr)
			veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(atoi(idv.c_str())));

		if (veterinario != nullptr)
		{

			char opt;
			std::cout << "Associar " << veterinario->getNome() << " como veterinário deste animal? S - Sim | N - Não" << std::endl;
			USERENTRY(lib::collect<char>(opt));
			IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
			if(opt == 'S' || opt == 's')
			{
				break;	
			}
		}
	} while (1);

	do
	{
		std::cout << "Insira a Nota Fiscal, se houver: " << std::endl;
		USERENTRY( getline(std::cin, NF) );
		IFEQ_WPAUSERETURN(NF, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		IFFOUND_CONTINUE(NF, ";", "O dado informado possui caracteres não permitidos.");
		break;
	} while(1);

	this->cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);
	this->save();

	FINALLY("Animal adicionado com sucesso" << std::endl);
	std::cout << "Informações adicionais estão disponíveis na alteração do cadastro." << std::endl;
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
std::shared_ptr<Animal> PetFera::cadAnimal(const std::string& especie, Classe classe, Classificacao classificacao, bool ameacadaExtincao, bool perigoso, const std::string& NF, std::shared_ptr<Tratador>& tratador, std::shared_ptr<Veterinario>& veterinario, const std::string& extra)
{
	std::shared_ptr<Animal> animal = nullptr;
	short cid = 1;
	if(this->animais.size() > 0)
	{
		cid = std::prev(this->animais.end())->get()->getId() + 1;
	}

	if(classificacao == domestico)
	{
		if(classe == anfibio)
		{
			animal = std::make_shared<AnfibioDomestico>(AnfibioDomestico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF));
		}
		else if (classe == ave)
		{
			animal = std::make_shared<AveDomestica>(AveDomestica(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF));
		}
		else if (classe == mamifero)
		{
			animal = std::make_shared<MamiferoDomestico>(MamiferoDomestico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF));
		}
		else if (classe == reptil)
		{
			animal = std::make_shared<ReptilDomestico>(ReptilDomestico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF));
		}
	}
	else if(classificacao == exotico)
	{
		if(classe == anfibio)
		{
			animal = std::make_shared<AnfibioExotico>(AnfibioExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == ave)
		{
			animal = std::make_shared<AveExotica>(AveExotica(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == mamifero)
		{
			animal = std::make_shared<MamiferoExotico>(MamiferoExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == reptil)
		{
			animal = std::make_shared<ReptilExotico>(ReptilExotico(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
	}
	else if(classificacao == nativo)
	{
		if(classe == anfibio)
		{
			animal = std::make_shared<AnfibioNativo>(AnfibioNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == ave)
		{
			animal = std::make_shared<AveNativa>(AveNativa(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == mamifero)
		{
			animal = std::make_shared<MamiferoNativo>(MamiferoNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
		}
		else if (classe == reptil)
		{
			animal = std::make_shared<ReptilNativo>(ReptilNativo(especie, classe, classificacao, cid, ameacadaExtincao, perigoso, NF, extra));
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
	std::shared_ptr<Animal> animal = nullptr;
	std::string id;
	do
	{
		std::cout << "Insira o animal a ser removido (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, id) );
		IFEQ_WPAUSERETURN(id, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		animal = this->buscarAnim(lib::stolower(id));
		if(animal == nullptr)
			animal = this->buscarAnim(atoi(id.c_str()));

		if(animal != nullptr)
		{
			char opt;
			std::cout << "Remover " << animal->getEspecie() << "? S (Sim) | N (Não)" << std::endl;
			USERENTRY(lib::collect<char>(opt));
			IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
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

	if(this->remAnimal(id))
	{
		FINALLY("Animal removido com sucesso" << std::endl);
		this->save();
	}
	else
	{
		WARN("Houve um problema ao tentar remover este animal." << std::endl);
	}

	PAUSE;
}

bool PetFera::remAnimal(int id)
{
	std::stringstream ss;
	ss << id;
	return remAnimal(ss.str());
}

/**
 * @brief Remove um Animal da loja
 * @details Recebe o id de um animal da PetFera e o retira do catálogo
 * @param id :: Informa o número de identificação do animal
 * @return Retorna um valor booleano referente ao sucesso da operação
*/
bool PetFera::remAnimal(const std::string& id)
{
	std::shared_ptr<Animal> animal;
	for(auto it = this->animais.begin(); it != this->animais.end(); ++it)
	{
		animal = (*it);
		if (animal->getEspecie() == id || animal->getId() == atoi(id.c_str()))
		{
			this->animais.erase(it);
			return true;
		}
	}
	return false;
}

void PetFera::redoAnimal(std::shared_ptr<Animal>& animal, const std::string& extra)
{
	std::string especie = animal->getEspecie();
	Classe classe = animal->getClasse();
	Classificacao classificacao = animal->getClassificacao();
	short id = animal->getId();
	bool ameacadaExtincao = animal->getAmeacadaExtincao();
	bool perigoso = animal->getPerigoso();
	std::string NF = animal->getNF();
	std::shared_ptr<Tratador> tratador = animal->getTratador();
	std::shared_ptr<Veterinario> veterinario = animal->getVeterinario();

	this->remAnimal(id);
	animal = this->cadAnimal(especie, classe, classificacao, ameacadaExtincao, perigoso, NF, tratador, veterinario, extra);
	animal->forceId(id);
}

/**
 * @brief Interface de alteração dos dados cadastrais do Animal
*/
void PetFera::altAnimal()
{
	std::shared_ptr<Animal> animal = nullptr;
	std::string idAlter;
	do
	{
		std::cout << "Insira o animal a ser alterado (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, idAlter) );
		IFEQ_WPAUSERETURN(idAlter, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		animal = this->buscarAnim(lib::stolower(idAlter));
		if(animal == nullptr)
			animal = this->buscarAnim(atoi(idAlter.c_str()));

		if (animal != nullptr)
		{
			break;
		}
		else
		{
			WARN("Animal não encontrado." << std::endl);
		}
	}while(1);

	std::string opt;
	do
	{
		lib::printTitle(animal->getEspecie(), fGREEN);
		std::cout << (*animal) << std::endl;
		NEWLINE;

		std::cout << "E. Alterar espécie" << std::endl;
		std::cout << "C. Alterar classe" << std::endl;
		std::cout << "S. Alterar classificacao" << std::endl;
		std::cout << "A. Alterar status de ameaçado de extinção" << std::endl;
		std::cout << "P. Alterar status de perigoso" << std::endl;
		if(animal->getClassificacao() == exotico)
		{
			std::cout << "N. Alterar território de origem" << std::endl;
		}
		else if(animal->getClassificacao() == nativo)
		{
			std::cout << "N. Alterar licença de transporte" << std::endl;
		}
		std::cout << "F. Alterar nota fiscal" << std::endl;
		std::cout << "V. Alterar veterinário responsável" << std::endl;
		std::cout << "T. Alterar tratador responsável" << std::endl;
		std::cout << "I. Informar idade" << std::endl;
		std::cout << "K. Informar peso" << std::endl;
		std::cout << "M. Informar tamanho" << std::endl;
		std::cout << "O. Informar sexo" << std::endl;
		std::cout << "Z. Alterar informações adicionais" << std::endl;
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
				IFEQ_BREAK(especie, "0");
				IFFOUND_CONTINUE(especie, ";", "O dado informado possui caracteres não permitidos.");
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
				USERENTRY(lib::collect<char>(cClasse));
				IFEQ_BREAK(cClasse, '0');
				if (lib::isany(cClasse, "AaBbMmRr"))
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
				this->redoAnimal(animal, "");
			}
			else if(animal->getClassificacao() == exotico)
			{
				this->redoAnimal(animal, std::dynamic_pointer_cast<Exotico>(animal)->getTerritorio());
			}
			else if(animal->getClassificacao() == nativo)
			{
				this->redoAnimal(animal, std::dynamic_pointer_cast<Nativo>(animal)->getLicenca());
			}
		}
		else if(opt == "S" || opt == "s")
		{
			std::string extra;
			char cClassificacao;
			do
			{
				std::cout << "Insira a classificação para manejo: N (Nativo) | E (Exotico) | D (Domestico)" << std::endl;
				USERENTRY(lib::collect<char>(cClassificacao));
				IFEQ_BREAK(cClassificacao, '0');
				if (lib::isany(cClassificacao, "Dd"))
				{
					break;
				}
				else if (lib::isany(cClassificacao, "NnEe"))
				{
					if(cClassificacao == 'N' || cClassificacao == 'n')
					{
						do
						{
							std::cout << "Informe a licença de transporte:" << std::endl;
							USERENTRY( getline(std::cin, extra) );
							IFEQ_BREAK(extra, "0");
							IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
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
							IFEQ_BREAK(extra, "0");
							IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
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
			IFEQ_CONTINUE(extra, "0");

			animal->setClassificacao(domestico);
			if (cClassificacao == 'E' || cClassificacao == 'e')
			{
				animal->setClassificacao(exotico);
			}
			else if (cClassificacao == 'N' || cClassificacao == 'n')
			{
				animal->setClassificacao(nativo);
			} 

			this->redoAnimal(animal, extra);
		}
		else if(opt == "A" || opt == "a")
		{
			char cAmeacadaExtincao;
			do
			{
				std::cout << "O animal possui algum grau de extinção? S (Sim) | N (Não)" << std::endl;
				USERENTRY(lib::collect<char>(cAmeacadaExtincao));
				IFEQ_BREAK(cAmeacadaExtincao, '0');
				if (lib::isany(cAmeacadaExtincao, "SsNn"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);
			animal->setAmeacadaExtincao(lib::isany(cAmeacadaExtincao, "Ss"));
		}
		else if(opt == "P" || opt == "p")
		{
			char cPerigoso;
			do
			{
				std::cout << "O animal é considerado perigoso ou venenoso? S (Sim) | N (Não)" << std::endl;
				USERENTRY(lib::collect<char>(cPerigoso));
				IFEQ_BREAK(cPerigoso, '0');
				if (lib::isany(cPerigoso, "SsNn"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);
			animal->setPerigoso(lib::isany(cPerigoso, "Ss"));
		}
		else if(animal->getClassificacao() == exotico && (opt == "N" || opt == "n"))
		{
			std::string extra;
			do
			{
				std::cout << "Informe o território de origem do animal:" << std::endl;
				USERENTRY( getline(std::cin, extra) );
				IFEQ_BREAK(extra, "0");
				IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
				if (extra != "")
				{
					std::dynamic_pointer_cast<Exotico>(animal)->setTerritorio(extra);
					break;
				}
				else
				{
					WARN("Este campo não pode ser deixado em branco" << std::endl);
				}
			} while (1);
		}
		else if(animal->getClassificacao() == nativo && (opt == "N" || opt == "n"))
		{
			std::string extra;
			do
			{
				std::cout << "Informe a licença de transporte:" << std::endl;
				USERENTRY( getline(std::cin, extra) );
				IFEQ_BREAK(extra, "0");
				IFFOUND_CONTINUE(extra, ";", "O dado informado possui caracteres não permitidos.");
				if (extra != "")
				{
					std::dynamic_pointer_cast<Nativo>(animal)->setLicenca(extra);
					break;
				}
				else
				{
					WARN("Este campo não pode ser deixado em branco" << std::endl);
				}
			} while (1);
		}
		else if(opt == "F" || opt == "f")
		{
			std::string NF;
			USERENTRY( getline(std::cin, NF) );
			IFEQ_CONTINUE(NF, "0");
			IFFOUND_CONTINUE(NF, ";", "O dado informado possui caracteres não permitidos.");
			animal->setNF(NF);
		}
		else if(opt == "V" || opt == "v")
		{
			std::shared_ptr<Veterinario> veterinario;
			std::string idv;
			do
			{
				std::cout << "Insira o veterinário do animal (nome ou ID)" << std::endl;
				USERENTRY( getline(std::cin, idv) );
				IFEQ_WPAUSERETURN(idv, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

				veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(lib::stolower(idv)));
					if(veterinario == nullptr)
						veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(atoi(idv.c_str())));

				if (veterinario != nullptr)
				{
					char opt;
					std::cout << "Associar " << veterinario->getNome() << " como veterinário deste animal? S - Sim | N - Não" << std::endl;
					USERENTRY(lib::collect<char>(opt));
					IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
					if(opt == 'S' || opt == 's')
					{
						animal->setVeterinario(veterinario);
						break;	
					}
				}
			} while (1);
		}
		else if(opt == "T" || opt == "t")
		{
			std::shared_ptr<Tratador> tratador;
			std::string idt;
			do
			{
				std::cout << "Insira o tratador do animal (nome ou ID)" << std::endl;
				USERENTRY( getline(std::cin, idt) );
				IFEQ_WPAUSERETURN(idt, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

				tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(lib::stolower(idt)));
					if(tratador == nullptr)
						tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(atoi(idt.c_str())));

				if (tratador != nullptr)
				{
					if(tratador->aptto(animal->getClasse(), animal->getPerigoso()))
					{
						char opt;
						std::cout << "Associar " << tratador->getNome() << " como tratador deste animal? S - Sim | N - Não" << std::endl;
						USERENTRY(lib::collect<char>(opt));
						IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
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
		else if(opt == "I" || opt == "i")
		{
			std::string idade;
			USERENTRY( getline(std::cin, idade) );
			IFEQ_CONTINUE(idade, "0");
			IFFOUND_CONTINUE(idade, ";", "O dado informado possui caracteres não permitidos.");
			animal->setIdade(idade);
		}
		else if(opt == "K" || opt == "k")
		{
			std::string peso;
			USERENTRY( getline(std::cin, peso) );
			IFEQ_CONTINUE(peso, "0");
			IFFOUND_CONTINUE(peso, ";", "O dado informado possui caracteres não permitidos.");
			animal->setPeso(peso);
		}
		else if(opt == "M" || opt == "m")
		{
			std::string tamanho;
			USERENTRY( getline(std::cin, tamanho) );
			IFEQ_CONTINUE(tamanho, "0");
			IFFOUND_CONTINUE(tamanho, ";", "O dado informado possui caracteres não permitidos.");
			animal->setTamanho(tamanho);
		}
		else if(opt == "O" || opt == "o")
		{
			char cSexo;
			do
			{
				std::cout << "Informe o sexo do animal: M (Macho) | F (Fêmea)" << std::endl;
				USERENTRY(lib::collect<char>(cSexo));
				IFEQ_BREAK(cSexo, '0');
				if (lib::isany(cSexo, "MmFf"))
				{
					break;
				}
				else
				{
					WARN("Opção inválida" << std::endl);
				}
			} while (1);
			if(lib::isany(cSexo, "Mm"))
			{
				animal->setSexo(macho);
			}
			else
			{
				animal->setSexo(femea);
			}
			
		}
		else if(opt == "Z" || opt == "z")
		{
			std::string informacoes;
			USERENTRY( getline(std::cin, informacoes) );
			IFEQ_CONTINUE(informacoes, "0");
			IFFOUND_CONTINUE(informacoes, ";", "O dado informado possui caracteres não permitidos.");
			animal->setInformacoes(informacoes);
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
		lib::printMenu("Pet Fera", "Listar animais", fLIGHT_GREEN);
		std::cout << "A. Listar todos os animais" << std::endl;
		std::cout << "E. Consultar um animal especifico" << std::endl;
		std::cout << "C. Listar os animais por classe e classificação" << std::endl;
		std::cout << "D. Listar animais sob responsabilidade" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "A" || opt == "a")
		{
			lib::printTitle("Imprimir todos os animais", fLIGHT_GREEN);
			this->listAll();
		}
		else if(opt == "E" || opt == "e")
		{
			lib::printTitle("Imprimir um animal especifico", fLIGHT_GREEN);
			this->listId();
		}
		else if(opt == "C" || opt == "c")
		{
			lib::printTitle("Listar todos os animais de uma classe", fLIGHT_GREEN);
			this->listClass();
		}
		else if(opt == "D" || opt == "d")
		{
			lib::printTitle("Listar animais sob responsabilidade", fLIGHT_GREEN);
			this->listRespn();
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
	for (auto animal : this->animais)
	{
		animal->geral();
		NEWLINE;
	}

	FINALLY("Foram listados " << this->animais.size() << " animais." << std::endl);
	std::cout << "Para mais informações, faça uma consulta direta." << std::endl;

	PAUSE;
}

/**
 * @brief Lista um animal pelo numero do ID
*/
void PetFera::listId()
{
	std::shared_ptr<Animal> animal = nullptr;
	std::string id;
	do
	{
		std::cout << "Informe o animal a ser impresso (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, id) );
		IFEQ_WPAUSERETURN(id, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		animal = this->buscarAnim(lib::stolower(id));
			if(animal == nullptr)
				animal = this->buscarAnim(atoi(id.c_str()));

		if (animal != nullptr)
		{
			std::cout << (*animal) << std::endl;
			break;
		}
		else
		{
			WARN("Animal não encontrado" << std::endl);
		}
	} while(1);

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
		USERENTRY(lib::collect<char>(cClasse));
		IFEQ_WPAUSERETURN(cClasse, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cClasse, "AaBbMmRr"))
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
		USERENTRY(lib::collect<char>(cClassificacao));
		IFEQ_WPAUSERETURN(cClassificacao, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
		if (lib::isany(cClassificacao, "NnEeDd"))
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

	int count = this->listClass(classe, classificacao);
	FINALLY("Foram listados " << count << " animais." << std::endl);
	PAUSE;
}

int PetFera::listClass(Classe classe, Classificacao classificacao)
{
	int count = 0;
	if(classificacao == domestico)
	{
		if(classe == anfibio)
		{
			lib::printTitle("Lista de anfíbios domésticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AnfibioDomestico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == ave)
		{
			lib::printTitle("Lista de aves domésticas", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AveDomestica>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == mamifero)
		{
			lib::printTitle("Lista de mamíferos domésticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<MamiferoDomestico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == reptil)
		{
			lib::printTitle("Lista de répteis domésticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<ReptilDomestico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
	}
	else if(classificacao == exotico)
	{
		if(classe == anfibio)
		{
			lib::printTitle("Lista de anfíbios exóticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AnfibioExotico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == ave)
		{
			lib::printTitle("Lista de aves exóticas", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AveExotica>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == mamifero)
		{
			lib::printTitle("Lista de mamíferos exóticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<MamiferoExotico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == reptil)
		{
			lib::printTitle("Lista de répteis exóticos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<ReptilExotico>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
	}
	else if(classificacao == nativo)
	{
		if(classe == anfibio)
		{
			lib::printTitle("Lista de anfíbios nativos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AnfibioNativo>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == ave)
		{
			lib::printTitle("Lista de aves nativas", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<AveNativa>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == mamifero)
		{
			lib::printTitle("Lista de mamíferos nativos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<MamiferoNativo>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
		else if (classe == reptil)
		{
			lib::printTitle("Lista de répteis nativos", fLIGHT_GREEN);
			for(auto a : this->animais)
			{
				std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<ReptilNativo>(a);
				if(animal)
				{
					std::cout << (*animal) << std::endl;
					++count;
				}
			}
		}
	}
	return count;
}

/**
 * @brief Lista os animais sob responsabilidade de algum Funcionario
*/
void PetFera::listRespn()
{
	std::shared_ptr<Funcionario> funcionario = nullptr;
	std::string id;
	do
	{
		std::cout << "Informe o funcionário (nome ou ID)" << std::endl;
		USERENTRY( getline(std::cin, id) );
		IFEQ_WPAUSERETURN(id, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		funcionario = this->buscaFunc(lib::stolower(id));
			if(funcionario == nullptr)
				funcionario = this->buscaFunc(atoi(id.c_str()));

		if(funcionario != nullptr)
		{
			break;
		}
		else
		{
			WARN("Funcionário não encontrado." << std::endl);
		}
	}while(1);

	std::cout << "Listando animais sob responsabilidade de " << funcionario->getNome() << ": " << std::endl;

	int count = this->listRespn(funcionario);
	FINALLY("Foram listados " << count << " animais." << std::endl);

	PAUSE;
}

int PetFera::listRespn(std::shared_ptr<Funcionario>& funcionario)
{
	int count = 0;
	for(auto a : this->animais)
	{
		if(a->getTratador() == funcionario || a->getVeterinario() == funcionario)
		{
			std::cout << (*a) << std::endl;
			++count;
		}
	}
	return count;
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
		lib::printMenu("Pet Fera", "Gerenciar cadastros", fLIGHT_GREEN);
		std::cout << "T. Cadastrar tratador" << std::endl;
		std::cout << "V. Cadastrar veterinário" << std::endl;
		std::cout << "U. Alterar dados de um tratador" << std::endl;
		std::cout << "A. Alterar dados de um veterinário" << std::endl;
		std::cout << "R. Remover funcionário" << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "T" || opt == "t")
		{
			lib::printTitle("Cadastrar tratador", fLIGHT_GREEN);
			this->cadTrat();
		}
		else if(opt == "V" || opt == "v")
		{
			lib::printTitle("Cadastrar veterinário", fLIGHT_GREEN);
			this->cadVetr();
		}
		else if(opt == "U" || opt == "u")
		{
			lib::printTitle("Alterar dados de um tratador", fLIGHT_GREEN);
			this->altTrat();
		}
		else if(opt == "A" || opt == "a")
		{
			lib::printTitle("Alterar dados de um veterinário", fLIGHT_GREEN);
			this->altVetr();
		}
		else if(opt == "R" || opt == "r")
		{
			lib::printTitle("Remover funcionário", fLIGHT_GREEN);
			this->remFunc();
		}
		else if(opt == "F" || opt == "f")
		{
			lib::printTitle("Listar funcionários", fLIGHT_GREEN);
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
std::shared_ptr<Animal> PetFera::buscarAnim(int id)
{
	for (auto& animal : this->animais)
	{
		if (animal->getId() == id)
		{
			return animal;
		}
	}
	return nullptr;
}

std::shared_ptr<Animal> PetFera::buscarAnim(const std::string& especie)
{
	for (auto animal = this->animais.begin(); animal != this->animais.end(); ++animal)
	{
		if ((*animal)->getEspecie() == especie)
		{
			return (*animal);
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
		IFEQ_WPAUSERETURN(nome, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		IFFOUND_CONTINUE(nome, ";", "O dado informado possui caracteres não permitidos.");
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
		IFEQ_WPAUSERETURN(CRMV, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		IFFOUND_CONTINUE(CRMV, ";", "O dado informado possui caracteres não permitidos.");

		if (strspn(CRMV.c_str(), "0123456789") == 0 || CRMV.length() < 4 || CRMV.length() > 6) { // Verifica se se o CRMV é válido
			WARN("CRMV inválido!" << std::endl);	
		}
		else
		{
			
			if(this->findCRMV(CRMV) == this->funcionarios.end())
			{
				break;
			}
			else
			{
				WARN("Já existe um veterinário com este número de CRMV cadastrado." << std::endl);
			}	
		}	
	} while (1);		

	this->cadVetr(nome, Status::ativo, CRMV, this->funcionarios.size() + 1);
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
std::shared_ptr<Veterinario> PetFera::cadVetr(const std::string& nome, Status status, const std::string& CRMV, int id)
{
	std::shared_ptr<Veterinario> vet = std::make_shared<Veterinario>(Veterinario(nome, id, status, CRMV));
	this->funcionarios[id] = vet;

	return vet;
}

/**
 * @brief Altera os dados cadastrais de um Veterinario
*/
void PetFera::altVetr()
{
	std::shared_ptr<Veterinario> veterinario = nullptr;
	std::string idAlter;
	do
	{
		std::cout << "Informe o veterinário a ser alterado (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, idAlter) );
		IFEQ_WPAUSERETURN(idAlter, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(lib::stolower(idAlter)));
			if(veterinario == nullptr)
				veterinario = std::dynamic_pointer_cast<Veterinario>(this->buscaFunc(atoi(idAlter.c_str())));

		if (veterinario != nullptr)
		{
			break;
		}
		else
		{
			WARN("Funcionário não encontrado." << std::endl);
		}
	}while(1);

	std::string opt;
	do
	{
		lib::printTitle(veterinario->getNome(), fGREEN);
		std::cout << (*veterinario) << std::endl;
		NEWLINE;

		std::cout << "N. Alterar nome" << std::endl;
		std::cout << "C. Alterar CRMV" << std::endl;
		std::cout << "S. Alterar status" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		
		USERENTRY( getline(std::cin, opt) );

		if(opt == "N" || opt == "n")
		{
			std::string nome;
			do
			{
				std::cout << "Informe o nome do veterinário: " << std::endl;
				USERENTRY( getline(std::cin, nome) );
				IFEQ_BREAK(nome, "0");
				IFFOUND_CONTINUE(nome, ";", "O dado informado possui caracteres não permitidos.");
				if (nome != "")
				{
					veterinario->setNome(nome);
					break;
				}
				else
				{
					WARN("Este campo não pode ser deixado em branco." << std::endl);
				}
			}while(1);
		}
		if(opt == "C" || opt == "c")
		{
			std::string CRMV;
			do
			{
				std::cout << "Insira o CRMV do veterinário: " << std::endl;
				USERENTRY( getline(std::cin, CRMV) );
				IFEQ_BREAK(CRMV, "0");
				IFFOUND_CONTINUE(CRMV, ";", "O dado informado possui caracteres não permitidos.");

				if (strspn(CRMV.c_str(), "0123456789") == 0 || CRMV.length() < 4 || CRMV.length() > 6)
				{
					WARN("CRMV inválido!" << std::endl);	
				}
				else
				{
					if(this->findCRMV(CRMV) == this->funcionarios.end())
					{
						veterinario->setCRMV(CRMV);
						break;
					}
					else
					{
						WARN("Já existe um veterinário com este número de CRMV cadastrado." << std::endl);
					}	
				}	
			} while (1);	
		}
		else if(opt == "S" || opt == "s")
		{
			if(veterinario->getStatus() == ativo)
			{
				veterinario->setStatus(inativo);
			}
			else if(veterinario->getStatus() == inativo)
			{
				veterinario->setStatus(ativo);
			}
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
		this->save();
	}while(1);
}

/**
 * @brief Realiza a busca de um Veterinario pelo CRMV
 * @param CRMV :: CRMV referente ao veterinário
 * @return Retorna um iterador do vetor de funcionários referente ao veterinário
*/
std::map<int, std::shared_ptr<Funcionario>>::iterator PetFera::findCRMV(const std::string& CRMV)
{
	std::shared_ptr<Veterinario> veterinario;
	for(auto it = this->funcionarios.begin(); it != this->funcionarios.end(); ++it)
	{
		veterinario = std::dynamic_pointer_cast<Veterinario>(it->second);
		if(veterinario != nullptr && veterinario->getCRMV() == CRMV)
		{
			return it;
		}
	}
	return this->funcionarios.end();
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
		IFEQ_WPAUSERETURN(nome, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		IFFOUND_CONTINUE(nome, ";", "O dado informado possui caracteres não permitidos.");
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
		std::cout << "Informe o nível de segurança: (" << lib::color(fGREEN) << "VERDE" << lib::color(fRESET) << " | " << lib::color(fBLUE) << "AZUL" << lib::color(fRESET) << " | " << lib::color(fRED) << "VERMELHO" << lib::color(fRESET) << ")" << std::endl;
		USERENTRY( getline(std::cin, seguranca) );
		IFEQ_WPAUSERETURN(seguranca, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
		if(lib::stolower(seguranca) == "verde" )
		{
			seg = verde;
			break;
		}
		else if(lib::stolower(seguranca) == "azul")
		{
			seg = azul;
			break;
		}
		else if(lib::stolower(seguranca) == "vermelho")
		{
			seg = vermelho;
			break;
		}
		else
		{
			WARN("Informe um nível de segurança válido." << std::endl);
		}
	} while(1);

	this->cadTrat(nome, Status::ativo, seg, this->funcionarios.size() + 1);
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
std::shared_ptr<Tratador> PetFera::cadTrat(const std::string& nome, Status status, Seguranca seg, int id)
{
	std::shared_ptr<Tratador> tratador = std::make_shared<Tratador>(Tratador(nome, id, status, seg));
	this->funcionarios[id] = tratador;

	return tratador;
}

/**
 * @brief Altera os dados cadastrais de um Tratador
*/
void PetFera::altTrat()
{
	std::shared_ptr<Tratador> tratador = nullptr;
	std::string idAlter;
	do
	{
		std::cout << "Insira o tratador a ser alterado (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, idAlter) );
		IFEQ_WPAUSERETURN(idAlter, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(lib::stolower(idAlter)));
			if(tratador == nullptr)
				tratador = std::dynamic_pointer_cast<Tratador>(this->buscaFunc(atoi(idAlter.c_str())));

		if (tratador != nullptr)
		{
			break;
		}
		else
		{
			WARN("Funcionário não encontrado." << std::endl);
		}
	}while(1);

	std::string opt;
	do
	{
		lib::printTitle(tratador->getNome(), fGREEN);
		std::cout << (*tratador) << std::endl;
		NEWLINE;

		std::cout << "N. Alterar nome" << std::endl;
		std::cout << "C. Alterar nível de segurança" << std::endl;
		std::cout << "S. Alterar status" << std::endl;
		NEWLINE;
		std::cout << "X. Voltar" << std::endl;
		NEWLINE;
		
		USERENTRY( getline(std::cin, opt) );

		if(opt == "N" || opt == "n")
		{
			std::string nome;
			do
			{
				std::cout << "Informe o nome do tratador: " << std::endl;
				USERENTRY( getline(std::cin, nome) );
				IFEQ_BREAK(nome, "0");
				IFFOUND_CONTINUE(nome, ";", "O dado informado possui caracteres não permitidos.");
				if (nome != "")
				{
					tratador->setNome(nome);
					break;
				}
				else
				{
					WARN("Este campo não pode ser deixado em branco" << std::endl);
				}
			}while(1);
		}
		if(opt == "C" || opt == "c")
		{
			std::string seguranca;
			do
			{
				std::cout << "Informe o nível de segurança: (" << lib::color(fGREEN) << "VERDE" << lib::color(fRESET) << " | " << lib::color(fBLUE) << "AZUL" << lib::color(fRESET) << " | " << lib::color(fRED) << "VERMELHO" << lib::color(fRESET) << ")" << std::endl;
				USERENTRY( getline(std::cin, seguranca) );
				IFEQ_WPAUSERETURN(seguranca, "0", VOIDRETURN, "Operação cancelada pelo usuário.");
				if(lib::stolower(seguranca) == "verde")
				{
					tratador->setSeguranca(verde);
					break;
				}
				else if(lib::stolower(seguranca) == "azul")
				{
					tratador->setSeguranca(azul);
					break;
				}
				else if(lib::stolower(seguranca) == "vermelho")
				{
					tratador->setSeguranca(vermelho);
					break;
				}
				else
				{
					std::cout << "Informe um nível de segurança válido." << std::endl;
				}
			} while(1);
		}
		else if(opt == "S" || opt == "s")
		{
			if(tratador->getStatus() == ativo)
			{
				tratador->setStatus(inativo);
			}
			else if(tratador->getStatus() == inativo)
			{
				tratador->setStatus(ativo);
			}
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
		this->save();
	}while(1);
}

/**
 * @brief Cadastra um Funcionario
 * @details Realiza o cadastro de um funcionário preexistente
 * @param funcionario :: Ponteiro para um funcionário
 * @return Retorna um apontador para o funcionário recém-cadastrado
*/
std::shared_ptr<Funcionario> PetFera::cadFunc(std::shared_ptr<Funcionario>& funcionario)
{
	this->funcionarios[funcionario->getId()] = funcionario;

	return funcionario;
}

/**
 * @brief Busca um Funcionario na PetFera
 * @param id :: id referente ao funcionário
 * @return  Retorna um ponteiro para o funcionário ou nullptr caso não seja encontrado
*/
std::shared_ptr<Funcionario> PetFera::buscaFunc(int id)
{
	auto find = this->funcionarios.find(id);
	if(find != this->funcionarios.end() && find->second->getStatus() == ativo)
	{
		return find->second;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<Funcionario> PetFera::buscaFunc(const std::string& nome)
{
	for(auto f = this->funcionarios.begin(); f != this->funcionarios.end(); ++f)
	{
		if(lib::stolower(f->second->getNome()) == nome && f->second->getStatus() == ativo)
		{
			return f->second;
		}
	}
	return nullptr;
}

/**
 * @brief Remove um Funcionario da loja
 * @details Recolhe os dados necessários para que o funcionário seja removido do catálogo
 * @return Retorna um valor booleano referente ao sucesso da operação
*/
void PetFera::remFunc()
{
	std::shared_ptr<Funcionario> funcionario = nullptr;
	std::string id;
	do
	{
		std::cout << "Insira o funcionário a ser removido (nome ou ID): " << std::endl;
		USERENTRY( getline(std::cin, id) );
		IFEQ_WPAUSERETURN(id, "0", VOIDRETURN, "Operação cancelada pelo usuário.");

		funcionario = this->buscaFunc(lib::stolower(id));
			if(funcionario == nullptr)
				funcionario = this->buscaFunc(atoi(id.c_str()));

		if(funcionario != nullptr)
		{
			char opt;
			std::cout << "Remover " << funcionario->getNome() << "? S (Sim) | N (Não)" << std::endl;
			USERENTRY(lib::collect<char>(opt));
			IFEQ_WPAUSERETURN(opt, '0', VOIDRETURN, "Operação cancelada pelo usuário.");
			if(opt == 'S' || opt == 's')
			{
				break;	
			}
		}
		else
		{
			WARN("Funcionário não encontrado." << std::endl);
		}
	} while (1);

	if(this->remFunc(id))
	{
		FINALLY("Funcionário removido com sucesso" << std::endl);
		this->save();
	}
	else
	{
		WARN("Houve um problema ao tentar remover este funcionário." << std::endl);
	}

	PAUSE;
}

bool PetFera::remFunc(int id)
{
	std::stringstream ss;
	ss << id;
	return this->remFunc(ss.str());
}

bool PetFera::remFunc(const std::string& id)
{
	std::shared_ptr<Funcionario> funcionario = nullptr;
	for(auto it = this->funcionarios.begin(); it != this->funcionarios.end(); ++it)
	{
		funcionario = it->second;
		if(funcionario->getNome() == id || funcionario->getId() == atoi(id.c_str()))
		{
			this->funcionarios.erase(it);
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
	std::cout << lib::color(fCYAN) << "Veterinários:" << lib::color(fRESET) << std::endl;
	for(auto f : this->funcionarios)
	{
		if(std::dynamic_pointer_cast<Veterinario>(f.second))
		{
			std::cout << (*f.second) << std::endl;
		}
	}
	NEWLINE;
	std::cout << lib::color(fCYAN) << "Tratadores:" << lib::color(fRESET) << std::endl;
	for(auto f : this->funcionarios)
	{
		if(std::dynamic_pointer_cast<Tratador>(f.second))
		{
			std::cout << (*f.second) << std::endl;
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
		lib::printMenu("Pet Fera", "Menu Principal", fLIGHT_GREEN);
		std::cout << "C. Cadastrar animal" << std::endl;
		std::cout << "R. Remover um animal" << std::endl;
		std::cout << "A. Alterar dados de um animal" << std::endl;
		std::cout << "L. Listar animais" << std::endl;
		std::cout << "F. Listar funcionários" << std::endl;
		std::cout << "G. Gerenciar funcionários" << std::endl;
		NEWLINE;
		std::cout << "X. Sair" << std::endl;
		NEWLINE;
		USERENTRY( getline(std::cin, opt) );

		if(opt == "C" || opt == "c")
		{
			lib::printTitle("Cadastrar Animal", fLIGHT_GREEN);
			this->cadAnimal();
		}
		else if(opt == "R" || opt == "r")
		{
			lib::printTitle("Remover um animal", fLIGHT_GREEN);
			this->remAnimal();
		}
		else if(opt == "A" || opt == "a")
		{
			lib::printTitle("Alterar dados de um animal", fLIGHT_GREEN);
			this->altAnimal();
		}
		else if(opt == "L" || opt == "l")
		{
			this->listAnimal();
		}
		else if(opt == "F" || opt == "f")
		{
			lib::printTitle("Lista de funcionários", fLIGHT_GREEN);
			this->listFunc();
		}
		else if(opt == "G" || opt == "g")
		{
			this->gerCad();
		}
		else if(opt == "X" || opt == "x")
		{
			break;
		}
	}while(1);
}
