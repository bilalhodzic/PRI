/*Dat je 2d niz dimenzija 8x8. omoguciti korisniku unos cjelobrojnih elemenata 2d niza tako da se u svaki 
neparni red unesu parni brojevi a u svaki parni red neparni broj. napraviti funkciju koja pronalazi kolonu
sa najmanjim prosjekom elemenata. U istoj fukciji ispisati indeks pronadjenje kolone
a u main funkcoiji sve elemente te kolone.*/
#include <iostream>
#include <iomanip>

using namespace std;

const int vel = 8;
void unos(int[][vel]);
void zamjena(int[][vel], int[][vel]);
void ispis(int [][vel]);
void minprosjek(int[][vel]);

int main()
{
	int niz[vel][vel], niz2[vel][vel];

	unos(niz);
	zamjena(niz, niz2);
	ispis(niz);
	minprosjek(niz2);



	system("pause>0");
	return 0;
}
void unos(int niz[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{

			if (i % 2 == 0)
			{
				do
				{
					cout << "unesite neparan broj" << endl;
					cin >> niz[i][j];
				} while (niz[i][j] % 2 == 0);
			}
			else
			{
				do
				{
					cout << "unesite paran broj" << endl;
					cin >> niz[i][j];
				} while (niz[i][j] % 2 != 0);
			}
		}
	}


}
void zamjena(int niz[][vel], int niz2[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			niz2[i][j] = niz[j][i];
		}
	}

}
void ispis(int niz[][vel])
{
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
			cout <<setw(5)<< niz[i][j];
		cout << endl;
	}

}
void minprosjek(int niz[][vel])
{
	double prosjek = 0, suma =0, min=0;
	int indeks=0;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			suma += niz[i][j];
		}
		
		prosjek = suma / vel;
		suma = 0;
		if (i == 0)
			min = prosjek;
		if (min > prosjek)
		{
			min = prosjek;
			indeks = i;
		}
	}

	cout << "najmanji prosjek je " << min << " iz kolone " << indeks + 1 << endl;

}