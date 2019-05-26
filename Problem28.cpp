/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

bool poda(int k, int sum, int &minSum, const std::vector<int> &minims) {
	int aux = sum;
	int lon = minims.size();
	for (int i = k + 1; i < lon; i++) {
		aux += minims[i];
	}

	return sum < minSum || minSum == std::numeric_limits<int>::max();
}

//Coste O(m^n) donde m son el número de tipos de colores de bombillas y n la cantidad de luces.
void shopping(int nSuper, int nProducts, const std::vector<std::vector<int>> &map,
	std::vector<int> &count, int k, int &sum, int &minSum, const std::vector<int> &minims) {
	for (int i = 0; i < nSuper; i++) {
		if (count[i] < 3) {
			sum += map[i][k];
			count[i]++;
			if (k == nProducts - 1) {
				if (sum < minSum || minSum == std::numeric_limits<int>::max()) {
					minSum = sum;
				}
			}
			else if (poda(k, sum, minSum, minims))
					shopping(nSuper, nProducts, map, count, k + 1, sum, minSum, minims);

			count[i]--;
			sum -= map[i][k];
		}
	}
}

void resuelveCaso() {

	/*
	nSuper = número de supermercados
	nProducts = número de productos
	*/
	int nSuper, nProducts;
	std::cin >> nSuper >> nProducts;

	/*
	map = matriz de supermercados y productos
	*/
	std::vector<int> minims(nProducts, std::numeric_limits<int>::max());
	int data;
	std::vector<std::vector<int>> map(nSuper, std::vector<int>(nProducts));
	for (int i = 0; i < nSuper; i++) {
		for (int j = 0; j < nProducts; j++) {
			std::cin >> data;
			map[i][j] = data;

			if (data < minims[j] || minims[j] == std::numeric_limits<int>::max())
				minims[j] = data;
		}
	}

	/*
	count = vector de contador de productos por supermercado
	*/
	std::vector<int> count(nSuper);

	int sum = 0;
	int minSum = std::numeric_limits<int>::max();
	shopping(nSuper, nProducts, map, count, 0, sum, minSum, minims);
	if (minSum == std::numeric_limits<int>::max())
		std::cout << "Sin solucion factible" << '\n';
	std::cout << minSum << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos28.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCases;
	std::cin >> numCases;
	while (numCases > 0) {
		resuelveCaso();
		numCases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}