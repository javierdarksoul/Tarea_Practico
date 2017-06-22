#ifndef CAS_H
#define CAS_H
typedef struct nodo{
    char val;
    struct nodo *w;
    struct nodo *d;
    struct nodo *s;
    struct nodo *a;

}nodo;
void bienvenida(){
	for(int x=0;x<20;x++){
		for(int y=0;y<20;y++){
			printf("*");
		}
		printf("\n");
	}
}

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
nodo* generar_posicion(nodo *k,char c){
	if(c=='w'){
		(k->w)->val='#';
		return k->w;
	}
	else if(c=='d'){
		(k->d)->val='#';
		return k->d;
	}
	else if(c=='s'){
		(k->s)->val='#';
		return k->s;
	}
	else if(c=='a'){
		(k->a)->val='#';
		return k->a;
	}
	
	
}
nodo* generar_direccion(nodo *k, nodo **j,char c, int n, int m){
	if(c=='w'){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(&j[x][y]==k){
				if(x==0){
					(&j[n-1][y])->val='x';
					return(&j[n-1][y]);
				}
				else{
					(&j[x-1][y])->val='x';
					return(&j[x-1][y]);
				}
				
			}
		}
	}
	}
	else if(c=='a'){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(&j[x][y]==k){
					if(y==0){
						(&j[x][m-1])->val='x';
						return(&j[x][m-1]);
					}
					else{
						(&j[x][y-1])->val='x';
						return(&j[x][y-1]);
					}
					
				}
			}
		}
	}
	else if(c=='d'){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(&j[x][y]==k){
					if(y==m-1){
						(&j[x][0])->val='x';
						return(&j[x][0]);
					}
					else{
						(&j[x][y+1])->val='x';
						return(&j[x][y+1]);
					}
					
				}
			}
		}
	}
	else if(c=='s'){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(&j[x][y]==k){
					if(x==n-1){
						(&j[0][y])->val='x';
						return(&j[0][y]);
					}
					else{
						(&j[x+1][y])->val='x';
						return(&j[x+1][y]);
					}
					
				}
			}
		}
	}

	
}
void limpiar_casilla(nodo *t){
	int g=0;
	if(t->a==NULL){
		g=g+1;
	}
	if(t->w==NULL){
		g=g+1;
	}
	if(t->d==NULL){
		g=g+1;
	}
	if(t->s==NULL){
		g=g+1;
	}
	if(g<4){
		t->val='O';
	}
	else{
		
		t->val=' ';
	}
	
}
void agregar_tierra(nodo *k,nodo *t,char c){
	int g=0;
	if(t->a==NULL){
		g=g+1;
	}
	if(t->w==NULL){
		g=g+1;
	}
	if(t->d==NULL){
		g=g+1;
	}
	if(t->s==NULL){
		g=g+1;
	}

	if(g>=2){
		if(c=='w'){
			t->w=k->w;
			(k->w)->s=t;
			k->w=t;
			t->s=k;
		}
		else if(c=='d'){
			t->d=k->d;
			(k->d)->a=t;
			k->d=t;
			t->a=k;
		}
		else if(c=='s'){
			t->s=k->s;
			(k->s)->w=t;
			k->s=t;
			t->w=k;
		}
		else if(c=='a'){
			t->a=k->a;
			(k->a)->d=t;
			k->a=t;
			t->d=k;
		}
		
	}
	else{
		printf("%s\n","la tierra escogida ya esta agregada " );
		printf("presione cualquier tecla para volver a intentar...\n");
		system("pause");
	}
}
void eliminar_tierra(nodo *t){
	nodo* arriba=t->w;
	nodo* abajo=t->s;
	nodo* izquierda=t->a;
	nodo* derecha=t->d;
	izquierda->d=derecha;
	derecha->a=izquierda;
	abajo->w=arriba;
	arriba->s=abajo;
	t->w=NULL;
	t->a=NULL;
	t->d=NULL;
	t->s=NULL;
	
}
void imprimir_matriz(nodo **k,int n, int m){
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			printf("%c",(&k[x][y])->val);
			if(y!=m-1){
				if((&k[x][y])->d==	&k[x][y+1]){
				printf("%s","-");
				}
				else{
					printf(" ");
				}
			}	
		}
		printf("\n" );
		if(x!=n-1){
			for(int j=0;j<m;j++){
				if((&k[x][j])->s==&k[x+1][j]){
				printf("%s","| ");
				}
				else{
					printf("  ");
				}
			}
		}	
		printf("\n" );
		
	}
}
#endif
