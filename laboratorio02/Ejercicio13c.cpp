#include<iostream>
using namespace std;

void fun(int n);

int main(){

int n, sum= 0;
cout<<"Ingrese num: ";
cin>>n;
fun(n);

return 0;

}
void fun(int n)
{
	int suma;
	for(int i=0;i<=n;i++){
		suma=suma+i;
	}cout<<suma;
}

