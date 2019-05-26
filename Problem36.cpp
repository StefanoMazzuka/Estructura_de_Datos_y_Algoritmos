// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
std::vector<int> resolver(std::vector<int> v) {
	int lon = v.size();
	int j = 0;
	for (int i = 0; i < lon; i++) {
		if (v[i] % 2 == 0) {
			v[j] = v[i];
			j++;
		}
	}
	v.resize(j);

	return v;
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

	std::vector<int> sol = resolver(v);
	// escribir sol

	for (int data : sol)
		std::cout << data << " ";
	std::cout << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos36.txt");
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