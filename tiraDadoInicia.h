#ifndef TIRADADOINICIA_H
#define TIRADADOINICIA_H
void tiraDadoInicia(int dadojugador1, int dadojugador2, string jugador1, string jugador2, int& jugadorActual){
	
	if(dadojugador2>dadojugador1){
		cout << "Gano: " << jugador1<< " Usted inicia" <<endl;
		jugadorActual=1;
	}
	else if(dadojugador2<dadojugador1){
		cout << "Gano: " << jugador2<< " Usted inicia" <<endl;
		jugadorActual=2;
	}else{
		cout << "¡Empate! Se tira el dado de nuevo." <<endl;
	}
}
#endif
