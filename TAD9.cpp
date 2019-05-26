/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "queueTAD9.h"

bool resuelveCaso() {

	int data;
	std::cin >> data;

	if (!std::cin) return false;

	QueueTAD9<int> q;
	while (data != 0) {
		q.push(data);
		std::cin >> data;
	}
	q.invert();
	q.print(std::cout);
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD9.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}