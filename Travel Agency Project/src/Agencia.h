/*
 * Agencia.h
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#ifndef SRC_AGENCIA_H_
#define SRC_AGENCIA_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

class Alojamento {
	string tipo, nome;
	float preco;
public:
	/**
	 Construtor base Alojamento
	 @param
	 @return
	 */
	Alojamento();
	/**
	 Construtor Alojamento
	 @param tipo Tipo de Alojamento
	 @param nome Nome do Alojamento
	 @param preco Preco do Alojamento
	 @return
	 */
	Alojamento(string tipo, string nome, float preco);
	/**
	 Destrutor Alojamento
	 @param void
	 @return
	 */
	virtual ~Alojamento();
	/**
	 Get do Nome do Alojamento
	 @param void
	 @return Nome do Alojamento
	 */
	string getNome() const;
	/**
	 Get do Tipo de Alojamento
	 @param void
	 @param Tipo de Alojamento
	 */
	string getTipo() const;
	/**
	 Get do Preco do Alojamento
	 @param void
	 @return Preco do Alojamento
	 */
	float getPreco() const;
	/**
	 Compara dois alojamentos
	 @param a Alojamento por referencia
	 @return true se for igual
	 @return false se for diferente
	 */
	bool operator==(const Alojamento& a) const;
};

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

class Troco {
	Cidade* origem, *destino;
	Transporte transporte;
	tm data;
public:
	/**
	 Construtor de Troco

	 @param origem Cidade
	 @param destino Cidade
	 @param transporte Transporte
	 @param data tm
	 @return
	 */
	Troco(Cidade* origem, Cidade* destino, Transporte transporte, tm data);
	/**
	 Destrutor de Troco

	 @param void
	 @return
	 */
	virtual ~Troco();
	/**
	 Retorna a Cidade de Origem do Troco

	 @param void
	 @return Cidade de  Origem do Troco
	 */
	Cidade* getCidadeOrigem() const;
	/**
	 Retorna a Cidade de Destino do Troco

	 @param void
	 @return Cidade de Destino do Troco
	 */
	Cidade* getCidadeDestino() const;
	/**
	 Retorna o Transporte utizado

	 @param void
	 @return Transporte
	 */
	Transporte getTransporte() const;
	/**
	 Retorna a Data em que o Troco foi executado

	 @param void
	 @return Data
	 */
	tm getData() const;
};

class Itinerario {
	Cidade *origem, *destino;
	vector<Troco> trocos;
public:
	/**
	 Construtor Itinerario
	 @param origem Cidade Origem
	 @param destino Cidade de Destino
	 @return
	 */
	Itinerario(Cidade* origem, Cidade* destino);
	/**
	 Adiciona um novo troco
	 @param troco Novo troco
	 @return
	 */
	void addTroco(Troco troco);
	/**
	 Destrutor de Itinerario
	 @param
	 @return
	 */
	virtual ~Itinerario();
	/**
	 Get do vetor de Trocos
	 @param void
	 @return Vetor Trocos
	 */
	vector<Troco> getTrocos();
	/**
	 Get da cidade Origem do Troco
	 @param void
	 @return Cidade Origem do Troco
	 */
	Cidade* getOrigem() const;
	/**
	 Get da cidade Destino do Troco
	 @param void
	 @return Cidade Destino do Troco
	 */
	Cidade* getDestino() const;

};

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

