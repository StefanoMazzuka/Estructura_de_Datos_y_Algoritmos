/*
E36
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>

int heigth(int nNodes) {
	if (nNodes == 0) return 0;
	int maxHeigth = 0;
	int childHeigth;
	for (int i = 0; i < nNodes; ++i) {
		int child;
		std::cin >> child;
		childHeigth = heigth(child) + 1;
		if (childHeigth > maxHeigth)
			maxHeigth = childHeigth;
	}
	return maxHeigth;
}

void resuelveCaso() {

	int nNodes;
	std::cin >> nNodes;
	int maxHeigth = 0;
	if (nNodes == 0) maxHeigth = 0;
	else {
		int childHeigth;
		for (int i = 0; i < nNodes; ++i) {
			int child;
			std::cin >> child;
			childHeigth = heigth(child) + 1;
			if (childHeigth > maxHeigth)
				maxHeigth = childHeigth;
		}	
	}
	std::cout << maxHeigth + 1 << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD17.txt");
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