#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;
class factura {
public:
	bool factura_platita;
	float* factura_suma;
	int nr_luni;
	char* nume_platitor;
	char* nume_emitent;
	const int CUI;
	static unsigned int nr_factura;
	//constructor fara parametrii
	factura() : CUI(factura::nr_factura)
	{
		this->factura_platita = true;
		this->nume_platitor = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_platitor, "Necunoscut");
		this->nume_emitent = new char[strlen("CompaniaX") + 1];
		strcpy(this->nume_emitent, "CompaniaX");
		this->nr_luni = 0;
		this->factura_suma = NULL;
		factura::nr_factura++;
	}
	//constructor cu toti parametrii
	factura(char* t_nume_platitor, char* t_nume_emitent, bool t_factura_platita, int t_nr_luni, float* t_suma) :CUI(factura::nr_factura)
	{
		int i;
		this->nume_platitor = new char[strlen(t_nume_platitor) + 1];
		strcpy(this->nume_platitor, t_nume_platitor);
		this->nume_emitent = new char[strlen(t_nume_emitent) + 1];
		strcpy(this->nume_emitent, t_nume_emitent);
		this->factura_platita = t_factura_platita;
		this->nr_luni = t_nr_luni;
		this->factura_suma = new float[this->nr_luni];
		for (i = 0; i < this->nr_luni; i++)
			this->factura_suma[i] = t_suma[i];
		factura::nr_factura++;
	}

	//constructor cu trei parametrii
	factura(char* t_nume_platitor, char* t_nume_emitent, int t_nr_luni, float* t_suma, bool t_factura_platita = false) :factura_platita(t_factura_platita), CUI(factura::nr_factura)
	{
		int i;
		this->nume_platitor = new char[strlen(t_nume_platitor) + 1];
		strcpy(this->nume_platitor, t_nume_platitor);
		this->nume_emitent = new char[strlen(t_nume_emitent) + 1];
		strcpy(this->nume_emitent, t_nume_emitent);
		this->nr_luni = t_nr_luni;
		this->factura_suma = new float[this->nr_luni];
		for (i = 0; i < this->nr_luni; i++)
			this->factura_suma[i] = t_suma[i];
		factura::nr_factura++;
	}

	//constructor de copiere
	factura(factura &f) :CUI(factura::nr_factura++)
	{
		int i;
		this->nume_emitent = new char[strlen(f.nume_emitent) + 1];
		strcpy(this->nume_emitent, f.nume_emitent);
		this->nume_platitor = new char[strlen(f.nume_platitor) + 1];
		strcpy(this->nume_platitor, f.nume_platitor);
		this->nr_luni = f.nr_luni;
		this->factura_platita = f.factura_platita;
		this->factura_suma = new float[this->nr_luni];
		for (i = 0; i < this->nr_luni; i++)
		{
			this->factura_suma[i] = f.factura_suma[i];
		}
	}
	//destructor
	/*
	~factura()
	{
		cout << "Destructorul functioneaza!" << endl;
		if (this->nume_platitor != NULL) {
			delete[] this->nume_platitor;
		}
		if (this->nume_emitent != NULL) {
			delete[] this->nume_emitent;
		}
		if (this->factura_suma != NULL) {
			delete[] this->factura_suma;
		}
		factura::nr_factura--;
	}*/
	//getteri 
	bool getFacturaPlatita()
	{
		return this->factura_platita;
	}

	float* getSuma()
	{
		return this->factura_suma;
	}

	char* getNumeEmitent()
	{
		return this->nume_emitent;
	}

	char* getNumePlatitor()
	{
		return this->nume_platitor;
	}

	static unsigned int getNrFactura()
	{
		return factura::nr_factura;
	}

	int getCUI()
	{
		return this->CUI;
	}

	//setteri

	void setSuma(int t_nr_luni, float* t_suma)
	{
		int i;
		this->nr_luni = t_nr_luni;
		if (this->factura_suma != NULL)
			delete[] this->factura_suma;
		this->factura_suma = new float[this->nr_luni];
		for (i = 0; i < this->nr_luni; i++)
			this->factura_suma[i] = t_suma[i];
	}
	void setNumePlatitor(char* t_nume_platitor)
	{


		if (this->nume_platitor != NULL)
		{
			delete[] this->nume_platitor;
		}
		this->nume_platitor = new char[strlen(t_nume_platitor) + 1];
		strcpy(this->nume_platitor, t_nume_platitor);

	}

	static void setNrFactura(unsigned int nrF)
	{
		factura::nr_factura = nrF;
	}

	void setNumeEmitent(char* t_nume_emitent)
	{


		if (this->nume_emitent != NULL)
		{
			delete[] this->nume_emitent;
		}
		this->nume_emitent = new char[strlen(t_nume_emitent) + 1];
		strcpy(this->nume_emitent, t_nume_emitent);

	}
	/*
	factura& operator=(const factura& s1)
	{
	int i;
	if (this->nume_emitent != NULL)
	{
	delete[] this->nume_emitent;
	}
	if (this->nume_platitor != NULL)
	{
	delete[] this->nume_platitor;
	}
	*/

	void operator=(factura &f) {
		delete[] factura_suma;
		delete[] nume_platitor;
		delete[] nume_emitent;
		this->nume_emitent = new char[strlen(f.nume_emitent) + 1];
		strcpy(this->nume_emitent, f.nume_emitent);
		this->nume_platitor = new char[strlen(f.nume_platitor) + 1];
		strcpy(this->nume_platitor, f.nume_platitor);
		this->factura_platita = f.factura_platita;
		this->nr_luni = f.nr_luni;
		this->factura_suma = new float[f.nr_luni];
		for (int i = 0; i < f.nr_luni; i++) {
			this->factura_suma[i] = f.factura_suma[i];
		}
	}

	friend ostream& operator<<(ostream& out, factura s2)
	{
		int i;
		out << "CUI: " << s2.CUI << endl;
		out << "Nume Emitent: " << s2.nume_emitent << endl;
		out << "Nume Platitor: " << s2.nume_platitor << endl;
		out << "Factura este platita?: " << s2.factura_platita << endl;
		out << "Numar luni facturate: " << s2.nr_luni << endl;
		for (i = 0; i < s2.nr_luni; i++)
			out << "\t" << s2.factura_suma[i] << endl;
		return out;
	}

#pragma region Citire si scriere in fisiere
	//citire si scriere in fisiere
	friend ofstream& operator<<(ofstream& out, factura f3) {
		out << f3.CUI << endl;
		out << f3.nume_emitent << endl;
		out << f3.nume_platitor << endl;
		out << f3.factura_platita << endl;
		out << f3.nr_luni << endl;
		for (int i = 0; i < f3.nr_luni; i++) {
			out << "\t" << f3.factura_suma[i] << " ";
		}
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, factura& f) {
		char buff1[50], buff2[50];
		in >> buff1;
		f.setNumeEmitent(buff1);
		in >> buff2;
		f.setNumePlatitor(buff2);
		in >> f.factura_platita;
		if (f.factura_platita == false)
		{
			in >> f.nr_luni;
			in.ignore();
			if (f.factura_suma != NULL)
				delete[] f.factura_suma;
			f.factura_suma = new float[f.nr_luni];
			for (int i = 0; i < f.nr_luni; i++) {
				in >> f.factura_suma[i];
			}
		}
		else {
			f.nr_luni = 0;
			f.factura_suma = NULL;
		}
		return in;
	}
#pragma endregion Citire si scriere in fisiere


	//functia de afisare a unui obiect
	void afisareF()
	{
		cout << "CUI: " << this->CUI << endl;
		cout << "Nume Emitent: " << this->nume_emitent << endl;
		cout << "Nume Platitor: " << this->nume_platitor << endl;
		cout << "Factura platita(1 DA/0 NU): " << this->factura_platita << endl;
		cout << "Suma: " << this->factura_suma << endl;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& in, factura& s3)
	{
		cout << "Nume emitent: " << endl;
		char buff1[50], buff2[50];
		in.getline(buff1, 50);
		s3.setNumeEmitent(buff1);
		//in.ignore();
		cout << "Nume platitor: " << endl;
		in.getline(buff2, 50);
		s3.setNumePlatitor(buff2);
		//in.ignore();
		cout << "Factura este platita?(1 DA/0 NU): " << endl;
		in >> s3.factura_platita;
		if (s3.factura_platita == false)
		{
			cout << "Numar luni facturate: " << endl;
			in >> s3.nr_luni;
			in.ignore();
			if (s3.factura_suma != NULL)
				delete[] s3.factura_suma;
			s3.factura_suma = new float[s3.nr_luni];
			for (int i = 0; i < s3.nr_luni; i++) {
				cout << "Suma pentru luna " << i + 1 << " este: ";
				in >> s3.factura_suma[i];
			}
		}
		else {
			s3.nr_luni = 0;
			s3.factura_suma = NULL;
		}
		return in;
	}

	//operatorul index
	char operator[](int i)
	{
		if (i >= 0 && i < (this->nr_luni))
			return this->factura_suma[i];
		else return -1;
	}

	//operatorul de incrementare; postincrementare & preincrementare
	factura operator++()
	{
		this->nr_luni++;
		return *this;
	}

	friend factura operator++(factura &f, int)
	{
		factura tmp = f;
		f.nr_luni++;
		return tmp;
	}

	//operatorul de decrementare; predrecrementare & postdecrementare
	factura operator--()
	{
		this->nr_luni--;
		return *this;
	}

	friend factura operator--(factura &f, int)
	{
		factura tmp = f;
		f.nr_luni--;
		return tmp;
	}

	//operator '+'
	factura operator+(int newNrluni)
	{
		this->nr_luni = this->nr_luni + newNrluni;
		return *this;
	}

	//operator '!'
	bool operator!()
	{
		if (this->factura_platita == false)
			return true;
		else return false;
	}

	//operator '>'
	bool operator>(factura f)
	{
		if (f.nr_luni > this->nr_luni)
			return true;
		else return false;
	}

	//operatorul '=='
	bool operator==(factura f)
	{
		if (strcmp(this->nume_emitent, f.nume_emitent) == 0 && strcmp(this->nume_platitor, f.nume_platitor) == 0 && this->nr_luni == f.nr_luni && this->factura_platita == f.factura_platita)
			return true;
		else return false;
	}

	//functie de prelucrare
	factura modificareBacnota(float s)
	{
		int i;
		for (i = 0; i < (this->nr_luni); i++)
			this->factura_suma[i] = this->factura_suma[i] / s;
		return *this;
	}
};

