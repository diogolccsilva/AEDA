/*
 * Transporte.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */


#ifndef SRC_TRANSPORTE_H_
#define SRC_TRANSPORTE_H_

#include "Agencia.h"

class Transporte {
	string tipo;
public:
	/**
	 Construtor de Transporte

	 @param tipo string
	 @return
	 */
	Transporte(string tipo);
	/**
	 Get do Tipo de Transporte
	 @param void
	 @return Tipo de Transporte
	 */
	string getTipo() const;
	/**
	 Destrutor de Transporte

	 @param void
	 @return
	 */
	virtual ~Transporte();
};

#endif SRC_TRASNPORTE_H_


