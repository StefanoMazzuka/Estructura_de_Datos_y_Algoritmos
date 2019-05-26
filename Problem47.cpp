// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos de la matriz (n * m)
int resolver(const std::vector<std::vector<int>> &v, int n, int m, int k, int y, int x) {

	std::vector<int> aux(m);
	int count;
	int correctColumns = 0;
	for (int i = 0; i < k; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 0)
				count++;
		}
		if (count >= x)
			correctColumns++;
		aux[i] = count;
	}

	int numStripes = 0;
	if (correctColumns >= y)
		numStripes++;

	for (int i = k; i < m; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 0)
				count++;
		}
		aux[i] = count;

		if (count >= x) correctColumns++;
		if (aux[i - k] >= x) correctColumns--;
		if (correctColumns >= y) numStripes++;
	}

	return numStripes;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m, k, y, x;
	std::cin >> n >> m >> k >> y >> x;

	if (!std::cin) return false;

	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	int data;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> data;
			v[i][j] = data;
		}
	}

	// escribir sol
	std::cout << resolver(v, n, m, k, y, x) << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos47.txt");
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