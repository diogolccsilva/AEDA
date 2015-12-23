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
	string nome, email, morada,status;
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
	Cliente(string nome, string email, string morada,string status = "Antigo", int pontos = 0);
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
	 Get do Status do Cliente
	 @param void
	 @return status Status do cliente
	 */
	string getStatus()const;
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
	/**
	 Get dos Pontos do CLiente
	 @param
	 @return void
	 */
	int getPontos() const;
	/**
	 Compara dois clientes e verifica qual tem menos pontos
	 @param a1 Cliente por referencia
	 @return true se for menor
	 @return false se for maior ou igual
	 */
	bool operator<(const Cliente& a1) const;
	/**
	 Funcao que atualiza os pontos de um cliente
	 @param c Cliente por apontador
	 @return void
	 */
	void updatePontos();
	/**
	 Funcao que faz o print das viagens de um cliente
	 @param
	 @return void
	 */
	void printViagens() const;
	/**
	 Funcao boleana que adiciona um destino ao cliente
	 @param d Destino por apontador
	 @return true se adicionar
	 @return false se nao adicionar
	 */
	bool addDestino(Destino* d);
	/**
	 Get do vetor de Destinos
	 @param
	 @return vector<Detino*> Vetor de destinos
	 */
	vector<Destino*> getDestinos() const;
	/**
	 Funcao que faz o update do Status do Cliente
	 @param
	 @return void
	 */
	void updateStatus();
	void sortViagens();

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
	return s1->getNome()==s2->getNome();
	}
};

#endif // SRC_CLIENTE_H_
