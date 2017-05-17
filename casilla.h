#ifndef CAS_H
#define CAS_H
typedef struct nodo{
    char val;
    struct nodo *w;
    struct nodo *d;
    struct nodo *s;
    struct nodo *a;

}nodo;

nodo* crear_nodo(){
	nodo *n=(nodo *)malloc(sizeof(nodo));
	n->w=NULL;
	n->d=NULL;
	n->a=NULL;
	n->s=NULL;
	n->val='O';
	return n;

}

nodo** generar_matriz(int n, int m){

	nodo** k=(nodo **)malloc(sizeof(nodo*)*n);
	for(int i=0; i<n; i++){
		k[i]=(nodo *)malloc(sizeof(nodo)*m);
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			k[x][y]=*crear_nodo();
		}
	}
	conectar_nodos(k,n,m);
	return k;
}

void conectar_nodos(nodo** k,int n, int m){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(x==0){
				(&k[x][y])->s=&k[x+1][y];
				(&k[x][y])->w=&k[n-1][y];
				if(y!=0 && y!=m-1){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][y-1];					
				}
				else if(y==0){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][m-1];
				}
				else{
					(&k[x][y])->d=&(k[x][0]);
					(&k[x][y])->a=&(k[x][y-1]);
				}
			}
			else if(x==n-1){
				(&k[x][y])->s=&k[0][y];
				(&k[x][y])->w=&k[x-1][y];
				if(y!=0 && y!=m-1){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][y-1];					
				}
				else if(y==0){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][m-1];
				}
				else{
					(&k[x][y])->d=&k[x][0];
					(&k[x][y])->a=&k[x][y-1];
				}
			}
			else{
				(&k[x][y])->s=&k[x+1][y];
				(&k[x][y])->w=&k[x-1][y];
				if(y!=0 && y!=m-1){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][y-1];					
				}
				else if(y==0){
					(&k[x][y])->d=&k[x][y+1];
					(&k[x][y])->a=&k[x][m-1];
				}
				else{
					(&k[x][y])->d=&k[x][0];
					(&k[x][y])->a=&k[x][y-1];
				}
			}
		}
	}
}
void generar_posicion(nodo *k){
	k->val='#';
}
void generar_direccion(nodo *k){
	k->val='X';
}
void limpiar_casilla(nodo *k){
	k->val='O';
}
void eliminar_tierra(nodo *k,nodo *t){
	if(k->w==t){
		printf("%s\n","si entre" );
		k->w=t->w;
		(t->w)->s=k;
		t->w=NULL;
		t->s=NULL;
	}
}
void imprimir_matriz(nodo **k,int n, int m){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			printf("%c",(&k[x][y])->val);
			if(y!=m-1){
				if((&k[x][y])->d==&k[x][y+1]){
				printf("%s","-");
				}
			}
			
		}
		printf("\n" );
		if(x!=n-1){
			for(int j=0;j<m;j++){
				if((&k[x][j])->s==&k[x+1][j]){
				printf("%s","| ");
				}
			}
		}
		
		printf("\n" );
		
	}
}
#endif
