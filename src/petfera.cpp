
#include "petfera.hpp"
#include "interface.hpp"

void PetFera::cadAnimal()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore to the end of line
	cout<<"Entrou"<<endl;
	short id;
	string strClassificacao_;
	classificacao classificacao_;
	char ameacadaExtincao;
	char perigoso;        
	string NF;
	Animal* criado = nullptr;

	cout<< "Insira o id do animal: "<<endl;
	cin>>id;
	std::cin.clear();
	cout<< "Insira a classificação para manejo: N - Nativo | E - Exotico | D - Domestico"<<endl;
	cin>>strClassificacao_;
	std::cin.clear();
	cout<< "O animal possui algum grau de extinção? S (sim) / N (não) "<<endl;
	cin>>ameacadaExtincao;
	std::cin.clear();
	cout<< "O animal é considerado perigoso ou venenoso? S (sim) / N (não) "<<endl;
	cin>>perigoso;
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
		cout << "Erro!! Operação cancelada." << endl;
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

}

void PetFera::altAnimal()
{

}

void PetFera::listClass()
{
	if (this->animais.size()==0) {
		cout << "Não há animais cadastrados." << endl;
	for (auto& animal : this->animais)
		{
			animal->printAnimal();
		}
	}
	PAUSE;
}

void PetFera::listRespn()
{

}