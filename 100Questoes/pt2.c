#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;


//1.
int length(LInt l){
	int count = 0;

	while(l != NULL){
		count++;
		l = l->prox;
	}
	return count;
}

//2.
void freeL(LInt l){
	LInt list;

	while(l != NULL){
		list = l->prox;
		free(l);
		l = list;
	}

}

//3.
void imprimeL(LInt l){

	while(l != NULL){
		printf("%d\n", l->valor);
		l = l->prox;
	}
}

//4.
LInt reverseL(LInt l){
	LInt front, back = NULL;

	while(l) {
		front = l->prox;
		l->prox = back;
		back = l;
		l = front;
	}

	return back;
}

//5.
void insertOrd (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new -> valor = x;
    new -> prox = NULL;
    LInt prev = NULL;
    for(;*l && (*l) -> valor < x; l = &((*l) -> prox));
    if(prev){
        new -> prox = (*l);
        prev -> prox = new;
    }
    else {
        new -> prox = (*l);
        *l = new;
    }
}

//6.
int removeOneOrd (LInt *l, int x){
    int a = 1;
    for(; j-> valor < x; l =&((*l)->prox);
    
    if(*l && (*l)-> valor == x){
        a = 0;
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    return a;
}



//7.
void merge (LInt *r, LInt a, LInt b){
    
    while(a!= NULL || b!= NULL){
        
        if( (a!=NULL && b!=NULL && a->valor < b->valor) || b == NULL){
            
            *r = a;
            a = a->prox;
            
        } else {
            
            *r = b;
            b = b-> prox;
        }
        r = &((*r)->prox);
    } 
    *r = NULL;
}

//8. parte a lista l em duas
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(l == NULL) return;
    if(l->valor < x){
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox,x, &((*mx) -> prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox,x, mx, &((*Mx) -> prox));
    }
}


//9.
LInt parteAmeio (LInt *l){
    int i;
    int meio = length(*l)/2;
    if (meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for(i = 0; i < meio; i++){
        prev = (*l);
        (*l) = (*l) -> prox;
    }
    prev -> prox = NULL;
    return y;
}

//10.
int removeAll (LInt *l, int x){
    int rem = 0;
    LInt prev = NULL;
    
    while(*l){
        if((*l)-> valor == x){
            if(prev == NULL) (*l) = (*l) -> prox;
            else prev->prox = (*l) -> prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

//11.
int removeDups(LInt *l){
	int count = 0;

	for(; *l ; l = (&(*l)->prox) ){
		LInt anterior = (*l);
		LInt seguinte = (*l)->prox;
		for(; seguinte; seguinte = anterior -> prox){
		    if(seguinte -> valor == (*l) -> valor){
		        count++;
		        anterior -> prox = seguinte -> prox;
		        free(seguinte);
		    }
		    else anterior = seguinte;
		}
	}	
	return count;
}

//12. 
int removeMaiorL (LInt *l){
    LInt ant = NULL;
    LInt mant = NULL;
    LInt aux = *l;
    LInt maxl = *l;
    
    int maiorv = 0;
    
    for(;aux; aux = aux->prox){
        if(aux->valor > maiorv){
            mant = ant;
            maiorv = aux->valor;
            maxl = aux;
            
        }
        ant = aux;
    }
    if(mant==NULL) (*l) = (*l) -> prox;
    else mant->prox = maxl -> prox;
    
    return maiorv;
}

//13.
void init(LInt *l){

	while( (*l)->prox )
		l = &(*l)->prox;
	
	free(*l);
	*l = NULL;
}

//14.
void appendL(LInt *l, int x){

	while( *l )
		l = &(*l)->prox;
    
    *l = malloc(sizeof(struct lligada));
	(*l)->valor = x;
	(*l)->prox = NULL;
}


//15.
void concatL (LInt *a, LInt b){

	while( *a )
		a = &( (*a)->prox );

	(*a) = b;
}

//16.
LInt cloneL (LInt l){
	LInt new_list;
	LInt *sitio;

	sitio = &new_list;

	while( l ){
		*sitio = malloc(sizeof(struct lligada));
		(*sitio)->valor = l->valor;
		l = l->prox;
		sitio = &( (*sitio)->prox );
	}

	*sitio = NULL;

	return new_list;
}

//17. rever este exercício
LInt cloneRev (LInt l) {
    LInt new = NULL, list = NULL;

    for (; l; l = l->prox) {
        new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
    }
    
    return list;
}

//18.
int maximo(LInt l){
	int maior = l->valor;

	while(l){
		if(l->valor > maior)
			maior = l->valor;
		l = l->prox;
	}
			


	return maior;
}

//19.
int take(int n, LInt *l){
	int i = 0;

	while( i < n && *l ){
		l = &(*l)->prox;
		i++;
	}

	if(!(*l))
		return i;
	
	while(*l){
		LInt temp = (*l)->prox;
		free(*l);
	    *l = temp;
	}

	return n;
}


//20.
int drop(int n, LInt *l){

	if(!(*l))
		return 0;

    int i = 0;
	while(i < n && (*l) ){
		LInt temp = (*l);
		*l = (*l)->prox;
		free(temp);
		i++;
	}

	return i;
}

//21.
LInt NForward(LInt l, int N){
	LInt aux = l;
	int i = 0;

	while(i != N){
		aux = aux->prox;
		i++;
	}

	return aux;
}

//22.
int listToArray(LInt l, int v[], int N){
	int i;

	for( i=0; i < N && l; i+=1, l = l->prox )
		v[i] = l->valor;


	return i;
}

//23.
LInt arrayToList(int v[], int N){
	LInt head;
	LInt *r = &head;
	int i;

	for(i=0; i < N; i++){
		*r = malloc(sizeof(struct lligada));
		(*r)->valor = v[i];
		r = &(*r)->prox;
	}

	*r = NULL;
	return head;
}

//24.
LInt somasAcL(LInt l){
	LInt head;
	LInt *r = &head;

	int acc = 0;

	for(; l ; r = &(*r)->prox ){
		acc += l->valor;
		*r = malloc(sizeof(struct lligada));
		(*r)->valor = acc;
		l = l->prox;
	}

	*r = NULL;

	return head;
}

//25. ver melhor esta depois
void remreps (LInt l){
    for (; l; l = l->prox) {
        LInt *c = &(l->prox);
        while (*c && (*c)->valor == l->valor) {
            LInt temp = *c;
            *c = (*c)->prox;
            free(temp);
        }
    }
}

//26.
LInt rotateL(LInt l){
	
	if(!l || !(l->prox))
		return l;
	
	LInt aux = l;
	LInt head = l->prox;

	while(aux->prox)
		aux = aux->prox;

	aux->prox = l;
	l->prox = NULL;

	return head;
}

//27.
LInt parte (LInt l){
    LInt head, *p = &head, *i = &l;
    int j;
    for (j = 1; *i; j++) {
        if (!(j%2)) {
            *p = *i;
            *i = (*i)->prox;
            p = &(*p)->prox;
           
        }
        else 
            i = &(*i)->prox;
    }
    *p = NULL;
    return head;
}

// Binary Trees
typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

//28.
int maximo(int a, int b){
	int r;

	if(a>=b)
		r = a;
	else
		r = b;

	return r;
}

int altura (ABin a){
	int r = 0;

	if(!a)
		r = 0;
	else {
		r = 1 + maximo(altura(a->esq), altura(a->dir));
	}

	return r;
}

//29.
ABin cloneAB(ABin a){
	ABin r = a;

	if(!a){
		r = NULL;
	} else {
		r = malloc(sizeof(struct nodo));
		r->valor = a->valor;
		r->esq = cloneAB(a->esq);
		r->dir = cloneAB(a->dir);
	}

	return r;
}

//30.
void mirror(ABin *a){
	if(*a){
		ABin temp = (*a)->esq;
		(*a)->esq = (*a)->dir;
		(*a)->dir = temp;
		mirror(&(*a)->esq);
		mirror(&(*a)->dir);
	}
}

//31.
void inorder(ABin a, LInt *l){
	
	if(!a)
		*l = NULL;
	else {
		
		inorder(a->esq, l);
		
		while(*l)
			l = &(*l)->prox;

		*l = malloc(sizeof(struct nodo));
		(*l)->valor = a->valor;
		inorder(a->dir, &(*l)->prox);
	}
}	

//32.
void preorder(ABin a, LInt *l){

	if(!a)
		*l = NULL;
	else {
		*l = malloc(sizeof(struct nodo));
		(*l)->valor = a->valor; 
		preorder(a->esq, &(*l)->prox);
		while(*l)
        	l = &(*l)->prox;
		preorder(a->dir, l);
	}

}

//33.
void posorder(ABin a, LInt *l){

	if(a){
		posorder(a->esq, l);
		while(*l)
			l = &(*l)->prox;

		posorder(a->dir, l);
		while(*l)
			l = &(*l)->prox;

		*l = malloc(sizeof(struct nodo));
		(*l)->valor = a->valor;

		(*l)->prox = NULL;
	} else
		*l = NULL;
}

//34. versão do jbb
int min(int a, int b){
	int r = a;

	if(a < b)
		r = a;
	else 
		r = b;

	return r;
}

int depth(ABin a, int x){
	int e, d;

	if(a == NULL)
		return -1;
	
	if(a->valor == x)
		return 1;

	e = depth(a->esq, x);
	d = depth(a->dir, x);

	if(e == -1 && d == -1)
		return -1;

	if(e == -1)
		return d+1;

	if(d == -1)
		return e+1;

	return (1 + min(e,d));
}

//35.
int freeAB(ABin a){
	int r = 0;

    if(a){
	    r+= 1+ freeAB(a->esq) + freeAB(a->dir);
	    free(a);
	}

	return r;
}

//36.
int pruneAB(ABin *a, int l){
	int r = 0;
        
    if(!(*a))
        return r;
    else{
		if(l == 0){
			r+= 1 + pruneAB( &(*a)->esq, l) + pruneAB( &(*a)->dir, l);
			free(*a);
			*a = NULL;
		} else {
			r += pruneAB( &(*a)->esq, l-1);
			r += pruneAB( &(*a)->dir, l-1);
		}
	}

	return r;
}

//37.
int iguaisAB(ABin a, ABin b){
	int r = 0;  

	if(!a && b || a && !b)
		return 0;	// falso
	
	if(!a && !b || a == b) // ambos null ou ambos não null
	    return 1;	// verdade
	
	return a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    
}

//38. rever 
LInt concat(LInt a, LInt b) {
    if(!a)
    	return b;
    
    LInt temp = a;
    while(temp->prox) 
    	temp = temp->prox;
    
    temp->prox = b;
    return a;
}
 
LInt nivelL (ABin a, int n) {
    if(!a || n < 1) 
    	return NULL;
    
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    } else
    	return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));

} 


//39.
int nivelV(ABin a, int n, int v[]){
	int r = 0;

	if(!a || n < 1)
		return 0;
	
	if(n == 1){
		*v = a->valor;
		return 1;
	} else {
		int e = nivelV(a->esq, n-1, v);
		int d = nivelV(a->dir, n-1, v+e);
		return e+d;	
	}
}


//40.
int dumpAbin(ABin a, int v[], int N){

	if(!a || N < 0)
		return 0; 
	
	int e = dumpAbin(a->esq, v, N);
	if(e < N){
	    *(v+e) = a->valor;
	    return e + dumpAbin(a->dir, v + e +1, N -e-1) +1;
	} else 
    	 return N;

}

//41.
ABin somasAcA(ABin a){
	
	if(!a)
		return NULL;

	ABin novaAbin = malloc(sizeof(struct nodo));
	novaAbin->esq = somasAcA(a->esq);
	novaAbin->dir = somasAcA(a->dir);
	novaAbin->valor = a->valor + (novaAbin->esq ? novaAbin->esq->valor : 0) + (novaAbin->dir ? novaAbin->dir->valor : 0);


	return novaAbin;
}

//42.
int contaFolhas(ABin a){
	int r = 0;

	if(a){
	    if(!(a->esq) && !(a->dir))
	        r = 1;
	    else 
	        r = contaFolhas(a->esq) + contaFolhas(a->dir);
	}
	
	return r;
}

//43.
ABin cloneMirror(ABin a){
	if(!a)
		return NULL;	

	ABin new = malloc(sizeof(struct nodo));
	new->valor = a->valor;
	new->esq = cloneMirror(a->dir);
	new->dir = cloneMirror(a->esq);

	return new;
}

//44.
int addOrd(ABin *a, int x){
	int r = 0;

	while(*a && r != 1){
		if(x > (*a)->valor)
			a = &(*a)->dir;
		else if(x < (*a)->valor)
			a = &(*a)->esq;
		else
			r = 1;
	}

	if(r != 1){
		*a = malloc(sizeof(struct nodo));
		(*a)->valor = x;
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}


	return r;
}

//45.
int lookupAB(ABin a, int x){
	int r = 0; // falso

	while(a){
		if(x < a->valor)
			a = a->esq;
		else if(x > a->valor)
			a = a->dir;
		else
			return 1;
	}
	return r;
}

// forma recursiva
int lookupABrec(ABin a, int x){
	int r = 0;

	if(!a)
	    return r;

	if(a->valor == x)
		return 1;
	else if(a->valor > x)
		return lookupABrec(a->esq ,x);
	else
		return lookupABrec(a->dir, x);
}

//46.
int depthOrd(ABin a, int x){
	int r = 1;

	while(a){
		if(a->valor == x)
			return r;
		else if(a->valor < x){
			r++;
			a = a->dir;
		} else{
			r++;
			a = a->esq;
		}
	}

	return -1;
}
// forma recursiva
int depthOrdRec(ABin a, int x){
    int r = 1;

	if(!a)
		return -1;

	if(a->valor == x)
		return 1;

	if(a->valor < x)
		r = depthOrdRec(a->dir, x);
	else
		r = depthOrdRec(a->esq, x);


	return ( r==-1 ? r : 1+r);
}

//47.
int maiorAB(ABin a){
    while(a->dir)
        a = a->dir;
        
    return a->valor;
}
// forma recursiva
int maiorABrec(ABin a){
	if(a->dir)
		return maiorABrec(a->dir);
	else
		return a->valor;
}

//48.
void removeMaiorArec(ABin *a){
    
    if( (*a)->dir == NULL){
        ABin temp = (*a);
        free(*a);
        (*a) = temp->esq;
    } else {
        removeMaiorA( &(*a)->dir );
    }
}
// forma iterativa
void removeMaiorAite(ABin *a){
	while(*a && (*a)->dir)
		a = &(*a)->dir;

	ABin link = (*a)->esq;
	free(*a);
	(*a) = link;

}

//49.
int quantosMaiores(ABin a, int x){
	int r = 0;

	if(!a)
		return 0;

	if(a->valor > x)
		return r = 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
	else 
		return r = quantosMaiores(a->dir, x);
	
	return r;
}

//50. árvore em que os nodos à esquerda são todos NULL
void listToBTree(LInt l, ABin *a){
	while(l!=NULL){
		*a = malloc(sizeof(struct nodo));
		(*a)->valor = l->valor;
		(*a)->esq = NULL;	
		a = ( &(*a)->dir );
		l = l->prox;
	}

	*a = NULL;
}
