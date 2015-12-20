/*
 * Alojamento.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_ALOJAMENTO_H_
#define SRC_ALOJAMENTO_H_

#include "Agencia.h"

class Alojamento {
	string tipo, nome;
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
	Alojamento(string tipo, string nome, float preco);
	/**
	 Destrutor Alojamento
	 @param void
	 @return
	 */
	virtual ~Alojamento();
	/**
	 Get do Nome do Alojamento
	 @param void
	 @return Nome do Alojamento
	 */
	string getNome() const;
	/**
	 Get do Tipo de Alojamento
	 @param void
	 @param Tipo de Alojamento
	 */
	string getTipo() const;
	/**
	 Get do Preco do Alojamento
	 @param void
	 @return Preco do Alojamento
	 */
	float getPreco() const;
	/**
	 Compara dois alojamentos
	 @param a Alojamento por referencia
	 @return true se for igual
	 @return false se for diferente
	 */
	bool operator==(const Alojamento& a) const;
};
#endif SRC_ALOJAMENTO_H_
