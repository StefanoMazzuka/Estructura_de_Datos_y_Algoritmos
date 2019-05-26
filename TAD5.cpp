/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MySet.h"

bool resuelveCaso() {

	char type;
	std::cin >> type;

	if (!std::cin) return false;

	if (type == 'N') {	
		int k;
		std::cin >> k;
		myset<int> s(k);
		int data;
		std::cin >> data;
		while (data != -1) {
			s.insert(data);
			std::cin >> data;
		}
		s.show();
	}

	else if (type == 'P') {
		int k;
		std::cin >> k;
		myset<std::string> s(k);
		std::string data;
		std::cin >> data;
		while (data != "FIN") {
			s.insert(data);
			std::cin >> data;
		}
		s.show();
	}

	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD5.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}