unsigned int factura::nr_factura = 0;

class FisierFactura : public factura {
public:
	void FisierBinar(char* nume_fisier) {
		ofstream backup;
		backup.open(nume_fisier, ios::out | ios::binary);
		if (backup.is_open()) {
			char buff1[50], buff2[50];
			strcpy(buff1, this->nume_platitor);
			strcpy(buff2, this->nume_emitent);
			backup.write(buff1, 50);
			backup.write(buff2, 50);
			if (this->factura_platita != NULL) {
				backup.write((char*)& this->factura_platita, sizeof(bool));
				backup.write((char*)& this->nr_luni, sizeof(int));
				for (int i = 0; i < this->nr_luni; i++)
					backup.write((char*)&this->factura_suma[i], sizeof(float));
			}
		}
	}

	FisierFactura citire_csv(char* nume_fisier, char despartitor) {
		ifstream fisier_csv(nume_fisier);
		if (fisier_csv.is_open()) {
			while (fisier_csv.good()) {
				fisier_csv.getline(this->nume_emitent, 256, despartitor);
				fisier_csv.getline(this->nume_platitor, 256, despartitor);
				char factura_platita[2];
				fisier_csv.getline(factura_platita, 256, despartitor);
				this->factura_platita = atoi(factura_platita);
				char nr_luni[100];
				fisier_csv.getline(nr_luni, 256, despartitor);
				this->nr_luni = atoi(nr_luni);
				char factura_suma[100];
				fisier_csv.getline(factura_suma, 256, despartitor);
				//this->factura_suma = atof(factura_suma);
			}
		}
		return *this;
	}
};

class RaportFacturi {
public:
	factura* facturi;
	int nr_facturi;
	RaportFacturi() {
		this->nr_facturi = 0;
		this->facturi = NULL;
	}

	RaportFacturi(factura* t_facturi, int t_nr_facturi) {
		this->nr_facturi = t_nr_facturi;
		this->facturi = new factura[this->nr_facturi];
		for (int i = 0; i < this->nr_facturi; i++) {
			this->facturi[i] = t_facturi[i];
		}
	}

	friend ostream& operator<<(ostream& out, RaportFacturi &f) {
		out << "Numar facturi: " << f.nr_facturi << endl;
		out << "Facturile sunt: " << endl;
		for (int i = 0; i < f.nr_facturi; i++) {
			out << "Factura " << i + 1 << " este :" << f.facturi[i] << endl;
		}
		out << endl;
		return out;
	}

	//afisare raport in text

	void Raport(RaportFacturi factura, char* nume_fisier) {
		ofstream raport;
		raport.open(nume_fisier, ios::out | ios::trunc);
		if (raport.is_open()) {

			raport << "Numar facturi: " << factura.nr_facturi << endl;;
			raport << "\t Facturile sunt: " << endl;
			for (int i = 0; i < factura.nr_facturi; i++) {
				raport << factura.facturi[i] << endl;
			}
			raport << endl;
			raport.close();
		}
	}

};

class client {
public:
	char* nume_client;
	char* adresa;
	unsigned int joburi;
	float* venit_disponibil;
	//constructor fara parametrii
	client()
	{
		this->nume_client = new char[strlen("Anonim") + 1];
		strcpy(this->nume_client, "Anonim");
		this->adresa = new char[strlen("AdresaX") + 1];
		strcpy(this->adresa, "AdresaX");
		this->joburi = 0;
		this->venit_disponibil = NULL;

	}

	//constructor cu toti parametrii
	client(char* t_nume_client, char* t_adresa, float* t_venit_disponibil, unsigned int t_joburi)
	{
		this->nume_client = new char[strlen(t_nume_client) + 1];
		strcpy(this->nume_client, t_nume_client);
		this->adresa = new char[strlen(t_adresa) + 1];
		strcpy(this->adresa, t_adresa);
		this->joburi = t_joburi;
		this->venit_disponibil = new float[this->joburi];
		for (int i = 0; i < this->joburi; i++)
			this->venit_disponibil[i] = t_venit_disponibil[i];
	}

	//constructor cu doi parametrii
	client(char* t_adresa, float* t_venit_disponibil)
	{
		int i;
		this->nume_client = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume_client, "Necunoscut");
		this->adresa = new char[strlen(t_adresa) + 1];
		strcpy(this->adresa, t_adresa);
		this->joburi = 1;
		this->venit_disponibil = new float[this->joburi];
		for (i = 0; i < this->joburi; i++)
			this->venit_disponibil[i] = t_venit_disponibil[i];
	}

	//constructorul de copiere
	client(const client& source)
	{
		int i;
		this->nume_client = new char[strlen(source.nume_client) + 1];
		strcpy(this->nume_client, source.nume_client);
		this->adresa = new char[strlen(source.adresa) + 1];
		strcpy(this->adresa, source.adresa);
		this->joburi = source.joburi;
		this->venit_disponibil = new float[this->joburi];
		for (i = 0; i < this->joburi; i++)
			this->venit_disponibil[i] = source.venit_disponibil[i];
	}
	/*
	~client()
	{
	cout << "In al doilea destructor!.." << endl;
	if (this->nume_client != NULL) {
	delete[] this->nume_client;
	}
	if (this->adresa != NULL) {
	delete[] this->adresa;
	}
	if (this->venit_disponibil != NULL) {
	delete[] this->venit_disponibil;
	}

	}*/

	//getteri
	char* getNume_Client()
	{
		return this->nume_client;
	}

	char* getAdresa()
	{
		return this->adresa;
	}

	float* getVenit_Disponibil()
	{
		return this->venit_disponibil;
	}

	unsigned int getJoburi()
	{
		return this->joburi;
	}

	//setteri 

	void setVenit_Disponibil(unsigned int t_joburi, float* t_venit_disponibil)
	{
		int i;
		this->joburi = t_joburi;
		if (this->venit_disponibil != NULL)
			delete[] this->venit_disponibil;
		this->venit_disponibil = new float[this->joburi];
		for (i = 0; i < this->joburi; i++)
			this->venit_disponibil[i] = t_venit_disponibil[i];
	}

	void setNume_Client(char* t_nume_client)
	{

		if (this->nume_client != NULL)
			delete[] this->nume_client;
		this->nume_client = new char[strlen(t_nume_client) + 1];
		strcpy(this->nume_client, t_nume_client);

	}

	void setAdresa(char* t_adresa)
	{

		if (this->adresa != NULL)
			delete[] this->adresa;
		this->adresa = new char[strlen(t_adresa) + 1];
		strcpy(this->adresa, t_adresa);

	}

	//supraincarcare operatori <<,>>

	friend ostream& operator<<(ostream& out, client s)
	{
		out << "Nume client: " << s.nume_client << endl;
		out << "Adresa: " << s.adresa << endl;
		out << "Numarul de joburi: " << s.joburi;
		for (int i = 0; i < s.joburi; i++)
			out << "\t" << "Venitul pentru jobul " << i + 1 << "este: " << s.venit_disponibil[i] << endl;
		return out;
	}

	friend istream& operator>>(istream& in, client& s1)
	{
		char buff1[50];
		char buff2[50];
		cout << "Nume client: " << endl;
		in >> buff1;
		s1.setNume_Client(buff1);
		in.ignore();
		cout << "Adresa: " << endl;
		in >> buff2;
		s1.setAdresa(buff2);
		in.ignore();
		cout << "Numar joburi: " << endl;
		in >> s1.joburi;
		if (s1.venit_disponibil != NULL)
			delete[] s1.venit_disponibil;
		s1.venit_disponibil = new float[s1.joburi];
		for (int i = 0; i < s1.joburi; i++) {
			cout << "Venitul pentru job " << i + 1 << "este: " << endl;
			in >> s1.venit_disponibil[i];
		}
		return in;
	}

	//supraincare operatori matematici +,-
	client operator +(int job_nou)
	{
		this->joburi = this->joburi + job_nou;
		return *this;
	}

	client operator-(int nr_joburi_minus)
	{
		this->joburi = this->joburi - nr_joburi_minus;
		return *this;
	}

	//supraincare operator ++
	//incrementeaza numarul de joburi
	//preincrementare
	friend client operator++(client& c, int)
	{
		client tmp = c;
		c.joburi++;
		return tmp;
	}

	//postincrementare
	client operator++()
	{
		this->joburi++;
		return *this;
	}
	//supraincare operator --
	//decrementeaza numarul de joburi
	//predecrementare
	friend client operator--(client& c, int)
	{
		client tmp = c;
		c.joburi--;
		return tmp;
	}

	//postdrecrementare
	client operator--()
	{
		this->joburi--;
		return *this;
	}

	//supraincare operator indexare[]
	//returneaza venitul la o luna i
	float operator[](int i)
	{
		if (i > 0 && i < (this->joburi))
			return this->venit_disponibil[i];
		else return -1;
	}

	//operatorul !
	bool operator!()
	{
		if (this->joburi > 0)
			return false;
		else return true;
	}
	//operatorul >
	bool operator>(client c)
	{
		if (c.joburi > this->joburi)
			return true;
		else return false;
	}

	//operatorul ==
	bool operator==(client c)
	{
		if (strcmp(this->nume_client, c.nume_client) == 0 && strcmp(this->adresa, c.adresa) == 0 && this->joburi == c.joburi)
			return true;
		else return false;
	}

	//citire din fisier
	friend ifstream& operator>>(ifstream& in, client& c) {
		char buff1[50], buff2[50];
		in >> buff1;
		c.setNume_Client(buff1);
		in >> buff2;
		c.setAdresa(buff2);
		in >> c.joburi;
		in.ignore();
		if (c.venit_disponibil != NULL)
			delete[] c.venit_disponibil;
		c.venit_disponibil = new float[c.joburi];
		for (int i = 0; i < c.joburi; i++) {
			in >> c.venit_disponibil[i];
		}
		return in;
	}

	//functie de prelucrare (transformare venit disponibil din lei in alta moneda)
	client modificareVenitDisponibil(float c)
	{
		int i;
		for (i = 0; i < (this->joburi); i++)
			this->venit_disponibil[i] = this->venit_disponibil[i] / c;
		return *this;
	}

	void afisare()
	{
		cout << "Nume: " << this->nume_client << endl;
		cout << "Salariu: " << this->adresa << endl;
		cout << "Numar de joburi: " << this->joburi << endl;
		for (int i = 0; i < this->joburi; i++)
			cout << "Venitul pentru jobul " << i + 1 << "este: " << this->venit_disponibil[i] << endl;
	}

};

