// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
bool resolver(std::vector<int> v, int p) {
	int lon = v.size();
	if (p != lon - 1) {
		int i = p - 1;
		int j = p + 1;
		int max = v[p];
		int min = v[p + 1];

		while (i >= 0 || j < lon) {
			if (i >= 0) {
				if (v[i] > max)
					max = v[i];
				i--;
			}
			if (j < lon) {
				if (v[j] < min)
					min = v[j];
				j++;
			}
		}

		return max < min;
	}

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, p;
	std::cin >> n >> p;

	std::vector<int> v(n);
	for (int &data : v)
		std::cin >> data;

	bool sol = resolver(v, p);
	// escribir sol

	if (sol)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos37.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}