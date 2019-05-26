// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int start;
	int end;
	int lon;
<<<<<<< HEAD
	int maxValue;
	tSol(int s, int e, int l, int mv) {
		start = s;
		end = e;
		lon = l;
		maxValue = mv;
=======
	int sum;
	tSol(int st, int e, int l, int su) {
		start = st;
		end = e;
		lon = l;
		sum = su;
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}
};

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
tSol resolver(const std::vector<int> &v, int n) {

<<<<<<< HEAD
	tSol sol(0, 0, 0, 0);
	int start = 0;
	for (int i = 0; i < n; i++) {

=======
	tSol sol(n - 1, 0, 0, 0);
	int sum = 0;
	int lon = 0;
	for (int i = n - 1; i >= 0; i--) {
		
		sum += v[i];
		lon++;

		if (sum <= 0) {
			sum = 0;
			lon = 0;
		}

		else if (sum > sol.sum) {
			sol.sum = sum;
			sol.start = i;
			sol.lon = lon;
		}

		else if (sum == sol.sum && lon <= sol.lon) {
			sol.sum = sum;
			sol.start = i;
			sol.lon = lon;
		}
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}

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

	tSol sol = resolver(v, n);

	// escribir sol
<<<<<<< HEAD
	std::cout 
		<< sol.maxValue << " " 
		<< sol.start << " " 
=======
	std::cout
		<< sol.sum << " "
		<< sol.start << " "
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
		<< sol.lon << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos45.txt");
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