class FisierClient : public client {
public:
	void ClientBinar(char* nume_fisier) {
		ofstream client_backup;
		client_backup.open(nume_fisier, ios::out | ios::binary);
		if (client_backup.is_open()) {
			char buff1[50], buff2[50];
			strcpy(buff1, this->nume_client);
			strcpy(buff2, this->adresa);
			client_backup.write((char*)&this->joburi, sizeof(int));
			if (this->venit_disponibil != NULL) {
				delete[]this->venit_disponibil;
			}
			for (int i = 0; i < this->joburi; i++) {
				client_backup.write((char*)&this->venit_disponibil[i], sizeof(float));
			}
		}
	}

	FisierClient citire_csv(char* nume_fisier, char despartitor) {
		ifstream fisier_csv(nume_fisier);
		if (fisier_csv.is_open()) {
			while (fisier_csv.good()) {
				fisier_csv.getline(this->nume_client, 256, despartitor);
				fisier_csv.getline(this->adresa, 256, despartitor);
				char joburi[100];
				fisier_csv.getline(joburi, 256, despartitor);
				this->joburi = atoi(joburi);
				char venit_disponibil[100];
				fisier_csv.getline(venit_disponibil, sizeof(venit_disponibil) + 1, despartitor);
			}
		}
		return *this;
	}


};

class Cheltuieli {
public:
	char* nume_cheltuiala;
	float* valoare_cheltuiala;
	int transa;
	char cod_cheltuiala[5];
	//constructor fara parametrii
	Cheltuieli()
	{
		this->nume_cheltuiala = new char[strlen("Necunoscuta") + 1];
		strcpy(this->nume_cheltuiala, "Necunoscuta");
		strcpy(this->cod_cheltuiala, "0000");
		this->transa = 0;
		this->valoare_cheltuiala = NULL;
	}

	//constructor cu un parametru
	Cheltuieli(char t_cod_cheltuiala[6], float* t_valoare_cheltuiala)
	{
		this->nume_cheltuiala = new char[strlen("Exemplu") + 1];
		strcpy(this->nume_cheltuiala, "Exemplu");
		strcpy(this->cod_cheltuiala, t_cod_cheltuiala);
		this->transa = 1;
		this->valoare_cheltuiala = new float[this->transa];
		this->valoare_cheltuiala[0] = t_valoare_cheltuiala[0];
	}

	//constructor cu toti parametrii
	Cheltuieli(char* t_nume_cheltuiala, char t_cod_cheltuiala[6], int t_transa, float* t_valoare_cheltuiala)
	{
		int i;
		this->nume_cheltuiala = new char[strlen(t_nume_cheltuiala) + 1];
		strcpy(this->nume_cheltuiala, t_nume_cheltuiala);
		strcpy(this->cod_cheltuiala, t_cod_cheltuiala);
		this->transa = t_transa;
		this->valoare_cheltuiala = new float[this->transa];
		for (i = 0; i < this->transa; i++)
			this->valoare_cheltuiala[i] = t_valoare_cheltuiala[i];
	}

	//constructor de copiere
	Cheltuieli(const Cheltuieli &c)
	{
		this->nume_cheltuiala = new char[strlen(c.nume_cheltuiala) + 1];
		strcpy(this->nume_cheltuiala, c.nume_cheltuiala);
		strcpy(this->cod_cheltuiala, c.cod_cheltuiala);
		this->transa = c.transa;
		int i;
		this->valoare_cheltuiala = new float[this->transa];
		for (i = 0; i < this->transa; i++)
			this->valoare_cheltuiala[i] = c.valoare_cheltuiala[i];
	}
	//destructor
	//~Cheltuieli()
	/*
	{

	cout << "Destructor3" << endl;
	if (this->nume_cheltuiala != NULL)
	{
	delete nume_cheltuiala;
	}
	if (this->valoare_cheltuiala != NULL)
	{
	delete valoare_cheltuiala;
	}
	}
	*/
	//supraincarcare operator =
	/*
	Cheltuieli& operator=(Cheltuieli &c)
	{
	int i;
	this->nume_cheltuiala = new char[strlen(c.nume_cheltuiala) + 1];
	strcpy(this->nume_cheltuiala, c.nume_cheltuiala);
	strcpy(this->cod_cheltuiala, c.cod_cheltuiala);
	this->transa = c.transa;
	this->valoare_cheltuiala = new float[this->transa];
	for (i = 0; i < c.transa; i++) {
	this->valoare_cheltuiala[i] = c.valoare_cheltuiala[i];
	}
	return *this;

	}*/

	void operator=(Cheltuieli &c) {
		delete[] this->nume_cheltuiala;
		delete[] this->valoare_cheltuiala;
		this->nume_cheltuiala = new char[strlen(c.nume_cheltuiala) + 1];
		strcpy(this->nume_cheltuiala, c.nume_cheltuiala);
		strcpy(this->cod_cheltuiala, c.cod_cheltuiala);
		this->transa = c.transa;
		this->valoare_cheltuiala = new float[c.transa];
		for (int i = 0; i < c.transa; i++) {
			this->valoare_cheltuiala[i] = c.valoare_cheltuiala[i];
		}
	}

#pragma region Getteri & Setteri
	char* getNume_cheltuiala()
	{
		return this->nume_cheltuiala;
	}

	char* getCod_cheltuiala()
	{
		return this->cod_cheltuiala;
	}

	int getTransa()
	{
		return this->transa;
	}

	float* getValoare_cheltuiala()
	{
		return this->valoare_cheltuiala;
	}

	void setNume_cheltuiala(char* t_nume_cheltuiala)
	{

		if (this->nume_cheltuiala != NULL) {
			delete[] this->nume_cheltuiala;
		}
		this->nume_cheltuiala = new char[strlen(t_nume_cheltuiala) + 1];
		strcpy(this->nume_cheltuiala, t_nume_cheltuiala);
	}

	void setCod_cheltuiala(char t_cod_cheltuiala[5])
	{
		strcpy(this->cod_cheltuiala, t_cod_cheltuiala);
	}

	void setTransa(int t_transa)
	{
		this->transa = t_transa;
	}

	void setValoare_cheltuiala(float* t_valoare_cheltuiala, int t_transa)
	{
		int i;
		this->transa = t_transa;
		if (this->valoare_cheltuiala != NULL) {
			delete[] this->valoare_cheltuiala;
		}
		else {
			this->valoare_cheltuiala = new float[this->transa];
			for (i = 0; i < this->transa; i++)
				this->valoare_cheltuiala[i] = t_valoare_cheltuiala[i];
		}
	}

#pragma endregion Getteri & Setteri
#pragma region operatori
	//operator <<,>>
	friend ostream& operator <<(ostream& out, Cheltuieli c)
	{
		int i;
		out << "Nume cheltuiala: " << c.nume_cheltuiala << endl;
		out << "Cod cheltuiala: " << c.cod_cheltuiala << endl;
		out << "Numar transe: " << c.transa << endl;
		for (i = 0; i < c.transa; i++)
			out << "\t" << c.valoare_cheltuiala[i] << endl;
		return out;

	}

	friend istream& operator>>(istream& in, Cheltuieli &c)
	{
		int i;
		cout << "Nume cheltuiala: " << endl;
		char buffer[50];
		in >> buffer[50];
		c.setNume_cheltuiala(buffer);
		in.ignore();
		cout << "Cod cheltuiala: " << endl;
		in >> c.cod_cheltuiala;
		cout << "Numar transe: " << endl;
		in >> c.transa;
		for (i = 0; i < c.transa; i++) {
			cout << "Valoarea cheltuielii " << i + 1 << "este de : ";
			in >> c.valoare_cheltuiala[i];
		}
		return in;
	}

