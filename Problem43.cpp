// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
int resolver(const std::vector<int> &v, int n) {

	int sum = 0;
	int max = v[0];
	int countMax = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == max)
			countMax++;
		
		else if (v[i] > max) {
			sum += max * countMax;
			max = v[i];
			countMax = 1;
		}

		else sum += v[i];
	}

	return sum;
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
	std::ifstream in("datos43.txt");
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