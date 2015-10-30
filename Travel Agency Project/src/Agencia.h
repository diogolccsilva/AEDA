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
#include <ctime>

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
	string tipo,nome;
public:
	Alojamento(string tipo,string nome);
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
	Cidade getCidadeOrigem() const;
	Cidade getCidadeDestino() const;
	Transporte getTransporte() const;

};

class Itinerario {
	Cidade origem,destino;
	vector<Troco> trocos;
public:
	Itinerario(Cidade origem,Cidade destino);
	void AddTroco(Troco troco);
	virtual ~Itinerario();
	vector<Troco> getTrocos();
	Cidade getOrigem();
	Cidade getDestino();

};

class Viagem {
	Alojamento alojamento;
	Itinerario itinerario;
	float preco;
	tm data;
public:
	Viagem(Itinerario itinerario,Alojamento alojamento,float preco,tm date);
	virtual ~Viagem();
	float getPreco() const;
	Itinerario getItinerario();
	Alojamento getAlojamento();
	tm getData() const;
};

class Cliente {
	string nome;
protected:
	vector<Viagem> viagens;
public:
	Cliente(string nome);
	virtual ~Cliente();
	int getNoViagens() const;
	string getNome() const;
	bool operator ==(const Cliente cliente);
	virtual void addViagem(Viagem viagem);
	vector<Viagem> getViagens() const;
};

class Particular: public Cliente {
public:
	Particular(string nome);
	virtual ~Particular();
};

class Comercial: public Cliente {
	int noparticipantes;
public:
	Comercial(string nome);
	virtual ~Comercial();
	void addViagem(Viagem viagem,int noparticipantes);
	int getMedParticipantes() const;
	float desconto();
};

class Agencia {
	string nome;
	vector<Cliente> clientes;
public:
	Agencia(string nome);
	virtual ~Agencia();
	string getNome() const;
	bool addCliente(Cliente cliente);
	void sortClientes();
	vector<Cliente> getClientes();
};
#endif /* SRC_AGENCIA_H_ */

