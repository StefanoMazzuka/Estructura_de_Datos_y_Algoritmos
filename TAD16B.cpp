/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "queueTAD16B.h"

void resuelveCaso(int length) {
	QueueTAD16B<int> q;

	int data;
	for (int i = 0; i < length; ++i) {
		std::cin >> data;
		q.push(data);
	}

	q.sol();
	q.print();
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD16B.txt");
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