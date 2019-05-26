/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "bintreeTAD19.h"

void resuelveCaso() {

	bintreeTAD19<char> tree;
	tree = leerArbolTAD19('.');
	tData data = tree.getData();
	std::cout << data.nNodes << " " << data.nLeafs << " " << data.height << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD19.txt");
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