
#include "veterinario.hpp"

/**
 * @brief Construtor padrão
*/
Veterinario::Veterinario()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor parametrizado do Veterinario
 * @param nome :: Especifica a nome do veterinário
 * @param id :: Especifica o id do veterinário
 * @param status :: Informa se o veterinário está ativo ou suspenso na empresa
 * @param CRMV :: CRMV do veterinario
*/
Veterinario::Veterinario(const std::string& nome, short id , Status status, const std::string& CRMV) : Funcionario(nome, 
id, status), CRMV(CRMV)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado por parâmetro." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
Veterinario::~Veterinario()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruído." << std::endl);
}

/**
 * @brief Retorna o numero do CRMV do veterinario
 * @return CRMV
*/
std::string Veterinario::getCRMV() const
{
	return this->CRMV;
}

/**
 * @brief Seta o numero do CRMV do veterinario
 * @param CRMV :: numero do CRMV do veterinario
*/
void Veterinario::setCRMV(const std::string& CRMV)
{
	this->CRMV = CRMV;
}

/**
 * @brief imprime os dados do Veterinario
 * @param o :: Stream de saída dos dados
*/
void Veterinario::print(std::ostream& o)
{
	o << "ID: " << this->getId() << std::endl;
	o << "NOME: " << this->getNome() << std::endl;
	o << "CRMV: " << this->getCRMV() << std::endl;
	
	if (this->status == inativo)
	{
		o << "STATUS: " << lib::color(fRED) << "inativo" << lib::color(fRESET) << std::endl;
	}
	else
	{
		o << "STATUS: " << lib::color(fGREEN) << "ativo" << lib::color(fRESET) << std::endl;
	}
}
void Veterinario::save(std::ofstream& file)
{
	file
	 << this->id     << ";"
	 << this->nome   << ";"
	 << this->status << ";"
	 << this->CRMV;
}
