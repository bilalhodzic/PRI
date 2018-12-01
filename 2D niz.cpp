#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int main(void) {

	cout << "Unesite rijec" << endl;
	string rijec;
	getline(cin, rijec);

	cout << "_______" << endl;

	for (int i = 0; i < rijec.length(); i++) {
		cout << rijec << " " << endl;
	}

	system("PAUSE");
	return 0;
}