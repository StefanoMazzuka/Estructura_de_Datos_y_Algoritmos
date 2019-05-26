/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <vector>

//Coste O(2N) donde N es number
int com(std::vector<std::vector<int>> & matrix, int a, int b) {
	if (a == b || b == 0) return 1;
	else if (a == 0) return 0;

	if (matrix[a - 1][b - 1] == - 1) matrix[a - 1][b - 1] = com(matrix, a - 1, b - 1);
	if (matrix[a - 1][b] == - 1) matrix[a - 1][b] = com(matrix, a - 1, b);

	return matrix[a - 1][b - 1] + matrix[a - 1][b];
}

bool resuelveCaso() {

	int a, b;
	std::cin >> a >> b;
	if (!std::cin) return false;

	std::vector<std::vector<int>> matrix(a + 1, std::vector<int>(b + 1));

	for (int i = 0; i < a + 1; i++)
		for (int j = 0; j < b + 1; j++)
			matrix[i][j] = -1;

	std::cout << com(matrix, a, b) << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos19.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}