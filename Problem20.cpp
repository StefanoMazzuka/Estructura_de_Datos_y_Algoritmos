/*
Stefano Mazzuka
E36
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
<<<<<<< HEAD

//Coste O(2N) donde N es number
int com(std::vector<std::vector<int>> & matrix, int a, int b) {
	if (a == b || b == 0) return 1;
	else if (a == 0) return 0;

	if (matrix[a - 1][b - 1] == -1) matrix[a - 1][b - 1] = com(matrix, a - 1, b - 1);
	if (matrix[a - 1][b] == -1) matrix[a - 1][b] = com(matrix, a - 1, b);

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
=======
#include <algorithm>

//Coste O(n)
void sum(std::vector<int> const& v, int n, int s) {

	std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(s + 1)); // n = número de objetos, M = peso máximo de la mochila.

	// Rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= s; ++j) {
			if (v[i] > j) {
				std::cout << v[i] << '\n';
				matrix[i][j] = matrix[i - 1][j];
			}

			else matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - v[i]]);
		}
	}
}

bool resuelveCaso() {
	int n, s;
	std::cin >> n >> s;

	if (!std::cin) return false;

	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) std::cin >> i;

	sum(v, n, s);
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos20.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}