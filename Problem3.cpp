/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal no final
int invertir(int n, int &pot) {
	if (n < 10) {
		pot = 10;
		return n;
	}
	int sol = invertir(n/10, pot) + (n % 10) * pot;
	pot *= 10;
	return sol;
}
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	int pot = 0;
	std::cout << invertir(n, pot) << '\n';
	return true;
	
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}