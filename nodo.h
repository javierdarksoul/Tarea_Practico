#ifndef NODO_H
#define NODO_H

int max(int a, int b){
    return a>b? a : b;
}

typedef struct nodo{
    int val;
    struct nodo *izq;
    struct nodo *der;
}nodo;




nodo* crear_nodo(int val){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->val = val;
    n->izq = NULL;
    n->der = NULL;
    return n;
}
int absolute(int f){
    if (f>0){
        return f;
    }
    else{
        f=-1*f;
        return f;
    }

}
int unhijo(nodo *r){
    if(r->izq!=NULL){
        if(r->der==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(r->izq==NULL){
        if(r->der!=NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int eshoja(nodo *r){
    if(r->izq == NULL && r->der == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
nodo* nodoanterior(nodo **r,nodo *j){
    if(j==*r){
        return NULL;
    }

    else if((*r)->der==j || (*r)->izq==j){
        return *r;
    }
    else{
        if(j->val>(*r)->val){
            nodoanterior(&(*r)->der,j);
        }
        else{
            nodoanterior(&(*r)->izq,j);
        }
    }
}

void imprimir(nodo *r, int depth, int *padres){
    if(r != NULL){
        printf("(%i)", r->val);
        char buf[512] = "  ";
        for(int i=0; i<depth; ++i){
            if(padres[i] == 1){
                strcat(buf, " \t");
            }
            else{
                strcat(buf, "|\t");
            }
        }
        if(eshoja(r)){
            return;
        }
        //printf("\n%s|----", buf);
        printf("--", buf);
        padres[depth] = 0;
        imprimir(r->der, depth+1, padres);

        printf("\n%s|-----", buf);
        padres[depth] = 1;
        imprimir(r->izq, depth+1, padres);
    }
}

// (1)
void bst_insertar(nodo **r, int val){

    if((*r)==NULL){
       
        (*r)=crear_nodo(val);
    }
    else{
        if((*r)->val>val){
            // nodo *j=(*r)->der;
             bst_insertar(&(*r)->izq,val);
        }
        else{
            
            bst_insertar(&(*r)->der,val);
        }
    }

}

// ((2)
nodo*bst_buscar(nodo **r, int val){ 
    if((*r)->val==val){
        return(*r);
    }
    else{
        if((*r)->val>val){
            bst_buscar(&(*r)->izq,val);
        }
        else{
            bst_buscar(&(*r)->der,val);
        }
    }
}

// (3)
void bst_eliminar(nodo **r,int val){
    nodo *j=bst_buscar((&(*r)),val);
    if(eshoja(j)==1){
        free(j);
    }
    else if(unhijo(j)==1){
        nodo *p=bst_buscar(&(*r),val);
        nodo *q=nodoanterior(&(*r),p);
        if(q->der==p){
            if(p->izq!=NULL){
                q->der=p->izq;
            }
            else{
                q->der=p->der;
            }
        }
        else{

            if(p->izq!=NULL){
                q->izq=p->izq;
            }
            else{
                q->izq=p->der;
            }

        }

    }
    else{
        nodo *p=bst_buscar(&(*r),val);
        nodo *q=nodoanterior(&(*r),p);
        nodo *b=p->der;
        if(q->izq==p){
            q->izq=p->der;
            while(b->izq!=NULL){
                b=b->izq;
            }
            b->izq=p->izq;
            free(p);

        }
        else{
            q->der=p->der;
             while(b->izq!=NULL){
                b=b->izq;
            }
            b->izq=p->izq;
            free(p);

        }

    }

}

// (5)
int altura(nodo *r){
    int alt=0;
    if(eshoja(r)==1){
        return alt;
    }
    else if(unhijo(r)==1){
        if(r->izq!=NULL){
            alt=altura(r->izq)+1;
        }
        else{
            alt=altura(r->der)+1;
        }       
    }
    else{

        alt=max(altura(r->izq),altura(r->der))+1;
        }   
}

// (6)
int bfactor(nodo *r){
    int c;
    int d;
    int e;
    if(eshoja(r)==1){
        return 0;
    }
    else if(unhijo(r)==1){
        if(r->izq!=NULL){
            c=altura(r->izq)+1;
            return c;
        }
        else{
            c=altura(r->der)+1;
            return c;
        }

    }
    else{
        c=altura(r->izq)+1;
        d=altura(r->der)+1;
        e=absolute(c-d);
        return e;
    }
    
}

// (7)
int arbol_balanceado(nodo *r){
    int c=1;
    int d=1;
    if(c==1){
        if(bfactor(r)>1){
        c=0;
        return c;
        }
        else if(eshoja(r)==1){
            return c;
        }   
        else if(unhijo(r)==1){
            if(r->izq!=NULL){
                c=arbol_balanceado(r->izq);
                return c;
            }
            else{
                c=arbol_balanceado(r->der);
                return c;
            }

        }
        else{

            c=arbol_balanceado(r->izq);
            d=arbol_balanceado(r->der);
            if(c==0 || d==0){
                c=0;
                return c;
            }
            else{
                return c;
            }
        }
    }
    else{
        return c;
    }
    
    
}

// (8)
void rot_der(nodo **r){
    nodo* b=(*r)->izq;
    (*r)->izq=b->der;
    b->der=(*r);
    (*r)=b;

    
}

// (8)
void rot_izq(nodo **r){
   //nodo* a=(*r);
   nodo* b=(*r)->der;
   (*r)->der=b->izq;
   b->izq=(*r);
   (*r)=b;
   
}

#endif
