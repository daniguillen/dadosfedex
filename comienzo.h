#ifndef COMIENZO_H
#define COMIENZO_H
#include <locale.h>
using namespace std;
int comienzo() {
	int opcion;
	cout << "-------- MENU --------"<< endl;
	cout << "1. JUEGO PARA 2 JUGADORES" << endl;
	cout << "2. ESTADISTICAS" << endl;
	cout << "3. CREDITOS" << endl;
	cout << "4. SALIR"    << endl;
	cout << "----------------------"    << endl;
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	return opcion;
}



#endif
