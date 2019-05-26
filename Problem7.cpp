/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Solucion recursiva final de O(logN)
int bongo(std::vector<int> const& v, int start, int end, int number) {
	if (start == end) {
		if (v[start] == number + start) return v[start];
		return -1;
	}

	int m = (start + end) / 2;
	if (v[m] < number + m) return bongo(v, m + 1, end, number);
	else return bongo(v, start, m, number);
}
void resuelveCaso() {
	int lon, number;
	std::cin >> lon >> number;

	std::vector<int> v(lon);
	int value;
	for (size_t i = 0; i < lon; i++) {
		std::cin >> value;
		v[i] = value;
	}

	int sol = bongo(v, 0, lon, number);
	if (sol == -1) std::cout << "NO" << '\n';
	else std::cout << sol << '\n';
	
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos7.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numInputs;
	std::cin >> numInputs;
	for (size_t i = 0; i < numInputs; i++) {
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}