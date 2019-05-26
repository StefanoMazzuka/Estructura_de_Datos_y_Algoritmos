/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct tData {
	int height;
	int totalNumBlue;
	int totalNumRed;
	int totalNumGreen;
};

bool valid(std::vector<int> & colors, std::vector<int> & sol, int k, tData data) {
	if (sol[k] == 2 && sol[k - 1] == 2)
		return false;
	if (colors[2] > colors[0])
		return false;
	if (colors[0] > data.totalNumBlue || colors[1] > data.totalNumRed || colors[2] > data.totalNumGreen)
		return false;
	return true;
}

void showSolution(std::vector<int> const& sol) {

	for (int i : sol) {
		if (i == 0)
			std::cout << "azul ";
		else if (i == 1)
			std::cout << "rojo ";
		else
			std::cout << "verde ";
	}
	std::cout << '\n';
}

//Coste O(2N) donde N es number
void tower(std::vector<int> & colors, std::vector<int> & sol, int k, tData data, bool & existSolution) {

	for (int i = 0; i < 3; ++i) {
		sol[k] = i;
		colors[i]++;
		if (valid(colors, sol, k, data)) {

			if (k != sol.size() - 1) 
				tower(colors, sol, k + 1, data, existSolution);

			else if (colors[1] > (colors[0] + colors[2])) {
				showSolution(sol);
				existSolution = true;
			}
		}
		colors[i]--;
	}
}

bool resuelveCaso() {

	tData data;
	std::cin >> data.height;
	if (data.height == 0) return false;

	std::cin >> data.totalNumBlue >> data.totalNumRed >> data.totalNumGreen;

	// colors es un vector contador para cada color; colors[0] = azul, colors[1] = red, colors[2] = green
	std::vector<int> colors(3);
	// El vector sol contiene números del 0 al 2; 0 = azul, 1 = red, 2 = green
	std::vector<int> sol(data.height);
	sol[0] = 1;
	colors[1]++;

	bool existSolution = false;
	tower(colors, sol, 1, data, existSolution);

	if (!existSolution)
		std::cout << "SIN SOLUCION" << '\n';

	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos24.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}