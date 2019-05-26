/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
IDEA:
	Buscar siempre la posicion final del value a buscar
*/
// Coste O(logN)*N
int searchRight(std::vector<int> const& v, int start, int end, int value) {
	if (v[start] == v[end]) return end;

	int m = (start + end + 1) / 2;
	if (v[m] != value) searchRight(v, start, m - 1, value);
	else searchRight(v, m, end, value) + 1;
}
void resuelveCaso(int lon) {
	std::vector<int> v(lon);
	int value;
	for (size_t i = 0; i < lon; i++) {
		std::cin >> value;
		v[i] = value;
	}

	int start = searchRight(v, 0, lon - 1, v[0]);
	int cont = 1;
	while (start != lon - 1) {
		start = searchRight(v, start + 1, lon - 1, v[start + 1]);
		cont++;
	}

	std::cout << cont << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int lon;
	std::cin >> lon;
	while (lon != 0) {
		resuelveCaso(lon);
		std::cin >> lon;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}