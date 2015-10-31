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


class Alojamento {
	string tipo,nome;
	float preco;
public:
	Alojamento(string tipo,string nome,float preco);
	virtual ~Alojamento();

};

class Cidade {
	string nome;
	vector<Alojamento*> alojamentos;
public:
	Cidade(string nome);
	virtual ~Cidade();
	string getNome() const;
	bool addAlojamento(Alojamento* a);
};

class Pais {
	vector<Cidade> cidades;
	string nome;
public:
	Pais(string nome);
	virtual ~Pais();
	bool addCidade(Cidade c);
	string getNome() const;
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
	Alojamento* alojamento;
	Itinerario itinerario;
	float preco;
	tm data;
	int id;
	static int sid;
public:
	Viagem(Itinerario itinerario,Alojamento* alojamento,float preco,tm date);
	virtual ~Viagem();
	float getPreco() const;
	Itinerario getItinerario();
	Alojamento* getAlojamento();
	tm getData() const;
	bool operator ==(const Viagem v);
	int getId() const;
};

class Cliente {
	string nome;
protected:
	vector<Viagem*> viagens;
public:
	Cliente(string nome);
	virtual ~Cliente();
	int getNoViagens() const;
	string getNome() const;
	bool operator ==(const Cliente c);
	virtual void addViagem(Viagem v);
	vector<Viagem*> getViagens() const;
	virtual string getTipo() const;
	friend ostream & operator<<(ostream & o, const Cliente & c);
};

class Particular: public Cliente {
public:
	Particular(string nome);
	virtual ~Particular();
	string getTipo() const;
};

class Comercial: public Cliente {
	int noparticipantes;
public:
	Comercial(string nome);
	virtual ~Comercial();
	void addViagem(Viagem* v,int np);
	int getMedParticipantes() const;
	float desconto();
	string getTipo() const;
};

class Agencia {
	string nome;
	vector<Cliente> clientes;
	vector<Viagem> viagens;
	vector<Alojamento> alojamentos;
public:
	Agencia(string nome);
	virtual ~Agencia();
	string getNome() const;
	bool addCliente(Cliente c);
	void sortClientes();
	vector<Cliente> getClientes();
	bool addViagem(Viagem v);
};
#endif /* SRC_AGENCIA_H_ */

