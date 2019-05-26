/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Coste O(N)
int comp(int number) {
	if (number < 10) return 9 - number;
	return comp(number / 10) * 10 + (9 - (number % 10));
}

// Coste O(N)
int inverseComp(int number, int resul) {
	if (number < 10) return resul * 10 + 9 - number;
	resul = resul * 10 + (9 - number % 10);
	return inverseComp(number / 10, resul);
}

void resuelveCaso() {
	
	int number;
	std::cin >> number;
	std::cout << comp(number) << " " << inverseComp(number, 0) << '\n';
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos15.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int n;
	std::cin >> n;
	while (n != 0) {
		resuelveCaso();
		n--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}