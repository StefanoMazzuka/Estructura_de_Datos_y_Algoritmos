/*
	Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal no final
// COSTE: O(logN)
long long int mul(long long int a, long long int b) {
	if (b == 0) return 0;
	else if (b == 1) return a;

	if (b % 2 == 0) return mul(2 * a, b / 2);
	else return mul(2 * a, b / 2) + a;
}
void resuelveCaso() {
	long long int a, b;
	std::cin >> a >> b;
	std::cout << mul(a, b) << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}