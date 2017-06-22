#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "casilla.h"
int main(int argc, char const *argv[])
{
	bienvenida();
	int bool=1;
	char f;
	char g='d';
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	nodo** l=generar_matriz(n,m);
	scanf("%i",&bool);
	nodo* i=&l[0][1];
	nodo* o =generar_posicion(i,'a');
	nodo* j=generar_direccion(o,l,g,n,m);

	
	while(bool==1){

		
		
		imprimir_matriz(l,n,m);
		scanf("%c",&f);

		if(f=='q'){
			eliminar_tierra(j);
			imprimir_matriz(l,n,m);
		}
		else if(f=='p'){
			bool=0;
		}
		else if(f=='e'){
			printf("entre al eliminar\n");
			agregar_tierra(o,j,g);
			imprimir_matriz(l,n,m);
		}
		else if(f==g){
			limpiar_casilla(j);
			limpiar_casilla(o);
			o=generar_posicion(o,f);
			j=generar_direccion(o,l,f,n,m);

			imprimir_matriz(l,n,m);
		}
		else if(f=='w'){
			printf("entre\n");
			limpiar_casilla(j);
			j=generar_direccion(o,l,f,n,m);
			g=f;
			
			imprimir_matriz(l,n,m);
			
			
		}
		else if(f=='a'){
			printf("entre\n");
			limpiar_casilla(j);
			j=generar_direccion(o,l,f,n,m);
			g=f;
			
			imprimir_matriz(l,n,m);
			
			
		}
		else if(f=='s'){
			limpiar_casilla(j);
			j=generar_direccion(o,l,f,n,m);
			g=f;
			
			imprimir_matriz(l,n,m);
			
			
		}
		else if(f=='d'){
			limpiar_casilla(j);
			j=generar_direccion(o,l,f,n,m);
			g=f;
			imprimir_matriz(l,n,m);
			
			
		}
		system("clear");
		fflush(stdin);
		
		

	}
	
}