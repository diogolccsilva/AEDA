/*
 * Comercial.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_COMERCIAL_H_
#define SRC_COMERCIAL_H_

#include "Agencia.h"

class Comercial: public Cliente {
	int noparticipantes;
public:
	/**
	 Construtor da classe Comercial
	 @param nome Nome do Cliente
	 @param noparticipantes Numero de Participantes do Cliente
	 @return
	 */
	Comercial(string nome, string email, string morada,
			int noparticipantes = 0);
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
	void addViagem(Viagem* v, int np);
	/**
	 Get do Numero de Participantes no Cliente Comercial
	 @param void
	 @return Numero de Participantes
	 */
	int getNoParticipantes() const;
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
	float desconto() const;
	/**
	 Get do Tipo de Cliente
	 @param void
	 @return Tipo de Cliente
	 */
	string getTipo() const;
};

#endif SRC_COMERCIAL_H_
