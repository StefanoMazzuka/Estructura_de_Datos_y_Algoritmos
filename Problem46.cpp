// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
int resolver(const std::vector<std::vector<int>> &v, int n, int m) {

	int correct = 0;
	int countM = 0;
	int countN = 0;
	for (int i = 0; i < n * m; i++) {
		if (v[countN][countM] == countN)
			correct++;
		countM++;
		if (countM == m) {
			countN++;
			countM = 0;
		}
	}

	return correct;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	std::cin >> n >> m;

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
	std::cout << resolver(v, n, m) << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos46.txt");
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