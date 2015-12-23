/*
 * Destino.h
 *
 *  Created on: 21/12/2015
 *      Author: Diogo
 */

#ifndef SRC_DESTINO_H_
#define SRC_DESTINO_H_

#include "Pais.h"
#include "Viagem.h"

class Destino {
	int id;
	static int sid;
	Cidade* cidade;
	Alojamento* alojamento;
	Viagem* viagem;
	float desconto, preco; //entre 0,0 e 100,0%
public:
	Destino();
	Destino(float desconto, Cidade* c, Viagem* viagem, Alojamento* alojamento =
			new Alojamento(), int id = sid);
	virtual ~Destino();
	bool operator<(const Destino &d1) const;
	Cidade* getCidade() const;
	Viagem* getViagem() const;
	float getDesconto() const;
	void updatePreco();
	float getPreco() const;
	/**
	 Retorna o Alojamento, se este existir

	 @param void
	 @return Alojamento
	 */
	Alojamento* getAlojamento() const;
	/**
	 Adiciona um Alojamento as caracteristicas de viagem, uma vez que este nao e obrigatorio

	 @param alojamento Alojamento
	 @return
	 */
	bool addAlojamento(Alojamento* a);
	/**
	 Elimina o Alojamento

	 @param void
	 @return
	 */
	void delAlojamento();
	/**
	 Altera o Alojamento da Viagem

	 @param a Alojamento
	 @return true, se alteracao for aplicada, caso contrario false
	 */
	bool changeAlojamento(Alojamento* a);
	int getId() const;
	friend ostream & operator<<(ostream & o, const Destino & d);
};

#endif /* SRC_DESTINO_H_ */
