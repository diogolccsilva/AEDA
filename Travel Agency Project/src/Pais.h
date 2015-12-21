/*
 * Pais.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_PAIS_H_
#define SRC_PAIS_H_

#include "Cidade.h"

class Pais {
	vector<Cidade> cidades;
	string nome;
public:
	/**
	 Construtor de Pais
	 @param Nome do Pais
	 @return
	 */
	Pais(string nome);
	/**
	 Destrutor de Pais
	 @param void
	 @return
	 */
	virtual ~Pais();
	/**
	 Booleana para saber se pode adicionar cidade
	 @param c Cidade que se deseja adicionar
	 @return Retorna se pode adicionar a cidade
	 */
	bool addCidade(const Cidade& c);
	/**
	 Get do Nome do Pais
	 @param void
	 @return Nome do Pais
	 */
	string getNome() const;
	/**
	 Overload do operador == em Pais
	 @param p Pais por referência
	 @return Pais e, ou nao, igual
	 */
	bool operator==(const Pais& p) const;
	/**
	 Get da cidade do Pais
	 @param nome Nome da cidade
	 @return Nome da cidade
	 */
	Cidade* getCidade(string nome);
	/**
	 Get do vetor com as Cidades
	 @param void
	 @return Vetor com as Cidades
	 */
	vector<Cidade> getCidades() const;
	/**
	 Classe da excecao Cidade Inexistente
	 @param void
	 @return
	 */
	class CidadeInexistente {
		string nome;
	public:
		/**
		 Construtor da excecao Cidade Inexistente
		 @param nome Nome da Cidade Inexistente
		 @return
		 */
		CidadeInexistente(string nome);
		/**
		 Get do Nome da Cidade Inexistente
		 @param void
		 @return Nome da Cidade Inexistente
		 */
		string getNome() const;
	};
};


#endif // SRC_PAIS_H_

