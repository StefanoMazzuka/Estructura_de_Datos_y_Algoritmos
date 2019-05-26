/*
	E36
	Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Polynomial.h"

bool resuelveCaso() {

	int coefficient;
	int exponent;
	std::cin >> coefficient >> exponent;

	if (!std::cin) return false;

	Polynomial pol;
	while (coefficient != 0 || exponent != 0) {
		pol.addMonomial(coefficient, exponent);
		std::cin >> coefficient >> exponent;
	}

	int n;
	std::cin >> n;
	int data;
	for (int i = 0; i < n; i++) {
		std::cin >> data;
		std::cout << pol.result(data) << " ";
	}

	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD4.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}