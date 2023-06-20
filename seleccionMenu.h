#ifndef SELECCIONMENU_H
#define SELECCIONMENU_H

#include <iostream>
#include <functional>

int seleccionMenu(function<int()> a, function<string()> b)
{
	int seleccionMenuPrincipal = a();
	string credito = b();
	
	cout << "Usted ha elegido: " << seleccionMenuPrincipal << endl;
	
	while (seleccionMenuPrincipal < 1 || seleccionMenuPrincipal > 4)
	{
		cout << "Usted ha seleccionado una opci�n incorrecta, por favor ingrese una opci�n correcta" << endl;
		seleccionMenuPrincipal = a();
	}
	
	// la selecci�n del men�
	
	switch (seleccionMenuPrincipal)
	{
	case 1:
		cout << "Bienvenido Inicio del juego" << endl;
		break;
		
	case 2:
		cout << "Bienvenidos Estad�sticas" << endl;
		break;
		
	case 3:
		cout << credito << std::endl;
		break;
		
	default:
		cout << "Usted ha elegido No Jugar" << endl;
		break;
	}
	return seleccionMenuPrincipal;
}

#endif
