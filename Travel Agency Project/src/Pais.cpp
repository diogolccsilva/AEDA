/*
 * Pais.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Pais.h"

/* Class: Pais
 *
 *
 *
 */

Pais::Pais(string nome) :
		nome(nome) {

}

Pais::~Pais() {
	// TODO Auto-generated destructor stub
}

bool Pais::addCidade(const Cidade& c) {
	vector<Cidade>::const_iterator it;
	it = find(cidades.begin(), cidades.end(), c);
	if (it != cidades.end())
		return false; //TODO change to a throw eventually
	cidades.push_back(c);
	return true;
}

string Pais::getNome() const {
	return nome;
}

bool Pais::operator==(const Pais& p) const {
	return nome == p.nome;
}

Cidade* Pais::getCidade(string nome) {
	int it = -1;
	for (unsigned int i = 0; i < cidades.size(); i++) {
		if (cidades[i].getNome() == nome)
			it = i;
	}
	if (it == -1)
		throw CidadeInexistente(nome);
	return &cidades[it];
}

vector<Cidade> Pais::getCidades() const {
	return cidades;
}

Pais::CidadeInexistente::CidadeInexistente(string nome) :
		nome(nome) {

}

string Pais::CidadeInexistente::getNome() const {
	return this->nome;
}


