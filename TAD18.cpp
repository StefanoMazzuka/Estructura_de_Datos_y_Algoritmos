/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>

int nWorkers(int nNodes, int nBosses, int heigth) {
	if (nNodes == 0) {
		if (heigth >= nBosses) return 1;
		return 0;
	}
	int childWorkers = 0;
	for (int i = 0; i < nNodes; ++i) {
		int child;
		std::cin >> child;
		childWorkers += nWorkers(child, nBosses, heigth + 1);
	}
	return childWorkers;
}

bool resuelveCaso() {

	int nBosses;
	std::cin >> nBosses;

	if (!std::cin) return false;

	int nNodes;
	std::cin >> nNodes;
	int workers = nWorkers(nNodes, nBosses, 0);

	std::cout << workers << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD18.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}