#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Agencia.h"
#include "Itinerario.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);
}

void test_Cidade() {
	/*
	 Cidade c1("Paris");
	 Cidade c2("Oslo");
	 Cidade c3("Tokio");
	 Cidade c4("Sidney");

	 ASSERT_EQUAL("Paris", c1.getNome());
	 ASSERT_EQUAL("Oslo", c2.getNome());
	 ASSERT_EQUAL("Tokio", c3.getNome());
	 ASSERT_EQUAL("Sidney", c4.getNome());*/
}

void test_Pais() {
	/*
	 Pais p1("França");
	 Pais p2("Noruega");
	 Pais p3("Japao");
	 Pais p4("Autralia");

	 ASSERT_EQUAL("França", p1.getNome());
	 ASSERT_EQUAL("Noruega", p2.getNome());
	 ASSERT_EQUAL("Japao", p3.getNome());
	 ASSERT_EQUAL("Australia", p4.getNome());

	 //p1.addCidade("Paris");
	 */
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(test_Cidade));
	s.push_back(CUTE(test_Pais));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

void pclientes(Agencia* a) {
	a->printClientes();
	getch();
}

void addcliente(Agencia* a) {
	string nome, email, morada;
	char tipo;
	cout << "Nome: ";
	cin >> nome;
	cout << "Email: ";
	cin >> nome;
	cout << "Morada: ";
	cin >> morada;
	cout << "Tipo ('P' ou 'C'): ";
	cin >> tipo;
	switch (tipo) {
	case 'P':
		a->addCliente(new Particular(nome, email, morada));
		break;
	case 'C':
		a->addCliente(new Comercial(nome, email, morada));
		break;
	default:
		cout << "Tipo de cliente inexistente!" << endl;
		system("pause");
		return;
		break;
	}
}

void cpviagens(Agencia* a,Cliente* c) {
	c->printViagens();
	getch();
}

void mcliente(Agencia* a) {
	string nome;
	cout << "Nome: ";
	cin >> nome;
	Cliente* c1;
	try {
		c1 = a->getCliente(nome);
	} catch (Agencia::ClienteInexistente &ci) {
		cout << "Cliente inexistente!" << endl;
		getch();
		return;
	}
	char c;
	cout << c1 << endl;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Comprar viagem;" << endl;
		cout << "2- Ver viagens futuras;" << endl;
		cout << "3- " << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':

			break;
		case '2':
			cpviagens(a,c1);
			break;
		case '3':

			break;
		default:
			break;
		}
	}
}

void gclientes(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Ver clientes;" << endl;
		cout << "2- Adicionar cliente;" << endl;
		cout << "3- Remover cliente;" << endl;
		cout << "4- Guardar clientes" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			pclientes(a);
			break;
		case '2':
			addcliente(a);
			break;
		case '3':
			break;
		case '4':
			a->saveClientes();
			break;
		default:
			break;
		}
	}
}

void pviagens(Agencia* a) {
	a->printViagens();
	getch();
}

