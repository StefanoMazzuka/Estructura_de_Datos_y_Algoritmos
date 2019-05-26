/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "bintree_eda.h"

void postorden(const bintree<int> &tree) {
	if (!tree.empty()) {
		postorden(tree.left());
		postorden(tree.right());
		std::cout << tree.root() << " ";
	}
}

int getPosRoot(const std::vector<int> &v, int value, int start, int end) {
	for (int i = start; i <= end; i++)
		if (value == v[i]) return i;
	return -1;
}

// lee un árbol binario de la entrada estándar
inline bintree<int> leerArbolTAD24(const std::vector<int> &preorden, int startPreorden, int endPreorden,
	const std::vector<int> &inorden, int startInorden, int endInorden) {

	if (startPreorden == endPreorden && startInorden == endInorden)
		return { bintree<int>(), preorden[startPreorden], bintree<int>() };

	// leer recursivamente los hijos
	int posRoot = getPosRoot(inorden, preorden[startPreorden], startInorden, endInorden);

	auto iz = bintree<int>();
	if (posRoot > startInorden) {
		int lStartPreorden = startPreorden + 1;
		int lEndPreorden = startPreorden + (posRoot - startInorden);
		iz = leerArbolTAD24(preorden, lStartPreorden, lEndPreorden, inorden, startInorden, posRoot - 1);
	}

	auto dr = bintree<int>();
	if (posRoot < endInorden) {
		int rStartPreorden = startPreorden + (posRoot - startInorden) + 1;
		int rEndPreorden = rStartPreorden + (endInorden - posRoot) - 1;
		dr = leerArbolTAD24(preorden, rStartPreorden, rEndPreorden, inorden, posRoot + 1, endInorden);
	}

	return { iz, preorden[startPreorden], dr };
}

bool resuelveCaso() {
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);

	if (!std::cin) return false;

	int value;
	std::vector<int> preorden;
	while (ss >> value)
		preorden.push_back(value);

	std::getline(std::cin, line);
	std::stringstream ss2(line);

	std::vector<int> inorden;
	while (ss2 >> value)
		inorden.push_back(value);

	int length = preorden.size() - 1;
	bintree<int> tree = leerArbolTAD24(preorden, 0, length, inorden, 0, length);

	postorden(tree);
	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD24.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}