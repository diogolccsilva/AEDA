/*
 * Viagem.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_VIAGEM_H_
#define SRC_VIAGEM_H_

#include "Itinerario.h"

class Viagem {
	Itinerario itinerario;
	float preco;
	int id, pontos;
	//vai ter que se acrescentar data
public:
	static int sid;
	/**
	 Construtor de Viagem

	 @param itinerario Itinerario
	 @param preco float
	 @param alojamento Alojamento
	 @param id int
	 @return
	 */
	Viagem(Itinerario itinerario, float preco, int id = sid);
	/**
	 Destrutor de Viagem

	 @param void
	 @return
	 */
	virtual ~Viagem();
	/**
	 Retorna o Preco Total da Viagem

	 @param void
	 @return Preco
	 */
	float getPreco() const;
	/**
	 Retorna o Itinerario da Viagem

	 @param void
	 @return Itinerario
	 */
	Itinerario getItinerario() const;
	/**
	 Overload do operador ==

	 @param v Viagem
	 @return true se a Viagem v é igual a uma Viagem , caso contrario false
	 */
	bool operator==(const Viagem& v) const;
	/**
	 Retorna o Id da Viagem

	 @param void
	 @return Id da Viagem
	 */
	int getId() const;

	int getPontos() const;
};

#endif // SRC_VIAGEM_H_
