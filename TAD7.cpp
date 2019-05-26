/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.h"

bool resuelveCaso() {

	int length;
	std::cin >> length;

	if (!std::cin) return false;

	std::vector<int> v(length);

	for (int &data : v) std::cin >> data;

	int medium = -1;
	int big = -1;
	bool wrong = false;
	stack<int> s;
	s.push(v[length - 1]);
	for (int i = length - 1; i >= 0 && !wrong; i--) {
		if (v[i] < medium) wrong = true;
		else {
			while (!s.empty() && v[i] > s.top()) {
				medium = s.top();
				s.pop();
			}
			big = v[i];
			s.push(v[i]);
		}
	}

	if (wrong) std::cout << "ELEGIR OTRA" << '\n';
	else std::cout << "SIEMPRE PREMIO" << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD7.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}