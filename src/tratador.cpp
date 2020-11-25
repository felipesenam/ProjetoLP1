
#include "tratador.hpp"

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
Tratador::Tratador()
{}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
Tratador::Tratador(std::string nome, short id, Status status, Seguranca seguranca) :
Funcionario(nome, id, status), seguranca(seguranca)
{}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
Tratador::~Tratador()
{}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
Seguranca Tratador::getSeguranca() const
{
	return this->seguranca;
}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
*/
void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}

/**
 * @brief DESCRIÇÃO_BREVE_DA_FUNÇÃO
 * @details DESCRIÇÃO_DETALHADA_DA_FUNÇÃO
 * @param PARÂMETROS_PASSADOS_PARA_A_FUNÇÃO
 * @return RETORNO_DA_FUNÇÃO
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
