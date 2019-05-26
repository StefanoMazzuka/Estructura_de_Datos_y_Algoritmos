/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Coste O(LogN) donde N es son los elementos del vector 
int missed(std::vector <int> const & a, std::vector <int> const & b, int start, int end) {
	if (start == end) return a[start];
	else if (start + 1 == end) {
		if (a[start] != b[start]) return a[start];
		return a[end];
	}

	int m = (start + end) / 2;
	if (a[m] == b[m]) return missed(a, b, m + 1, end);
	return missed(a, b, start, m);
}

bool resuelveCaso() {
	int lon;
	std::cin >> lon;

	std::vector <int> a(lon);
	for (int & n : a) std::cin >> n;

	std::vector <int> b(lon - 1);
	for (int & m : b) std::cin >> m;

	std::cout << missed(a, b, 0, a.size() - 1) << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos17.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int cases;
	std::cin >> cases;
	while (cases > 0) {
		resuelveCaso();
		cases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}