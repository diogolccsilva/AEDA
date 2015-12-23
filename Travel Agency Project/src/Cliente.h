/*
 * Cliente.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include "Destino.h"

class Cliente {
	string nome, email, morada;
	vector<Viagem*> viagens;
	int pontos;
	vector<Destino*> destinos;
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
	Cliente(string nome, string email, string morada, int pontos = 0);
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
	 Get do Email do Cliente
	 @param void
	 @return Email do Cliente
	 */
	string getEmail() const;
	/**
	 Set do Email do Cliente
	 @param email String que se pretende adicionar ou alterar
	 @return void
	 */
	void setEmail(string e);
	/**
	 Get da Morada do Cliente
	 @param void
	 @return Morada do Cliente
	 */
	string getMorada() const;
	/**
	 Set da Morada do Cliente
	 @param morada String que se pretende adicionar ou alterar
	 @return void
	 */
	void setMorada(string m);
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
	 Get do Numero Participantes no Cliente Comercial
	 @param void
	 @return Numero de Participantes
	 */
	virtual int getNoParticipantes() const = 0;
	/**
	 Calculo do desconto do Cliente
	 @param void
	 @return Desconto do cliente
	 */
	virtual float desconto() const = 0;
	/**
	 Calculo da media de participantes do Cliente Comercial
	 @param void
	 @return Media de Participantes
	 */
	virtual int getMedParticipantes() const = 0;
	/**
	 Overload do operador << da classe Cliente
	 @param o Parâmetro de saída
	 @param c Cliente
	 @return Parâmetro de saída
	 */
	friend ostream & operator<<(ostream & o, const Cliente & c);
	int getPontos() const;
	bool operator<(const Cliente& a1) const;
	void atualizaPontos(Cliente* c);
	void printViagens() const;
	bool addDestino(Destino* d);
	vector<Destino*> getDestinos() const;
};

struct hstr
{
	int operator()(const Cliente* s1) const
	{
		string f1 = s1->getNome();
		int v = 0;
		for (unsigned int i = 0; i < f1.size(); i++)
			v = 37 * v + f1[i];
		return v;
	}

	bool operator() (const Cliente * s1, const Cliente* s2) const
	{
	return s1->getEmail()==s2->getEmail();
	}
};

#endif // SRC_CLIENTE_H_
