/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "queue_eda.h"

void resuelveCaso(int length, int saved) {

	queue<int> q;
	for (int i = 1; i <= length; ++i)
		q.push(i);
	
	while (q.size() != 1) {
		for (int i = 0; i < saved; ++i) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	std::cout << q.front() << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD12.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int length, saved;
	std::cin >> length >> saved;
	while (length != 0 && saved != 0) {
		resuelveCaso(length, saved);
		std::cin >> length >> saved;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}