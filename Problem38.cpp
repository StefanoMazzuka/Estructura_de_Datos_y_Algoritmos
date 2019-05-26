// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int start;
	int gain;
};

// función que resuelve el problema
// COSTE O(n - numWagons) siendo n el número de elementos del vector y numWagons cuantos se pueden asaltar
tSol resolver(std::vector<int> v, int numWagons) {
	int lon = v.size();

	int gain = 0;
	for (int i = 0; i < numWagons; i++) {
		gain += v[i];
	}

	int i;
	tSol sol;
	sol.start = 0;
	sol.gain = gain;
	for (i = numWagons; i < lon; i++) {
		gain = (gain - v[i - numWagons] + v[i]);
		if (sol.gain <= gain) {
			sol.gain = gain;
			sol.start = i - numWagons + 1;
		}
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, numWagons;
	std::cin >> n >> numWagons;

	std::vector<int> v(n);
	for (int &data : v)
		std::cin >> data;

	tSol sol = resolver(v, numWagons);
	// escribir sol

	std::cout << sol.start << " " << sol.gain << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos38.txt");
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