	//citire din fisier
	friend ifstream& operator>>(ifstream& in, Cheltuieli &ch) {
		char buff1[50], buff2[5];
		in >> buff1;
		ch.setCod_cheltuiala(buff1);
		in >> buff2;
		strcpy(ch.cod_cheltuiala, buff2);
		in >> ch.transa;
		in.ignore();
		if (ch.valoare_cheltuiala != NULL) {
			delete[]ch.valoare_cheltuiala;
		}
		ch.valoare_cheltuiala = new float[ch.transa];
		for (int i = 0; i < ch.transa; i++)
			in >> ch.valoare_cheltuiala[i];
		return in;
	}



	//operator +
	Cheltuieli operator+(int t_transa)
	{
		this->transa = this->transa + t_transa;
		return *this;
	}

	//operator -
	Cheltuieli operator-(int t_transa)
	{
		this->transa = this->transa - t_transa;
		return *this;
	}

	//operator ++ preincrementare & postincrementare
	Cheltuieli operator++()
	{
		this->transa++;
		return *this;
	}

	friend Cheltuieli operator++(Cheltuieli &c, int)
	{
		Cheltuieli tmp = c;
		c.transa++;
		return tmp;
	}

	//operator --
	Cheltuieli operator--()
	{
		this->transa--;
		return *this;
	}

	friend Cheltuieli operator--(Cheltuieli &c, int)
	{
		Cheltuieli tmp = c;
		c.transa--;
		return tmp;
	}

	//operator ==
	bool operator==(Cheltuieli c)
	{
		if (this->transa == c.transa && strcmp(this->nume_cheltuiala, c.nume_cheltuiala) == 0 && strcmp(this->cod_cheltuiala, c.cod_cheltuiala) == 0)
			return true;
		else return false;
	}

	//operator >
	bool operator>(Cheltuieli &c)
	{
		if (this->transa > c.transa)
			return true;
		else return false;
	}

	//bool operator <
	bool operator<(Cheltuieli &c)
	{
		if (this->transa < c.transa)
			return true;
		else return false;
	}

	//operator index
	char operator[](int i)
	{
		if (i > 0 && i < (strlen(this->nume_cheltuiala)))
			return this->nume_cheltuiala[i];
		else return -1;
	}

#pragma endregion operatori

#pragma modalitate & afisare
	

	void afisare() {
		cout << "Nume cheltuiala: " << this->nume_cheltuiala << endl;
		cout << "Cod cheltuiala: " << this->cod_cheltuiala << endl;
		//cout << "Numar transe: " << this->transa << endl;
		for (int i = 0; i < this->transa; i++)
			cout << "Valoarea cheltuielii " << i + 1 << " este: " << this->valoare_cheltuiala[i] << endl;
	}



	Cheltuieli modificareCod_cheltuiala(char t_cod_cheltuiala[5])
	{
		strcpy(this->cod_cheltuiala, t_cod_cheltuiala);
		return *this;
	}

#pragma endregion modalitate & afisare

};

class FisierCheltuieli :public Cheltuieli {
public:
	void FisierBinar(char* nume_fisier) {
		ofstream cheltuieli_backup;
		cheltuieli_backup.open(nume_fisier, ios::out | ios::binary);
		if (cheltuieli_backup.is_open()) {
			char buff1[5], buff2[50];
			strcpy(buff2, this->nume_cheltuiala);
			strcpy(buff1, this->cod_cheltuiala);
			cheltuieli_backup.write(buff2, 50);
			cheltuieli_backup.write(buff1, 5);
			cheltuieli_backup.write((char*)& this->transa, sizeof(int));
			for (int i = 0; i < this->transa; i++) {
				cheltuieli_backup.write((char*)& this->valoare_cheltuiala[i], sizeof(float));
			}
		}
	}

	FisierCheltuieli citire_csv(char* nume_fisier, char despartitor) {
		ifstream fisier_csv(nume_fisier);
		if (fisier_csv.is_open()) {
			while (fisier_csv.good()) {
				fisier_csv.getline(this->nume_cheltuiala, 256, despartitor);
				fisier_csv.getline(this->cod_cheltuiala, 256, despartitor);
				char transa[100];
				fisier_csv.getline(transa, 256, despartitor);
				this->transa = atoi(transa);
				char valoare_cheltuiala[100];
				fisier_csv.getline(valoare_cheltuiala, 256, despartitor);
				//this->valoare_cheltuiala = atof(valoare_cheltuiala);
			}
		}
		return *this;
	}

};

class RaportCheltuieli {
public:
	Cheltuieli* cheltuieli;
	int nr_cheltuieli;
	RaportCheltuieli() {
		this->cheltuieli = NULL;
		this->nr_cheltuieli = 0;
	}

	RaportCheltuieli(Cheltuieli* t_cheltuieli, int t_nr_cheltuieli) {
		this->nr_cheltuieli = t_nr_cheltuieli;
		this->cheltuieli = new Cheltuieli[this->nr_cheltuieli];
		for (int i = 0; i < this->nr_cheltuieli; i++) {
			this->cheltuieli[i] = t_cheltuieli[i];
		}
	}

	friend ostream& operator<<(ostream& out, RaportCheltuieli& r) {
		out << "Numar cheltuieli: " << r.nr_cheltuieli << endl;
		out << "Cheltuielile sunt: " << endl;
		for (int i = 0; i < r.nr_cheltuieli; i++) {
			out << "Cheltuiala " << i + 1 << " este: " << r.cheltuieli[i] << endl;
		}
		out << endl;
		return out;
	}

	//afisare raport in text
	void Raport(RaportCheltuieli cheltuiala, char* nume_fisier) {
		ofstream raport;
		raport.open(nume_fisier, ios::out | ios::trunc);
		if (raport.is_open()) {
			raport << cheltuiala.nr_cheltuieli;
			raport << "\t Cheltuielile sunt: " << endl;
			for (int i = 0; i < cheltuiala.nr_cheltuieli; i++) {
				raport << cheltuiala.cheltuieli[i] << endl;
			}
			raport << endl;
			raport.close();
		}
	}

};

enum Tip {
	IT,
	Financiar,
	Fizic
};

class Vanzari {
private:
	bool pe_stoc;
	int nr_produse;
	float* pret;
	char* nume_produs;
	Tip tip;
public:
	//constructor implicit
	Vanzari()
	{
		this->nume_produs = new char[strlen("necunoscut") + 1];
		strcpy(this->nume_produs, "necunoscut");
		this->pe_stoc = false;
		this->nr_produse = 0;
		this->pret = NULL;
		this->tip = Fizic;
	}

	//constructor cu un parametru
	Vanzari(float* t_pret)
	{
		int i;
		this->nume_produs = new char[strlen("necunoscut") + 1];
		strcpy(this->nume_produs, "necunoscut");
		this->nr_produse = 1;
		this->pe_stoc = true;
		this->pret = new float[this->nr_produse];
		for (i = 0; i < this->nr_produse; i++)
			this->pret[i] = t_pret[i];
		this->tip = Fizic;
	}

	//constructor cu toti parametrii
	Vanzari(char* t_nume_produs, bool t_pe_stoc, int t_nr_produse, float* t_pret, Tip t_tip) {
		int i;
		this->nume_produs = new char[strlen(t_nume_produs) + 1];
		strcpy(this->nume_produs, t_nume_produs);
		this->pe_stoc = t_pe_stoc;
		this->nr_produse = t_nr_produse;
		this->pret = new float[this->nr_produse];
		for (i = 0; i < this->nr_produse; i++)
			this->pret[i] = t_pret[i];
		this->tip = t_tip;
	}

	//constructor de copiere
	Vanzari(Vanzari &source)
	{
		int i;
		this->nume_produs = new char[strlen(source.nume_produs) + 1];
		strcpy(this->nume_produs, source.nume_produs);
		this->pe_stoc = source.pe_stoc;
		this->nr_produse = source.nr_produse;
		this->pret = new float[source.nr_produse];
		for (i = 0; i < this->nr_produse; i++)
			this->pret[i] = source.pret[i];
		this->tip = source.tip;
	}

	//destructor
	/*
	~Vanzari()
	{
		if (this->nume_produs != NULL)
		{
			delete[] this->nume_produs;
		}
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
	}*/

#pragma region Getteri si setteri
	//getteri si setteri

	char* getNume_produs()
	{
		return this->nume_produs;
	}

	bool getPe_stoc()
	{
		return this->pe_stoc;
	}

	float* getPret()
	{
		return this->pret;
	}

	int getNr_produse()
	{
		return this->nr_produse;
	}

	Tip getTip()
	{
		return this->tip;
	}

	void setNr_produse(int t_nr_produse) {
		this->nr_produse = t_nr_produse;
	}

	void setNume_produs(char* t_nume_produs)
	{
		if (this->nume_produs != NULL) {
			delete[] this->nume_produs;
		}
		this->nume_produs = new char[strlen(t_nume_produs) + 1];
		strcpy(this->nume_produs, t_nume_produs);
	}

	void setPret(int t_nr_produse, float* t_pret)
	{
		int i;
		if (this->pret != NULL)
			delete[] this->pret;
		this->pret = new float[t_nr_produse];
		for (i = 0; i < t_nr_produse; i++)
			this->pret[i] = t_pret[i];
	}

	void setTip(Tip t_tip)
	{
		this->tip = t_tip;
	}

#pragma endregion Getteri si setteri

#pragma region Operatori
	//operator egal
	Vanzari& operator=(Vanzari &source)
	{
		if (this->nume_produs != NULL) {
			delete[] this->nume_produs;
		}
		if (this->pret != NULL) {
			delete[] this->pret;
		}
		this->nume_produs = new char[strlen(source.nume_produs) + 1];
		strcpy(this->nume_produs, source.nume_produs);
		this->nr_produse = source.nr_produse;
		this->pe_stoc = source.pe_stoc;
		this->pret = new float[source.nr_produse];
		for (int i = 0; i < source.nr_produse; i++)
			this->pret[i] = source.pret[i];
		this->tip = source.tip;
		return *this;
	}

