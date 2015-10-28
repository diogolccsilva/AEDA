/*
 * Agencia.h
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#ifndef SRC_AGENCIA_H_
#define SRC_AGENCIA_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cidade {
	string nome;
public:
	Cidade(string nome);
	virtual ~Cidade();
	string getNome() const;
};

class Pais {
	vector<Cidade*> cidades;
	string nome;
public:
	Pais(string nome);
	virtual ~Pais();
	void AddCidade(Cidade *cidade);
	string getNome() const;
};

class Alojamento {
public:
	Alojamento();
	virtual ~Alojamento();
};

class Transporte {
public:
	Transporte();
	virtual ~Transporte();
};

class Troco {
	Cidade origem,destino;
	Transporte transporte;
public:
	Troco(Cidade origem,Cidade destino,Transporte transporte);
	virtual ~Troco();

};

class Itenerario {
	Cidade origem,destino;
	vector<Troco> trocos;
public:
	Itenerario(Cidade origem,Cidade destino);
	void AddTroco(Troco troco);
	virtual ~Itenerario();
	vector<Troco> getTrocos();
	Cidade getOrigem();
	Cidade getDestino();

};

class Viagem {
	Alojamento alojamento;
	Itenerario itenerario;
	float preco;
public:
	Viagem(Itenerario itenerario,Alojamento alojamento,float preco);
	virtual ~Viagem();
	float getPreco() const;
	Itenerario getItenerario();
	Alojamento getAlojamento();
};

class Cliente {
	int noviagens;
	string nome;
	vector<Viagem> viagens;
public:
	Cliente(string nome,int noviagens = 0);
	virtual ~Cliente();
	int getNoviagens() const;
	string getNome() const;
	bool operator ==(const Cliente cliente);
	void addViagem(Viagem viagem);
};

class Particular: public Cliente {
public:
	Particular(string nome,int noviagens=0);
	virtual ~Particular();
};

class Comercial: public Cliente {
	int noparticipantes;
public:
	Comercial(string nome,int noviagens=0);
	virtual ~Comercial();
};

class Agencia {
	string nome;
	vector<Cliente> clientes;
public:
	Agencia(string nome);
	virtual ~Agencia();
	string getNome() const;
	bool addCliente(Cliente cliente);
};
#endif /* SRC_AGENCIA_H_ */

