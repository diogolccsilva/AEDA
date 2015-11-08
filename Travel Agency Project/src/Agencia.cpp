/*
 * Agencia.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: Diogo
 */

#include "Agencia.h"

int Viagem::sid = 0;

/* Class: Agencia
 *
 *
 *
 */

Agencia::Agencia(string nome) :
		nome(nome) {

}

Agencia::~Agencia() {
	// TODO Auto-generated destructor stub
}

string Agencia::getNome() const {
	return nome;
}

bool Agencia::addCliente(Cliente* c) {
	vector<Cliente*>::const_iterator it;
	it = find(clientes.begin(), clientes.end(), c);
	if (it != clientes.end())
		return false; //TODO change to a throw eventually
	clientes.push_back(c);
	return true;
}

vector<Cliente*> Agencia::getClientes() const {
	return clientes;
}

void Agencia::sortClientes() {

}

bool Agencia::addViagem(Viagem v) {
	vector<Viagem>::const_iterator it;
	it = find(viagens.begin(), viagens.end(), v);
	if (it != viagens.end())
		return false; //TODO change to a throw eventually
	viagens.push_back(v);
	return true;
}

bool Agencia::addPais(Pais p) {
	vector<Pais>::const_iterator it;
	it = find(paises.begin(), paises.end(), p);
	if (it != paises.end())
		return false; //TODO change to a throw eventually
	paises.push_back(p);
	return true;
}

Agencia::ClienteInexistente::ClienteInexistente(string nome) :
		nome(nome) {

}

Cliente* Agencia::getCliente(string nome) const {
	int it = -1;
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (clientes[i]->getNome() == nome)
			it = i;
	}
	if (it == -1)
		throw ClienteInexistente(nome);
	return clientes[it];
}

Pais Agencia::getPais(string nome) const {
	int it = -1;
	for (unsigned int i = 0; i < paises.size(); i++) {
		if (nome == paises[i].getNome())
			it = i;
	}
	if (it == -1)
		throw PaisInexistente(nome);
	return paises[it];
}

Agencia::PaisInexistente::PaisInexistente(string nome) :
		nome(nome) {

}

void Agencia::loadDestinos() {
	string filename = "../destinos" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string pais;
			getline(file, pais, '-');
			pais.erase(pais.end() - 1);
			string cidade = "";
			getline(file, cidade);
			cidade.erase(cidade.begin());
			addPais(Pais(pais));
			getPais(pais).addCidade(Cidade(cidade));
		}
	} else {

	}
}

void Agencia::loadViagens() {
	string filename = "../viagens" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string id;
			getline(file, id, '-');
			id.erase(id.end() - 1);
			string preco;
			getline(file, preco, ';');
			preco.erase(preco.end() - 1);
			string itinerario;
			getline(file, itinerario, '-');
			itinerario.erase(itinerario.begin());
			itinerario.erase(itinerario.end() - 1);
			istringstream istream(itinerario);
			vector<Cidade> vc;
			while (!istream.eof()) {
				string temp = "";
				getline(istream, temp, ';');
				istringstream tempstream(temp);
				string pais = "", cidade = "";
				getline(tempstream, pais, ',');
				getline(tempstream, cidade);
				vc.push_back(getPais(pais).getCidade(cidade));
			}
			Itinerario i(vc[0],vc[vc.size()-1]);
			string transporte;
			getline(file, transporte, '-');
			transporte.erase(transporte.end() - 1);
			string data;
			getline(file, data, '-');
			data.erase(transporte.end() - 1);
			Cidade origem = vc[0], destino = vc[1];
			for (unsigned int i = 1;i<vc.size();i++){
				Troco t()
			}
			string alojamento;
			getline(file, alojamento);
			alojamento.erase(transporte.begin());
		}
	} else {

	}
}

void Agencia::loadClientes() {
	string filename = "../clientes" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string nome = "";
			getline(file, nome, '-');
			nome.erase(nome.end() - 1);
			string tipo = "";
			getline(file, tipo, '-');
			tipo.erase(tipo.begin());
			tipo.erase(tipo.end() - 1);
			if (tipo == "P") {
				addCliente(new Particular(nome));
			} else if (tipo == "C") {
				string noparticipantes = "";
				getline(file, noparticipantes, '-');
				noparticipantes.erase(noparticipantes.begin());
				noparticipantes.erase(noparticipantes.end() - 1);
				addCliente(new Comercial(nome, atoi(noparticipantes.c_str())));
			}
			string temp;
			getline(file, temp);
		}
	} else {

	}
}

/* Class: Cliente
 *
 *
 *
 */

Cliente::Cliente() :
		nome("") {

}

