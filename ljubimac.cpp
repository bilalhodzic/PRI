#include <iostream>
using namespace std;
/*Kreirajte niz objekata ljubimac (o broju objekata odlučuje korisnik) sa sljedećim obilježjima:
Ime (pokazivac na char), 
•	dob (u mjesecima)
•	vrsta (pokazivač na char)
•	spol (pokazivač na char), 
•	cijepljenje //cijepljenje je zasebna struktura koja se sastoji od
datuma (koji također može biti zasebna strukrura) i opisa(pokazivač na char)

i funkcije članice:
•	funkciju za u za unos obilježja objekta;void ljubimac :: unos();
•	funkciju za ispis obilježja objekta

1.	funkciju koja će pronaći i objekt(e)/ljubimca(e) one vrste koje korisnik odabere; za 
ispis koristite funkciju za ispis;
2.	funkciju koja pronalazi sve ljubimce koji su cijepljeni na datum koji odabere korisnik; za
ispis koristite funkciju za ispis;
3.	funkciju čija je zadaća da pronađe ljubimca s najkraćim imenom;
4.	funkciju koja će kreirati novi niz ljubimaca u kojem će se nalaziti podaci o ljubimcima koji 
su mlađi od 13 mjeseci;
5.	funkciju koja će provjeriti postoje li dva ljubimca s istim imenom;
6.	kreirati pokazivače na funkcije i sve prethodno definirane funkcije pozvati preko pokazivača
7.	dealocirati sve dinamički kreirane objekte.

*/

struct datum
{
	int dan, mjesec, godina;
};
struct cijepljenje
{
	datum datum;
	char*opis=new char[20];
	

};

struct ljubimac
{
	char*ime = new char[20];
	char*vrsta=new char[20];
	char*spol=new char[10];
	int dob;
	cijepljenje cijepljenje;
	void unos();
	void ispis()
	{
		cout << "    \nISPIS     " << endl;
		cout << "Ime: " << ime << " | Vrsta: " << vrsta << " | Spol: " << spol<<endl;
		cout << "Dob: " << dob << " | Datum cijepljenja: " << cijepljenje.datum.dan << " " << cijepljenje.datum.mjesec;
		cout << " " << cijepljenje.datum.godina << " | Vrsta cijepljenja: " << cijepljenje.opis << endl;
		cout << endl;
	}
	void dealociraj()
	{
		delete[]ime;
		ime = nullptr;
		delete[]vrsta;
		vrsta = nullptr;
		delete[]spol;
		spol = nullptr;
		delete[]cijepljenje.opis;
		cijepljenje.opis = nullptr;
	}

};

void ljubimac::unos()
{
	cout << "unesite dob u mjesecima" << endl;
	cin >> dob;
	cout << "unesite ime" << endl;
	cin.ignore();
	cin.getline(ime, 20);
	cout << "unesite vrstu " << endl;
	cin.getline(vrsta, 20);
	cout << "unesite spol" << endl;
	cin.getline(spol, 10);
	cout << "unesite datum cijepljenja(dd/mm/gg)" << endl;
	cin >> cijepljenje.datum.dan;
	cin >> cijepljenje.datum.mjesec;
	cin >> cijepljenje.datum.godina;
	cout << "unesite vrstu cijepljenja" << endl;
	cin.ignore();
	cin.getline(cijepljenje.opis, 20);

}

void pronaci_vrstu(ljubimac *niz, int vel, char odabir[])
{
	for (int i = 0; i < vel; i++)
	{
		if (strcmp(niz[i].vrsta, odabir) == 0)
			niz[i].ispis();
	}
}
void pronaci_datum(ljubimac*niz, int vel, datum trazeni)
{
	for (int i = 0; i < vel; i++)
	{
		if (niz[i].cijepljenje.datum.dan == trazeni.dan)
			if (niz[i].cijepljenje.datum.mjesec == trazeni.mjesec)
				if (niz[i].cijepljenje.datum.godina == trazeni.godina)
					niz[i].ispis();
	}
}
void najkrace_ime(ljubimac*niz, int vel)
{
	int min = strlen(niz[0].ime);
	int index = 0;
	for (int i = 1; i < vel; i++)
	{
		if (strlen(niz[i].ime) < min)
		{
			min = strlen(niz[i].ime);
			index = i;
		}
	}
	niz[index].ispis();
}
int mladi_ljubimci(ljubimac *niz, int vel)
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		if (niz[i].dob < 13)
			brojac++;
	}
	return brojac;
}
void isto_ime(ljubimac*niz, int vel)
{
	for (int i = 0; i < vel; i++)  //dvije for petlje da bi pretrazio sve ljubimce u nizu
	{
		for (int j = i+1; j < vel; j++)
			if (strcmp(niz[i].ime, niz[j].ime) == 0) {
				niz[i].ispis();
				niz[j].ispis();
			}
	}
}

int main()
{
	int vel;
	cout << "koliko objekata zelite" << endl;
	cin >> vel;

	ljubimac *niz = new ljubimac[vel];

	void(*pok)(ljubimac *, int) = nullptr; //pokazivac na funkcije

	cout << "unesite podatke o ljubimcima" << endl;


	for (int i = 0; i < vel; i++)
	{
		niz[i].unos();    //unos niza ljubimaca
	}
	for (int i = 0; i < vel; i++)
	{
		niz[i].ispis();  //ispis
	}
	char vrsta[20];       //treba upisati vrstu koju zelite pronaci
	cout << "koju vrstu zelite pronaci" << endl;
	cin.getline(vrsta, 20);
	cout << "ljubimci sa trazenom vrstom " << vrsta << " :" << endl;
	//pronaci_vrstu(niz, vel, vrsta);
	void(*pok1)(ljubimac*, int, char[]) = pronaci_vrstu;   //pokazivac na funkciju 
	pok1(niz, vel, vrsta);

	datum odabir;     //treba da ispise ljubimce cijepljenje na unesni datum
	cout << "unesite datum na koji su cijepljenji ljubimci" << endl;
	cin >> odabir.dan >> odabir.mjesec >> odabir.godina;
	cout << "ljubimci cijepljeni na uneseni datum" << endl;
	//pronaci_datum(niz, vel, odabir);
	void(*pok2)(ljubimac* niz, int vel, datum odabir) = pronaci_datum;
	pok2;

	cout << " ljubimac sa najkracim imenom je: " << endl;
	//najkrace_ime(niz, vel);
	pok = najkrace_ime;
	pok(niz, vel);

	int nova_vel = mladi_ljubimci(niz, vel);  //vraca broj ljubimaca mladji od 13 mjeseca i pravi novi niz
	ljubimac *novi = new ljubimac[nova_vel];
	//cout << "\nBroj ljubimaca koji su mladji od 13 mjeseci je: " << novi_vel << endl;
	int(*pok3)(ljubimac *niz, int vel) = mladi_ljubimci;
	nova_vel = (*pok3)(niz, vel);
	cout << "\nBroj ljubimaca koji su mladji od 13 mjeseci je: " << nova_vel << endl;


	cout << "\n\nLjubimci sa istim imenom su:\n";
	//isto_ime(niz, vel);
	pok = isto_ime;
	pok(niz, vel);



	for (int i = 0; i < vel; i++)
		niz[i].dealociraj();
	
	delete[]niz;
	niz = nullptr;

	for (int i = 0; i < nova_vel; i++)
		novi[i].dealociraj();
	delete[]novi;
	novi = nullptr;

	system("pause>0");
	return 0;
}
