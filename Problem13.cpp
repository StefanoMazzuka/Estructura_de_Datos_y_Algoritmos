/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct tSol {
	bool isPS;
	int numMax;
	int numMin;
};

// Coste lineal en N donde N son los elementos del vector 
tSol parcialSort(std::vector <int> const & v, int start, int end) {
	tSol sol;
	if (start == end) {
		sol.isPS = true;
		sol.numMax = v[end];
		sol.numMin = v[start];
		return sol;
	}

	else if (start + 1 == end) {
		if (v[start] <= v[end]) {
			sol.isPS = true;
			sol.numMax = v[end];
			sol.numMin = v[start];
		}
		else {
			sol.isPS = false;
			sol.numMax = v[start];
			sol.numMin = v[end];
		}
		return sol;
	}

	int m = (start + end) / 2;
	tSol left = parcialSort(v, start, m);
	tSol right = parcialSort(v, m + 1, end);

	sol.isPS = false;
	sol.numMax = right.numMax;
	sol.numMin = left.numMin;

	if ((left.isPS == true && right.isPS == true) &&
		(left.numMax <= right.numMax) &&
		left.numMin <= right.numMin)
		sol.isPS = true;

	return sol;
}

bool resuelveCaso() {
	
	int value;
	std::cin >> value;
	if (value == 0) return false;

	std::vector <int> v;
	do {
		v.push_back(value);
		std::cin >> value;
	} while (value != 0);

	if (parcialSort(v, 0, v.size() - 1).isPS) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos13.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}