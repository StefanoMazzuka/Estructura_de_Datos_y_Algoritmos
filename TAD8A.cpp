/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queueTAD8A.h"

bool resuelveCaso() {

	int data;
	std::cin >> data;

	if (!std::cin) return false;

	QueueTAD8A<int> q;
	while (data != 0) {
		q.push(data);
		std::cin >> data;
	}

	if (q.size() > 0)
		q.duplicate();
	q.print();

	std::cin >> data;
	while (data != 0) {
		q.addBack(data);
		std::cin >> data;
	}

	std::cin >> data;
	q.remove(data);
	q.print();

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD8A.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}