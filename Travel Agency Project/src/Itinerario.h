/*
 * Itinerario.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */


#ifndef SRC_ITINERARIO_H_
#define SRC_ITINERARIO_H_

#include "Agencia.h"

class Itinerario {
	Cidade *origem, *destino;
	vector<Troco> trocos;
public:
	/**
	 Construtor Itinerario
	 @param origem Cidade Origem
	 @param destino Cidade de Destino
	 @return
	 */
	Itinerario(Cidade* origem, Cidade* destino);
	/**
	 Adiciona um novo troco
	 @param troco Novo troco
	 @return
	 */
	void addTroco(Troco troco);
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
	Cidade* getOrigem() const;
	/**
	 Get da cidade Destino do Troco
	 @param void
	 @return Cidade Destino do Troco
	 */
	Cidade* getDestino() const;

};

#endif SRC_ITINERARIO_H_


