/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "queueTAD10.h"

bool resuelveCaso() {

	int length;
	std::cin >> length;

	if (!std::cin) return false;

	QueueTAD10<int> q1;
	int data;
	for (int i = 0; i < length; i++) {
		std::cin >> data;
		q1.push(data);
	}

	int length2;
	int start;
	std::cin >> length2 >> start;

	QueueTAD10<int> q2;
	for (int i = 0; i < length2; i++) {
		std::cin >> data;
		q2.push(data);
	}

	q1.add(q2, start);
	q1.print();

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}