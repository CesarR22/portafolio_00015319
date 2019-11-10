#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{

int dato;
Nodo *right;
Nodo *left;
Nodo *madre;
	
};

void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
void delete(Nodo *, int);
void deleteNodo(Nodo *);
Nodo *menor(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;

int main(void){
	
	menu();
	
	
	
	return 0;
}

void menu(){
	
	int dato;
	int opcion;
	bool continuar = true;
	int cont = 0;
	
	do{
		
		
		cout<<"1.Insertar nodo"<<endl;
		cout<<"2.Mostrar el arbol"<<endl;
		cout<<"3.delete un nodo del arbol"<<endl;
		cout<<"4.Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			
			case 1: cout<<"\nDigite un numero: ";
			        cin>>dato;
			        insertarNodo(arbol,dato,NULL);
			        cout<<"\n";
			        system("pause");
			        break;
			        
			case 2: cout<<"Mostrando  arbol: \n\n";
			        mostrarArbol(arbol,cont);
			        cout<<"\n";
			        system("pause");
			        break;
			        
			 case 3: cout<<"\nDigite el numero a delete: ";
			         cin>>dato;       
			         delete(arbol,dato);
			         cout<<"\n";
			         system("pause");
			         break;
			         
			case 4: break;
		}
		system("cls");
	}while(continuar);
}

Nodo *crearNodo(int n, Nodo *madre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->right = NULL;
	nuevo_nodo->left = NULL;
	nuevo_nodo->madre = madre;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *madre){
	
	if(arbol == NULL){
		
		Nodo *nuevo_nodo = crearNodo(n,madre);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->left,n,arbol);
		}
		else{
			insertarNodo(arbol->right,n,arbol);
		}
		
		
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->right, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"    ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->left,cont + 1);
	}
}

void delete(Nodo *arbol, int n){
	
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		delete(arbol->left,n);
	}
	else if(n > arbol->dato){
		delete(arbol->right,n);
	}
	else{
		deleteNodo(arbol);
	}
}

Nodo *menor(Nodo *arbol){
	if( arbol == NULL){
		return NULL;
	}
	if(arbol->left){
		return menor(arbol->left);
	}
	else{
		return arbol;
	}
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->madre){
		if(arbol->dato == arbol->madre->left->dato){
			arbol->madre->left = nuevoNodo;
		}
		else if(arbol->dato == arbol->madre->right->dato){
			arbol->madre->right = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->madre = arbol->madre;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->left = NULL;
	nodo->right = NULL;
	
	delete nodo;
}

void deleteNodo(Nodo *nododelete){
	
	if(nododelete->left && nododelete->right){
		Nodo *menor = menor(nododelete->right);
		nododelete->dato = menor->dato;
		deleteNodo(menor);
		
	}
	
	else if(nododelete->left){
		reemplazar(nododelete,nododelete->left);
		destruirNodo(nododelete);
	}
	else if(nododelete->right){
		reemplazar(nododelete,nododelete->right);
		destruirNodo(nododelete);
	}
	else{
		reemplazar(nododelete,NULL);
		destruirNodo(nododelete);
		
		
	}
	
	

}
