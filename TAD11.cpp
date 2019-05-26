/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "queueTAD11.h"

void resuelveCaso() {

	QueueTAD11<int> q1;
	int data;
	std::cin >> data;
	while (data != 0) {	
		q1.push(data);
		std::cin >> data;
	}

	QueueTAD11<int> q2;
	std::cin >> data;
	while (data != 0) {
		q2.push(data);
		std::cin >> data;
	}
	if (q1.size() == 0)
		q2.print();
	else {
		q1.sort(q2);
		q1.print();
	}
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD11.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases != 0) {
		resuelveCaso();
		--nCases;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}