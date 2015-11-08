#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Agencia.h"

void thisIsATest() {
	ASSERTM("start writing tests", false);
}

void test_Cidade() {

	Cidade c1("Paris");
	Cidade c2("Oslo");
	Cidade c3("Tokio");
	Cidade c4("Sidney");

	ASSERT_EQUAL("Paris", c1.getNome());
	ASSERT_EQUAL("Oslo", c2.getNome());
	ASSERT_EQUAL("Tokio", c3.getNome());
	ASSERT_EQUAL("Sidney", c4.getNome());
}

void test_Pais() {

	Pais p1("Fran�a");
	Pais p2("Noruega");
	Pais p3("Japao");
	Pais p4("Autralia");

	ASSERT_EQUAL("Fran�a", p1.getNome());
	ASSERT_EQUAL("Noruega", p2.getNome());
	ASSERT_EQUAL("Japao", p3.getNome());
	ASSERT_EQUAL("Australia", p4.getNome());

	//p1.addCidade("Paris");

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
	for (unsigned int i = 0; i < a->getClientes().size(); i++)
		cout << (*a->getClientes()[i]) << endl;
	getch();
}
void addcliente(Agencia* a) {
	string nome;
	char tipo;
	cout << "Nome: ";
	cin >> nome;
	cout << "Tipo ('P' ou 'C'): ";
	cin >> tipo;
	switch (tipo) {
	case 'P':
		a->addCliente(new Particular(nome));
		break;
	case 'C':
		a->addCliente(new Comercial(nome));
		break;
	default:
		cout << "Tipo de cliente inexistente!" << endl;
		system("pause");
		return;
		break;
	}
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
		system("pause");
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
		cin >> c;
		system("cls");
		switch (c) {
		case '1':

			break;
		case '2':

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
		cout << "2- Adicionar Cliente;" << endl;
		cout << "3- Remover Cliente;" << endl;
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
		default:
			break;
		}
	}
}

void gviagens(Agencia* a) {

}

void pdestinos(Agencia* a) {
	for (unsigned int i = 0; i < a->getPaises().size(); i++) {
		for (unsigned int j = 0; j < a->getPaises()[i].getCidades().size();
				j++) {
			cout << a->getPaises()[i].getNome() << ","
					<< a->getPaises()[i].getCidades()[j].getNome() << endl;
		}
	}
	getch();
}

void adddestino(Agencia* a) {
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
	a->getPais(pais).addCidade(Cidade(cidade));
	cout << "Destino " << pais << "," << cidade << " adicionado!" << endl;
	getch();
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
			adddestino(a);
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
	getline(cin,nome);
	cout << "Tipo: ";
	string tipo = "";
	cin >> tipo;
	cout << "Preco: ";
	float preco = 0;
	cin >> preco;
	a->getPais(pais).getCidade(cidade)->addAlojamento(Alojamento(tipo,nome,preco));
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

void admin(Agencia* a) {
	char c;
	while (c != 27 && c != '9') {
		system("cls");
		cout << "1- Gerir clientes;" << endl;
		cout << "2- Gerir viagens;" << endl;
		cout << "3- Gerir destinos;" << endl;
		cout << "4- Gerir alojamentos;" << endl;
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
			gdestinos(a);
			break;
		case '4':
			galojamentos(a);
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
	//Carregar informa��es para agencia
	a->loadDestinos();
	a->loadAlojamentos();
	a->loadViagens();
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
	while (c != 27 && c != 3) {
		cout << "1- Automatico" << endl;
		cout << "2- Manual" << endl;
		cout << "3- Sair" << endl;
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
