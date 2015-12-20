/*
 * Cidade.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Cidade.h"

/* Class: Cidade
 *
 *
 *
 */

Cidade::Cidade(string nome, string pais) :
		nome(nome), pais(pais) {

}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub
}

string Cidade::getNome() const {
	return nome;
}

string Cidade::getPais() const {
	return pais;
}

bool Cidade::addAlojamento(const Alojamento& a) {
	vector<Alojamento>::const_iterator it;
	it = find(alojamentos.begin(), alojamentos.end(), a);
	if (it != alojamentos.end())
		return false; //TODO change to a throw eventually
	alojamentos.push_back(a);
	return true;
}

Alojamento* Cidade::getAlojamento(string nome) {
	int it = -1;
	for (unsigned int i = 0; i < alojamentos.size(); i++) {
		if (alojamentos[i].getNome() == nome)
			it = i;
	}
	if (it == -1)
		throw AlojamentoInexistente(nome);
	return &alojamentos[it];
}

vector<Alojamento> Cidade::getAlojamentos() {
	return alojamentos;
}

bool Cidade::operator==(const Cidade& c) const {
	return nome == c.nome;
}

Cidade::AlojamentoInexistente::AlojamentoInexistente(string nome) :
		nome(nome) {

}

string Cidade::AlojamentoInexistente::getNome() const {
	return this->nome;
}

