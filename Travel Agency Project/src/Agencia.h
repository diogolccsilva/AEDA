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
	/**
	   Construtor de Cidade

	    @param Nome da Cidade
	    @return
	*/
	Cidade(string nome);
	/**
	    Destrutor de Cidade

	    @param void
	    @return
	*/
	virtual ~Cidade();
	/**
	    Retorna o Nome da Cidade

	    @param void
	    @return Nome da Cidade
	*/
	string getNome() const;
	/**
	    Verifica a possibilidade de adicionar um Alojamento ao vetor alojamentos

	    @param Alojamento
	    @return true se for possivel adicionar o Alojamento , caso contrario false
	*/
	bool addAlojamento(const Alojamento& a);
	/**
	    Overload do operador ==

	    @param  a Alojamento
	    @return true se o Alojamento a e igual a um Alojamento, caso contrario false
	*/
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
	/**
	    Construtor de Transporte

	    @param void
	    @return
	*/
	Transporte();
	/**
	    Destrutor de Transporte

	    @param void
	    @return
	*/
	virtual ~Transporte();
};

class Troco {
	Cidade origem,destino;
	Transporte transporte;
	tm data;
public:
	/**
	    Construtor de Troco

	    @param origem Cidade
	    @param destino Cidade
	    @param transporte Transporte
	    @param data tm
	    @return
	*/
	Troco(Cidade origem,Cidade destino,Transporte transporte,tm data);
	/**
	    Destrutor de Troco

	    @param void
	    @return
	*/
	virtual ~Troco();
	/**
	    Retorna a Cidade de Origem do Troco

	    @param void
	    @return Cidade de  Origem do Troco
	*/
	Cidade getCidadeOrigem() const;
	/**
		    Retorna a Cidade de Destino do Troco

		    @param void
		    @return Cidade de Destino do Troco
		*/
	Cidade getCidadeDestino() const;
	/**
		    Retorna o Transporte utizado

		    @param void
		    @return Transporte
		*/
	Transporte getTransporte() const;
	/**
		    Retorna a Data em que o Troco foi executado

		    @param void
		    @return Data
		*/
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
	float preco; //apenas o preco da viagem, para obter o preco total adicionar o preco do alojamento
	int id;
	static int sid;
public:
	/**
		   Construtor de Viagem

		    @param itinerario Itinerario
		    @param preco float
		    @param id int
		    @param alojamento Alojamento
		    @return
	*/
	Viagem(Itinerario itinerario,float preco,int id = sid++,Alojamento* alojamento = new Alojamento());
	/**
			   Destrutor de Viagem

			   @param void
		       @return
	*/

	virtual ~Viagem();
	/**
			   Retorna o Preco Total da Viagem

			    @param void
			    @return Preco
	*/

	float getPreco() const; //retorna o preco total da viagem (incluindo alojamento)
	/**
			   Retorna o Itinerario da Viagem

			    @param void
			    @return Itinerario
	*/

	Itinerario getItinerario() const;
	/**
			   Retorna o Alojamento, se este existir

			    @param void
			    @return Alojamento
	*/

	Alojamento* getAlojamento() const;
	/**
			   Overload do operador ==

			    @param v Viagem
			    @return true se a Viagem v é igual a uma Viagem , caso contrario false
	*/
	bool operator==(const Viagem& v) const;
	/**
			   Retorna o Id da Viagem

			    @param void
			    @return Id da Viagem
	*/

	int getId() const;
	/**
			  Adiciona um Alojamento as caracteristicas de viagem, uma vez que este nao e obrigatorio

			   @param alojamento Alojamento
			   @return
	*/

	bool addAlojamento(Alojamento* a);
	/**
			   Elimina o Alojamento

			    @param void
			    @return
		*/

	void delAlojamento();
	/**
			   Altera o Alojamento da Viagem

			   @param a Alojamento
			   @return true, se alteracao for aplicada, caso contrario false
	*/

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
	virtual string getTipo() const = 0;
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
	Comercial(string nome,int noparticipantes = 0);
	virtual ~Comercial();
	void addViagem(Viagem* v,int np);
	int getMedParticipantes() const;
	float desconto();
	string getTipo() const;
};

class Agencia {
	string nome;
	vector<Cliente*> clientes; //clientes da agencia
	vector<Viagem> viagens; //totalidade de viagens da agencia (ja efetuadas e futuras)
	vector<Pais> paises; //paises para os quais faz viagens
public:
	Agencia(string nome);
	virtual ~Agencia();
	string getNome() const;
	bool addCliente(Cliente* c);
	void sortClientes();
	vector<Cliente*> getClientes() const;
	bool addViagem(Viagem v);
	bool addPais(Pais p);
	Cliente* getCliente(string nome) const;
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

