
#include "tratador.hpp"

/**
 * @brief Construtor padrão
*/
Tratador::Tratador()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado." << std::endl);
}

/**
 * @brief Construtor parametrizado do Tratador
 * @param nome :: Especifica a nome do Tratador
 * @param id :: Especifica o id do Tratador
 * @param status :: Informa se o Tratador está ativo ou suspenso na empresa
 * @param seguranca :: nivel de segurança do tratador para manejo de animais
*/
Tratador::Tratador(const std::string& nome, short id, Status status, Seguranca seguranca) :
Funcionario(nome, id, status), seguranca(seguranca)
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi criado por parâmetro." << std::endl);
}

/**
 * @brief Destrutor padrão
*/
Tratador::~Tratador()
{
	Debug(typeid(*this).name() << " ID:" << this->id << " [" << this << "] foi destruído." << std::endl);
}

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
 * @param seguranca :: nivel de segurança do tratador
*/
void Tratador::setSeguranca(Seguranca seguranca)
{
	this->seguranca = seguranca;
}

/**
 * @brief imprime os dados do Tratador
 * @param o :: Stream de saída dos dados
*/
void Tratador::print(std::ostream& o)
{
	o << "ID: " << this->getId() << std::endl;
	o << "NOME: " << this->getNome() << std::endl;

	o << "NIVEL DE SEGURANÇA: ";
	if (this->getSeguranca() == verde)
	{
		o << lib::color(fGREEN) << "Aves" << lib::color(fRESET) << std::endl;
	}
	else if (this->getSeguranca() == azul)
	{
		o << lib::color(fBLUE) << "Aves, mamíferos e répteis" << lib::color(fRESET) << std::endl;
	}
	else if (this->getSeguranca() == vermelho)
	{
		o << lib::color(fRED) << "Animais venenosos ou perigosos" << lib::color(fRESET) << std::endl;
	}

	o << "STATUS: ";
	if (this->status == inativo)
	{
		o << lib::color(fRED) << "inativo" << lib::color(fRESET) << std::endl;
	}
	else
	{
		o << lib::color(fGREEN) << "ativo" << lib::color(fRESET) << std::endl;
	}
}

void Tratador::save(std::ofstream& file)
{
	file
	 << this->id     << ";"
	 << this->nome   << ";"
	 << this->status << ";"
	 << this->seguranca;
}

/**
 * @brief Verifica se um Tratador está apto a cuidar de um animal
 * @param classe :: Informa a classe do animal que será tratado
 * @param perigoso :: Informa se o animal que será tratado é perigoso
 * @return Retorna um valor booleano true caso o tratador seja apto a tratar do animal, false caso contrário
*/
bool Tratador::aptto(Classe classe, bool perigoso)
{
	if(this->seguranca == verde)
	{
		if(classe == ave && !perigoso)
		{
			return true;
		}
	}
	else if(this->seguranca == azul)
	{
		if((classe == ave || classe == mamifero || classe == reptil) && !perigoso)
		{
			return true;
		}
	}
	else if(this->seguranca == vermelho)
	{
		return true;
	}
	return false;
}
