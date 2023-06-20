#ifndef FEDEX_H
#define FEDEX_H


#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
	
	bool i=true, empate=true;
	int opcion, d10j1, d10j2,estatuillastotales, jugador_actual, estatuilla_elegida, dado10a, dado10b;
	string jugador1, jugador2;
	int estatuillaJ1[5]={}, estatuillaJ2[5]={};
	srand(time(0));
	
	
	cout << "-------- MENU --------"<< endl;
	cout << "1. JUEGO PARA 2 JUGADORES" << endl;
	cout << "2. ESTADISTICAS" << endl;
	cout << "3. CREDITOS" << endl;
	cout << "4. SALIR"    << endl;
	cout << "----------------------"    << endl;
	cout << "Ingrese una opcion: ";
	cin>>opcion;
	
	
	
	//pedido de nombres//
	cout << "Ingrese el nombre del Jugador 1: "<<endl;
	cin>> jugador1;
	cout << "Ingrese el nombre del Jugador 2: "<<endl;
	cin>> jugador2;
	cout << "nombre jugador 1: " << jugador1 <<endl;
	cout << "nombre de jugador 2 :" << jugador2 <<endl;
	
	//quien arranca//
	do{
		d10j1 = rand() % 10 + 1;
		cout<<"Jugador " <<jugador1<<" tira el dado y saca un:"<<d10j1<<endl;
		cout<<endl;
		d10j2 = rand() % 10 + 1;
		cout<<"Jugador "<<jugador2<< " tira el dado y saca un: "<<d10j2<<endl;
		cout<<endl;
		
		
		if (d10j1 < d10j2) {
			cout << "Jugador "<<jugador1<<" empieza la partida!"<<endl;
			cout << "------------------------" <<endl;
			empate = false;
			jugador_actual=1;
		} else if (d10j2 < d10j1) {
			cout << "Jugador "<<jugador2<<" empieza la partida!" <<endl;
			cout << "------------------------" <<endl;
			empate = false;
			jugador_actual=2;
		} else {
			cout << "¡Empate! Se tira el dado de nuevo." <<endl;
		}
		
		cout << "------------------------" <<endl;
	} while (empate==true);
	
	//ESTATUILLAS
	estatuillastotales=5;
	bool b1=true, b2=true, b3=true, b4=true, b5=true;
	cout<<"1- Cangrejo"<<endl;
	cout<<"Obtención: Uno de sus dados debe ser par y otro de sus dados impar."<<endl;
	cout<<"Bendición (En fase final)"<<endl;
	cout<<"Podrá lanzar los dados dos veces en el primer tiro de la fase final."<<endl;
	cout<<"Maldición (En fase expedición"<<endl;
	cout<<" El rival tira un dado de diez caras y el valor obtenido son los puntos de victoria que le descuenta al portador de la estatuilla al final de la partida."<<endl;
	cout<< "------------------------" <<endl;
	cout<<endl;
	
	cout<<"2- Hormiga"<<endl;
	cout<<"Obtención: Al menos dos dados deben ser menores a 5."<<endl;
	cout<<"Bendición (En fase final)"<<endl;
	cout<<"Antes de empezar la fase final el portador de la estatuilla puede elegir un número del 1 al 6. Luego, en cada tiro puede optar por elegir uno de los cinco dados del lanzamiento y reemplazarlo por el número elegido"<<endl;
	cout<<"Maldición (En fase expedición"<<endl;
	cout<<"El rival tira dos dados de diez caras y el valor obtenido son los puntos de victoria que le descuenta al portador de la estatuilla al final de la partida."<<endl;
	cout<< "------------------------" <<endl;
	cout<<endl;
	
	cout<<"3- Medusa"<<endl;
	cout<<"Obtención: La suma de dos de los dados lanzados debe dar exactamente siete."<<endl;
	cout<<"Bendición (En fase final)"<<endl;
	cout<<"Permite ganar el desafío de la Fase Final también con la obtención de 5 dados iguales."<<endl;
	cout<<"Maldición (En fase expedición"<<endl;
	cout<<"El portador de la estatuilla debe esperar 3 turnos sin lanzar dados para seguir la Fase de Expedición."<<endl;
	cout<< "------------------------" <<endl;
	cout<<endl;
	
	cout<<"4- Aguila"<<endl;
	cout<<"Obtención: Dos de los dados lanzados deberán devolver los números 1 y 10."<<endl;
	cout<<"Bendición (En fase final)"<<endl;
	cout<<"En cada tirada de la Fase Final el portador de la estatuilla podrá elegir un dado y modificar su número a su antojo."<<endl;
	cout<<"Maldición (En fase expedición"<<endl;
	cout<<"El rival tira dos veces por turno durante el resto de la Fase de Expedición."<<endl;
	cout<< "------------------------" <<endl;
	cout<<endl;
	
	cout<<"5- Salamandra"<<endl;
	cout<<"Obtención: Los dados lanzados deben ser consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10)"<<endl;
	cout<<"Bendición (En fase final)"<<endl;
	cout<<"El portador de la estatuilla podrá ganar la fase final con una escalera de 4 dados consecutivos entre 5 dados lanzados"<<endl;
	cout<<"Maldición (En fase expedición"<<endl;
	cout<<"El rival juega con tres dados durante el resto de la Fase de Expedición."<<endl;
	cout<< "------------------------" <<endl;
	cout<<endl;
	
	
	
	//FASE EXPEDICION
	
	
	while(estatuillastotales>0){
		if(jugador_actual==1){
			cout<< "jugador "<<jugador1<<" elija estatuilla"<<endl;}
		cout<< "jugador 1"<<endl;}
	cout<< "jugador 2"<<endl;}

		else {
	cout<< "jugador "<<jugador1<<" elija estatuilla"<<endl;}