void addviagem(Agencia* a) {
	cout << "Numero de trocos: ";
	unsigned int nt;
	cin >> nt;
	cin.ignore();
	vector<Troco> trocos;
	for (unsigned int i = 0; i < nt; i++) {
		cout << "Troco " << i + 1 << ":" << endl;
		string cidade = "";
		string pais = "";
		cout << "Origem (Pais,Cidade): ";
		Cidade* origem;
		getline(cin, pais, ',');
		getline(cin, cidade);
		try {
			origem = a->getPais(pais).getCidade(cidade);
		} catch (Agencia::PaisInexistente &pi) {
			cout << "Pais " << pi.getNome() << " inexistente!" << endl;
			getch();
			return;
		} catch (Pais::CidadeInexistente &ci) {
			cout << "Cidade " << ci.getNome() << " inexistente!" << endl;
			getch();
			return;
		}
		cout << "Destino (Pais,Cidade): ";
		Cidade* destino;
		getline(cin, pais, ',');
		getline(cin, cidade);
		try {
			destino = a->getPais(pais).getCidade(cidade);
		} catch (Agencia::PaisInexistente &pi) {
			cout << "Pais " << pi.getNome() << " inexistente!" << endl;
			getch();
			return;
		} catch (Pais::CidadeInexistente &ci) {
			cout << "Cidade " << ci.getNome() << " inexistente!" << endl;
			getch();
			return;
		}
		cout << "Transporte: ";
		string transporte = "";
		cin >> transporte;
		cin.ignore();
		cout << "Data (DD/MM/AA HH:MM): ";
		string d, m, a, h, min;
		getline(cin, d, '/');
		getline(cin, m, '/');
		getline(cin, a, ' ');
		getline(cin, h, ':');
		getline(cin, min);
		tm data;
		data.tm_mday = atoi(d.c_str());
		data.tm_mon = atoi(m.c_str()) - 1;
		data.tm_year = atoi(a.c_str()) + 100;
		data.tm_hour = atoi(h.c_str());
		data.tm_min = atoi(min.c_str());
		trocos.push_back(Troco(origem, destino, Transporte(transporte), data));
	}
	Itinerario iti(trocos[0].getCidadeOrigem(),
			trocos[trocos.size() - 1].getCidadeDestino());
	for (unsigned int i = 0; i < trocos.size(); i++) {
		iti.addTroco(trocos[i]);
	}
	cout << "Preco: ";
	float preco;
	cin >> preco;
	cout << "Alojamento? (y/n): ";
	char check;
	cin >> check;
	cin.ignore();
	if (check == 'y') {
		cout << "Nome: ";
		string alojamento = "";
		getline(cin, alojamento);
		Alojamento* al;
		try {
			al = trocos[trocos.size() - 1].getCidadeDestino()->getAlojamento(
					alojamento);
		} catch (Cidade::AlojamentoInexistente &ai) {
			cout << "Alojamento " << ai.getNome() << " inexistente!" << endl;
			getch();
			return;
		}
		//TODO: FIX THIS SHIT
		Viagem v(iti, preco + al->getPreco());
		if (a->addViagem(v))
			cout << "Viagem adicionada! ID: " << v.getId() << endl;
		else {
			cout << "Erro!" << endl;
		}
		getch();
	} else {
		//TODO: FIX THIS SHIT x2
		Viagem v(iti, preco);
		if (a->addViagem(v))
			cout << "Viagem adicionada! ID: " << v.getId() << endl;
		else {
			cout << "Erro!" << endl;
		}
		getch();
	}
}

void gviagens(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Ver viagens;" << endl;
		cout << "2- Adicionar viagem;" << endl;
		cout << "3- Remover viagem;" << endl;
		cout << "4- Guardar viagens;" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			pviagens(a);
			break;
		case '2':
			addviagem(a);
			break;
		case '3':

			break;
		case '4':
			a->saveViagens();
			break;
		default:
			break;
		}
	}
}

void pcidades(Agencia* a) {
	a->printCidades();
	getch();
}

void addcidade(Agencia* a) {
	cout << "Pais: ";
	string pais = "";
	cin >> pais;
	try {
		a->getPais(pais);
	} catch (Agencia::PaisInexistente &pi) {
		a->addPais(Pais(pais));
	}
	cout << "Cidade: ";
	string cidade = "";
	cin >> cidade;
	a->getPais(pais).addCidade(Cidade(cidade, pais));
	cout << "Destino " << pais << "," << cidade << " adicionado!" << endl;
	getch();
}

void gcidades(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Ver cidades;" << endl;
		cout << "2- Adicionar cidade;" << endl;
		cout << "3- Remover cidade;" << endl;
		cout << "4- Guardar cidades;" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			pcidades(a);
			break;
		case '2':
			addcidade(a);
			break;
		case '3':
			break;
		case '4':
			a->saveDestinos();
			break;
		default:
			break;
		}
	}
}

