/*
	Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal no final
std::string bin(int n) {
	if (n == 0) return "0";
	else if (n == 1) return "1";
	return bin(n / 2) + char('0' + n % 2);
}
void resuelveCaso() {
	int n;
	std::cin >> n;
	std::cout << bin(n) << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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