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
	Cidade* cidade;
	Alojamento* alojamento;
public:
	Destino();
	Destino(Cidade* c,Alojamento* alojamento = new Alojamento());
	virtual ~Destino();
	bool operator<(const Destino &d1) const;
	Cidade* getCidade() const;
	Alojamento* getAlojamento() const;
};

#endif /* SRC_DESTINO_H_ */
