/*
 * Particular.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_PARTICULAR_H_
#define SRC_PARTICULAR_H_

#include "Agencia.h"

class Particular: public Cliente {
public:
	/**
	 Construtor da classe Particular
	 @param nome Nome do Cliente
	 @return
	 */
	Particular(string nome, string email, string morada);
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
	/**
	 Get do Numero de Participantes no Cliente Particular
	 @param void
	 @return Numero de Participantes
	 */
	int getNoParticipantes() const;
	/**
	 Calculo do desconto do Cliente
	 @param void
	 @return Desconto
	 */
	float desconto() const;
	/**
	 Get do Numero Medio de Participantes do Cliente
	 @param void
	 @return Numero Medio de Participantes
	 */
	int getMedParticipantes() const;
};


#endif SRC_PARTICULAR_H_
