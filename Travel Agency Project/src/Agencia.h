/*
 * Agencia.h
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#ifndef SRC_AGENCIA_H_
#define SRC_AGENCIA_H_

#include "Cliente.h"
#include "Destino.h"
#include "Particular.h"
#include "Comercial.h"

class Agencia {
	static time_t tempo_local;
	static tm* tempo_info;
	string nome;
	vector<Cliente*> clientes; //clientes da agencia
	vector<Viagem> viagens; //totalidade de viagens da agencia (ja efetuadas e futuras)
	vector<Pais> paises; //paises para os quais faz viagens
	BST<Destino> destinos; //destinos para os quais a agência faz viagens
	tr1::unordered_set<Cliente*, hstr, hstr> clientes_antigos;
	priority_queue<Cliente*> clientes_frequentes;
public:
	/**
	 Construtor da classe Agencia
	 @param nome Nome da Agencia
	 @return
	 */
	Agencia(string nome);
	/**
	 Destrutor da classe Agencia
	 @param void
	 @return
	 */
	virtual ~Agencia();
	/**
	 Retorna o nome da agencia

	 @param void
	 @return string nome
	 */
	string getNome() const;
	/**
	 Funcao booleana para verificar se pode adicionar cliente
	 @param c Apontador para um Cliente
	 @return true se poder adicionar
	 @return false se nao poder adicionar
	 */
	bool addCliente(Cliente* c);
	/**
	 Get do vetor de Clientes por apontador
	 @param void
	 @return vetor de apontadores para Clientes
	 */
	vector<Cliente*> getClientes() const;
	/**
	 Get do vetor de Viagens
	 @param void
	 @return Vetor de Viagens
	 */
	vector<Viagem> getViagens() const; //TODO REMOVE THIS
	/**
	 Funcao booleana para verificar se pode adicionar viagem
	 @param v Viagem
	 @return true se poder adicionar
	 @return false se nao poder adicionar
	 */
	bool addViagem(Viagem v);
	/**
	 Funcao booleana para verificar se pode adicionar Pais
	 @param p Pais
	 @return true se poder adicionar
	 @return false se nao poder adicionar
	 */
	bool addPais(Pais p);
	/**
	 Get do vetor dos Paises
	 @param void
	 @return vetor dos Paises
	 */
	vector<Pais> getPaises() const;
	/**
	 Get do apontador para Cliente
	 @param nome Nome do Cliente
	 @return Apontador para cliente
	 */
	Cliente* getCliente(string nome) const;
	class ClienteInexistente {
		string nome;
	public:
		/**
		 Construtor da excecao para Cliente Inexistente
		 @param nome Nome do Cliente Inexistente
		 @return
		 */
		ClienteInexistente(string nome);
	};
	/**
	 Get do Pais por referencia
	 @param nome Nome do Pais
	 @return Pais por referencia
	 */
	Pais& getPais(string nome);
	class PaisInexistente {
		string nome;
	public:
		/**
		 Construtor da excecao Pais Inexistente
		 @param nome Nome do Pais Inexistente
		 @return
		 */
		PaisInexistente(string nome);
		/**
		 Get do Nome do Pais Inexistente
		 @param void
		 @return Nome do Pais Inexistente
		 */
		string getNome() const;
	};
	/**
	 Get do apontador para uma Viagem
	 @param id ID da Viagem
	 @return Apontador para Viagem
	 */
	Viagem* getViagem(int id);
	class ViagemInexistente {
		int id;
	public:
		/**
		 Construtor da excecao Viagem Inexistente
		 @param id ID da Viagem Inexistente
		 @return
		 */
		ViagemInexistente(int id);
	};
	/**
	 Load do ficheiro cidades para saber o Pais e a Cidade
	 @param void
	 @return
	 */
	void loadCidades();
	/**
	 Load do ficheiro alojamentos para saber o nome, tipo, preco e pais
	 @param void
	 @return
	 */
	void loadAlojamentos();
	/**
	 Load do ficheiro viagens para saber o id, o preco e o itinerario
	 @param void
	 @return
	 */
	void loadViagens();
	/**
	 Load do ficheiro destinos para saber os destinos disponiveis
	 @param void
	 @return
	 */
	void loadDestinos();
	/**
	 Load do ficheiro clientes para saber o nome e o tipo
	 @param void
	 @return
	 */
	void loadClientes();
	/**
	 Atualizacao do ficheiro cidades
	 @param void
	 @return
	 */
	void saveCidades();
	/**
	 Atualizacao do ficheiro alojamentos
	 @param void
	 @return
	 */
	void saveAlojamentos();
	/**
	 Atualizacao do ficheiro Viagens
	 @param void
	 @return
	 */
	void saveViagens();
	/**
	 Atualizacao do ficheiro destinos
	 @param void
	 @return
	 */
	void saveDestinos();
	/**
	 Atualizacao do ficheiro clientes
	 @param void
	 @return
	 */
	void saveClientes();
	class DestinoInexistente {
		string nome;
	public:
		/**
		 Construtor da excecao para Destino Inexistente
		 @param nome Nome do Destino Inexistente
		 @return
		 */
		DestinoInexistente(string nome);
		string getNome() const;
	};
	Destino* addDestino(Destino d1);
	//retorna o destino com o nome nome, mais barato
	Destino* getDestino(string nome) const;
	static tm* getTempo_Info();
	void imprimeClientes();
	void procurarClienteEmail(string e);
	void procurarClienteNome(string n);
	void procurarClienteMorada(string m);
	void addClienteAntigo(Cliente *c);
};

#endif SRC_AGENCIA_H_
