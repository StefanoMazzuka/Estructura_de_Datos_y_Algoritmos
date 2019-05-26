/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using key = int;
using value = int;

void resuelveCaso() {
	std::map<key, value> capsMap;
	int nCaps;
	std::cin >> nCaps;
	int start;
	for (int i = 0; i < nCaps; i++) {


		std::getline(std::cin, name);
		std::getline(std::cin, calification);
		if (exam.find(name) == exam.end()) {
			if (calification == "CORRECTO") exam.insert({ name, 1 });
			else exam.insert({ name, -1 });
		}
		else {
			if (calification == "CORRECTO") exam.at(name) = exam.at(name) + 1;
			else exam.at(name) = exam.at(name) - 1;
		}
	}

	auto it = exam.begin();
	while (it != exam.end()) {
		if (it->second != 0) std::cout << it->first << ", " << it->second << '\n';
		it++;
	}
	std::cout << "---" << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD29.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases > 0) {
		resuelveCaso(nCases);
		--nCases;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}