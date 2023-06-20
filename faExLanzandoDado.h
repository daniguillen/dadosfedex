#ifndef FAEXLANZANDODADO_H
#define FAEXLANZANDODADO_H

void faExDados2(int& dado1, int& dado2, int (*function)(string&), string& jugador1) {
	dado1 = function(jugador1);
	dado2 = function(jugador1);
	cout << "Dado 1 es: " << dado1 << endl;
	cout << "Dado 2 es: " << dado2 << endl;
}

void faExDados3(int& dado1, int& dado2, int& dado3, int (*function)(string&), string& jugador1) {
	dado1 = function(jugador1);
	dado2 = function(jugador1);
	dado3 = function(jugador1);
	cout << "Dado 1 es: " << dado1 << endl;
	cout << "Dado 2 es: " << dado2 << endl;
	cout << "Dado 3 es: " << dado3 << endl;
}
void faExMaldicionCangrejo(int& dado, int (*function)(string&), string& jugador1) {
	dado = function(jugador1);
}
void faExMaldicionHormiga(int& a, int (*function)(string&), string& jugador1) {
	int dado1;
	int dado2;
	dado1 = function(jugador1);
	cout << "Dado 1 es: " << dado1 << endl;
	dado2 = function(jugador1);
	cout << "Dado 2 es: " << dado2 << endl;
	a= dado1+dado2;
	

}

void faExDados5(int& dado1, int& dado2, int& dado3, int& dado4,int& dado5, int (*function)(string&), string& jugador1) {
	dado1 = function(jugador1);
	dado2 = function(jugador1);
	dado3 = function(jugador1);
	dado4 = function(jugador1);
	dado5 = function(jugador1);
	cout << "Dado 1 es: " << dado1 << endl;
	cout << "Dado 2 es: " << dado2 << endl;
	cout << "Dado 3 es: " << dado3 << endl;
	cout << "Dado 4 es: " << dado4 << endl;
	cout << "Dado 5 es: " << dado5 << endl;
}




#endif
