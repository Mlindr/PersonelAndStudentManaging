#include <iostream>
#include "Sovellus.h"
#include <limits>
using std::cout; using std::cin; using std::endl;

int main() {

	Sovellus kaynnistys;//luodaan sovellus olio

	try {
		kaynnistys.aja();//ajetaan ohjelmaa
	}

	catch (...) {
		cout << "Ohjelma kaatui, kokeile uudestaan" << endl;
	}

	system("pause");
	return 0;
}
