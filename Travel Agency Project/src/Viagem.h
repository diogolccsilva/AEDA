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
	Alojamento* alojamento;
	float preco; //apenas o preco da viagem, para obter o preco total adicionar o preco do alojamento
	int id;
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
	Viagem(Itinerario itinerario, float preco, Alojamento* alojamento =
			new Alojamento(), int id = sid);
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
	 Retorna o Alojamento, se este existir

	 @param void
	 @return Alojamento
	 */
	Alojamento* getAlojamento() const;
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
};

#endif SRC_VIAGEM_H_
