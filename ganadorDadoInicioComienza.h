#ifndef GANADORDADOINICIOCOMIENZA_H
#define GANADORDADOINICIOCOMIENZA_H
void iniciarLosDados( string jugador1, string jugador2,int& dadojugador1 , int& dadojugador2 ,int& jugadorActual){
	
	do{
		dadojugador1 = dados10Caras(jugador1);
		dadojugador2 = dados10Caras(jugador1);
		
		cout << "Dado de:  "<< jugador1 << " es: "<< dadojugador1<<endl;
		cout << "Dado de:  "<< jugador2 << " es: "<< dadojugador2 <<endl;
		
		if(dadojugador2>dadojugador1){
			cout << "Gano: " << jugador1<< " Usted inicia" <<endl;
			jugadorActual=1;
		}
		else if(dadojugador2<dadojugador1){
			cout << "Gano: " << jugador2<< " Usted inicia" <<endl;
			jugadorActual=2;
		}else{
			cout << "¡Empate! Se tira el dado de nuevo." <<endl;
		};
	}
	while (dadojugador1==dadojugador2);
	
	
}



#endif