Cliente::Cliente(string nome) :
		nome(nome) {

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

int Cliente::getNoViagens() const {
	return viagens.size();
}

string Cliente::getNome() const {
	return nome;
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

/* Class: Particular
 *
 *
 *
 */

Particular::Particular(string nome) :
		Cliente(nome) {

}

Particular::~Particular() {
	// TODO Auto-generated destructor stub
}

string Particular::getTipo() const {
	return "Particular";
}

/* Class: Comercial
 *
 *
 *
 */

Comercial::Comercial(string nome, int noparticipantes) :
		Cliente(nome), noparticipantes(noparticipantes) {

}

Comercial::~Comercial() {
	// TODO Auto-generated destructor stub
}

string Comercial::getTipo() const {
	return "Comercial";
}

void Comercial::addViagem(Viagem* v, int np) {
	Cliente::addViagem(v);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const {
	return noparticipantes / getViagens().size();
}

float Comercial::desconto() {

	float desconto = 0;

	if (getViagens().size() > 5 && getMedParticipantes() > 10) {
		desconto = 0.5;
	}

	if (getViagens().size() > 5 && getMedParticipantes() > 15) {
		desconto = 0.10;
	}

	return desconto;
}

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itinerario itinerario, float preco, int id,
		Alojamento* alojamento) :
		itinerario(itinerario), alojamento(alojamento), preco(preco), id(id) {

}

Viagem::~Viagem() {
	// TODO Auto-generated destructor stub
}

float Viagem::getPreco() const {
	return preco;
}

Itinerario Viagem::getItinerario() const {
	return itinerario;
}

Alojamento* Viagem::getAlojamento() const {
	//TODO add a throw eventually for non existent alojamento
	return alojamento;
}

int Viagem::getId() const {
	return id;
}

bool Viagem::operator==(const Viagem& v) const {
	return (getId() == v.getId());
}

bool Viagem::addAlojamento(Alojamento* a) {
	if (!(alojamento == new Alojamento()))
		return false; //TODO change to a throw eventually
	alojamento = a;
	return true;
}

void Viagem::delAlojamento() {
	alojamento = new Alojamento();
}

bool Viagem::changeAlojamento(Alojamento* a) {
	delAlojamento();
	return addAlojamento(a);
}

/* Class: Itinerario
 *
 *
 *
 */

Itinerario::Itinerario(Cidade origem, Cidade destino) :
		origem(origem), destino(destino) {

}

Itinerario::~Itinerario() {
	// TODO Auto-generated destructor stub
}

void Itinerario::addTroco(Troco troco){
	trocos.push_back(troco);
}

vector<Troco> Itinerario::getTrocos() {
	return trocos;
}

Cidade Itinerario::getOrigem() {
	return origem;
}

Cidade Itinerario::getDestino() {
	return destino;
}

/* Class: Troco
 *
 *
 *
 */

Troco::Troco(Cidade origem, Cidade destino, Transporte transporte, tm data) :
		origem(origem), destino(destino), transporte(transporte), data(data) {

}

Troco::~Troco() {
	// TODO Auto-generated destructor stub
}

Cidade* Troco::getCidadeOrigem() const {
	return origem;
}

Cidade* Troco::getCidadeDestino() const {
	return destino;
}

Transporte Troco::getTransporte() const {
	return transporte;
}

tm Troco::getData() const {
	return data;
}

/* Class: Transporte
 *
 *
 *
 */

Transporte::Transporte(string tipo):tipo(tipo) {
	// TODO Auto-generated constructor stub
}

Transporte::~Transporte() {
	// TODO Auto-generated destructor stub
}

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

Cidade Pais::getCidade(string nome) const {
	int it = -1;
	for (unsigned int i = 0; i < cidades.size(); i++) {
		if (cidades[i].getNome() == nome)
			it = i;
	}
	if (it == -1)
		throw CidadeInexistente(nome);
	return cidades[it];
}

Pais::CidadeInexistente::CidadeInexistente(string nome) :
		nome(nome) {

}

/* Class: Cidade
 *
 *
 *
 */

Cidade::Cidade(string nome) :
		nome(nome) {

}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub
}

string Cidade::getNome() const {
	return nome;
}

bool Cidade::addAlojamento(const Alojamento& a) {
	vector<Alojamento>::const_iterator it;
	it = find(alojamentos.begin(), alojamentos.end(), a);
	if (it != alojamentos.end())
		return false; //TODO change to a throw eventually
	alojamentos.push_back(a);
	return true;
}

bool Cidade::operator==(const Cidade& c) const {
	return nome == c.nome;
}

/* Class: Alojamento
 *
 *
 *
 */

Alojamento::Alojamento() :
		tipo(""), nome(""), preco(0) {

}

Alojamento::Alojamento(string tipo, string nome, float preco) :
		tipo(tipo), nome(nome), preco(preco) {

}

Alojamento::~Alojamento() {
	// TODO Auto-generated destructor stub
}

bool Alojamento::operator==(const Alojamento& a) const {
	return (nome == a.nome);
}
