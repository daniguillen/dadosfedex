#ifndef RETURNMENU_H
#define RETURNMENU_H
int returnMenu() {
	int opcion;
	cout << "-------- MENU --------"<< endl;
	cout << "2. ESTADISTICAS" << endl;
	cout << "3. CREDITOS" << endl;
	cout << "4. SALIR"    << endl;
	cout << "----------------------"    << endl;
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	return opcion;
}
#endif
