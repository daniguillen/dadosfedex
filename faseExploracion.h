#ifndef FASEEXPLORACION_H
#define FASEEXPLORACION_H

bool verificacionStautillaSeleccionada(int jugador,int seleccion, int Statuillas [][5]){
	jugador = jugador-1;
	bool verificado = true;
	if(Statuillas [jugador][seleccion]==0){
		cout << "Estautilla disponible y seleccionada"<< endl;
		verificado = true;
	}else{
		  verificado = false;
		  cout << "Estautilla NO disponible "<< endl;
	}
		return verificado;
}

#endif
