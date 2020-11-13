
#include "petfera.hpp"

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
		{ cout<< "Insira o id do animal: "<<endl;
		cin>>id;
		if (this->buscarId(id)!=nullptr)
			cout<< "Erro! ID já cadastrado"<<endl;
			
		} while (this->buscarId(id)!=nullptr);
		std::cin.clear();

	do {
		cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
		cin>>strClassificacao_;
		if (strClassificacao_ != "N" && strClassificacao_ != "n"
			&& strClassificacao_ != "E" && strClassificacao_ != "e"
			&& strClassificacao_ != "D" && strClassificacao_ != "d")
			cout<<"Opção inválida"<<endl;
	} 	while (strClassificacao_ != "N" && strClassificacao_ != "n"
			&& strClassificacao_ != "E" && strClassificacao_ != "e"
			&& strClassificacao_ != "D" && strClassificacao_ != "d");
	std::cin.clear();

	do {
		cout<< "O animal possui algum grau de extinção? S (sim) / N (não)"<<endl;
		cin>>ameacadaExtincao;
		if (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N')
			cout<<"Opção inválida"<<endl;
	} while (ameacadaExtincao != 's' && ameacadaExtincao != 'S'
			&& ameacadaExtincao != 'n' && ameacadaExtincao != 'N' );
		std::cin.clear();

	do {
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

	if (strClassificacao_=="E" || strClassificacao_=="e") {
		classificacao_ = exotico;
	} else if (strClassificacao_=="D" || strClassificacao_=="d") {
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
	do{
		cout<<"Insira o id do animal a ser removido.";
		cin>>idRem;

	} while (this->buscarId(idRem)==nullptr);

	if (this->remAnimal_(idRem)) {
		cout << "Operação realizada com sucesso." << endl;
	} else {
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
		cout << "Não há animais cadastrados." << endl;
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

Animal* PetFera::buscarId(int id) { //Busca o id do animal no vetor
	for (auto& animal : this->animais)
	{
		if (animal->getId()==id)
		{
			return animal;
		}
	}
	return nullptr;
}