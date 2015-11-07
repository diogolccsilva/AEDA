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
	/**
	 Construtor base Alojamento
	 @param
	 @return
	 */
	Alojamento();
	/**
	 Construtor Alojamento
	 @param tipo Tipo de Alojamento
	 @param nome Nome do Alojamento
	 @param preco Preco do Alojamento
	 @return
	 */
	Alojamento(string tipo,string nome,float preco);
	/**
	 Destrutor Alojamento
	 @param void
	 @return
	 */
	virtual ~Alojamento();
	/**
	 Overload do operador == em Alojamento
	 @param a Alojamento por referencia
	 @return Alojamento e, ou nao, igual
	 */
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
	/**
	 Construtor de Pais
	 @param Nome do Pais
	 @return
	 */
	Pais(string nome);
	/**
	 Destrutor de Pais
	 @param void
	 @return
	 */
	virtual ~Pais();
	/**
	 Booleana para saber se pode adicionar cidade
	 @param c Cidade que se deseja adicionar
	 @return Retorna se pode adicionar a cidade
	 */
	bool addCidade(const Cidade& c);
	/**
	 Get do Nome do Pais
	 @param void
	 @return Nome do Pais
	 */
	string getNome() const;
	/**
	 Overload do operador == em Pais
	 @param p Pais por referência
	 @return Pais e, ou nao, igual
	 */
	bool operator==(const Pais& p) const;
	/**
	 Get da cidade do Pais
	 @param nome Nome da cidade
	 @return Nome da cidade
	 */
	Cidade getCidade(string nome) const;
	/**
	 Classe da excecao Cidade Inexistente
	 @param void
	 @return
	 */
	class CidadeInexistente{
		string nome;
	public:
		/**
		 Construtor da excecao Cidade Inexistente
		 @param nome Nome da Cidade Inexistente
		 @return
		 */
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
	/**
	 Construtor Itinerario
	 @param origem Cidade Origem
	 @param destino Cidade de Destino
	 @return
	 */
	Itinerario(Cidade origem,Cidade destino);
	/**
	 Adiciona um novo troco
	 @param troco Novo troco
	 @return
	 */
	void AddTroco(Troco troco);
	/**
	 Destrutor de Itinerario
	 @param
	 @return
	 */
	virtual ~Itinerario();
	/**
	 Get do vetor de Trocos
	 @param void
	 @return Vetor Trocos
	 */
	vector<Troco> getTrocos();
	/**
	 Get da cidade Origem do Troco
	 @param void
	 @return Cidade Origem do Troco
	 */
	Cidade getOrigem();
	/**
	 Get da cidade Destino do Troco
	 @param void
	 @return Cidade Destino do Troco
	 */
	Cidade getDestino();

};

class Viagem {
	Itinerario itinerario;
	Alojamento* alojamento;
	float preco; //apenas o preco da viagem, para obter o preco total adicionar o preco do alojamento
	int id;
	static int sid;
public:
	Viagem(Itinerario itinerario,float preco,int id = sid++,Alojamento* alojamento = new Alojamento());
	virtual ~Viagem();
	float getPreco() const; //retorna o preco total da viagem (incluindo alojamento)
	Itinerario getItinerario() const; //retorna o Itinerario da viagem
	Alojamento* getAlojamento() const; //retorna o Alojamento da viagem
	bool operator==(const Viagem& v) const; //overload da função ==
	int getId() const; //retorna o ID da viagem
	bool addAlojamento(Alojamento* a); //verifica se pode adicionar alojamento
	void delAlojamento(); //Elimina alojamento
	bool changeAlojamento(Alojamento* a);
};

class Cliente {
	string nome; //nome do cliente
	vector<Viagem*> viagens; //totalidade de viagens do cliente (ja efetuadas e futuras)
public:
	/**
	 Construtor base de Cliente
	 @param void
	 @return
	 */
	Cliente();
	/**
	 Construtor Cliente
	 @param nome Nome do Cliente
	 @return
	 */
	Cliente(string nome);
	/**
	 Destrutor de Cliente
	 @param void
	 @return
	 */
	virtual ~Cliente();
	/**
	 Get do Numero de Viagens
	 @param void
	 @return Número de Viagens
	 */
	int getNoViagens() const;
	/**
	 Get do Nome do Cliente
	 @param void
	 @return Nome do Cliente
	 */
	string getNome() const;
	/**
	 Overload do operador == em Clientes
	 @param c Cliente
	 @return Se cliente e, ou nao, igual
	 */
	bool operator==(const Cliente& c) const;
	/**
	 Funcao virtual para adicionar
	 @param v Viagem que se pretende adicionar
	 @return
	 */
	virtual void addViagem(Viagem* v);
	/**
	 Get do vetor Viagens
	 @param void
	 @return Vetor Viagens da classe Viagem
	 */
	vector<Viagem*> getViagens() const;
	/**
	 Tipo de Cliente (Comercial ou Privado)
	 @param void
	 @return 0
	 */
	virtual string getTipo() const = 0;
	/**
	 Overload do operador << da classe Cliente
	 @param o Parâmetro de saída
	 @param c Cliente
	 @return Parâmetro de saída
	 */
	friend ostream & operator<<(ostream & o, const Cliente & c);
};

class Particular: public Cliente {
public:
	/**
	 Construtor da classe Particular
	 @param nome Nome do Cliente
	 @return
	 */
	Particular(string nome);
	/**
	 Destrutor
	 @param void
	 @return
	 */
	virtual ~Particular();
	/**
	 Get do Tipo de Cliente
	 @param void
	 @return Tipo de Cliente
	 */
	string getTipo() const;
};

class Comercial: public Cliente {
	int noparticipantes;
public:
	/**
	 Construtor da classe Comercial
	 @param nome Nome do Cliente
	 @param noparticipantes Numero de Participantes do Cliente
	 @return
	 */
	Comercial(string nome,int noparticipantes = 0);
	/**
	 Destrutor
	 @param void
	 @return
	 */
	virtual ~Comercial();
	/**
	 Adiciona Viagem
	 @param v Apontador para a Viagem
	 @param np Numero de Participantes
	 @return
	 */
	void addViagem(Viagem* v,int np);
	/**
	 Get da Media de Participantes
	 @param void
	 @return Media de Participantes
	 */
	int getMedParticipantes() const;
	/**
	 Calculo do desconto do Cliente
	 @param
	 @return Desconto
	 */
	float desconto();
	/**
	 Get do Tipo de Cliente
	 @param void
	 @return Tipo de Cliente
	 */
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