	//operatori <<,>>
	friend ostream& operator<<(ostream& out, Vanzari v) {
		int i;
		out << "Nume produs: " << v.nume_produs << endl;
		out << "Este pe stoc? " << v.pe_stoc << endl;
		out << "Numar produse: " << v.nr_produse << endl;
		for (i = 0; i < v.nr_produse; i++)
			out << "Pretul produsului " << i + 1 << "este: " << v.pret[i] << endl;
		out << "Tipul produsului este: " << v.tip << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Vanzari &v) {
		char buffer[50];
		cout << "Nume produs: " << endl;
		in >> buffer;
		v.nume_produs = new char[51];
		in.ignore();
		strcpy(v.nume_produs, buffer);
		cout << "Dati stare stoc: " << endl;
		in >> v.pe_stoc;
		in.ignore();
		cout << "Dati nr produse: " << endl;
		in >> v.nr_produse;
		v.pret = new float[v.nr_produse];
		for (int i = 0; i < v.nr_produse; i++) {
			cout << "Dati pretul pentru produsul " << i + 1 << " : " << endl;
			in >> v.pret[i];
		}
		return in;
	}

	//operatorul +,-
	Vanzari operator+(int t_nr_produse)
	{
		this->nr_produse = this->nr_produse + t_nr_produse;
		return *this;
	}

	Vanzari operator-(int t_nr_produse)
	{
		this->nr_produse = this->nr_produse - t_nr_produse;
		return *this;
	}

	//operator index
	char operator[](int ind)
	{
		if (ind < 0 || ind >= this->nr_produse)
		{
			cout << "Nu este valid! " << endl;

		}
		else {
			return this->nume_produs[ind];
		}
	}

	//operator >,<
	bool operator>(Vanzari &v)
	{
		if (this->nr_produse > v.nr_produse)
			return true;
		else return false;
	}

	bool operator<(Vanzari &v)
	{
		if (this->nr_produse < v.nr_produse)
			return true;
		else return false;
	}

	//operator ==
	bool operator==(Vanzari &v)
	{
		if (this->nr_produse == v.nr_produse || strcmp(this->nume_produs, v.nume_produs) == 0 || this->pe_stoc == v.pe_stoc)
			return true;
		else return false;
	}

	//operator de preincrementare,postincrementare
	Vanzari operator++()
	{
		this->nr_produse++;
		return *this;
	}

	friend Vanzari operator++(Vanzari &v, int)
	{
		Vanzari tmp = v;
		v.nr_produse++;
		return tmp;
	}

	//operator de predecrementare, postdecrementare
	Vanzari operator--()
	{
		this->nr_produse--;
		return *this;
	}

	friend Vanzari operator--(Vanzari &v, int)
	{
		Vanzari tmp = v;
		v.nr_produse--;
		return tmp;
	}

#pragma endregion Operatori

	//functia de afisare si de prelucrare
	void afisare()
	{
		int i;
		cout << "Nume produs: " << this->nume_produs << endl;
		cout << "Este pe stoc?: " << this->pe_stoc << endl;
		cout << "Numar produse: " << this->nr_produse << endl;
		for (i = 0; i < this->nr_produse; i++)
			cout << "Pretul produsului " << i + 1 << "este: " << this->pret[i] << endl;
		cout << "Tip: " << this->tip << endl;
	}

	int comandareStocNou(int stoc_nou)
	{
		return this->nr_produse = this->nr_produse*stoc_nou;
	}

};

class Economii {
public:
	float* cont_bancar;
	int surse_finantare;
	char* nume_sursa;
	bool cont_activ;
#pragma region Constructori
	//constructor implicit
	Economii() {
		this->nume_sursa = new char[strlen("Anonima") + 1];
		strcpy(nume_sursa, "Anonima");
		this->surse_finantare = 0;
		this->cont_activ = false;
		this->cont_bancar = NULL;
	}

	//constructor cu un parametru
	Economii(char* t_nume_sursa, bool t_cont_activ) {
		this->nume_sursa = new char[strlen(t_nume_sursa) + 1];
		strcpy(this->nume_sursa, t_nume_sursa);
		this->cont_activ = t_cont_activ;
		this->surse_finantare = 1;
		this->cont_bancar = new float[this->surse_finantare];
		this->cont_bancar[0] = 1.0;
	}

	//constructor cu toti parametrii
	Economii(char* t_nume_sursa, bool t_cont_activ, int t_surse_finantare, float* t_cont_bancar)
	{
		this->nume_sursa = new char[strlen(t_nume_sursa) + 1];
		strcpy(this->nume_sursa, t_nume_sursa);
		this->cont_activ = t_cont_activ;
		this->surse_finantare = t_surse_finantare;
		this->cont_bancar = new float[this->surse_finantare];
		for (int i = 0; i < this->surse_finantare; i++)
			this->cont_bancar[i] = t_cont_bancar[i];
	}

	//constructorul de copiere
	Economii(Economii &s)
	{
		this->cont_activ = s.cont_activ;
		this->nume_sursa = new char[strlen(s.nume_sursa) + 1];
		strcpy(this->nume_sursa, s.nume_sursa);
		this->surse_finantare = s.surse_finantare;
		this->cont_bancar = new float[s.surse_finantare];
		for (int i = 0; i < this->surse_finantare; i++)
			this->cont_bancar[i] = s.cont_bancar[i];
	}

	//destructor
	/*
	~Economii()
	{
	cout << "In ultimul destructor" << endl;
	if (this->nume_sursa != NULL) {

	delete[] this->nume_sursa;
	}
	if (this->cont_bancar != NULL) {
	cout << ".........." << endl;
	for (int i = 0; i < this->surse_finantare; i++)
	cout << this->cont_bancar[i] << endl;
	delete[] this->cont_bancar;

	}

	}*/


#pragma endregion Constructori
#pragma region Getteri si setteri
	char* getNume_sursa()
	{
		return this->nume_sursa;
	}
	float* getCont_bancar()
	{
		return this->cont_bancar;
	}
	int getSurse_finantare()
	{
		return this->surse_finantare;
	}

	bool getCont_activ() {
		return this->cont_activ;
	}

	void setNume_sursa(char* t_nume_sursa) {
		if (this->nume_sursa != NULL) {
			delete[] this->nume_sursa;
		}
		this->nume_sursa = new char[strlen(t_nume_sursa) + 1];
		strcpy(this->nume_sursa, t_nume_sursa);
	}

	void setCont_bancar(int t_surse_finantare, float* t_cont_bancar)
	{
		if (this->cont_bancar != NULL) {
			delete[] this->cont_bancar;
		}
		this->cont_bancar = new float[t_surse_finantare];
		for (int i = 0; i < this->surse_finantare; i++)
			this->cont_bancar[i] = t_cont_bancar[i];
	}

	void setCont_activ(bool t_cont_activ)
	{
		this->cont_activ = t_cont_activ;
	}

	void setSurse_finantarer(int t_surse_finantare)
	{
		this->surse_finantare = t_surse_finantare;
	}

#pragma endregion Getteri si setteri

#pragma region Operatori

	void operator=(Economii &e) {
		delete[] this->nume_sursa;
		delete[] this->cont_bancar;
		this->nume_sursa = new char[strlen(e.nume_sursa) + 1];
		strcpy(this->nume_sursa, e.nume_sursa);
		this->cont_activ = e.cont_activ;
		this->surse_finantare = e.surse_finantare;
		this->cont_bancar = new float[e.surse_finantare];
		for (int i = 0; i < e.surse_finantare; i++) {
			this->cont_bancar[i] = e.cont_bancar[i];
		}
	}

	//operator +,-
	Economii operator+(int t_surse_finantare)
	{
		this->surse_finantare = this->surse_finantare + t_surse_finantare;
		return *this;
	}

	Economii operator-(int t_surse_finantare)
	{
		this->surse_finantare = this->surse_finantare - t_surse_finantare;
		return *this;
	}

	//operator ++ postincrementare,preincrementare
	Economii operator++()
	{
		this->surse_finantare++;
		return *this;
	}

	friend Economii operator++(Economii &e, int)
	{
		Economii tmp = e;
		e.surse_finantare++;
		return tmp;
	}

	//operator -- postdecrementare, predecrementare
	Economii operator--()
	{
		this->surse_finantare--;
		return *this;
	}

	friend Economii operator--(Economii &e, int)
	{
		Economii tmp = e;
		e.surse_finantare--;
		return tmp;
	}

	//operator <<,>>
	friend ostream& operator<<(ostream& out, Economii e)
	{
		out << "Nume: " << e.nume_sursa << endl;
		out << "Contul este activ? " << e.cont_activ << endl;
		out << "Numar surse finantare: " << e.surse_finantare << endl;
		for (int i = 0; i < e.surse_finantare; i++)
			out << "Valoarea din contul bancar " << i + 1 << " este: " << e.cont_bancar[i] << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Economii &e)
	{
		char buff[50];
		delete[] e.nume_sursa;
		cout << "Dati nume: " << endl;
		in >> buff;
		e.nume_sursa = new char[strlen(buff) + 1];
		strcpy(e.nume_sursa, buff);
		in.ignore();
		cout << "Este cont activ? " << endl;
		in >> e.cont_activ;
		cout << "Cate surse de finantare? " << endl;
		in >> e.surse_finantare;
		delete[] e.cont_bancar;
		e.cont_bancar = new float[e.surse_finantare];
		for (int i = 0; i < e.surse_finantare; i++) {
			cout << "Valoarea in ccb " << i + 1 << " este: " << endl;
			in >> e.cont_bancar[i];
		}
		return in;
	}

