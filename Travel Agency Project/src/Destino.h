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
	/**
	 Construtor base de Destino
	 @param
	 @return void
	 */
	Destino();
	/**
	 Construtor de Destino
	 @param desconto Desconto do destino
	 @param c Apontador de cidade
	 @param viagem Apontador de viagem
	 @param alojamento Apontador de Alojamento
	 @param id ID do Destino
	 */
	Destino(float desconto, Cidade* c, Viagem* viagem, Alojamento* alojamento =
			new Alojamento(), int id = sid);
	/**
	 Destrutor de Destino
	 @param
	 @return void
	 */
	virtual ~Destino();
	/**
	 Compara dois destinos e ve qual e mais barato
	 @param d1 Destino por referencia
	 @return true se for mais barato
	 @return false se for mais caro
	 */
	bool operator<(const Destino &d1) const;
	/**
	 Get de um apontador de Cidade do Destino
	 @param
	 @return void
	 */
	Cidade* getCidade() const;
	/**
	 Get de um apontador de Viagem do Destino
	 @param
	 @return void
	 */
	Viagem* getViagem() const;
	/**
	 Get de desconto do Destino
	 @param
	 @return void
	 */
	float getDesconto() const;
	/**
	 Funcao que faz o update do preco do destino
	 @param
	 @return void
	 */
	void updatePreco();
	/**
	 Get do Preco do Destino
	 @param
	 @return void
	 */
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
