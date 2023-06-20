#ifndef DADOS10CARAS_H
#define DADOS10CARAS_H
#include <cstdlib>
#include <ctime>
#include <random>
int dados10Caras(string& jug1) {
	int resultado;
	if (jug1 == "LAB1") {
		cout << "Ingrese el número del dado" << endl;
		cin >> resultado;
		while(resultado>10 || resultado<1){
			cout << "Ingrese el número del dado entre 1 y 10" << endl;
			cin >> resultado;
		}
	} else {
		resultado = rand() % 10 + 1;
	}
	
	return resultado;
}
#endif
