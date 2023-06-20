#ifndef GANOESTATUILLA_H
#define GANOESTATUILLA_H

int ganoLaEstautilla(int dado1, int dado2, int dado3, int seleccionJugador) {
	int gana = 0; // Inicializamos la variable gana a 0
	
	switch (seleccionJugador) {
	case 1:
		if ((dado1 % 2 == 0 && dado2 % 2 != 0) ||
			(dado1 % 2 != 0 && dado2 % 2 == 0) ||
			((dado3 > 0 && dado3 % 2 != 0) && dado1 % 2 == 0) ||
			((dado3 > 0 && dado3 % 2 == 0) && dado1 % 2 != 0) ||
			((dado3 > 0 && dado3 % 2 != 0) && dado2 % 2 == 0) ||
			((dado3 > 0 && dado3 % 2 == 0) && dado2 % 2 != 0))
		{
			gana = 1;
			cout <<dado1 << endl;
			cout <<dado2 << endl;
			cout <<dado3 << endl;
			cout << "Felicidades ganaste la Estautilla Cangrejo" << endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}
		else
		{
			cout << "Lo siento No te ganaste la estautilla" << endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}
		break;
	case 2:
		if ((dado1 < 5 && dado2 < 5) ||
			(dado2 < 5 && (dado3 < 5 && dado3 > 0)))
		{
			gana = 1;
			cout << "Felicidades ganaste la Estautilla Hormiga"<<endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}else{
			cout << "Lo siento No te ganaste la estautilla"<<endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}
		break;
	case 3:
		if (dado1 + dado2 == 7 || (dado3>0 && (dado1 + dado3 == 7)) || (dado3> 0 && dado2 + dado3 == 7))
		{
			gana = 1;
			cout << "Felicidades ganaste la Estautilla Medusa"<<endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}else{
			cout << "Lo siento No te ganaste la estautilla"<<endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}
		break;
	case 4:
		if ((dado1 == 1 && dado2 == 10) ||
			(dado1 == 10 && dado2 == 1) ||
			(dado1 == 1 && dado3 == 10) ||
			(dado1 == 10 && dado3 == 1) ||
			(dado2 == 1 && dado3 == 10) ||
			(dado2 == 10 && dado3 == 1))
		{
			gana = 1;
			cout << "Felicidades ganaste la Estautilla Aguila" << endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}
		else
			{
				cout << "Lo siento, no ganaste la estautilla" << endl;
				dado3 = 0;
				dado2=0;
				dado1=0;
			}
			break;
	case 5:
		if ((dado1 == dado2 - 1) || 
			(dado2 == dado1 - 1) || 
			
			(dado2 == dado3 - 1) ||
			(dado3 > 0 && dado3 == dado2 - 1) ||
			
			(dado3 > 0 && dado3 == dado1 - 1) ||
			(dado3 > 0 && dado1 == dado3 - 1)
			)
		{
			gana = 1;
			cout << "Felicidades ganaste la Estautilla Salamandra"<<endl;
			dado3 = 0;
			dado2=0;
			dado1=0;
		}else{
				cout << "Lo siento No te ganaste la estautilla"<<endl;
				dado3 = 0;
				dado2=0;
				dado1=0;
			}
			break;
	default:
		gana = 0;
		break;
	}
	
	return gana;
}

#endif

