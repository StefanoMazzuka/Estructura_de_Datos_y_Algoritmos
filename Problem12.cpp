/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Coste O(N) donde N es son los elementos del vector 
bool balanced(std::vector <int> const & v, int start, int end, int K) {
	if (start == end) return true;
	else if (start + 1 == end) return K <= std::abs((v[start] - v[end]));

	int m = (start + end) / 2;
	return balanced(v, start, m, K) && balanced(v, m + 1, end, K) && K <= std::abs((v[start] - v[end]));
}

bool resuelveCaso() {
	int lon, K;
	std::cin >> lon >> K;
	if (!std::cin) return false;

	std::vector <int> v(lon);
	for (int & n : v) std::cin >> n;

	if (balanced(v, 0, v.size() - 1, K)) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos12.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}