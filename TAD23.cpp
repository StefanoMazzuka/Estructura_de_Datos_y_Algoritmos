/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tData {
	int nRescueTeams;
	int maxHikers;
	tData() {
		nRescueTeams = 0;
		maxHikers = 0;
	}
	tData(int n, int m) {
		nRescueTeams = n;
		maxHikers = m;
	}
};

tData trappedHikers(const bintree<int> &tree) {
	if (tree.left().empty() && tree.right().empty()) {
		if (tree.root() > 0) return { 1, tree.root() };
		return { 0, tree.root() };
	} 

	tData data, left, right;
	if (!tree.left().empty()) left = trappedHikers(tree.left());
	if (!tree.right().empty()) right = trappedHikers(tree.right());

	if (tree.root() > 0 && left.nRescueTeams == 0 && right.nRescueTeams == 0) data.nRescueTeams = 1;
	else data.nRescueTeams = left.nRescueTeams + right.nRescueTeams;

	data.maxHikers = tree.root() + std::max(left.maxHikers, right.maxHikers);
	return data;
}

void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	tData data = trappedHikers(tree);
	std::cout << data.nRescueTeams << " " << data.maxHikers << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD23.txt");
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