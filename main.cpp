#include <iostream>
#include <locale.h>
#include "comienzo.h"
#include "cangrejo.h"
#include "seleccionMenu.h"
#include "tiraDadoInicia.h"
#include "nombreStatuillas.h"
#include "hormiga.h"
#include "medusa.h"
#include "aguila.h"
#include "salamandra.h"
#include "nombres.h"
#include "creditos.h"
#include "seleccionEstatuilla.h"
#include "seleccionEstatuillaNombre.h"
#include "validacionEntrada.h"
#include "dados10Caras.h"
#include "ganadorDadoInicioComienza.h"
#include "nombresIngresos.h"

//fase exploracion
#include "faseExploracion.h"
#include "faExLanzandoDado.h"
#include "ganoEstatuilla.h"


#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

int main() {
	//semilla de los dados
	srand(time(0));
	//pedido de seleccion de menu
	int selecionMenuPrincial ;
	//string credito = creditos();
	int seleccion ;
	int jugadorActual=0;
	int dadojugador1=0;
	int dadojugador2=0;
	string jugador1;
	string jugador2;
	int contadorEstatuillasDisponibles=5;
	int Statuillas [3][5]{};
	do{
	
	selecionMenuPrincial=seleccionMenu(comienzo,creditos);
	
	if(selecionMenuPrincial==1){
		
		nombreIngreso(jugador1, jugador2 );
		//nombres
		cout<<"--------------------------------------------------------------------------------"<<endl;
		iniciarLosDados( jugador1, jugador2,dadojugador1 ,dadojugador2 , jugadorActual);
	
		
		string StatuillasNombres[5]{};
	//se debe modificar las estauillas
		nombreStatuillas(StatuillasNombres);
		
		for(int i=0 ; i<5; i++){
			cout<< StatuillasNombres[i]<<endl;
		}

		int seleccionEstatuillaDisponibleJugador1;
		int seleccionEstatuillaDisponibleJugador2;
	//contador estatuillas disponibles	
		
		int dado1, dado2, dado3=0;
		int resultado=0;
		bool verificado;
		bool maldicionMedusa = false;
		bool maldicionAguila =false;
		int aplicacionAguila=0;
		bool banderaAguila= false;
		int contadorAplicacionAguila=2;
		int jugadorMedusa;
		bool banderaMedusa= true;
		int contadorMedusa=3;
		int jugadorSalamandra;
		int PuntosDescuentoMaldicionCangrejo=0;
		bool maldicionCangrejo= true;
		bool maldicionHormiga =true;
		int jugadorMaldicionCangrejo;
		int jugadorMaldicionHormiga;
		bool maldicionSalamandra=false;
		int contadorPuntosPrimerJugador=0;
		int contadorPuntosSegundoJugador=0;
		int auxPuntosJugador=0;
		int auxcontador=0;
		bool banderaPrimerTurno=true;
		int dadoHormiga=0;	
		int puntosRestarJugador2=0;
		int puntosRestarJugador1=0;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		while(contadorEstatuillasDisponibles>0){
			
			
			resultado=0;
				eligiendoEstatuillaJugado1(jugadorActual,  jugador1, jugador2, seleccionEstatuillaDisponibleJugador1, Statuillas);
				seleccionEstatuilla(seleccionEstatuillaDisponibleJugador1 );
				if( maldicionSalamandra  && jugadorActual == jugadorSalamandra){
					faExDados3(dado1,dado2,dado3, dados10Caras, jugador1 );
				}else{
				faExDados2(dado1,dado2, &dados10Caras, jugador1 );
				}
				cout <<"dado1 "<<dado1<<endl;
				cout <<"dado2 "<<dado2<<endl;
				
				if(dado3>0){
				cout <<"dado3 "<<dado3<<endl;}

				resultado= ganoLaEstautilla(dado1, dado2, dado3, seleccionEstatuillaDisponibleJugador1);
				cout <<"seleccion jugador: "<<seleccionEstatuillaDisponibleJugador1<<endl;
				
				//gana los diez puntos en el primer turno
				if(jugadorActual!=auxPuntosJugador && resultado){
					contadorPuntosPrimerJugador+=10;
					cout<<"Usted HA ganado 10 puntos para la fase final: "<< jugador1<<endl;
					auxPuntosJugador=jugadorActual;
					cout<<"los puntos de: "<< jugador1<<" son "<< contadorPuntosPrimerJugador<<endl;
					banderaPrimerTurno=false;

				}
				if(jugadorActual!=auxPuntosJugador && resultado && banderaPrimerTurno){
					contadorPuntosSegundoJugador+=10;
					cout<<"Usted HA ganado 10 puntos para la fase final: "<< jugador1<<endl;
					auxPuntosJugador=jugadorActual;
					cout<<"los puntos de: "<< jugador1<<" son "<< contadorPuntosSegundoJugador<<endl;
					banderaPrimerTurno=false;
				}
				//resta puntos al rival
				
				//descuento de 3 puntos al otro jugador si gana estatuilla
				if(resultado && jugadorActual==1){
					puntosRestarJugador2-=3;
					cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador2<<endl;
					
				}
				if(resultado && jugadorActual==2){
					puntosRestarJugador1-=3;
					cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador1<<endl;
				}
				//fin de resta de puntos
				
				if(resultado){
					contadorEstatuillasDisponibles--;
				}		
				
			if(resultado==1 && contadorEstatuillasDisponibles>0){
				Statuillas [jugadorActual-1][seleccionEstatuillaDisponibleJugador1-1]=1;

				Statuillas [2][seleccionEstatuillaDisponibleJugador1-1]=1;
				
	
				if(banderaMedusa && Statuillas [2][seleccionEstatuillaDisponibleJugador1-1]==1){
					banderaMedusa=false;
					if( jugadorActual==1 ){
						jugadorMedusa=2;
					}else{
						jugadorMedusa=1;
					}
				}
				StatuillasNombres[seleccionEstatuillaDisponibleJugador1-1]= to_string(seleccionEstatuillaDisponibleJugador1)+") No disponible";
			}

			
			if (resultado == 1 && Statuillas[jugadorActual - 1][2] == 1 && contadorEstatuillasDisponibles > 0) {
				maldicionMedusa = true;
				cout << "se activa Maldicion de medusa: " << maldicionMedusa << endl;
				contadorMedusa--;
				jugadorActual = jugadorMedusa;
			}
			
			if (maldicionMedusa && contadorEstatuillasDisponibles > 0) {
				contadorMedusa--;
				maldicionMedusa = false;
				jugadorActual = jugadorMedusa;
				for (int i = 0; i < 3; i++) {
					
					for (int i = 0; i < 5; i++) {
						cout << StatuillasNombres[i] << endl;
					}
					eligiendoEstatuillaJugado1(jugadorActual, jugador1, jugador2, seleccionEstatuillaDisponibleJugador1, Statuillas);
					seleccionEstatuilla(seleccionEstatuillaDisponibleJugador1);
					if( maldicionSalamandra  && jugadorActual == jugadorSalamandra){
						faExDados3(dado1,dado2,dado3, dados10Caras, jugador1 );
					}else{
						faExDados2(dado1,dado2, &dados10Caras, jugador1 );
					}
					cout << "dado1 " << dado1 << endl;
					cout << "dado2 " << dado2 << endl;
					cout << "dado3 " << dado3 << endl;
					resultado = ganoLaEstautilla(dado1, dado2, dado3, seleccionEstatuillaDisponibleJugador1);
					cout << "seleccion jugador: " << seleccionEstatuillaDisponibleJugador1 << endl;
					//colocacion de la verificacion en la matriz
					Statuillas [jugadorActual-1][seleccionEstatuillaDisponibleJugador1-1]=1;
					
					Statuillas [2][seleccionEstatuillaDisponibleJugador1-1]=1;
					//fin ncolocacion de la verificacion en la matriz
					
					
					
					//descuento de 3 puntos al otro jugador si gana estatuilla
					if(resultado && jugadorActual==1){
						puntosRestarJugador2-=3;
						cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador2<<endl;
						
					}
					if(resultado && jugadorActual==2){
						puntosRestarJugador1-=3;
						cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador1<<endl;
					}
					//fin de resta de puntos
					
					
					
					
					
					//maldicion salamandra
					if (resultado == 1 && Statuillas[jugadorActual - 1][4] == 1 && contadorEstatuillasDisponibles > 0) {
						maldicionSalamandra = true;
						cout << "se activa Maldicion de Salamandra: " << endl;
						if( jugadorActual==1 ){
							jugadorSalamandra=2;
						}else{
							jugadorSalamandra=1;
						}
					}
					
					//termina salamandra
					//maldicion cangrejo
					
					if (resultado == 1 && Statuillas[jugadorActual - 1][0] == 1 && contadorEstatuillasDisponibles > 0 && maldicionCangrejo) {
						maldicionCangrejo = false;
						cout << "se activa Maldicion de Cangrejo Tire un Dado de diez cara y se le descontara al final de la partida: " << endl;
						cout<<"El rival debe Tirar un dado PorFavor lanze el Dado: "<<endl;
						faExMaldicionCangrejo(PuntosDescuentoMaldicionCangrejo, &dados10Caras, jugador1 );
						cout<<"Puntos que se le descontaran: "<<PuntosDescuentoMaldicionCangrejo<<endl;
					}
					
					
					//maldicion cangrejo
					
					//maldicion hormiga
					if (resultado == 1 && Statuillas[jugadorActual - 1][1] == 1 && maldicionHormiga ) {
						maldicionHormiga = false;
						cout << "se activa Maldicion de Hormiga Tire Dos Dados de diez cara y se le descontara al portador de la estautilla al final de la partida: " << endl;
						cout<<"El rival debe Tirar dos dados PorFavor lanze los dados: "<<endl;
						faExMaldicionHormiga(dadoHormiga, &dados10Caras,jugador1);
						cout<<"Puntos que se le descontaran: "<<dadoHormiga<<endl;
						Statuillas[2][seleccionEstatuillaDisponibleJugador1 - 1] = 1;
						StatuillasNombres[seleccionEstatuillaDisponibleJugador1 - 1] = to_string(seleccionEstatuillaDisponibleJugador1) + ") No disponible";
					}
					
					//Termina maldicion hormiga
					
					
					
					
					
					
					
					
					
					if (resultado == 1) {
						Statuillas[jugadorActual - 1][seleccionEstatuillaDisponibleJugador1 - 1] = 1;
						if (Statuillas[jugadorActual - 1][2] == 1) {
							
						}
						Statuillas[2][seleccionEstatuillaDisponibleJugador1 - 1] = 1;
						StatuillasNombres[seleccionEstatuillaDisponibleJugador1 - 1] = to_string(seleccionEstatuillaDisponibleJugador1) + ") No disponible";
						
						cout << "estautillanombre de la seleccion: " << Statuillas[jugadorActual - 1][seleccionEstatuillaDisponibleJugador1 - 1] << endl;
						cout << "numero de la seleccion del jugador: " << seleccionEstatuillaDisponibleJugador1 - 1 << endl;
						contadorEstatuillasDisponibles--;
					}
					
					if( contadorEstatuillasDisponibles==0){
						break;
					}
				}
			}
			
//maldicion AGUILA
			
			if (Statuillas[jugadorActual - 1][3] == 1 && contadorEstatuillasDisponibles > 0) {
				cout << "ACTIVA MALDICION AGUILA: " << endl;
				
			
				if (jugadorActual == 1) {
					jugadorActual = 2;
				} else {
					jugadorActual = 1;
				}
				
				for (int i = 0; i < 2; i++) {

	//solo muestra las estuillas disponibles
					for (int i = 0; i < 5; i++) {
						cout << StatuillasNombres[i] << endl;
					}

					
					eligiendoEstatuillaJugado1(jugadorActual, jugador1, jugador2, seleccionEstatuillaDisponibleJugador1, Statuillas);
					seleccionEstatuilla(seleccionEstatuillaDisponibleJugador1);
					
					if( maldicionSalamandra  && jugadorActual == jugadorSalamandra){
						faExDados3(dado1,dado2,dado3, dados10Caras, jugador1 );

					}else{
						faExDados2(dado1,dado2, &dados10Caras, jugador1 );
					}
					
					
					cout << "dado1 " << dado1 << endl;
					cout << "dado2 " << dado2 << endl;
					if(dado3 >0){
					cout << "dado3 " << dado3 << endl;}
					
					
					resultado = ganoLaEstautilla(dado1, dado2, dado3, seleccionEstatuillaDisponibleJugador1);
					Statuillas [jugadorActual-1][seleccionEstatuillaDisponibleJugador1-1]=1;
					Statuillas [2][seleccionEstatuillaDisponibleJugador1-1]=1;
					if(resultado){
						contadorEstatuillasDisponibles--;
					}
					if(contadorEstatuillasDisponibles==0){
						i=2;
					}
					if (resultado == 1) {
						Statuillas[jugadorActual - 1][seleccionEstatuillaDisponibleJugador1 - 1] = 1;}

	//descuento de 3 puntos al otro jugador si gana estatuilla
					if(resultado && jugadorActual==1){
						puntosRestarJugador2-=3;
						cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador2<<endl;
						
					}
					if(resultado && jugadorActual==2){
						puntosRestarJugador1-=3;
						cout<<"Usted HA perdido 3 puntos para la fase final: "<< jugador1<<endl;
					}
	//fin de resta de puntos
					cout<<"cantidad de estatuilla: "<< contadorEstatuillasDisponibles<<endl;
					
					
					
					
					if(resultado == 1 && Statuillas[jugadorActual - 1][0] == 1 && maldicionCangrejo){
						cout << "se activa Maldicion de Cangrejo 257" << endl;
					}
					
					cout << "seleccion jugador: " << seleccionEstatuillaDisponibleJugador1<<" jugador actual "<<jugadorActual << endl;
	//cangrejo
					
					if (resultado == 1 && Statuillas[jugadorActual - 1][0] == 1 && maldicionCangrejo) {
						maldicionCangrejo = false;
						cout << "se activa Maldicion de Cangrejo Tire un Dado de diez cara y se le descontara al final de la partida: " << endl;
						cout<<"El rival debe Tirar un dado PorFavor lanze el Dado: "<<endl;
						faExMaldicionCangrejo(PuntosDescuentoMaldicionCangrejo, &dados10Caras, jugador1 );
						cout<<"Puntos que se le descontaran: "<<PuntosDescuentoMaldicionCangrejo<<endl;
					}
	//cangrejo
					
					cout << "Dentro del for 250: " << endl;
					
	//maldicion salamandra
					if (resultado == 1 && Statuillas[jugadorActual - 1][4] == 1 && contadorEstatuillasDisponibles > 0) {
						maldicionSalamandra = true;
						cout << "se activa Maldicion de Salamandra: " << endl;
						if( jugadorActual==1  && contadorEstatuillasDisponibles > 0){
							jugadorSalamandra=2;
						}else{
							jugadorSalamandra=1;
						}
					}
					
					//termina salamandra
					//maldicion cangrejo
				
			
					//maldicion hormiga
					if (resultado == 1 && Statuillas[jugadorActual - 1][1] == 1 && maldicionHormiga ) {
						maldicionHormiga = false;
						cout << "se activa Maldicion de Hormiga Tire Dos Dados de diez cara y se le descontara al portador de la estautilla al final de la partida: " << endl;
						cout<<"El rival debe Tirar dos dados PorFavor lanze los dados: "<<endl;
						faExMaldicionHormiga(dadoHormiga, &dados10Caras,jugador1);
						cout<<"Puntos que se le descontaran: "<<dadoHormiga<<endl;
						
					}
					
					//Termina maldicion hormi
					
					
					if (resultado == 1) {
						Statuillas[jugadorActual - 1][seleccionEstatuillaDisponibleJugador1 - 1] = 1;
						if (Statuillas[jugadorActual - 1][2] == 1) {
							
						}
						Statuillas[2][seleccionEstatuillaDisponibleJugador1 - 1] = 1;
						StatuillasNombres[seleccionEstatuillaDisponibleJugador1 - 1] = to_string(seleccionEstatuillaDisponibleJugador1) + ") No disponible";
						
						cout << "estautillanombre de la seleccion: " << Statuillas[jugadorActual - 1][seleccionEstatuillaDisponibleJugador1 - 1] << endl;
						cout << "numero de la seleccion del jugador: " << seleccionEstatuillaDisponibleJugador1 - 1 << endl;
				
						
						if (maldicionMedusa && contadorEstatuillasDisponibles > 0) {
							contadorMedusa--;
							maldicionMedusa = false;
							jugadorActual = jugadorMedusa;
							cout<<"--------------------------------------------------------------------------------"<<endl;
						}
					}
					
				}
			}
			
			
			
			
			
			
			if (resultado == 1 && Statuillas[jugadorActual - 1][4] == 1 && contadorEstatuillasDisponibles > 0) {
				maldicionSalamandra = true;
				cout << "se activa Maldicion de Salamandra: " << endl;
				if( jugadorActual==1 ){
					jugadorSalamandra=2;
				}else{
					jugadorSalamandra=1;
				}
			}
			
			
			if (resultado == 1 && Statuillas[jugadorActual - 1][0] == 1 && maldicionCangrejo) {
				maldicionCangrejo = false;
				cout << "se activa Maldicion de Cangrejo Tire un Dado de diez cara y se le descontara al final de la partida: " << endl;
				cout<<"El rival debe Tirar un dado PorFavor lanze el Dado: "<<endl;
				faExMaldicionCangrejo(PuntosDescuentoMaldicionCangrejo, &dados10Caras, jugador1 );
				cout<<"Puntos que se le descontaran: "<<PuntosDescuentoMaldicionCangrejo<<endl;
			}
			
			//maldicion hormiga
			if (resultado == 1 && Statuillas[jugadorActual - 1][1] == 1 && maldicionHormiga ) {
				maldicionHormiga = false;
				cout << "se activa Maldicion de Hormiga Tire Dos Dados de diez cara y se le descontara al portador de la estautilla al final de la partida: " << endl;
				cout<<"El rival debe Tirar dos dados PorFavor lanze los dados: "<<endl;
				faExMaldicionHormiga(dadoHormiga, &dados10Caras,jugador1);
				cout<<"Puntos que se le descontaran: "<<dadoHormiga<<endl;
			}
			
			//Termina maldicion hormiga
			
			
	
			

		
		if( jugadorActual==1 ){
			jugadorActual=2;
		}else{
			jugadorActual=1;
		}

				cout<<"hay "<< contadorEstatuillasDisponibles<< " Disponibles"<<endl;
				
				

		//fin del while
		for(int i=0 ; i<5; i++){
			cout<< StatuillasNombres[i]<<endl;
		
		}
		
		}
		
	}
	
	
	
//	
	
	
	cout<<"---------------------------------------------"<<endl;
	
	
	
	
	if(contadorEstatuillasDisponibles==0){
	bool primeraEntrada=true;
	int puntosFinalRestaJugado1=0;
	int puntosFinalRestaJugado2 = 0;
	bool ganaLaPartida= true;
	cout<<"Bienvenido a la Fase Final"<<endl;
		while(ganaLaPartida){
			//ganar la partida
				int dado1=0;
				int dado2=0;
				int dado3=0;
				int dado4=0;
				int dado5=0;
				int acumuladorJugado1=0;
				int acumuladorJugado2=0;
				int vectorDados[5];
				
				cout<< "jugador1----- "<< jugador1<< Statuillas [1][5]<<"estatuillas"<<endl;
				cout<< "jugador2 ----"<< jugador2<< Statuillas [0][5]<<"estatuillas"<<endl;
				
				
				
				
						if(Statuillas [0][0]==1){
							acumuladorJugado1++;
							cout<< "Usted ha ganado la estatuilla de Cangrejo"<< jugador1<<endl;
						}
						if(Statuillas [0][1]==1){
							acumuladorJugado1++;
							cout<< "Usted ha ganado la estatuilla de Hormiga"<< jugador1<<endl;
						}
						if(Statuillas [0][2]==1){
							acumuladorJugado1++;
							cout<< "Usted ha ganado la estatuilla de Medusa"<< jugador1<<endl;
						}
						if(Statuillas [0][3]==1){
							acumuladorJugado1++;
							cout<< "Usted ha ganado la estatuilla de Aguila"<< jugador1<<endl;
						}
						if(Statuillas [0][3]==1){
							acumuladorJugado1++;
							cout<< "Usted ha ganado la estatuilla de Salamadra"<< jugador1<<endl;
						}
					
					
				
				
						
						if(Statuillas [1][0]==1){
							acumuladorJugado2++;
							cout<< "Usted ha ganado la estatuilla de Cangrejo "<< jugador2<<endl;
						}
						if(Statuillas [1][1]==1){
							acumuladorJugado2++;
							cout<< "Usted ha ganado la estatuilla de Hormiga "<< jugador2<<endl;
						}
						if(Statuillas [1][2]==1){
							acumuladorJugado2++;
							cout<< "Usted ha ganado la estatuilla de Medusa "<< jugador2<<endl;
						}
						if(Statuillas [1][3]==1){
							acumuladorJugado2++;
							cout<< "Usted ha ganado la estatuilla de Aguila "<< jugador2<<endl;
						}
						if(Statuillas [1][3]==1){
							acumuladorJugado2++;
							cout<< "Usted ha ganado la estatuilla de Salamadra "<< jugador2<<endl;
						}

				
				
				
				if(acumuladorJugado1>acumuladorJugado2 && primeraEntrada){
					jugadorActual=1;
					primeraEntrada=false;
				}else{
					jugadorActual=2;
					primeraEntrada=false;
				}
				
				
				if( jugadorActual==1 && !primeraEntrada ){
					jugadorActual=2;
				}else{
					jugadorActual=1;
				}
				faExDados5(dado1,dado2, dado3, dado4,dado5, &dados10Caras,jugador1);
				
				
				vectorDados[0]=dado1;
				vectorDados[1]=dado2;
				vectorDados[2]=dado3;
				vectorDados[3]=dado4;
				vectorDados[4]=dado5;
					for (int i = 0; i < 25 - 1; i++) {
						if (vectorDados[i] > vectorDados[i + 1]) {
							// Intercambiar elementos
							int temp = vectorDados[i];
							vectorDados[i] = vectorDados[i + 1];
							vectorDados[i + 1] = temp;
						}
					}
				
				if ((vectorDados[0] == 1 && vectorDados[1] == 2 && vectorDados[2] == 3 && vectorDados[3] == 4 && vectorDados[4] == 5) 

					
					
					
					
					) {
					cout << "Ganó la Fase Final: " << jugadorActual<<endl;
					ganaLaPartida=false;
					
				}
					
				//salamandra
					
					if(Statuillas [jugadorActual-1][4]==1){
						if( vectorDados[0]==1 && vectorDados[1]==2 && vectorDados[2]==3 &&vectorDados[3]==4||
						   vectorDados[0]==2 && vectorDados[1]==3 && vectorDados[2]==4 &&vectorDados[3]==5
						   )
							{
								cout << "Ganó la Fase Final: " << jugadorActual<<endl;
								ganaLaPartida=false;
							}
						}
						
					//medusa
					
						if(Statuillas [jugadorActual-1][2]==1){
							if(dado1==dado2 && dado2==dado3 && dado3==dado4 && dado4==dado5){
								cout << "Ganó la Fase Final: " << jugadorActual<<endl;
									ganaLaPartida=false;
								}
						}
					

						
						if(ganaLaPartida==true){
							if(jugadorActual==1){
								cout<<"se le resta 1 punto"<<endl;
								puntosFinalRestaJugado1++;
							}
							if(jugadorActual==2){
								cout<<"se le resta 1 punto"<<endl;
								puntosFinalRestaJugado2++;
							}
						}

					}


				}
	

	}while(selecionMenuPrincial != 4);	
	return 0;
}


