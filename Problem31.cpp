/*
Stefano Mazzuka
E36
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tSol {
	int weight;
	int balanced;
	tSol() { weight = 0; balanced = false; }
	tSol(int w, int b) {
		weight = w;
		balanced = b;
	}
};

bool isValid(const std::vector<int> &prices, const std::vector<std::vector<int>> &points, std::vector<bool> marked,
	int nRoles, int nActors, int p, int pMin, int k, int sum, int countP, int &pMax, std::vector<int> sol) {

	if (points[k][sol[k]] < pMin)
		return false;

	if (sum > p)
		return false;

	return true;
}

//Coste O(n^m)
void movie(const std::vector<int> &prices, const std::vector<std::vector<int>> &points, std::vector<bool> &marked,
	int nRoles, int nActors, int p, int pMin, int k, int sum, int &bestSum, int countP, int &pMax, std::vector<int> sol, std::vector<int> &bestSol) {
	for (int i = 0; i < nActors; i++) {
		if (!marked[i]) {
			sol[k] = i;
			sum += prices[i];
			countP += points[k][sol[k]];
			if (isValid(prices, points, marked, nRoles, nActors, p, pMin, k, sum, countP, pMax, sol)) {
				if (k == nRoles - 1) {
					if (countP > pMax) {
						pMax = countP;
						bestSol = sol;
						bestSum = sum;
					}
				}
				else {
					marked[i] = true;
					movie(prices, points, marked, nRoles, nActors, p, pMin, k + 1, sum, bestSum, countP, pMax, sol, bestSol);
					marked[i] = false;
				}
			}

			sum -= prices[i];
			countP -= points[k][sol[k]];
		}
	}
}

bool resuelveCaso() {
	/*
	nRoles = número papeles de la obra.
	nActors = número de actores.
	p = presupuesto.
	pMin = puntuación mínima.
	*/
	int nRoles, nActors, p, pMin;
	std::cin >> nRoles >> nActors >> p >> pMin;

	if (nRoles == 0 && nActors == 0 && p == 0 && pMin == 0) return false;

	// prices = vector de lo que cobra cada actor.
	std::vector<int> prices(nActors);
	for (int &data : prices) std::cin >> data;

	// points = matriz de puntos de los actores por cada obra.
	std::vector<std::vector<int>> points(nRoles, std::vector<int>(nActors));
	for (int i = 0; i < nRoles; i++)
	for (int &data : points[i]) std::cin >> data;

	// marked = vector de marcados.
	std::vector<bool> marked(nActors);

	// sol = vector soluciones con los actores elegidos.
	std::vector<int> sol(nRoles);

	// sol = vector con la mejor solución.
	std::vector<int> bestSol(nRoles);

	int bestSum = 0;
	int pMax = 0;
	movie(prices, points, marked, nRoles, nActors, p, pMin, 0, 0, bestSum, 0, pMax, sol, bestSol);

	std::cout << pMax << " " << bestSum << '\n';
	if (bestSum != 0 && pMax != 0) {
		for (int i = 0; i < nRoles; i++) {
			std::cout << i << " " << bestSol[i] << '\n';
		}
	}
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos31.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}