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

Agencia::Agencia(string nome):nome(nome) {

}

Agencia::~Agencia() {
	// TODO Auto-generated destructor stub
}

string Agencia::getNome() const{
	return nome;
}

bool Agencia::addCliente(Cliente c){
	vector<Cliente>::const_iterator it;
	it = find(clientes.begin(),clientes.end(),c);
	if (it!=clientes.end())
		return false; //TODO change to a throw eventually
	clientes.push_back(c);
	return true;
}

vector<Cliente> Agencia::getClientes(){
	return clientes;
}

void Agencia::sortClientes(){

}

bool Agencia::addViagem(Viagem v) {
	vector<Viagem>::const_iterator it;
	it = find(viagens.begin(), viagens.end(), v);
	if (it != viagens.end())
		return false; //TODO change to a throw eventually
	viagens.push_back(v);
	return true;
}

/* Class: Cliente
 *
 *
 *
 */

Cliente::Cliente():nome("") {

}

Cliente::Cliente(string nome):nome(nome) {

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

int Cliente::getNoViagens() const{
	return viagens.size();
}

string Cliente::getNome() const{
	return nome;
}

bool Cliente::operator==(const Cliente& cliente) const{
	return (nome==cliente.nome);
}

void Cliente::addViagem(Viagem* v){
	viagens.push_back(v);
}

vector<Viagem*> Cliente::getViagens() const{
	return viagens;
}

string Cliente::getTipo() const{
	return "";
}

//TODO usar templates talvez para ver se imprime o tipo direito
ostream & operator<<(ostream & o, const Cliente & c){
	o << "Nome: " << c.getNome() << ";\n" << "Tipo: " << c.getTipo() << ";\n" << "No de Viagens: " << c.getNoViagens() << ";\n";
	return o;
}

Cliente* Agencia::getCliente(string nome){
	for(unsigned int i=0; i < clientes.size();i++){
		if(clientes[i].getNome()== nome)
			return &clientes[i];
	}
	return new Cliente();
}

/* Class: Particular
 *
 *
 *
 */

Particular::Particular(string nome):Cliente(nome) {

}

Particular::~Particular() {
	// TODO Auto-generated destructor stub
}

string Particular::getTipo() const{
	return "particular";
}

/* Class: Comercial
 *
 *
 *
 */

Comercial::Comercial(string nome):Cliente(nome),noparticipantes(0) {

}

Comercial::~Comercial() {
	// TODO Auto-generated destructor stub
}

string Comercial::getTipo() const{
	return "comercial";
}

void Comercial::addViagem(Viagem* v,int np){
	Cliente::addViagem(v);
	this->noparticipantes += noparticipantes;
}

int Comercial::getMedParticipantes() const{
	return noparticipantes/getViagens().size();
}

float Comercial::desconto(){

	float desconto=0;

	if (getViagens().size() > 5 && getMedParticipantes()>10)
	{
		desconto = 0.5;
	}

	if (getViagens().size() > 5 && getMedParticipantes() > 15)
	{
		desconto=0.10;
	}

	return desconto;
}

/* Class: Viagem
 *
 *
 *
 */

Viagem::Viagem(Itinerario itinerario,float preco,Alojamento* alojamento):itinerario(itinerario),alojamento(alojamento),preco(preco),id(sid++) {

}

Viagem::~Viagem() {
	// TODO Auto-generated destructor stub
}

float Viagem::getPreco() const{
	return preco;
}

Itinerario Viagem::getItinerario(){
	return itinerario;
}

Alojamento* Viagem::getAlojamento(){
	//TODO add a throw eventually for non existent alojamento
	return alojamento;
}

int Viagem::getId() const{
	return id;
}

bool Viagem::operator==(const Viagem& v) const{
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

Itinerario::Itinerario(Cidade origem,Cidade destino):origem(origem),destino(destino) {

}

Itinerario::~Itinerario() {
	// TODO Auto-generated destructor stub
}

vector<Troco> Itinerario::getTrocos(){
	return trocos;
}

Cidade Itinerario::getOrigem(){
	return origem;
}

Cidade Itinerario::getDestino(){
	return destino;
}

/* Class: Troco
 *
 *
 *
 */

Troco::Troco(Cidade origem,Cidade destino,Transporte transporte,tm data):origem(origem),destino(destino),transporte(transporte),data(data) {

}

Troco::~Troco() {
	// TODO Auto-generated destructor stub
}

Cidade Troco::getCidadeOrigem() const{
	return origem;
}

Cidade Troco::getCidadeDestino() const{
	return destino;
}

Transporte Troco::getTransporte() const{
	return transporte;
}

tm Troco::getData() const{
	return data;
}

/* Class: Transporte
 *
 *
 *
 */

Transporte::Transporte() {
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

Pais::Pais(string nome):nome(nome) {

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

string Pais::getNome() const{
	return nome;
}

/* Class: Cidade
 *
 *
 *
 */

Cidade::Cidade(string nome):nome(nome) {

}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub
}

string Cidade::getNome() const{
	return nome;
}

bool Cidade::addAlojamento(const Alojamento& a){
	vector<Alojamento>::const_iterator it;
	it = find(alojamentos.begin(), alojamentos.end(), a);
	if (it != alojamentos.end())
		return false; //TODO change to a throw eventually
	alojamentos.push_back(a);
	return true;
}

bool Cidade::operator==(const Cidade& c) const{
	return (nome==c.nome);
}

/* Class: Alojamento
 *
 *
 *
 */

Alojamento::Alojamento():tipo(""),nome(""),preco(0){

}

Alojamento::Alojamento(string tipo, string nome, float preco):tipo(tipo),nome(nome),preco(preco) {

}

Alojamento::~Alojamento() {
	// TODO Auto-generated destructor stub
}

bool Alojamento::operator==(const Alojamento& a) const{
	return (nome==a.nome);
}