	//operator >,<
	bool operator>(Economii e)
	{
		if (this->surse_finantare > e.surse_finantare)
			return true;
		else return false;
	}

	bool operator<(Economii e)
	{
		if (this->surse_finantare < e.surse_finantare)
			return true;
		else return false;
	}

	//operator index
	char operator[](int i)
	{
		if (i >= 0 && i < (strlen(this->nume_sursa)))
			return this->nume_sursa[i];
		else return -1;
	}

	//operatorul cast

	operator float()
	{
		return(float)this->surse_finantare;
	}


	//afisare si metoda prelucrare
	void afisare()
	{
		cout << "Nume sursa: " << this->nume_sursa << endl;
		cout << "Cont activ? " << this->cont_activ << endl;
		cout << "Numar surse finantare: " << this->surse_finantare << endl;
		for (int i = 0; i < this->surse_finantare; i++)
			cout << "Valoarea din ccb pentru sursa " << i + 1 << " este: " << this->cont_bancar[i] << endl;
	}

	void valEuroCCB(int t_surse_finantare, float* t_cont_bancar)
	{
		for (int i = 0; i < t_surse_finantare; i++)
			cout << t_cont_bancar[i] / 4.6 << endl;
	}

	//citire din fisier text
	friend ifstream& operator>>(ifstream& in, Economii& e) {
		char buff1[50];
		in >> buff1;
		e.setNume_sursa(buff1);
		in >> e.cont_activ;
		in.ignore();
		if (e.cont_activ != NULL) {
			in >> e.surse_finantare;
			if (e.cont_bancar != NULL) {
				delete[] e.cont_bancar;
			}
			e.cont_bancar = new float[e.surse_finantare];
			for (int i = 0; i < e.surse_finantare; i++) {
				in >> e.cont_bancar[i];
			}
		}
		return in;
	}

};
//extindere clasa Cheltuieli
class productie : public Cheltuieli {
private:
	char nume_fabrica[50];
	int nr_angajati;
public:
	productie() :Cheltuieli() {
		strcpy(this->nume_fabrica, "Fabrica Necunoscuta");
		this->nr_angajati = 0;
	}
	productie(char t_nume_fabrica[50], int t_nr_angajati, char* t_nume_cheltuiala, char t_cod_cheltuiala[6], int t_transa, float* t_valoare_cheltuiala) :Cheltuieli(t_nume_cheltuiala, t_cod_cheltuiala, t_transa, t_valoare_cheltuiala) {
		strcpy(this->nume_fabrica, t_nume_fabrica);
		this->nr_angajati = t_nr_angajati;
	}
	productie(const productie& p) {
		strcpy(this->nume_cheltuiala, p.nume_cheltuiala);
		this->nr_angajati = p.nr_angajati;
	}

	friend ostream& operator<<(ostream& out, productie p) {
		int i;
		out << "Nume cheltuiala: " << p.nume_cheltuiala << endl;
		out << "Cod cheltuiala: " << p.cod_cheltuiala << endl;
		out << "Numar transe: " << p.transa << endl;
		for (i = 0; i < p.transa; i++)
			out << "\t" << p.valoare_cheltuiala[i] << endl;
		out << "Nume fabrica: " << p.nume_fabrica << endl;
		out << "Numar angajati: " << p.nr_angajati << endl;
		return out;
	}

};



class RaportEconomii {
public:
	Economii* economii;
	int nr_economii;
	RaportEconomii() {
		this->nr_economii = 0;
		this->economii = NULL;
	}
	RaportEconomii(Economii* t_economii, int t_nr_economii) {
		this->nr_economii = t_nr_economii;
		this->economii = new Economii[this->nr_economii];
		for (int i = 0; i < this->nr_economii; i++) {
			this->economii[i] = t_economii[i];
		}
	}

	friend ostream& operator<<(ostream& out, RaportEconomii& e) {
		out << "Numar economii: " << e.nr_economii << endl;
		out << "Economiile sunt: " << endl;
		for (int i = 0; i < e.nr_economii; i++) {
			out << "Economia " << i + 1 << " este: " << e.economii[i] << endl;
		}
		out << endl;
		return out;
	}

	//afisare raport in text
	void Raport(RaportEconomii economie, char* nume_fisier) {
		ofstream raport;
		raport.open(nume_fisier, ios::out | ios::trunc);
		if (raport.is_open()) {
			raport << economie.nr_economii << endl;
			raport << "\t Economiile sunt: " << endl;
			for (int i = 0; i < economie.nr_economii; i++) {
				raport << economie.economii[i] << endl;
			}
			raport << endl;
			raport.close();
		}
	}

};

class FisierEconomii : public Economii {
public:
	void FisierBinar(char* nume_fisier) {
		ofstream economii_backup;
		economii_backup.open(nume_fisier, ios::out | ios::binary);
		if (economii_backup.is_open()) {
			char buff1[50];
			strcpy(buff1, this->nume_sursa);
			economii_backup.write(buff1, 50);
			if (this->cont_activ != NULL) {
				economii_backup.write((char*)& this->cont_activ, sizeof(bool));
				economii_backup.write((char*)& this->surse_finantare, sizeof(int));
				for (int i = 0; i < this->surse_finantare; i++) {
					economii_backup.write((char*)& this->cont_bancar[i], sizeof(float));
				}
			}
		}
	}

	FisierEconomii citire_csv(char* nume_fisier, char despartitor) {
		ifstream fisier_csv(nume_fisier);
		if (fisier_csv.is_open()) {
			while (fisier_csv.good()) {
				fisier_csv.getline(this->nume_sursa, 256, despartitor);
				char cont_activ[2];
				fisier_csv.getline(cont_activ, 256, despartitor);
				this->cont_activ = atoi(cont_activ);
				char surse_finantare[10];
				fisier_csv.getline(surse_finantare, 256, despartitor);
				this->surse_finantare = atoi(surse_finantare);
				char cont_bancar[100];
				fisier_csv.getline(cont_bancar,256,despartitor);
			}
		}
		return *this;
	}
};

//faza3

class Contabilitate {
protected:
	int nr_transferuri;
	float cont_curent;
	float titluri;
	float val_marfuri;
	float val_produse_finite;
public:
	Contabilitate() {
		this->nr_transferuri = 0;
		this->cont_curent = 0;
		this->titluri = 0;
		this->val_marfuri = 0;
		this->val_produse_finite = 0;
	}

	Contabilitate(int t_nr_transferuri, float t_cont_curent) {
		this->nr_transferuri = t_nr_transferuri;
		this->cont_curent = t_cont_curent;
		this->titluri = 0;
		this->val_marfuri = 0;
		this->val_produse_finite = 0;
	}

	void operator=(Contabilitate& c) {
		this->nr_transferuri = c.nr_transferuri;
		this->cont_curent = c.cont_curent;
		this->titluri = c.titluri;
		this->val_marfuri = c.val_marfuri;
		this->val_produse_finite = c.val_produse_finite;
	}

	virtual void vTitluri() = 0;
	virtual void vMarfuri() = 0;
	virtual void vProdFinite() = 0;
	virtual void afisare() {
		cout << "Nr transferuri: " << this->nr_transferuri << endl;
	}
};

class trimestru :public Contabilitate {
private:
	float val_achizitie;
public:
	trimestru() :Contabilitate() {
		this->val_achizitie = 0;
	}

	trimestru(int t_nr_transferuri, float t_cont_curent, float t_val_achizitie) :Contabilitate(t_nr_transferuri, t_cont_curent)
	{
		this->val_achizitie = t_val_achizitie;
	}

	void vTitluri()
	{
		this->titluri = this->cont_curent - (0.45*this->cont_curent) + this->val_achizitie;
	}

	void vMarfuri() {
		this->val_marfuri = this->cont_curent - (0.23* this->cont_curent) + this->val_achizitie;
	}

	void vProdFinite() {
		this->val_produse_finite = this->cont_curent - (0.32* this->cont_curent);
	}

	void afisare() {
		cout << "Numar transferuri" << this->nr_transferuri << endl;
		cout << "Cont curent la banca: " << this->cont_curent << endl;
		cout << "Titluri: " << this->titluri << endl;
		cout << "Valoare marfuri: " << this->val_marfuri << endl;
		cout << "Valoare produse finite: " << this->val_produse_finite << endl;
	}

	friend istream& operator>>(istream& in, trimestru& t) {
		cout << "Valoare achizitie: " << endl;
		in >> t.val_achizitie;
		return in;
	}

};

class anFinanciar :public Contabilitate {
private:
	float impozit_anual;
	float TVA_deductibil;
public:
	anFinanciar() :Contabilitate() {
		this->impozit_anual = 0;
		this->TVA_deductibil = 0;
	}

	anFinanciar(int t_nr_transferuri, float t_cont_curent, float t_impozit_anual, float t_TVA_deductibil) :Contabilitate(t_nr_transferuri, t_cont_curent)
	{
		this->impozit_anual = t_impozit_anual;
		this->TVA_deductibil = t_TVA_deductibil;
	}

	void vTitluri() {
		this->titluri = this->cont_curent - (0.45*this->cont_curent) - this->impozit_anual + this->TVA_deductibil;
	}

	void vMarfuri() {
		this->val_marfuri = this->cont_curent - (0.23* this->cont_curent) - this->impozit_anual + this->TVA_deductibil;
	}

