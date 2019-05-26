/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
	Creo un data con un id que valdrá los pares desde 0 a n (0 2 4 6 ...)
	y el valor a añadir.
*/
struct data {
	int id;
	int value;
};
// Coste O(log(N - 1)) menos 1 porque la pos 0 tiene que ser par
int odd(std::vector<data> const& v, int start, int end) {
	if (start == end) return v[start].value;

	int m = (start + end) / 2;
	/*
		Resto el valor de m a la posicion inicial.
		Si m es 1 entonces:

		m:	   0 1 2 3  4
		id:    0 2 4 6  8
		value: 6 8 9 10 12

		value - v[0] == id? 
		8 - 6 == 2?

		si es true, avanzo a la derecha, sino, a la izq

		IMPORTANTE la pos 0 tiene que ser PAR
	*/
	if ((v[m].value - v[0].value) == v[m].id) return odd(v, m + 1, end); 
	else return odd(v, start, m);
}

void resuelveCaso(int lon) {

	std::vector<data> v(lon);
	int value;
	for (size_t i = 0; i < lon; i++) {
		std::cin >> value;
		v[i].value = value;
		if (i == 0) v[i].id = i;
		else v[i].id = v[i - 1].id + 2;
	}

	if (v[0].value % 2 != 0) std::cout << v[0].value << '\n';
	else std::cout << odd(v, 0, lon) << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos9.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int end;
	std::cin >> end;
	while (end != 0) {
		resuelveCaso(end);
		std::cin >> end;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}