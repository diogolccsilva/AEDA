/*
 * Cliente.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include "Viagem.h"

class Cliente {
	string nome, email, morada;
	vector<Viagem*> viagens;
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
	Cliente(string nome, string email, string morada);
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
};

#endif // SRC_CLIENTE_H_
