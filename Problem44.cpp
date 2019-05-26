// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
std::vector<int> resolver(std::vector<int> v, int l) {
	int lon = v.size();
	std::vector<int> sol;
	int max = v[lon - 1];
	int cont = 1;
	int start = lon - 1;
	int numMeadow = 0;
	int maxLon = 0;
	for (int i = lon - 2; i >= 0; i--) {
		if (v[i] == v[start] && v[i] >= max) {
			cont++;
		}
		if (v[i] != v[start] || (v[i] == v[start] && i == 0)) {
			if (cont >= l) {
				numMeadow++;
				sol.push_back(start);
				if (cont > maxLon)
					maxLon = cont;
			}
			cont = 1;
			start = i;
			if (v[i] >= max)
				max = v[i];
		}
	}
	sol.push_back(numMeadow);
	sol.push_back(maxLon);
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, l;
	std::cin >> n >> l;

	if (!std::cin) return false;

	std::vector<int> v(n);
	for (int &data : v)
		std::cin >> data;

	std::vector<int> sol = resolver(v, l);
	// escribir sol
	int lon = sol.size();
	std::cout << sol[lon - 1] << " " << sol[lon - 2] << " ";
	for (int i = 0; i < lon - 2; i++) {
		std::cout << sol[i] << " ";
	}

	std::cout << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos44.txt");
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