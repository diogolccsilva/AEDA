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
	nome.~basic_string();
	clientes.~vector();
	viagens.~vector();
	paises.~vector();
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

vector<Pais> Agencia::getPaises() const {
	return paises;
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

Pais& Agencia::getPais(string nome) {
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

string Agencia::PaisInexistente::getNome() const {
	return this->nome;
}

Viagem* Agencia::getViagem(int id) {
	int it = -1;
	for (unsigned int i = 0; i < viagens.size(); i++) {
		if (viagens[i].getId() == id)
			it = i;
	}
	if (it == -1)
		throw ViagemInexistente(id);
	return &viagens[it];
}

Agencia::ViagemInexistente::ViagemInexistente(int id) :
		id(id) {

}

void Agencia::loadDestinos() {
	string filename = "../destinos" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string pais = "";
			getline(file, pais, '-');
			string cidade = "";
			getline(file, cidade);
			addPais(Pais(pais));
			getPais(pais).addCidade(Cidade(cidade, pais));
		}
		file.close();
	} else {

	}
}

void Agencia::loadAlojamentos() {
	string filename = "../alojamentos" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string nome = "";
			getline(file, nome, '-');
			string tipo = "";
			getline(file, tipo, '-');
			string preco = "";
			getline(file, preco, '-');
			string pais = "";
			getline(file, pais, ',');
			string cidade = "";
			getline(file, cidade);
			getPais(pais).getCidade(cidade)->addAlojamento(
					Alojamento(tipo, nome, atof(preco.c_str())));
		}
		file.close();
	} else {

	}
}

void Agencia::loadViagens() {
	int vid = 0;
	string filename = "../viagens" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			//Ler id
			string id;
			getline(file, id, '-');
			if (vid < atoi(id.c_str())) {
				vid = atoi(id.c_str());
			}
			//Ler preco
			string preco;
			getline(file, preco, '-');
			//Ler itinerario/trocos
			string itinerario;
			getline(file, itinerario, '-');
			istringstream istream(itinerario);
			vector<Cidade*> vc;
			while (!istream.eof()) {
				string temp = "";
				getline(istream, temp, ';');
				istringstream tempstream(temp);
				string pais = "", cidade = "";
				getline(tempstream, pais, ',');
				getline(tempstream, cidade);
				try {
					vc.push_back(getPais(pais).getCidade(cidade));
				} catch (Pais::CidadeInexistente &ci) {
					cout << "Cidade " << ci.getNome() << " nao existe!" << endl;
				}
			}
			Itinerario iti(vc[0], vc[vc.size() - 1]);
			//Ler transportes
			string transportes;
			getline(file, transportes, '-');
			istringstream tstream(transportes);
			vector<string> vt;
			while (!tstream.eof()) {
				string temp = "";
				getline(tstream, temp, ';');
				vt.push_back(temp);
			}
			//Ler datas
			string datas;
			getline(file, datas, '-');
			istringstream dstream(datas);
			vector<tm> vd;
			while (!dstream.eof()) {
				tm nd;
				string dia = "";
				getline(dstream, dia, '/');
				nd.tm_mday = atoi(dia.c_str());
				string mes = "";
				getline(dstream, mes, '/');
				nd.tm_mon = atoi(mes.c_str()) - 1;
				string ano = "";
				getline(dstream, ano, ' ');
				nd.tm_year = atoi(ano.c_str()) + 100;
				string hora = "";
				getline(dstream, hora, ':');
				nd.tm_hour = atoi(hora.c_str());
				string minuto = "";
				getline(dstream, minuto, ';');
				nd.tm_min = atoi(minuto.c_str());
				vd.push_back(nd);
			}
			//Adicionar os trocos
			for (unsigned int i = 0; i < vc.size() - 1; i++) {
				iti.addTroco(Troco(vc[i], vc[i + 1], vt[i], vd[i]));
			}
			//Ler alojamento
			string alojamento;
			getline(file, alojamento);
			try {
				addViagem(
						Viagem(iti, atof(preco.c_str()), atoi(id.c_str()),
								iti.getDestino()->getAlojamento(alojamento)));
			} catch (Cidade::AlojamentoInexistente &ai) {
				cout << "Alojamento " << ai.getNome() << " " << endl;
			}

		}
		file.close();
	} else {

	}
	Viagem::sid = vid;
}

void Agencia::loadClientes() {
	string filename = "../clientes" + nome + ".txt";
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (!file.eof()) {
			string nome = "";
			getline(file, nome, '-');
			string tipo = "";
			getline(file, tipo, '-');
			if (tipo == "P") {
				addCliente(new Particular(nome));
			} else if (tipo == "C") {
				string nop = "";
				getline(file, nop, '-');
				addCliente(new Comercial(nome, atoi(nop.c_str())));
			}
			string vids = "";
			getline(file, vids);
			istringstream svids(vids);
			while (!svids.eof()) {
				string id = "";
				getline(svids, id, ' ');
				try {
					getCliente(nome)->addViagem(getViagem(atoi(id.c_str())));
				} catch (Agencia::ViagemInexistente &vi) {
					//should work still
				}
			}
		}
		file.close();
	} else {

	}
}

void Agencia::saveDestinos() {
	string filename = "../destinos" + nome + ".txt";
	if (ifstream(filename.c_str())) {
		remove(filename.c_str());
	}
	ofstream file(filename.c_str());
	for (unsigned int i = 0; i < paises.size(); i++) {
		for (unsigned int j = 0; j < paises[i].getCidades().size(); j++) {
			if (!(i == 0 && j == 0)) {
				file << endl;
			}
			file << paises[i].getNome() << "-"
					<< paises[i].getCidades()[j].getNome();
		}
	}
	file.close();
}

