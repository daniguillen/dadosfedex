#ifndef SELECCIONESTATUILLA_H
#define SELECCIONESTATUILLA_H

void seleccionEstatuilla(int seleccion){

	switch (seleccion){
		
	case 1:
		
		cout << "1- Cangrejo" << endl;


		break;
	case 2:
		cout << "2- Hormiga" << endl;


		break;
	case 3:
		cout << "3- Medusa" << endl;


		break;
	case 4:
		cout << "4- Aguila" << endl;


		break;
	case 5:
		cout << "5- Salamandra" << endl;
		


		break;
	default:
		cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;

		break;
	}

}

#endif
