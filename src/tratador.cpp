
#include "tratador.hpp"

Tratador::Tratador()
{}

Tratador::Tratador(std::string nome, short id, Status status, Seguranca seguranca) :
Funcionario(nome, id, status), seguranca(seguranca)
{}

Tratador::~Tratador()
{}

Seguranca Tratador::getSeguranca() const
{
	return this->seguranca;
}

void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}

void Tratador::print(std::ostream& o)
{
	o << "ID:" << this->getId() << std::endl;
	o << "NOME: " << this->getNome() << std::endl;
	o << "NIVEL DE SEGURANÇA: ";
	std::string Seguranca_;
	if (this->getSeguranca() == verde){
		Color(fGREEN);
		Seguranca_="Aves";
	}
	else if (this->getSeguranca() == azul){
		Color(fBLUE);
		Seguranca_="Aves, Mamíferos e Répteis";
	}
	else if (this->getSeguranca() == vermelho){
		Color(fRED);
		Seguranca_="Animais venenosos ou perigosos";
	}
	o << Seguranca_ << std::endl;
	Color(fRESET);
}
