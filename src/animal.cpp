#include "animal.hpp"

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x) 
#endif 

Animal::Animal(short id, classificacao classificacao_, bool perigoso, string NF):id(id),
classificacao_(classificacao_),perigoso(perigoso),NF(NF){
	Debug("Animal " << this->id << " [" << this << "] foi criado." << endl);
}

Animal::~Animal(){}

short 
Animal::getId(){
	return this->id;
}

classificacao 
Animal::getClassificacao(){
	return this->classificacao_;
}

void 
Animal::printAnimal(){
	cout<<"id: "<< this->id<<endl
	<<"Classificação: "<< this->classificacao_<<endl
	<<"perigoso? "<<this->perigoso<<endl
	<<"NF: "<<this->NF<<endl;
}