/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool isPair(int x) {
	return (x % 2 == 0);
}

struct tSol {
	bool isCaucasian;
	int numPairs;
};

// Coste lineal en N donde N son los elementos del vector 
tSol caucasian(std::vector <int> const & v, int start, int end) {
	tSol sol;
	if (start == end) {
		if (isPair(v[start])) sol.numPairs = 1;
		else sol.numPairs =  0;
		sol.isCaucasian = true;
		return sol;
	}

	else if (start + 1 == end) {
		int cont = 0;
		if (isPair(v[start])) cont++;
		if (isPair(v[end])) cont++;
		sol.numPairs =  cont;
		sol.isCaucasian = true;
		return sol;
	}

	int m = (start + end) / 2;
	tSol left = caucasian(v, start, m);
	tSol right = caucasian(v, m + 1, end);
	
	sol.numPairs = left.numPairs + right.numPairs;
	sol.isCaucasian = false;

	if ((left.isCaucasian == true && right.isCaucasian == true) && 
		(abs(left.numPairs - right.numPairs) <= 2))
		sol.isCaucasian = true;

	return sol;
}

bool resuelveCaso(int lon) {

	std::vector <int> v(lon);
	for (int & n : v) std::cin >> n;

	if (caucasian(v, 0, lon - 1).isCaucasian) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos21.txt");
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