void Agencia::saveAlojamentos() {
	string filename = "../alojamentos" + nome + ".txt";
	if (ifstream(filename.c_str())) {
		remove(filename.c_str());
	}
	ofstream file(filename.c_str());
	for (unsigned int i = 0; i < paises.size(); i++) {
		for (unsigned int j = 0; j < paises[i].getCidades().size(); j++) {
			for (unsigned int k = 0;
					k < paises[i].getCidades()[j].getAlojamentos().size();
					k++) {
				if (!(i == 0 && j == 0 && k == 0)) {
					file << endl;
				}
				file << paises[i].getCidades()[j].getAlojamentos()[k].getNome()
						<< "-"
						<< paises[i].getCidades()[j].getAlojamentos()[k].getTipo()
						<< "-"
						<< paises[i].getCidades()[j].getAlojamentos()[k].getPreco()
						<< "-" << paises[i].getNome() << ","
						<< paises[i].getCidades()[j].getNome();
			}
		}
	}
	file.close();
}

void Agencia::saveViagens() {
	string filename = "../viagens" + nome + ".txt";
	if (ifstream(filename.c_str())) {
		remove(filename.c_str());
	}
	ofstream file(filename.c_str());
	for (unsigned int i = 0; i < viagens.size(); i++) {
		if (i != 0) {
			file << endl;
		}
		file << viagens[i].getId() << "-" << viagens[i].getPreco() << "-";
		vector<Troco> trocos = viagens[i].getItinerario().getTrocos();
		file << trocos[0].getCidadeOrigem()->getPais() << ","
				<< trocos[0].getCidadeOrigem()->getNome() << ";";
		for (unsigned int j = 0; j < trocos.size(); j++) {
			if (j != 0) {
				file << ";";
			}
			file << trocos[j].getCidadeDestino()->getPais() << ","
					<< trocos[j].getCidadeDestino()->getNome();
		}
		file << "-";
		for (unsigned int j = 0; j < trocos.size(); j++) {
			if (j != 0) {
				file << ";";
			}
			file << trocos[j].getTransporte().getTipo();
		}
		file << "-";
		for (unsigned int j = 0; j < trocos.size(); j++) {
			if (j != 0) {
				file << ";";
			}
			file << trocos[j].getData().tm_mday << "/"
					<< trocos[j].getData().tm_mon + 1 << "/"
					<< trocos[j].getData().tm_year - 100 << " "
					<< trocos[j].getData().tm_hour << ":"
					<< trocos[j].getData().tm_min;
		}
		file << "-";
		file << viagens[i].getAlojamento()->getNome();
	}
}

void Agencia::saveClientes() {
	string filename = "../clientes" + nome + ".txt";
	if (ifstream(filename.c_str())) {
		remove(filename.c_str());
	}
	ofstream file(filename.c_str());
	for (unsigned int i = 0; i < clientes.size(); i++) {
		if (i != 0) {
			file << endl;
		}
		file << clientes[i]->getNome() << "-";
		if (clientes[i]->getTipo() == "Comercial") {
			file << "C" << "-";
			file << clientes[i]->getNoParticipantes() << "-";
		} else if (clientes[i]->getTipo() == "Particular") {
			file << "P" << "-";
		}
		for (unsigned int j = 0; j < clientes[i]->getViagens().size(); j++) {
			if (j != 0) {
				file << " ";
			}
			file << clientes[i]->getViagens()[j]->getId();
		}
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
	nome.~basic_string();
	viagens.~vector();
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

}

string Particular::getTipo() const {
	return "Particular";
}

int Particular::getNoParticipantes() const {
	return 0;
}

float Particular::desconto() const {
	return 0;
}

int Particular::getMedParticipantes() const {
	return 0;
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

}

string Comercial::getTipo() const {
	return "Comercial";
}

int Comercial::getNoParticipantes() const {
	return noparticipantes;
}

void Comercial::addViagem(Viagem* v, int np) {
	Cliente::addViagem(v);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const {
	return noparticipantes / getViagens().size();
}

float Comercial::desconto() const {
	if (getViagens().size() > 5 && getMedParticipantes() > 10) {
		return 0.5;
	}
	if (getViagens().size() > 5 && getMedParticipantes() > 15) {
		return 0.10;
	}
	return 0;
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

Itinerario::Itinerario(Cidade* origem, Cidade* destino) :
		origem(origem), destino(destino) {

}

Itinerario::~Itinerario() {
	// TODO Auto-generated destructor stub
}

void Itinerario::addTroco(Troco troco) {
	trocos.push_back(troco);
}

vector<Troco> Itinerario::getTrocos() {
	return trocos;
}

Cidade* Itinerario::getOrigem() const {
	return origem;
}

Cidade* Itinerario::getDestino() const {
	return destino;
}

/* Class: Troco
 *
 *
 *
 */

Troco::Troco(Cidade* origem, Cidade* destino, Transporte transporte, tm data) :
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

Transporte::Transporte(string tipo) :
		tipo(tipo) {
	// TODO Auto-generated constructor stub
}

Transporte::~Transporte() {
	// TODO Auto-generated destructor stub
}

string Transporte::getTipo() const {
	return tipo;
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

string Cidade::AlojamentoInexistente::getNome() const{
	return this->nome;
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
	tipo.~basic_string();
	nome.~basic_string();
}

string Alojamento::getNome() const {
	return nome;
}

string Alojamento::getTipo() const {
	return tipo;
}

float Alojamento::getPreco() const {
	return preco;
}

bool Alojamento::operator==(const Alojamento& a) const {
	return (nome == a.nome);
}
