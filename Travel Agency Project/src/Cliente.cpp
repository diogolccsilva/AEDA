/*
 * Cliente.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

/* Class: Cliente
 *
 *
 *
 */

#include "Cliente.h"

Cliente::Cliente() :
		nome(""), email(""), morada("") {

}

Cliente::Cliente(string nome, string email, string morada) :
		nome(nome), email(email), morada(morada) {

}

Cliente::~Cliente() {

}

int Cliente::getNoViagens() const {
	return viagens.size();
}

string Cliente::getNome() const {
	return nome;
}

string Cliente::getEmail()const
{
	return email;
}

void Cliente::setEmail(string e)
{
	email=e;
}

string Cliente::getMorada() const
{
	return morada;
}

void Cliente::setMorada(string m)
{
	morada=m;
}

bool Cliente::operator==(const Cliente& cliente) const {
	return (nome == cliente.nome);
}

void Cliente::addViagem(Viagem* v) {
	viagens.push_back(v);
}

vector<Viagem*> Cliente::getViagens() const {
	return viagens;
}

//TODO usar templates talvez para ver se imprime o tipo direito
ostream & operator<<(ostream & o, const Cliente & c) {
	o << "Nome: " << c.getNome() << ";\n" << "Tipo: " << c.getTipo() << ";\n"
			<< "No de Viagens: " << c.getNoViagens() << ";\n";
	return o;
}


