/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
// Solucion recursiva final de O(logN)
int curvaConcava(std::vector<int> const& v, int start, int end) {
	if (start == end) return v[start]; // Queda un elemento;
	else if (start + 1 == end) { // Quedan dos elementos;
		if (v[start] < v[end]) return v[start];
		else return v[end];
	}
	int m = (start + end) / 2;
	if (v[m - 1] > v[m] && v[m] < v[m + 1]) return v[m]; // Encontramos el punto menor
	else if (v[m - 1] > v[m] && v[m] > v[m + 1]) return curvaConcava(v, m + 1, end);
	else return curvaConcava(v, start, m);
}
bool resuelveCaso() {
	int n, aux;
	std::cin >> n;
	if (!std::cin) return false;

	std::vector<int> v(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> aux;
		v[i] = aux;
	}
	std::cout << curvaConcava(v, 0, n - 1) << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos5.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}