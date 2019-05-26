/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "bintree_eda.h"

int getFlow(const bintree<int> &tree, int &count) {
	if (tree.empty()) { 
		count = 0; 
		return 0;
	}
	if (tree.left().empty() && tree.right().empty()) {
		count = 0;
		return 1;
	}

	int countLeft;
	int leftFlow = getFlow(tree.left(), countLeft);
	int countRight;
	int rightFlow = getFlow(tree.right(), countRight);

	if (leftFlow >= 3) countLeft++;
	if (rightFlow >= 3) countRight++;

	count = countLeft + countRight;

	int flow = (leftFlow + rightFlow) - tree.root();
	if (flow < 0) flow = 0;
	return flow;
}

void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	int count;
	int flow = getFlow(tree, count);

	std::cout << count << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD25E.txt");
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