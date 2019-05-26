/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tData {
	int node;
	int height;
};

bool isPrime(int n) {
	if (n < 3) return true;
	for (int i = 2; i <= n / 2; ++i)
		if (n%i == 0) return false;
	return true;
}

tData getData(const bintree<int> &tree) {
	if (tree.empty()) return { -1, 0 };
	if (tree.left().empty() && tree.right().empty()) {
		if (tree.root() % 7 == 0) return { tree.root(), 1};
		return { -1, 0 };
	}

	if (tree.root() % 7 != 0 && isPrime(tree.root())) return { -1, 0 };

	tData left = getData(tree.left());
	tData right = getData(tree.right());

	if (tree.root() % 7 == 0) return { tree.root(), 1 };

	if (left.node % 7 == 0 && right.node % 7 == 0) {
		if (left.height <= right.height) return { left.node, left.height + 1 };
		return { right.node, right.height + 1 };
	}

	if (left.node % 7 == 0 && right.node % 7 != 0) return { left.node, left.height + 1 };
	if (left.node % 7 != 0 && right.node % 7 == 0) return { right.node, right.height + 1 };

	return { -1, 0 };
}

void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	tData data = getData(tree);

	if (data.node == -1) std::cout << "NO HAY" << '\n';
	else std::cout << data.node << " " << data.height << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD25.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases > 0) {
		resuelveCaso();
		--nCases;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}