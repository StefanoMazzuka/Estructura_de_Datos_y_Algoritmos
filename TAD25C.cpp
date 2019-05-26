/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "bintree_eda.h"

struct tData {
	std::string leaf;
	int nDragons;

	tData() {
		leaf = "";
		nDragons = std::numeric_limits<int>::max();
	}
	tData(std::string l, int n) {
		leaf = l;
		nDragons = n;
	}
};

tData bestWay(bintree<std::string> tree) {
	if (tree.left().empty() && tree.right().empty()) return { tree.root(), 0 };

	tData left, right;
	if (!tree.left().empty()) left = bestWay(tree.left());
	if (!tree.right().empty()) right = bestWay(tree.right());

	tData data("", 0);
	if (left.nDragons <= right.nDragons) data = left;
	else data = right;

	if (tree.root() == "Dragon") data.nDragons++;

	return data;
}

void resuelveCaso() {
	bintree<std::string> tree;
	std::string emp = "...";

	tree = leerArbol(emp);
	tData data = bestWay(tree);
	std::cout << data.leaf << " " << data.nDragons << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD25C.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases != 0) {
		resuelveCaso();
		nCases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}