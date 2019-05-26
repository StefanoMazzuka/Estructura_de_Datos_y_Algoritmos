// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
int resolver(const std::vector<int> &v, int n) {

	int countOnes = 0;
	int countZeros = 0;
	int sol = -1;
	for (int i = 0; i < n; i++) {
		if (v[i] == 1)
			countOnes++;
		else if (v[i] == 0)
			countZeros++;
		if (countOnes == countZeros)
			sol = i;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for (int &data : v)
		std::cin >> data;

	// escribir sol
	std::cout << resolver(v, n) << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos42.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	while (numCasos > 0) {
		resuelveCaso();
		numCasos--;
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}