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
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

class Alojamento {
	string tipo,nome;
	float preco;
public:
	Alojamento();
	Alojamento(string tipo,string nome,float preco);
	virtual ~Alojamento();
	bool operator==(const Alojamento& a) const;
};

class Cidade {
	string nome;
	vector<Alojamento> alojamentos;
public:
	Cidade(string nome);
	virtual ~Cidade();
	string getNome() const;
	bool addAlojamento(const Alojamento& a);
	bool operator==(const Cidade& c) const;
};

class Pais {
	vector<Cidade> cidades;
	string nome;
public:
	Pais(string nome);
	virtual ~Pais();
	bool addCidade(const Cidade& c);
	string getNome() const;
	bool operator==(const Pais& p) const;
	Cidade getCidade(string nome) const;
	class CidadeInexistente{
		string nome;
	public:
		CidadeInexistente(string nome);
	};
};

class Transporte {
public:
	Transporte();
	virtual ~Transporte();
};

class Troco {
	Cidade origem,destino;
	Transporte transporte;
	tm data;
public:
	Troco(Cidade origem,Cidade destino,Transporte transporte,tm data);
	virtual ~Troco();
	Cidade getCidadeOrigem() const;
	Cidade getCidadeDestino() const;
	Transporte getTransporte() const;
	tm getData() const;
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
	Itinerario itinerario;
	Alojamento* alojamento;
	float preco; //apenas o preço da viagem, para obter o preço total adicionar o preço do alojamento
	int id;
	static int sid;
public:
	Viagem(Itinerario itinerario,float preco,Alojamento* alojamento = new Alojamento());
	virtual ~Viagem();
	float getPreco() const;
	Itinerario getItinerario();
	Alojamento* getAlojamento();
	bool operator==(const Viagem& v) const;
	int getId() const;
	bool addAlojamento(Alojamento* a);
	void delAlojamento();
	bool changeAlojamento(Alojamento* a);
};

class Cliente {
	string nome; //nome do cliente
	vector<Viagem*> viagens; //totalidade de viagens do cliente (ja efetuadas e futuras)
public:
	Cliente();
	Cliente(string nome);
	virtual ~Cliente();
	int getNoViagens() const;
	string getNome() const;
	bool operator==(const Cliente& c) const;
	virtual void addViagem(Viagem* v);
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
	vector<Cliente> clientes; //clientes da agencia
	vector<Viagem> viagens; //totalidade de viagens da agência (já efetuadas e futuras)
	vector<Pais> paises; //paises para os quais faz viagens
public:
	Agencia(string nome);
	virtual ~Agencia();
	string getNome() const;
	bool addCliente(Cliente c);
	void sortClientes();
	vector<Cliente> getClientes() const;
	bool addViagem(Viagem v);
	bool addPais(Pais p);
	Cliente getCliente(string nome) const;
	class ClienteInexistente{
		string nome;
	public:
		ClienteInexistente(string nome);
	};
	Pais getPais(string nome) const;
	class PaisInexistente{
		string nome;
	public:
		PaisInexistente(string nome);
	};
	void loadDestinos();
	void loadViagens();
	void loadClientes();
};

#endif /* SRC_AGENCIA_H_ */

