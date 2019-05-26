/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "bintree_eda.h"

using key = std::string;
using value = int;

void resuelveCaso() {
	std::map<key, value> oldMap;
	std::map<key, value> newMap;
	std::vector<key> added;
	std::vector<key> deleted;
	std::vector<key> modified;
	auto itOld = oldMap.begin();
	auto itNew = newMap.begin();

	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	std::string aux; // ss >> aux
	while (ss >> aux) {
		int n;
		ss >> n;
		oldMap.insert({aux, n});
	}

	while (itOld != oldMap.end() && itNew != newMap.end()) {
		if (itOld->first < itNew->first) {
			deleted.push_back(itOld->first);
			++itOld;
		}
		else if (itOld->first > itNew->first) {
			deleted.push_back(itNew->first);
			++itNew;
		}
		else {
			
		}

		while (itOld != oldMap.end()) {
			deleted.pop_back();
		}

		while (itNew != newMap.end()) {
			added.pop_back();
		}
	}
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD30.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases > 0) {
		resuelveCaso();
		--nCases;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}