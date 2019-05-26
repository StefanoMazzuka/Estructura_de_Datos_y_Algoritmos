/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "queueTAD16D.h"
#include "Hour.h"

void resuelveCaso(int length) {
	QueueTAD16D<Hour> q;

	Hour data;
	for (int i = 0; i < length; ++i) {
		std::cin >> data;
		q.push(data);
	}

	q.deleteMins();
	q.print();
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD16D.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int length;
	std::cin >> length;
	while (length != 0) {
		resuelveCaso(length);
		std::cin >> length;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}