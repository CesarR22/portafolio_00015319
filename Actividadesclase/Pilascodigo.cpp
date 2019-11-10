#include <iostream>
#include <stack>
using namespace std;


int main()
{
int *puntero;

	stack<int> s;

	s.push(1);	
	s.push(2);	
	s.push(3);	
	s.push(4);	

	
	cout << "Tam de Pila: " << s.size() << endl;
	cout << "Top es: " << s.top() << endl;
	
	if(s.empty()){
		cout<<"la pila esta vacia"<<endl;
	}
		else{
			s.pop();
	}
	
	if(s.empty()){
		cout<<"la pila esta vacia"<<endl;
		}else{
			s.pop();
	}


if(s.empty()){
		cout<<"la pila esta vacia"<<endl;
		}else{
			s.push(3);
	}
	
	cout << "el nuevo top " << s.top() << endl;

	if (s.empty())
		cout << "esta vacia";
	else
		cout << "no vacia";

	return 0;
}

