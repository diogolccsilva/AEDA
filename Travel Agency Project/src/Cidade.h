/*
 * Cidade.h
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#ifndef SRC_CIDADE_H_
#define SRC_CIDADE_H_

#include "Alojamento.h"

class Cidade {
	string nome;
	string pais;
	vector<Alojamento> alojamentos;
public:
	/**
	 Construtor de Cidade

	 @param Nome da Cidade
	 @return
	 */
	Cidade(string nome, string pais);
	/**
	 Destrutor de Cidade

	 @param void
	 @return
	 */
	virtual ~Cidade();
	/**
	 Get do Nome da Cidade

	 @param void
	 @return Nome da Cidade
	 */
	string getNome() const;
	/**
	 Get do Pais da Cidade

	 @param void
	 @return Pais da Cidade
	 */
	string getPais() const;
	/**
	 Verifica a possibilidade de adicionar um Alojamento ao vetor alojamentos

	 @param Alojamento
	 @return true se for possivel adicionar o Alojamento , caso contrario false
	 */
	bool addAlojamento(const Alojamento& a);
	/**
	 Get do Apontador para Alojamento
	 @param nome Nome do Alojamento
	 @return Alojamento por apontador
	 */
	Alojamento* getAlojamento(string nome);
	/**
	 Get do vetor de Alojamentos existentes
	 @param void
	 @return Vetor de Alojamentos existentes
	 */
	vector<Alojamento> getAlojamentos();
	/**
	 Compara as duas cidades

	 @param  c Cidade
	 @return true se as cidades forem iguais
	 @return false se as cidades forem diferentes
	 */
	bool operator==(const Cidade& c) const;
	class AlojamentoInexistente {
		string nome;
	public:
		/**
		 Construtor da excecao AlojamentoInexistente
		 @param nome Nome do Alojamento Inexistente
		 @return
		 */
		AlojamentoInexistente(string nome);
		/**
		 Get do Nome do Alojamento Inexistente
		 @param void
		 @return Nome do Alojamento
		 */
		string getNome() const;
	};
};

#endif // SRC_CIDADE_H_
