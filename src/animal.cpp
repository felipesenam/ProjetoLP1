
#include "animal.hpp"

Animal::Animal(short id, classificacao classificacao_,char ameacadaExtincao, char perigoso, string NF):id(id),
classificacao_(classificacao_),ameacadaExtincao(ameacadaExtincao),perigoso(perigoso),NF(NF)
{
	Debug("Animal " << this->id << " [" << this << "] foi criado." << endl);
}

Animal::Animal(){}

Animal::~Animal()
{}

short 
Animal::getId() const
{
	return this->id;
}

classificacao 
Animal::getClassificacao() const
{
	return this->classificacao_;
}

void 
Animal::printAnimal()
{
	cout<<"id: "<< this->id<<endl
	<<"Classificação: "<< this->classificacao_<<endl
	<<"extinção? "<<this->ameacadaExtincao<<endl
	<<"perigoso? "<<this->perigoso<<endl
	<<"NF: "<<this->NF<<endl;
}

ostream& operator<< (ostream& saida, Animal& a) {
	cout << "id: "<< a.id<<endl << "Classificação: "<< a.classificacao_<<endl
	 <<"extinção? "<<a.ameacadaExtincao<<endl <<"perigoso? "<<a.perigoso<<endl
	 <<"NF: "<<a.NF<<endl;
	return saida;
}
