/*
 * Viagem.cpp
 *
 *  Created on: 20/12/2015
 *      Author: Rita
 */

#include "Viagem.h"

int Viagem::sid = 0;

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itinerario itinerario, float preco, int id) :
		itinerario(itinerario), preco(preco), id(id) {
	sid=id+1;
	pontos = preco/2;
}

Viagem::~Viagem() {
}

float Viagem::getPreco() const {
	return preco;
}

Itinerario Viagem::getItinerario() const {
	return itinerario;
}

int Viagem::getId() const {
	return id;
}

bool Viagem::operator==(const Viagem& v) const {
	return (id == v.id);
}

int Viagem::getPontos() const {
	return pontos;
}

ostream & operator<<(ostream & o, const Viagem & v){
	o << "Origem: " << v.getItinerario().getOrigem()->getNome() << endl;
	o << "Destino: " << v.getItinerario().getDestino()->getNome() << endl;
	o << "Transporte(s):";
	for (unsigned int i=0;i<v.getItinerario().getTrocos().size();i++){
		cout << " " << v.getItinerario().getTrocos()[i].getTransporte().getTipo();
	}
	o << endl;
	tm data = v.getItinerario().getTrocos()[0].getData();
	o << "Data: " << data.tm_mday << "/" << data.tm_mon+1 << "/" << data.tm_year-100 << endl;
	o << "Pontos: " << v.getPontos() << endl;
	return o;
}