	void vProdFinite() {
		this->val_produse_finite = this->cont_curent - (0.32* this->cont_curent) - this->impozit_anual + this->TVA_deductibil;
	}

	void afisare() {
		cout << "Numar transferuri" << this->nr_transferuri << endl;
		cout << "Cont curent la banca: " << this->cont_curent << endl;
		cout << "Titluri: " << this->titluri << endl;
		cout << "Valoare marfuri: " << this->val_marfuri << endl;
		cout << "Valoare produse finite: " << this->val_produse_finite << endl;
	}

	friend istream& operator>>(istream& in, anFinanciar& t) {
		cout << "Valoare impozit anual: " << endl;
		in >> t.impozit_anual;
		cout << "Valoare TVA deductibil: " << endl;
		in >> t.TVA_deductibil;
		return in;
	}
};


void main(int arg1,char* arg2[]) {

	//testare prima clasa
	factura::setNrFactura(2300);
	//testare constructor fara parametrii
	factura f1;
	f1.afisareF();

	//testare constructor cu toti parametrii
	float v1[3] = { 1000.00,1300.00,50.00 };
	factura f2("Ion", "Enel", false, 3, v1);
	f2.afisareF();

	//testare constructor cu 3 parametrii
	float v[2] = { 200, 340 };
	factura f4("Ion", "costel", true, 2, v);
	cout << f4;

	//testare constructor de copiere
	factura f5 = f4;//sursa este f4
	cout << f4;

	//testare operatori >>,<<
	factura f3;
	cin >> f3;
	cout << f3;
	cout << "Numarul total de facturi este: " << factura::getNrFactura() << endl;

	//-----------------------------------------------------------
	//testare a doua clasa client
	//apel constructor implicit

	client c1;
	c1.afisare();

	//apel constructor explicit cu toti parametrii
	float cv[2] = { 780,678 };
	client c2("testare", "str. Coposu", cv, 2);
	c2.afisare();
	//apel constructor explicit cu un parametrii
	float cv2[1] = { 234 };
	client c3("Address", cv2);
	c3.afisare();

	//apel constructor de copiere
	client c4 = c2;
	c4.afisare();

	//apel operator egal
	c4 = c3;
	c4.afisare();

	//apelare <<,>>
	client c5;
	cin >> c5;
	cout << c5 << endl;

	//apel operator index
	cout << c5[2] << endl;

	//apel operator !
	if (!c4)
		cout << "Clientul este angajat! " << endl;
	else cout << "Clientul nu are venituri!" << endl;

	//apel getteri si setteri
	cout << c4.getAdresa() << endl;
	cout << c4.getNume_Client() << endl;
	cout << c4.getJoburi() << endl;
	cout << c4.getVenit_Disponibil() << endl;

	c4.setNume_Client("Test12");
	c4.setAdresa("str.Olimpului");
	float c11[1] = { 1003 };
	c4.setVenit_Disponibil(1, c11);

	//apel operator >
	if (c4 > c3)
		cout << "Clientul 4 are mai multe venituri decat clientul 3!" << endl;
	else cout << "Clientul 3 are mai multe venituri decat clientul 4!" << endl;

	//apel operator preincrementare
	cout << ++c4;

	//apel operator postincrementare

	c4++;
	cout << c4;

	//apel operator +
	int j1;
	cout << "Introduceti numarul de surse de venit: " << endl;
	cin >> j1;
	cout << c4.getJoburi() + j1;
	//------------------------------------------------------------------------------
	//Testare clasa Cheltuieli
	//testare constructor implicit
	Cheltuieli ch1;
	ch1.afisare();

	//testare constructor cu un parametru
	float val0[1] = { 1003 };
	Cheltuieli ch2("abcd43", val0);
	ch2.afisare();

	//testare constructor cu toti parametrii
	float val1[2] = { 2500,8000 };
	Cheltuieli ch3("Constructie", "134ab", 2, val1);
	ch3.afisare();

	//apel constructor de copiere
	Cheltuieli ch4 = ch3;
	ch4.afisare();

	//apel operator egal
	ch4 = ch2;
	ch4.afisare();

	//apel operatori <<,>>
	client ch5;
	cin >> ch5;
	cout << ch5 << endl;

	//apel operator index
	if (ch5[1])
		cout << "Exista o singura cheltuiala!" << endl;
	else
		if (ch5[2])
			cout << "Exista doua cheltuieli!" << endl;
		else cout << "Exista mai mult de doua cheltuieli!" << endl;

		//apel operator >,<
		if (ch4 > ch3)
			cout << "Cheltuiala 4 se va plati in mai multe transe!" << endl;
		else cout << "Cheltuiala 3 se va plati in mai multe transe!" << endl;

		if (ch4<ch3)
			cout << " Cheltuiala 3 se va plati in mai multe transe!" << endl;
		else cout << " Cheltuiala 4 se va plati in mai multe transe!" << endl;

		//apel operator ==
		if (ch4 == ch3)
			cout << "Este aceeasi cheltuiala!" << endl;
		else cout << "Sunt cheltuieli diferite!" << endl;

		//apel operator preincrementare, postincrementare
		cout << ++ch3;
		ch3++;
		cout << ch3;

		//apel operator predrecrementare, postdecrementare
		cout << --ch3;
		ch3--;
		cout << ch3;

		//apel operator +
		int tr1;
		cout << "Introduceti numarul de transe de adaugat: " << endl;
		cin >> tr1;
		cout << ch4 + tr1;

		//apel operator -
		int tr2;
		cout << "Introduceti numarul de transe de scazut: " << endl;
		cin >> tr2;
		cout << ch4 - tr2;

		//----------------------------------------------------
		//testare clasa 4 - Vanzari
		//apel constructor implicit
		Vanzari vn1;
		vn1.afisare();

		//apel constructor cu un parametru
		float pr1[1] = { 230.34 };
		Vanzari vn2(pr1);
		vn2.afisare();

		//apel constructor cu toti parametrii
		float pr2[3] = { 430.23,320.3,100.00 };
		Vanzari vn3("ProdusX", true, 3, pr2, IT);
		cout << vn3;

		//apel constructor de copiere
		Vanzari vn4 = vn3;
		cout << vn4;

		//apel operator egal
		vn4 = vn1;
		cout << vn4;

		//apel getteri
		cout << vn3.getNume_produs() << endl;
		cout << vn3.getPe_stoc() << endl;
		cout << vn3.getNr_produse() << endl;
		cout << vn3.getPret() << endl;
		cout << vn3.getTip() << endl;

		//apel setteri
		vn3.setNume_produs("ProdusY");
		vn3.setNr_produse(1);
		float pr3[1] = { 100.23 };
		vn3.setPret(1,pr3);
		vn3.setTip(Financiar);
		vn3.afisare();

		//apel <<,>>
		Vanzari vn5;
		cin >> vn5;
		cout << vn5;

		//apelare >,<
		if (vn3 > vn4)
		cout << "Exista mai multe stocuri din produsul 3" << endl;
		else cout << "Exista mai multe stocuri din produsul 4" << endl;
		if (vn3 < vn4)
		cout << "Exista mai multe stocuri din produsul 4" << endl;
		else cout << "Exista mai multe stocuri din produsul 3" << endl;

		//apelare =
		vn3 = vn4;
		vn3.afisare();

		//apelare index
		if (vn3[1])
		cout << "Exista mai multe produse pe stoc!" << endl;
		else cout << "Nu exista produse pe stoc!" << endl;

		//apelare operator preincrementare,postincrementare
		++vn3;
		cout << vn3;
		vn3++;
		cout << vn3;

		//apelare operator predecrementare,postdecrementare
		cout << --vn3;
		vn3--;
		cout << vn3;

		//---------------------------------------------------
		//testare clasa 5 - Economii
		//apel constructor implicit
		Economii ec1;
		ec1.afisare();

		//apel constructor cu un parametru
		float er1[1] = { 230.34 };
		Economii ec2("Dividende",true);
		ec2.afisare();

		//apel constructor cu toti parametrii
		float er2[3] = { 430.23,320.3,100.00 };
		Economii ec3("Obligatiuni",true,3,er2);
		cout << ec3;

		//apel constructor de copiere
		Economii ec4 = ec3;
		cout << ec3;

		//apel operator egal
		ec4 = ec2;
		cout << ec4;

		//apel getteri
		cout << ec3.getNume_sursa() << endl;
		cout << ec3.getCont_activ() << endl;
		cout << ec3.getSurse_finantare() << endl;
		cout << ec3.getCont_bancar() << endl;

		//apel setteri
		ec3.setNume_sursa("Chirie");
		ec3.setCont_activ(true);
		float er3[1] = { 100.23 };
		ec3.setSurse_finantarer(1);
		ec3.setCont_bancar(1,er3);

		//apel <<,>>
		Economii ec5;
		cin >> ec5;
		cout << ec5;

		//apelare >,<
		if (ec3 > ec4)
		cout << "Exista mai multe surse de finantare pentru economiile 3" << endl;
		else cout << "Exista mai multe surse de finantare pentru economiile 4" << endl;
		if (ec3 < ec4)
		cout << "Exista mai multe surse de finantare pentru economiile 4" << endl;
		else cout << "Exista mai multe surse de finantare pentru economiile 3" << endl;

		//apelare =
		ec3 = ec4;
		ec3.afisare();

		//apelare index
		if (ec3[1])
		cout << "Exista mai multe surse de finantare!" << endl;
		else cout << "Nu exista surse de finantare!" << endl;

		//apelare operator preincrementare,postincrementare
		++ec3;
		cout << ec3;
		ec3++;
		cout << ec3;

		//apelare operator predecrementare,postdecrementare
		--ec3;
		cout << ec3;
		ec3--;
		cout << ec3;

		//operatorul cast
		cout << (float)ec3 << endl;

		//metoda prelucrare
		float er5[2] = { 100.3,599.3 };
		ec3.valEuroCCB(2, er5);

		//Main faza 2
		//citire text Factura
		cout <<endl<<"-----------------------------------------------------Fisiere----------------------------------------" << endl;
		ifstream fact("Factura.txt", ios::in);
		factura f100;
		fact >> f100;
		cout << f100;
		//scriere in binar Factura
		FisierFactura bin1;
		bin1.FisierBinar("factura.dat");

		//citire din csv Factura
		FisierFactura csvF;
		cout << csvF.citire_csv("factura.csv", ',');

		//citire text Client
		ifstream clt("Client.txt", ios::in);
		client c100;
		clt >> c100;
		cout << c100;

		//scriere in binar Client
		FisierClient bin2;
		bin2.ClientBinar("client.dat");
		//citire din csv Client
		FisierClient csvC;
		cout << csvC.citire_csv("client.csv", ',');


		//citire din text Cheltuieli
		ifstream cht("Cheltuieli.txt", ios::in);
		Cheltuieli ch100;
		cht >> ch100;
		cout << ch100;

		//scriere in binar Cheltuieli
		FisierCheltuieli bin3;
		bin3.FisierBinar("cheltuieli.dat");

		//citire din csv Cheltuieli
		FisierCheltuieli csvCH;
		cout << csvCH.citire_csv("cheltuieli.csv", ',');


		//citire din text Economii
		ifstream eco("Economii.txt", ios::in);
		Economii ec100;
		eco >> ec100;
		cout << ec100;

		//scriere in binar Economii
		FisierEconomii bin4;
		bin4.FisierBinar("economii.dat");

		//citire din csv Economii
		FisierEconomii csvECO;
		cout << csvECO.citire_csv("economii.csv", ',');


		//raport pentru Cheltuieli

		float tx[2] = { 100,200 };
		Cheltuieli ch200("Taxe", "10000", 2, tx);
		float tx2[1] = { 1323 };
		Cheltuieli ch300("135463", tx2);
		float tx3[3] = { 234,786,654 };
		Cheltuieli ch400("Impozite pe venit", "765", 3, tx3);
		Cheltuieli raportC[3];
		raportC[0] = ch200;
		raportC[1] = ch300;
		raportC[2] = ch400;

		RaportCheltuieli raport1(raportC, 3);
		raport1.Raport(raport1, "raportCheltuieli.txt");

		//Raport pentru Economii
		float ind1[2] = { 346,400 };
		Economii ec200("Indemnizatie Copil", 1, 2, ind1);
		Economii ec300("Dobanda cont", 1);
		float ind2[1] = { 1300 };
		Economii ec400("Chiriasi", 1, 1, ind2);
		Economii raportE[3];
		raportE[0] = ec200;
		raportE[1] = ec300;
		raportE[2] = ec400;

		RaportEconomii raport2(raportE, 3);
		raport2.Raport(raport2, "raportEconomii.txt");

		//Raport pentru facturi
		float sm1[2] = { 1000,2000 };
		factura f200("SC.Painea", "SC.Graul", 1, 2, sm1);
		float sm2[3] = { 2343,322,100 };
		factura f300("SC.Impex", "Daniel&Asociatii", 1, 3, sm2);
		float sm3[1] = { 10000 };
		factura f400("Consultanta SA", "PrimariaBucuresti", 1, 1, sm3);
		factura raportF[3];
		raportF[0] = f200;
		raportF[1] = f300;
		raportF[2] = f400;

		RaportFacturi raport3(raportF, 3);
		raport3.Raport(raport3, "raportFacturi.txt");

		cout << endl << "-------------------------------------Rapoarte------------------------------" << endl;
	//FAZA 3
	//STL
	cout << endl << "---------------------------STL--------------------";
	cout << endl << "------------------------------VECTOR--------------------";
	cout << endl << "-----------------productie-------------" << endl;
	float chtl1[3] = { 1704,1230,1954 };
	vector<productie> vectorProductie;
	productie prod1("Impexim", 3, "Salarii", "1043", 3, chtl1);
	float chtl2[2] = { 2345,2880 };
	productie prod2("Farmorex", 2, "Achiztie Produse", "78765", 2, chtl2);
	float chtl3[4] = { 2430,2500,1200,1800 };
	productie prod3("Flamingo", 4, "Salarii", "1043", 4, chtl3);
	vectorProductie.push_back(prod1);
	vectorProductie.push_back(prod2);
	vectorProductie.push_back(prod3);
	vector<productie>::iterator it1;
	for (it1 = vectorProductie.begin(); it1 != vectorProductie.end(); it1++) {
		(*it1).afisare();
	}

	cout << endl << "----------------Trimestru----------------" << endl;
	vector<trimestru>vectorTrimestru;
	trimestru trim1(4, 2400, 234);
	trimestru trim2(2, 5700, 804);
	trimestru trim3(1, 24312, 244);
	vectorTrimestru.push_back(trim1);
	vectorTrimestru.push_back(trim2);
	vectorTrimestru.push_back(trim3);
	vector<trimestru>::iterator it2;
	for (it2 = vectorTrimestru.begin(); it2 != vectorTrimestru.end(); it2++) {
		(*it2).afisare();
	}

	cout << endl << "-----------------------AN Financiar==========================" << endl;
	vector<anFinanciar>vectorAn;
	anFinanciar afin1(4, 2400, 231, 400);
	anFinanciar afin2(2, 5700, 432, 234);
	anFinanciar afin3(1, 24312, 784, 903);
	afin1.vMarfuri();
	afin1.vProdFinite();
	afin1.vTitluri();
	afin2.vMarfuri();
	afin2.vProdFinite();
	afin2.vTitluri();
	afin3.vMarfuri();
	afin3.vProdFinite();
	afin3.vTitluri();
	vectorAn.push_back(afin1);
	vectorAn.push_back(afin2);
	vectorAn.push_back(afin3);
	vector<anFinanciar>::iterator it3;
	for (it3 = vectorAn.begin(); it3 != vectorAn.end(); it3++) {
		(*it3).afisare();
	}

	cout << endl << "------------------------------LIST-----------------------------------" << endl;
	cout << endl << "----------------------------------Cheltuieli-----------------------------" << endl;
	float vchl1[2] = { 1000,2003 };
	Cheltuieli cht4("Achizitie produs", "10453", 2, vchl1);
	float vchl2[2] = { 39431,1231 };
	Cheltuieli cht5("Salarii", "1045", 2, vchl2);
	float vchl3[2] = {10391,2031};
	Cheltuieli cht6("Achizitie utilaj", "10452", 2, vchl3);
	list<Cheltuieli>listChelt;
	listChelt.push_back(cht4);
	listChelt.push_back(cht5);
	listChelt.push_back(cht6);
	list<Cheltuieli>::iterator it4;
	cout << endl << "-----------------------------------Client-------------------------" << endl;
	float vnt1[2] = { 4000,243 };
	client clt1("Vlad", "Dimitrie Cantemir",vnt1,2);
	float vnt2[2] = { 2000,421 };
	client clt2("Popa", "Ograzii", vnt2, 2);
	float vnt3[2] = { 4021,4311 };
	client clt3("Ionescu", "Popesti", vnt3, 2);
	float vnt4[3] = { 9121,12345,9182 };
	client clt4("George", "Stefanesti", vnt4, 3);
	float vnt5[2] = { 7463,1234 };
	client clt5("Emilia", "Pantelimon", vnt5, 2);
	list<client>listClient;
	listClient.push_back(clt1);
	listClient.push_back(clt2);
	listClient.push_back(clt3);
	listClient.push_front(clt4);
	listClient.push_back(clt5);
	list<client>::iterator it5;
	for (it5 = listClient.begin(); it5 != listClient.end(); it5++) {
		(*it5).afisare();
	}
	

	map<int, RaportFacturi>mapRaportFact;
	RaportFacturi rap1(raportF, 3);
	factura raportF1[3];
	raportF1[0] = f2;
	raportF1[1] = f3;
	raportF1[2] = f4;
	RaportFacturi rap2(raportF1, 3);
	mapRaportFact[1] = rap1;
	mapRaportFact[2] = rap2;
	map<int, RaportFacturi>::reverse_iterator it6;
	for (it6 = mapRaportFact.rbegin(); it6 != mapRaportFact.rend(); it6++) {
		cout << it6->first << " " << it6->second << endl;
	}
	cout <<endl<< "Aplicatia dispune de un numar de: " << arg1 <<" argumente"<<endl;
	cout <<endl<< "Mai jos sunt enumerate argumentele"<<endl;
	for (int i = 0; i < arg1; i++) {
		cout << "Argumentul " << i + 1 << " este: " << arg2[i] << endl;
	}

	cout << "Alegeti o optiune: " << endl;
	int x;
	cin >> x;
	switch (x) {
	case 1:
		cout << "Raport Cheltuieli" << endl;
		cout << raport1;
		raport1.Raport(raport1, "raportCheltuieli1.txt");
		break;
	case 2:
		cout << "Raport Economii" << endl;
		cout << raport2;
		raport2.Raport(raport2, "raportEconomii1.txt");
		break;
	case 3:
		cout << "Raport Facturi" << endl;
		cout << raport3;
		raport3.Raport(raport3, "raportFacturi1.txt");
		break;
	default: cout << "Aceasta optiune nu este valabila. Va rog cititi instructiunile!" << endl;

	}
}