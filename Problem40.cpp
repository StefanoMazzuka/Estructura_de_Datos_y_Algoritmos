// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int start;
	int end;
	int maxSequence;
	int numSequences;
	int numMatches;
};

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
tSol resolver(const std::vector<int> &v) {
	int lon = v.size();

	tSol sol;
	sol.start = 0;
	sol.maxSequence = -1;
	sol.numMatches = 0;
	sol.numSequences = 0;

	int start = 0;
	int end = 0;
	for (int i = 0; i < lon; i++) {
		if (v[i] <= 0) {
			start = i + 1;
		}
		else if (i - start == sol.maxSequence) {
			sol.numSequences++;
			end = i;
		}
		if (i - start > sol.maxSequence) {
			sol.maxSequence++;
			end = i;
		}
	}

	sol.numMatches = lon - end - 1;

	if (sol.maxSequence >= 0 && sol.numSequences == 0) {
		sol.numSequences++;
	}

	if (sol.maxSequence == -1)
		sol.numMatches++;

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> v(n);
	for (int &data : v)
		std::cin >> data;

	tSol sol = resolver(v);
	// escribir sol

	std::cout << sol.maxSequence + 1 << " " << sol.numSequences << " " << sol.numMatches << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos40.txt");
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