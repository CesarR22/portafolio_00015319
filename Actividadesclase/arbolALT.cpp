#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{

int ALT;
int valor;
Nodo *left = NULL;
Nodo *right = NULL;		
};

Nodo *raiz = NULL;
Nodo *madre = NULL;

void buscarcolocar(Nodo *pase, int valorc, Nodo *nvo){
	
	if(pase!=NULL){
		if(valorc < pase->valor && pase -> left==NULL){
			
			pase->left = nvo;
			nvo->ALT = pase->ALT+1;
			return;
		}
		if(valorc > pase->valor && pase -> right==NULL){
			pase->right = nvo;
			nvo->ALT = pase->ALT+1;
			return;
		}
		if(valorc < pase->valor && pase -> left!=NULL){
			buscarcolocar(pase -> left, valorc, nvo);
			return;
		}
		if(valorc > pase->valor && pase -> right!=NULL){
			buscarcolocar(pase -> right, valorc, nvo);
			return;
		}
	}
}

void mostrar(Nodo *madrecin){
	if(madrecin!=NULL){
		mostrar(madrecin->left);
		cout<<"La ALT del nodo: "<<madrecin->valor<<" "<<"es: "<<" "<<madrecin->ALT<<endl;
		mostrar(madrecin->right);
		
	}
}

void  ingresar(int valorcin){
	
	Nodo *nvoo= new Nodo();
	nvoo->valor=valorcin;
	if(raiz == NULL){
		raiz = nvoo;
		raiz->ALT=0;
	}
	else{
	
	buscarcolocar(raiz,valorcin, nvoo);	
	}
}

int maximaALT(int a1_left , int a2_right){
	
	if(a1_left>a2_right){
		return a1_left;
	}
	else{
		return a2_right;
	}
	
}

int ALTArbol(Nodo *madre){
	if(madre==NULL){
		return 0;
	}
	else{
		return(1+maximaALT(ALTArbol(madre->left),ALTArbol(madre->right)));
	}
	
}




int main (void){
	
	ingresar(68);
	ingresar(34);
	ingresar(21);
	ingresar(43);
	ingresar(96);
	ingresar(75);
	ingresar(99);
	mostrar(raiz);		
	
	int ALTDelArbol=ALTArbol(raiz);
	cout<<"\n"<<"La ALT del arbol es: "<<ALTDelArbol;
		
	
	
	
	return 0;
}
