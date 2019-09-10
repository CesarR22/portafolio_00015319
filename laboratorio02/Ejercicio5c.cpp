#include <iostream>
using namespace std;

int cont = 0;
void colors(int Num, char *pParti , char *pFinal) {
    
	char *arr[] = { "", "Azul", "Verde", "Amarillo", "Naranja", "Rojo" };
	
	cout << "\t\tStep " << ++cont;
	
	cout << ": Movimiento " << arr[Num] << " de " << pParti << " a " << pFinal << "\n";
}

void torre(int a, char *pParti , char *auxiliar, char *pFinal) {
	if (a == 1) {
		colors(1, pParti, pFinal);
	}
	else {
		torre(a - 1, pParti, pFinal, auxiliar);
		colors(a, pParti, pFinal);
		torre(a - 1, auxiliar, pParti, pFinal);
	}
}

int main() {
	int n;
	cout <<"Torre Hanoi"<<endl;
	cout << "Ingrese # de discos: ";
	cin >> n;
	
	torre(n, "Nuevo", "Auxiliar", "Final");

	return 0;
}

