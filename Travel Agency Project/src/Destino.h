/*
 * Destino.h
 *
 *  Created on: 21/12/2015
 *      Author: Diogo
 */

#ifndef SRC_DESTINO_H_
#define SRC_DESTINO_H_

#include "Pais.h"

class Destino {
	Pais* pais;
	Cidade* cidade;
public:
	Destino();
	Destino(Pais* p, Cidade* c);
	virtual ~Destino();
};

#endif /* SRC_DESTINO_H_ */
