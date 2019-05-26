/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Solucion recursiva final de O(logN)

/*
	IDEA: Ya que la curva realiza lo siugiente:

7		\
6	     \
5	      \
4	\
3	 \
2	  \
1	   *

	Todo lo que esté a la derecha del valor mínimo (*) 
	será mayor que el punto inicial (4)
	y lo que esté a la izquierda será menor que (4).
*/
int rotation(std::vector<int> const& v, int start, int end) {
	if (start == end) return v[start]; // Caso base si queda 1 elemento
	else if (start + 1 == end) { // Caso base si quedan 2 elementos devuelve el menor
		if (v[start] < v[end]) return v[start];
		else return v[end];
	}
	int m = (start + end) / 2; // Calculamos el punto medio
	if (v[0] > v[m]) return rotation(v, m, end); // Comparamos el contenido del punto medio con el de la primer posición
	else return rotation(v, start, m - 1);
}
bool resuelveCaso() {
	int lon;
	std::cin >> lon;

	if (!std::cin) return false;

	std::vector<int> v(lon);
	int value;
	for (size_t i = 0; i < lon; i++) {
		std::cin >> value;
		v[i] = value;
	}

	std::cout << rotation(v, 0, lon - 1) << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos8.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}