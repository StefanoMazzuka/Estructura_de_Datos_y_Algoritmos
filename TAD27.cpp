/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "bintree_eda.h"

void postorden(const bintree<int> &tree) {
	if (!tree.empty()) {
		postorden(tree.left());
		postorden(tree.right());
		std::cout << tree.root() << " ";
	}
}

bintree<int> buildTree(std::vector<int> nodes) {
	if (nodes.empty()) return { bintree<int>() };
	if (nodes.size() == 1) return { bintree<int>(), nodes[0], bintree<int>() };

	int root = nodes[0];
	int lenght = nodes.size();
	std::vector<int> left, right;
	int i = 1;
	while (i < lenght && nodes[i] < root) {
		left.push_back(nodes[i]);
		i++;
	}
	while (i < lenght && nodes[i] > root) {
		right.push_back(nodes[i]);
		i++;
	}

	return { buildTree(left), root, buildTree(right) };
}

bool resuelveCaso() {

	std::vector<int> nodes;
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	std:int n; // ss >> aux
	while (ss >> n) {
		nodes.push_back(n);
	}

	if (!std::cin) return false;

	bintree<int> tree = buildTree(nodes);
	postorden(tree);
	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD27.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}