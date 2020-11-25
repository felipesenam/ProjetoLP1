
#include "tratador.hpp"

/**
 * @brief Construtor padrão
*/
Tratador::Tratador()
{}

/**
 * @brief Construtor parametrizado do Tratador
 * @param nome :: Especifica a nome do Tratador
 * @param id :: Especifica o id do Tratador
 * @param status :: Informa se o Tratador está ativo ou suspenso na empresa
 * @param seguranca :: nivel de segurança do tratador para manejo de animais
*/
Tratador::Tratador(std::string nome, short id, Status status, Seguranca seguranca) :
Funcionario(nome, id, status), seguranca(seguranca)
{}

/**
 * @brief Destrutor padrão
*/
Tratador::~Tratador()
{}

/**
 * @brief Retorna o nivel de segurança do tratador
 * @return seguranca
*/
Seguranca Tratador::getSeguranca() const
{
	return this->seguranca;
}

/**
 * @brief Seta o nivel de segurança do tratador
 * @param segurança :: nivel de segurança do tratador
*/
void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}

/**
 * @brief imprime os dados do Tratador
 * @param o :: ostream
*/
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