cout<< "jugador 2"<<endl;}
cout<< "jugador 1"<<endl;}
		}


		cin>>estatuilla_elegida;
		
		cout<<"lanzando 2 dados de 10 caras......."<<endl;
		dado10a= rand() % 10 + 1;
		dado10b= rand() % 10 + 1;
		
		cout<<"dado 1 : "<<dado10a<<"   y  dado 2: "<<dado10b<<endl;
		
		
		switch (estatuilla_elegida){
			
		case 1:
			
			cout << "1- Cangrejo" << endl;
			if (b1==true && ((dado10a%2==0 && dado10b%2!=0)||(dado10a%2!=0 && dado10b%2==0))){
				if(jugador_actual==1){
					estatuillaJ1[0]++;
					b1=false;
					estatuillastotales--;
					cout<< jugador1 << " gano la estatuilla"<<endl;
				}
				else{estatuillaJ2[0]++;
				b1=false;
				estatuillastotales--;
				cout<< jugador2 << " gano la estatuilla"<<endl;
				}
			}else{
				cout<< "no gano la estatuilla"<<endl;}
			break;
		case 2:
			cout << "2- Hormiga" << endl;
			if (b2==true && (dado10a<5 && dado10b<5)){
				if(jugador_actual==1){
					estatuillaJ1[1]++;
					b2=false;
					estatuillastotales--;
					cout<< jugador1<< " gano la estatuilla"<<endl;}
				
				else{estatuillaJ2[1]++;
				b2=false;
				estatuillastotales--;
				cout<< jugador2 << " gano la estatuilla"<<endl;}
			}else{
				cout<< "no gano la estatuilla"<<endl;}
			break;
		case 3:
			cout << "3- Medusa" << endl;
			if (b3==true && (dado10a + dado10b==7)){
				if(jugador_actual==1){
					estatuillaJ1[2]++;
					b3=false;
					estatuillastotales--;
					cout<< jugador1<< " gano la estatuilla"<<endl;}
				else{estatuillaJ2[2]++;
				b3=false;
				estatuillastotales--;
				cout<< jugador2<< " gano la estatuilla"<<endl;}
			}else{
				cout<< "no gano la estatuilla"<<endl;}
			break;
		case 4:
			cout << "4- Aguila" << endl;
			if (b4==true && ((dado10a==1 && dado10b==10)||(dado10a==10 && dado10b==1))){
				if(jugador_actual==1){
					estatuillaJ1[3]++;
					b4=false;
					estatuillastotales--;
					cout<< jugador1<< " gano la estatuilla"<<endl;}
				else{estatuillaJ2[3]++;
				b4=false;
				estatuillastotales--;
				cout<< jugador2<< " gano la estatuilla"<<endl;}
			}else{
				cout<< "no gano la estatuilla"<<endl;}
			break;
		case 5:
			cout << "5- Salamandra" << endl;
			if (b5==true && ((dado10a+1==dado10b)||(dado10b+1==dado10a))){
				if(jugador_actual==1){
					estatuillaJ1[4]++;
					b5=false;
					estatuillastotales--;
					cout<< jugador1<< " gano la estatuilla"<<endl;}
				else{estatuillaJ2[4]++;
				b5=false;
				estatuillastotales--;
				cout<< jugador2<< " gano la estatuilla"<<endl;}
			}else{
				cout<< "no gano la estatuilla"<<endl;}
			break;
		default:
			cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
			break;
		}
		if (jugador_actual==1){
			cout<<"turno de : "<<jugador2<<endl;
			jugador_actual=2;
		}else{cout<<"turno de : "<<jugador1<<endl;
		jugador_actual=1;}}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}






#endif