void palojamentos(Agencia* a) {
	for (unsigned int i = 0; i < a->getPaises().size(); i++) {
		for (unsigned int j = 0; j < a->getPaises()[i].getCidades().size();
				j++) {
			for (unsigned int k = 0;
					k
							< a->getPaises()[i].getCidades()[j].getAlojamentos().size();
					k++) {
				cout << a->getPaises()[i].getNome() << ","
						<< a->getPaises()[i].getCidades()[j].getNome() << " - "
						<< a->getPaises()[i].getCidades()[j].getAlojamentos()[k].getNome()
						<< endl;
			}
		}
	}
	getch();
}

void addalojamento(Agencia* a) {
	cout << "Pais: ";
	string pais = "";
	cin >> pais;
	try {
		a->getPais(pais);
	} catch (Agencia::PaisInexistente &pi) {
		cout << "Pais " << pi.getNome() << " nao existe!" << endl;
		getch();
		return;
	}
	cout << "Cidade: ";
	string cidade = "";
	cin >> cidade;
	cin.ignore();
	try {
		a->getPais(pais).getCidade(cidade);
	} catch (Pais::CidadeInexistente &ci) {
		cout << "Cidade " << ci.getNome() << " nao existe!" << endl;
		getch();
		return;
	}
	cout << "Nome: ";
	string nome = "";
	getline(cin, nome);
	cout << "Tipo: ";
	string tipo = "";
	cin >> tipo;
	cout << "Preco: ";
	float preco = 0;
	cin >> preco;
	a->getPais(pais).getCidade(cidade)->addAlojamento(
			Alojamento(tipo, nome, preco));
	getch();
}

void galojamentos(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Ver alojamentos;" << endl;
		cout << "2- Adicionar alojamento;" << endl;
		cout << "3- Remover alojamento;" << endl;
		cout << "4- Guardar alojamentos;" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			palojamentos(a);
			break;
		case '2':
			addalojamento(a);
			break;
		case '3':
			break;
		case '4':
			a->saveAlojamentos();
			break;
		default:
			break;
		}
	}
}

void pdestinos(Agencia* a) {
	a->printDestinos();
	getch();
}

void adddestinos(Agencia* a) {

}

void gdestinos(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Ver destinos;" << endl;
		cout << "2- Adicionar destino;" << endl;
		cout << "3- Remover destino;" << endl;
		cout << "4- Guardar destinos;" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			pdestinos(a);
			break;
		case '2':
			adddestinos(a);
			break;
		case '3':
			break;
		case '4':
			a->saveDestinos();
			break;
		default:
			break;
		}
	}
}

void admin(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Gerir clientes;" << endl;
		cout << "2- Gerir viagens;" << endl;
		cout << "3- Gerir cidades;" << endl;
		cout << "4- Gerir alojamentos;" << endl;
		cout << "5- Gerir destinos;" << endl;
		cout << "9- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			gclientes(a);
			break;
		case '2':
			gviagens(a);
			break;
		case '3':
			gcidades(a);
			break;
		case '4':
			galojamentos(a);
			break;
		case '5':
			gdestinos(a);
			break;
		default:
			break;
		}
	}
}

void manual() {
	string nome;
	cout << "Nome da agencia: ";
	cin >> nome;
	Agencia* a = new Agencia(nome);
	//Carregar informações para agencia
	a->loadCidades();
	a->loadAlojamentos();
	a->loadViagens();
	a->loadDestinos();
	a->loadClientes();
	char c;
	system("cls");
	while (c != 27 && c != '3') {
		system("cls");
		cout << "1- Cliente;" << endl;
		cout << "2- Administrador;" << endl;
		cout << "3- Voltar;" << endl;
		c = getch();
		system("cls");
		switch (c) {
		case '1':
			mcliente(a);
			break;
		case '2':
			admin(a);
			break;
		default:
			break;
		}
	}
}

int main(int argc, char const *argv[]) {
	char c;
	while (c != 27 && c != '3') {
		cout << "1- Automatico;" << endl;
		cout << "2- Manual;" << endl;
		cout << "3- Sair." << endl;
		cout << asctime(Agencia::getTempo_Info()) << endl;
		c = getch();
		system("CLS");
		switch (c) {
		case '1':
			runAllTests(argc, argv);
			break;
		case '2':
			manual();
			break;
		default:
			break;
		}
	}
	return 0;
}
