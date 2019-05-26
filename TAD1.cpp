/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Hour.h"

void resuelveCaso(int trains, int hours) {

	std::vector<Hour> v(trains);
	for (Hour &data : v) std::cin >> data;

	for (int i = 0; i < trains; i++) {
		std::cout << v[i];
	}

	Hour h;
	for (int i = 0; i < hours; i++) {
		std::cin >> h;
	}
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int trains, hours;
	std::cin >> trains >> hours;
	while (trains != 0 && hours != 0) {
		resuelveCaso(trains, hours);
		std::cin >> trains >> hours;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}