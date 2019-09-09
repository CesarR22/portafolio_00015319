//Cesar Antonio Roque Castro 00015319
#include <iostream>
using namespace std;
int multiplicacion(int b, int a){
	if(b==1){
		cout << "n=" << b << " caso base" << endl;
		return a;
	}else{
		int B= b-1;
		multiplicacion(B, a);
		cout << "a=" << a << " b=" << b <<endl;
		return a+a*(b-1);
	}
}
int main()
{
	int a=2;
	int b=1;
	cout << "La multiplicacion de a*b\n";
	int r = multiplicacion (b, a);
	cout << "Resultado: " << r << endl;

}

