/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include "bintreeTAD21.h"

bool resuelveCaso() {

	char data;
	std::cin >> data;
	if (!std::cin) return false;

	if (data == 'N') {
		bintreeTAD21<int> tree;
		tree = leerArbolTAD21(-1);
		std::cout << tree.getMin() << '\n';
	}

	else {
		bintreeTAD21<std::string> tree;
		std::string empty = "#";
		tree = leerArbolTAD21(empty);
		std::cout << tree.getMin() << '\n';
	}

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD21.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}