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
		cout << "Usted ha seleccionado una opción incorrecta, por favor ingrese una opción correcta" << endl;
		seleccionMenuPrincipal = a();
	}
	
	// la selección del menú
	
	switch (seleccionMenuPrincipal)
	{
	case 1:
		cout << "Bienvenido Inicio del juego" << endl;
		break;
		
	case 2:
		cout << "Bienvenidos Estadísticas" << endl;
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
