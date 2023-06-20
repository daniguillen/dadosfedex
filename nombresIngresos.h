#ifndef NOMBRESINGRESOS_H
#define NOMBRESINGRESOS_H

void nombreIngreso(string& jugador1, string& jugador2 ){
	cout << "Ingrese el nombre del Jugador 1: " << endl;
	cin.ignore();
	jugador1 = nombre();
	
	cout << "Ingrese el nombre del Jugador 2: " << endl;
	jugador2 = nombre();
	
	cout << "nombre jugador 1: " << jugador1 << endl;
	cout << "nombre de jugador 2: " << jugador2 << endl;
}


#endif
