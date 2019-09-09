//Ejercicio 12 laboratorio
//Cesar Atonio Roque Castro 00015319
#include <iostream>
using namespace std;
int main(){

  int num, rsto,num_invert=0;
  cout<< "Ingrese # a invertir:"; 
  cin>> num;
  while(num>0){
    rsto = num % 10;
    num = num / 10;
    num_invert=num_invert*10+rsto;
}
cout<<"El # invertido es:"<<num_invert;

return 0;  
}
