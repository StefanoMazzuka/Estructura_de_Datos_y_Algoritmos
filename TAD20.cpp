/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "bintreeTAD20.h"

void resuelveCaso() {

	bintreeTAD20<int> tree;
	tree = leerArbolTAD20(-1);
	int aux = tree.showFrontiers();

	std::cout << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD20.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases != 0) {
		resuelveCaso();
		nCases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}