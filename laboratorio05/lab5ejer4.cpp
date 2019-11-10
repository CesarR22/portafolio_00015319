#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{

int dato;
Nodo *right;
Nodo *left;
Nodo *MADRE;
	
};

void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
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
	int contador = 0;
	
	do{
		
		cout<<"\t:MENU:."<<endl;
		cout<<"1.Insertar un nuevo nodo"<<endl;
		cout<<"2.Mostrar el arbol completo"<<endl;
		cout<<"3.Eliminar un nodo del arbol"<<endl;
		cout<<"4.Saber si es un arbol binario"<<endl;
		cout<<"5.Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			
			case 1: cout<<"\nDigite numero para el arbol: ";
			        cin>>dato;
			        insertarNodo(arbol,dato,NULL);
			        cout<<"\n";
			        system("pause");
			        break;
			        
			case 2: cout<<"arbol completo: \n\n";
			        mostrarArbol(arbol,contador);
			        cout<<"\n";
			        system("pause");
			        break;
			        
			 case 3: cout<<"\nnumero a eliminar: ";
			         cin>>dato;       
			         eliminar(arbol,dato);
			         cout<<"\n";
			         system("pause");
			         break;
			         
			 case 4: if(arbol == NULL){
			 	         
			 	     cout<<"Error el arbol esta vacio, no puedo saber si es binario de busqueda"<<endl;
			         }
			            
			         else{
					
			         cout<<"El arbol si es binario de busqueda"<<endl;
			         }
			         system("pause");
					 break;      
			         
			case 5: break;
		}
		system("cls");
	}while(continuar);
}

Nodo *crearNodo(int n, Nodo *MADRE){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->right = NULL;
	nuevo_nodo->left = NULL;
	nuevo_nodo->MADRE = MADRE;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *MADRE){
	
	if(arbol == NULL){
		
		Nodo *nuevo_nodo = crearNodo(n,MADRE);
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

void eliminar(Nodo *arbol, int n){
	
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->left,n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->right,n);
	}
	else{
		eliminarNodo(arbol);
	}
}

Nodo *minimo(Nodo *arbol){
	if( arbol == NULL){
		return NULL;
	}
	if(arbol->left){
		return minimo(arbol->left);
	}
	else{
		return arbol;
	}
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->MADRE){
		if(arbol->dato == arbol->MADRE->left->dato){
			arbol->MADRE->left = nuevoNodo;
		}
		else if(arbol->dato == arbol->MADRE->right->dato){
			arbol->MADRE->right = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->MADRE = arbol->MADRE;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->left = NULL;
	nodo->right = NULL;
	
	delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar){
	
	if(nodoEliminar->left && nodoEliminar->right){
		Nodo *menor = minimo(nodoEliminar->right);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
		
	}
	
	else if(nodoEliminar->left){
		reemplazar(nodoEliminar,nodoEliminar->left);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->right){
		reemplazar(nodoEliminar,nodoEliminar->right);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
		
		
	}
	
	

}
