#include "funcionario.hpp"

	Funcionario::Funcionario(){
	}
	Funcionario::Funcionario(std::string nome, short id, Status status):nome(nome), id(id), status(status)
	{}
	Funcionario::~Funcionario()
	{}
	std::string Funcionario:: getNome() const 
	{
		return this->nome;
	}
	short Funcionario::getId() const
	{
		return this->id;
	}

	void Funcionario::setNome(std::string nome){
		this->nome=nome;
	}
	void Funcionario::setStatus(Status status){
		this->status=status;
	}