class Cliente {
	string nome;
	vector<Viagem*> viagens;
public:
	/**
	 Construtor base de Cliente
	 @param void
	 @return
	 */
	Cliente();
	/**
	 Construtor Cliente
	 @param nome Nome do Cliente
	 @return
	 */
	Cliente(string nome);
	/**
	 Destrutor de Cliente
	 @param void
	 @return
	 */
	virtual ~Cliente();
	/**
	 Get do Numero de Viagens
	 @param void
	 @return Número de Viagens
	 */
	int getNoViagens() const;
	/**
	 Get do Nome do Cliente
	 @param void
	 @return Nome do Cliente
	 */
	string getNome() const;
	/**
	 Overload do operador == em Clientes
	 @param c Cliente
	 @return Se cliente e, ou nao, igual
	 */
	bool operator==(const Cliente& c) const;
	/**
	 Funcao virtual para adicionar
	 @param v Viagem que se pretende adicionar
	 @return
	 */
	virtual void addViagem(Viagem* v);
	/**
	 Get do vetor Viagens
	 @param void
	 @return Vetor Viagens da classe Viagem
	 */
	vector<Viagem*> getViagens() const;
	/**
	 Tipo de Cliente (Comercial ou Privado)
	 @param void
	 @return 0
	 */
	virtual string getTipo() const = 0;
	/**
	 Get do Numero Participantes no Cliente Comercial
	 @param void
	 @return Numero de Participantes
	 */
	virtual int getNoParticipantes() const = 0;
	/**
	 Calculo do desconto do Cliente
	 @param void
	 @return Desconto do cliente
	 */
	virtual float desconto() const = 0;
	/**
	 Calculo da media de participantes do Cliente Comercial
	 @param void
	 @return Media de Participantes
	 */
	virtual int getMedParticipantes() const = 0;
	/**
	 Overload do operador << da classe Cliente
	 @param o Parâmetro de saída
	 @param c Cliente
	 @return Parâmetro de saída
	 */
	friend ostream & operator<<(ostream & o, const Cliente & c);
};

class Particular: public Cliente {
public:
	/**
	 Construtor da classe Particular
	 @param nome Nome do Cliente
	 @return
	 */
	Particular(string nome);
	/**
	 Destrutor
	 @param void
	 @return
	 */
	virtual ~Particular();
	/**
	 Get do Tipo de Cliente
	 @param void
	 @return Tipo de Cliente
	 */
	string getTipo() const;
	/**
	 Get do Numero de Participantes no Cliente Particular
	 @param void
	 @return Numero de Participantes
	 */
	int getNoParticipantes() const;
	/**
	 Calculo do desconto do Cliente
	 @param void
	 @return Desconto
	 */
	float desconto() const;
	/**
	 Get do Numero Medio de Participantes do Cliente
	 @param void
	 @return Numero Medio de Participantes
	 */
	int getMedParticipantes() const;
};

class Comercial: public Cliente {
	int noparticipantes;
public:
	/**
	 Construtor da classe Comercial
	 @param nome Nome do Cliente
	 @param noparticipantes Numero de Participantes do Cliente
	 @return
	 */
	Comercial(string nome, int noparticipantes = 0);
	/**
	 Destrutor
	 @param void
	 @return
	 */
	virtual ~Comercial();
	/**
	 Adiciona Viagem
	 @param v Apontador para a Viagem
	 @param np Numero de Participantes
	 @return
	 */
	void addViagem(Viagem* v, int np);
	/**
	 Get do Numero de Participantes no Cliente Comercial
	 @param void
	 @return Numero de Participantes
	 */
	int getNoParticipantes() const;
	/**
	 Get da Media de Participantes
	 @param void
	 @return Media de Participantes
	 */
	int getMedParticipantes() const;
	/**
	 Calculo do desconto do Cliente
	 @param
	 @return Desconto
	 */
	float desconto() const;
	/**
	 Get do Tipo de Cliente
	 @param void
	 @return Tipo de Cliente
	 */
	string getTipo() const;
};

class Agencia {
	string nome;
	vector<Cliente*> clientes; //clientes da agencia
	vector<Viagem> viagens; //totalidade de viagens da agencia (ja efetuadas e futuras)
	vector<Pais> paises; //paises para os quais faz viagens
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
	 Load do ficheiro destinos para saber o Pais e a Cidade
	 @param void
	 @return
	 */
	void loadDestinos();
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
	 Load do ficheiro clientes para saber o nome e o tipo
	 @param void
	 @return
	 */
	void loadClientes();
	/**
	 Atualizacao do ficheiro destinos
	 @param void
	 @return
	 */
	void saveDestinos();
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
	 Atualizacao do ficheiro clientes
	 @param void
	 @return
	 */
	void saveClientes();
};

#endif /* SRC_AGENCIA_H_ */
