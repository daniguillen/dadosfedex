#ifndef VALIDACIONENTRADA_H
#define VALIDACIONENTRADA_H
#include <iostream>
#include <string>

void eligiendoEstatuillaJugado1(int jugadorActual, string nombre1,string nombre2, int& showJugador ,  int (*Statuillas)[5]) {
	
			if(jugadorActual==1){
			cout << "Elija una estatuilla con un número que esté en el índice" << endl;
			cout << nombre1 << " elija estatuilla" << endl;
			cin >> showJugador;
			cout << " Su seleccion Fue: "<<  showJugador<< endl;
			
				while(showJugador < 1 || showJugador > 5 || Statuillas[2][showJugador-1] ){
					cout << "Elija una estatuilla entre la 1 y la 5 o no esta disponible" <<endl;
					
					cout << nombre1 << " elija estatuilla" << endl;
					cin >> showJugador;
					cout << " Su seleccion Fue: "<<  showJugador<< endl;
				}
			}else{
				
				cout << "Elija una estatuilla con un número que esté en el índice" << endl;
				cout << nombre2 << " elija estatuilla" << endl;
				cin >> showJugador;
				cout << " Su seleccion Fue: "<<  showJugador<< endl;
			
				while(showJugador < 1 || showJugador > 5 || Statuillas[2][showJugador-1] ){
					cout << "Elija una estatuilla entre la 1 y la 5 o no esta disponible" <<endl;
					
					cout << nombre2 << " elija estatuilla" << endl;
					cin >> showJugador;
					cout << " Su seleccion Fue: "<<  showJugador<< endl;
				
				
				}
			}
	}


#endif


