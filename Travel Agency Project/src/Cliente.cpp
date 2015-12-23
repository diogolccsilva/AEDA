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

Cliente::Cliente(string nome, string email, string morada,int pontos) :
		nome(nome), email(email), morada(morada),pontos(pontos) {

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

bool Cliente::operator<(const Cliente& a1) const {
	if (pontos < a1.pontos)
		return true;
	else
		return false;
}

int Cliente::getPontos() const{
	return pontos;
}

void Cliente::atualizaPontos(Cliente* c) { //verifica please

	int pontostemp = 0;

	for (unsigned int i = 0; i<viagens.size(); i++)
		pontostemp += viagens[i]->getPontos();
}

void Cliente::printViagens() const{
	for (unsigned int i = 0;i<destinos.size();i++){
		cout << (*destinos[i]) << endl;
	}
}

bool Cliente::addDestino(Destino* d){
	vector<Destino*>::iterator it;
	it = find(destinos.begin(),destinos.end(),d);
	if (it!=destinos.end()){
		return false;
	}
	destinos.push_back(d);
	viagens.push_back(d->getViagem());
	return true;
}

vector<Destino*> Cliente::getDestinos() const{
	return destinos;
}
