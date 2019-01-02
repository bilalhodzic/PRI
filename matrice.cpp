/*omogućiti unos željene veličine matrica (broj redova i kolona – sve matrice moraju biti jednake veličine),
• omogućiti unos vrijednosti elemenata matrica s tastature,
• kreirati treću matricu čiji će elementi biti suma odgovarajućih elemenata matrica A i B,
• dealocirajte dinamički kreirane objekte,
• koristite funkcije.*/
#include <iostream>
#include <iomanip>
using namespace std;

void unos(double**, int, int);
void ispis(double**, int, int);
void inicijalizacija(double**, double**, double**, int, int);


int main()
{
	int red, kolona;
	cout << "unesite zeljeni broj redova " << endl;
	cin >> red;
	cout << "unesite broj kolona" << endl;
	cin >> kolona;

	double **a = new double*[red];
	double **b = new double*[red];
	double **c = new double*[red];

	for (int i = 0; i < red; i++)
	{
		a[i] = new double[kolona];
		b[i] = new double[kolona];
		c[i] = new double[kolona];

	}
	cout << endl<<"matrica A " << endl;
	unos(a, red, kolona);

	cout << "\nmatrica B" << endl;
	unos(b, red, kolona);

	cout << "\nzbir prve dvije matrice u trecoj matrici " << endl;
	inicijalizacija(a, b, c, red, kolona);
	ispis(c, red, kolona);

	for (int i = 0; i < red; i++)
	{
		delete[] a[i];
		delete[] b[i];
		delete[] c[i];

	}
	a = nullptr;
	b = nullptr;
	c= nullptr;








	system("pause>0");
	return 0;
}
void unos(double **pok, int red, int kolona)
{
	cout << "unesite brojeve u matricu" << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "[" << i + 1 << "] [" << j + 1 << "] ";
			cin >> pok[i][j];
		}
	}
}
void ispis(double** pok, int red, int kolona)
{
	cout << "****ISPIS*****" << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "[" << i + 1 << "] [" << j + 1 << "] ";

			cout << setw(6)<<pok[i][j]<<endl;
		}
	}
}
void inicijalizacija(double** a, double** b, double** c, int red, int kolona)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}