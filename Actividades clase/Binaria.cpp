
#include<iostream>
using namespace std;

float recibir (int x, int low,int high, int mid, int arreglo);

int main(){

int size=0;
int arreglo[8] = {1,3,4,5,17,18,31,33};
int low = 0;
int high = size - 1;
int i =  0 ;

cout<<"Ingrese un Numero: ";
cin>>i;

float recibir (int x, int low,int high, int mid, int arreglo);
	

if(i==-1){

    cout<<"el elemento no se encontró";
}
else{

    cout<<"el elemento se encuentra en la casilla: " << i <<endl;
    
	}

}	
	
	



float recibir (int x, int low,int high, int mid, int arreglo){


if(low > high){
    return(-1);
mid = (low + high) / 2;
}
if(x == mid){

    return(mid);
}
if(x < mid){
    cout<<"buscar x desde low hasta mid-1";
}
else{
    cout<<"buscar x desde mid+1 hasta high";
} 
}
