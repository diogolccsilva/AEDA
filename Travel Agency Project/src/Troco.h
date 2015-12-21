/*
 * Troco.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_TROCO_H_
#define SRC_TROCO_H_

#include "Transporte.h"
#include "Cidade.h"

class Troco {
	Cidade* origem, *destino;
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
	Troco(Cidade* origem, Cidade* destino, Transporte transporte, tm data);
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
	Cidade* getCidadeOrigem() const;
	/**
	 Retorna a Cidade de Destino do Troco

	 @param void
	 @return Cidade de Destino do Troco
	 */
	Cidade* getCidadeDestino() const;
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

#endif // SRC_TROCO_H_




