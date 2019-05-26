// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos de la matriz (n * m)
int resolver(const std::vector<std::vector<int>> &v, int n, int p) {

	int maxFishes = 0;
	int finalFishes = 0;
	for (int k = 0; k <= n - p; k++) {
		std::vector<int> rows(n);
		std::vector<int> columns(n);
		int totalFishes = 0;
		for (int i = k; i < k + p; i++) {
			for (int j = 0; j < p; j++) {
				totalFishes += v[i][j];
				columns[j] += v[i][j];
				rows[i] += v[i][j];
			}
		}

		int fishes;
		int maxFishes = totalFishes;
		for (int i = p; i < n; i++) {
			fishes = 0;
			for (int j = k; j < k + p; j++) {
				fishes += v[j][i];
			}
			columns[i] = fishes;
			totalFishes -= columns[i - p];
			totalFishes += fishes;

			if (totalFishes > maxFishes)
				maxFishes = totalFishes;
		}

		if (maxFishes > finalFishes)
			finalFishes = maxFishes;
	}

	return finalFishes;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, p;
	std::cin >> n >> p;

	if (!std::cin) return false;

	std::vector<std::vector<int>> v(n, std::vector<int>(n));
	int data;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> data;
			v[i][j] = data;
		}
	}

	// escribir sol
	std::cout << resolver(v, n, p) << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos48.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso()) {}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}