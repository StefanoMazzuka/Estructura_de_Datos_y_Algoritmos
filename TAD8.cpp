/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue.h"

bool resuelveCaso() {

	int data;
	std::cin >> data;

	if (!std::cin) return false;

	queue<int> q;
	while (data != 0) {
		q.push(data);
		std::cin >> data;
	}

	int length = q.size();
	if (length > 0) {
		q.duplicate(q.first());

		for (int i = 0; i < length * 2; i++) {
			std::cout << q.front() << " ";
			q.pop();
		}
	}

	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD8.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}