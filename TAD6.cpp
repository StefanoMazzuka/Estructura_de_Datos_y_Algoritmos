/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

bool resuelveCaso() {

	std::string data;
	std::getline(std::cin, data);

	if (!std::cin) return false;

	int i = 0;
	int length = data.size();
	bool correct = true;
	bool exist = false;
	stack<char> s;
	while (correct && i < length) {
		if (data[i] == '(' || data[i] == '{' || data[i] == '[') 
			s.push(data[i]);

		else if (data[i] == ')') {
			if (!s.empty() && s.top() == '(') s.pop();
			else correct = false;
		}

		else if (data[i] == '}') {
			if (!s.empty() && s.top() == '{') s.pop();
			else correct = false;
		}

		else if (data[i] == ']') {
			if (!s.empty() && s.top() == '[') s.pop();
			else correct = false;
		}
		i++;
	}

	if (correct && s.empty()) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD6.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}