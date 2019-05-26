/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool isValid(int s, std::vector<int> toysQuantity, std::vector<std::string> types,
<<<<<<< HEAD
	std::vector<std::vector<int>> kidsToysSatisfaction, std::vector<int> kidsToysMarked,
	std::vector<int> sol, int k) {

	if (sol[k] <= kidsToysMarked[sol[k]])
		return false;
=======
	std::vector<std::vector<int>> kidsToysSatisfaction, std::vector<int> sol, int k) {
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187

	if (toysQuantity[sol[k]] < 0)
		return false;

<<<<<<< HEAD
	if (k > 0 && k % 2 != 0) {
		if (types[sol[k]] == types[sol[k - 1]])
			return false;

		if ((kidsToysSatisfaction[(k - 1) / 2][sol[k]] + kidsToysSatisfaction[(k - 1) / 2][sol[k - 1]]) < s)
			return false;
	}
=======
	if (k % 2 != 0) {
		if (types[sol[k - 1]] == types[sol[k]])
			return false;

		if ((kidsToysSatisfaction[(k - 1) / 2][sol[k - 1]] + kidsToysSatisfaction[(k - 1) / 2][sol[k]]) < s)
			return false;
	}

>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	return true;
}

void showSolution(std::vector<int> sol) {
<<<<<<< HEAD
	for (int i : sol) {
		std::cout << i << " ";
=======
	int lon = sol.size();
	for (int i = 0; i < lon; i++) {
		std::cout << sol[i] << ' ';
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}
	std::cout << '\n';
}

//Coste O(m^n) donde m son el número de tipos de colores de bombillas y n la cantidad de luces.
void santa(int m, int n, int s, std::vector<int> toysQuantity, const std::vector<std::string> &types,
<<<<<<< HEAD
	const std::vector<std::vector<int>> &kidsToysSatisfaction, std::vector<int> kidsToysMarked,
	std::vector<int> sol, int k) {

	for (int i = 0; i < m; i++) {
		sol[k] = i;
		toysQuantity[i]--;
		kidsToysMarked[(k - 1) / 2] = i;

		if (isValid(s, toysQuantity, types, kidsToysSatisfaction, kidsToysMarked, sol, k)) {
			if (k == (n * 2) - 1) showSolution(sol);
			else santa(m, n, s, toysQuantity, types, kidsToysSatisfaction, kidsToysMarked, sol, k + 1);
		}

		toysQuantity[i]++;
=======
	const std::vector<std::vector<int>> &kidsToysSatisfaction, std::vector<std::vector<bool>> kidsToysMarked,
	std::vector<int> sol, int k, bool &exist) {

	for (int i = 0; i < m; i++) {
		if ((k % 2 != 0 && !kidsToysMarked[(k - 1) / 2][i]) || (k % 2 == 0 && !kidsToysMarked[k / 2][i])) {
			sol[k] = i;
			toysQuantity[i]--;

			if (isValid(s, toysQuantity, types, kidsToysSatisfaction, sol, k)) {					
				if (k == (n * 2) - 1) {
					showSolution(sol);
					exist = true;
				}

				else {
					// Marked
					if (k % 2 != 0) kidsToysMarked[(k - 1) / 2][i] = true;
					else kidsToysMarked[k / 2][i] = true;
					santa(m, n, s, toysQuantity, types, kidsToysSatisfaction, kidsToysMarked, sol, k + 1, exist);
				}
			}

			toysQuantity[i]++;
		}
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}
}

bool resuelveCaso() {

	/*
	m = número de juguetes
	n = número de niños
	s = satisfacción mínima
	*/
	int m, n, s;
	std::cin >> m >> n >> s;
	if (!std::cin) return false;

	/*
	toysQuantity = vector de cantidades de cada juguete, cada posición es un juguete
	*/
	std::vector<int> toysQuantity(m);
	for (int& i : toysQuantity) std::cin >> i;

	/*
	types = vector de tipos, cada posición es un juguete
	*/
	std::vector<std::string> types(m);
	for (std::string& i : types) std::cin >> i;

	/*
	kidsToysSatisfaction = matriz que guarda por cada fila las satisfacciones por cada juguete de un niño.
	*/
	std::vector<std::vector<int>> kidsToysSatisfaction(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
<<<<<<< HEAD
		for (int& j : kidsToysSatisfaction[i]) { std::cin >> j; }
=======
		for (int& j : kidsToysSatisfaction[i]) std::cin >> j;
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}

	/*
	kidsToysMarked = matriz de juguetes marcados por cada niño.
	*/
<<<<<<< HEAD
	std::vector<int> kidsToysMarked(n);
=======
	std::vector<std::vector<bool>> kidsToysMarked(n, std::vector<bool>(m));
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187

	/*
	sol = vector solución. Cada dos posiciones del vector son los dos juguetes de un niño.
	*/
	std::vector<int> sol(n * 2);
<<<<<<< HEAD
	santa(m, n, s, toysQuantity, types, kidsToysSatisfaction, kidsToysMarked, sol, 0);
=======
	bool exist = false;
	santa(m, n, s, toysQuantity, types, kidsToysSatisfaction, kidsToysMarked, sol, 0, exist);
	if (!exist) std::cout << "SIN SOLUCION" << '\n';
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos26.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}