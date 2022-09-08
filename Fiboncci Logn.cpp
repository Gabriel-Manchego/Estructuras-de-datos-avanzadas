#include <iostream>

using namespace std;

struct Matriz{
	int a=1, b=1, c=1, d=0;

	void printmat();
};

void Matriz::printmat() {
	cout << "|" << a << " " << b << "|" << endl << "|" << c << " " << d << "|" << endl;
}

void MatrizMult(Matriz &x, Matriz &y) {
	int a, b, c, d;
	a = x.a * y.a + x.b * y.c;
	b = x.a * y.b + x.b * y.d;
	c = x.c * y.a + x.d * y.c;
	d = x.c * y.b + x.d * y.d;
	
	x.a = a;
	x.b = b;
	x.c = c;
	x.d = d;
}

void power(Matriz &a, int num){
	if (num<=1){
		return;
	}
	Matriz b;
	power(a,num/2);
	MatrizMult(a,a);
	if (num %2 != 0)
		MatrizMult(a,b);
}

int FibonacciOn(int num){
	int a = 0, b = 1, c=a+b;
	if(num == 0)
		return a;
	for(int i = 2; i <= num; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}
int FibonacciEx(int num){
	if (num <= 1)
		return num;
	return FibonacciEx(num - 1) + FibonacciEx(num - 2);
}
int main(){
	int num;
	cout << "Ingrese numero: ";
	cin >> num;
	if(num ==0)
		cout<<0;
	else{
		Matriz a;
		power(a,num - 1);
		a.printmat();
		cout<<"Respuesta en O(Logn): "<<a.a<<endl;
	}
	cout<<"Respuesta con O(n): "<<FibonacciOn(num)<<endl;
	cout<<"Repuesta con exp: "<< FibonacciEx(num)<<endl;
	return 0;
}
	
	
