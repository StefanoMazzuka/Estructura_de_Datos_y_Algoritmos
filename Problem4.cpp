/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal final
long long int deletePairs(long long int n) {
	if (n < 10) {
		if (n != 0 && n % 2 != 0) return n;
		else return 0;
	}

	long long int sol = deletePairs(n / 10);
	long long int nextNum = n % 10;
	if (nextNum != 0 && nextNum % 2 != 0) return sol * 10 + nextNum;
	else return sol;
}
bool resuelveCaso() {
	long long int n;
	std::cin >> n;
	if (!std::cin) return false;
	std::cout << deletePairs(n) << '\n';
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos4.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}