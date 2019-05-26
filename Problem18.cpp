/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Coste O(2N) donde N es number
int fibMul(int number) {
	if (number == 0) return 0;
	else if (number == 1) return 1;
	return fibMul(number - 1) + fibMul(number - 2);
}

//Coste O(N) donde N es number
long long int fib(long long int number, long long int a, long long int b) {
	if (number == 0 || number == 1) return a;
	fib(number - 1, a + b, a);
}

bool resuelveCaso() {

	long long int value;
	std::cin >> value;
	if (!std::cin) return false;

	if (value == 0) std::cout << 0 << '\n';
	else std::cout << fib(value, 1, 0) << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos18.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}