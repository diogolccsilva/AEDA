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
		nome(""), email(""), morada(""), status("") {

}

Cliente::Cliente(string nome, string email, string morada, string status,
		int pontos) :
		nome(nome), email(email), morada(morada), status(status), pontos(pontos) {

}

Cliente::~Cliente() {

}

int Cliente::getNoViagens() const {
	return viagens.size();
}

string Cliente::getNome() const {
	return nome;
}

string Cliente::getEmail() const {
	return email;
}

void Cliente::setEmail(string e) {
	email = e;
}

string Cliente::getMorada() const {
	return morada;
}

void Cliente::setMorada(string m) {
	morada = m;
}

string Cliente::getStatus() const {
	return status;
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

ostream & operator<<(ostream & o, const Cliente & c) {
	o << "Nome: " << c.getNome() << ";\n" << "Tipo: " << c.getTipo() << ";\n"
			<< "No de Viagens: " << c.getNoViagens() << ";\n" << "Pontos: "
			<< c.getPontos() << ";\n";
	return o;
}

bool Cliente::operator<(const Cliente& a1) const {
	if (pontos < a1.pontos)
		return true;
	else
		return false;
}

int Cliente::getPontos() const {
	return pontos;
}

void Cliente::updatePontos() {
	int pontostemp = 0;
	tm data;
	for (unsigned int i = 0; i < viagens.size(); i++) {
		pontostemp += viagens[i]->getPontos();
		data = viagens[i]->getItinerario().getData();
	}
	tm tnow;
	time_t now;
	time(&now);
	tnow = *localtime(&now);
	int dtime = difftime(mktime(&tnow), mktime(&data)) / (60 * 60 * 24 * 30);
	pontos = pontostemp - dtime*10;
}

void Cliente::printViagens() const {
	for (unsigned int i = 0; i < destinos.size(); i++) {
		cout << (*destinos[i]) << endl;
	}
}

bool Cliente::addDestino(Destino* d) {
	vector<Destino*>::iterator it;
	it = find(destinos.begin(), destinos.end(), d);
	if (it != destinos.end()) {
		return false;
	}
	destinos.push_back(d);
	viagens.push_back(d->getViagem());
	updateStatus();
	updatePontos();
	return true;
}

vector<Destino*> Cliente::getDestinos() const {
	return destinos;
}

void Cliente::updateStatus() {
	tm t = getViagens()[0]->getItinerario().getData(), data;
	time_t now;
	time(&now);
	data = *localtime(&now);
	float dtime = difftime(mktime(&data), mktime(&t)) / (60 * 60 * 24);
	if (dtime > 365) {
		status = "Antigo";
	} else {
		status = "Frequente";
	}
}



