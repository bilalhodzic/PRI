/*Napišite program koji će omogućiti unos rednog broja, prezimena i imena za 3 učenika,
te broj opravdanih i neopravdanih sati. Ispisati redni broj, ime i prezime, te broj opravdanih i 
neopravdanih sati za svakog učenika. Izračunati i ispisati ukupan broj opravdanih i neopravdanih sati 
(za sve učenike), te ime i prezime učenika s najmanjim brojem neopravdanih i ime i 
prezime učenika s najvećim brojem opravdanih sati. Koristite funkcije. Pokušajte kreirati niz objekata ucenik.*/
#include <iostream>
using namespace std;

const int vel = 3;

struct ucenik
{
	int redniB;
	char imePrezime[20];
	int opravdani, neopravdani;
}ucenici[vel];

void unos(ucenik ucenici[])
{
	for (int i = 0; i < vel; i++)
	{

	cout << "unesite redni broj" << endl;
	cin >> ucenici[i].redniB;
	cin.ignore();
	cout << "unesite ime doticnog" << endl;
	cin.getline(ucenici[i].imePrezime, 20);
	cout << "unesite broj opravdanih sati" << endl;
	cin >> ucenici[i].opravdani;
	cout << "unesite broju neopravdanih stai" << endl;
	cin >> ucenici[i].neopravdani;

	}
}
void ispis(ucenik ucenici[])
{
	for (int i = 0; i < vel; i++)
	{
		cout << "Redni br: " << ucenici[i].redniB << " Ime: " << ucenici[i].imePrezime;
		cout << " opravdanih: " << ucenici[i].opravdani << " neoprvadanih: " << ucenici[i].neopravdani << endl;

	}

}
void ukupno(ucenik ucenici[])
{
	int zbir1 = 0, zbir2 = 0;
	for (int i = 0; i < vel; i++)
	{
		zbir1 += ucenici[i].neopravdani;
		zbir2 += ucenici[i].opravdani;
	}
	
	cout << "\nukupno opravdanih ima: " << zbir2 << ", a neopravdanih " << zbir1 << endl;
}
void najmanje(ucenik ucenici[])
{
	int min = INT_MAX , pozicija = 0;
	for (int i = 0; i < vel; i++)
	{
		if (ucenici[i].neopravdani < min)
		{
			min = ucenici[i].neopravdani;
			pozicija = i;
		}

	}
	cout << endl;
	cout << "ucenik sa najmanje neopravdanih je " << ucenici[pozicija].imePrezime << endl;
	

}
void najviseOp(ucenik ucenici[])
{
	int max = 0, pozicija=0;
	for (int i = 0; i < vel; i++)
	{
		if (ucenici[i].opravdani > max)
		{
			max = ucenici[i].opravdani;
			pozicija = i;
		}
	}

	cout << endl;
	cout << "ucenik sa najvise opravdanih sati: " << ucenici[pozicija].imePrezime << endl;
}

int main()
{
	unos(ucenici);
	ispis(ucenici);
	ukupno(ucenici);
	najmanje(ucenici);
	najviseOp(ucenici);

	system("pause>0");
	return 0;
}