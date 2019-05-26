/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Coste O(LogN) donde N es son los elementos del vector 
int galactica(std::vector <int> &v, int start, int end) {
	if (start == end)
		return 0;

	int m = (start + end) / 2;
	int left = galactica(v, start, m);
	int right = galactica(v, m + 1, end);

	int i = start;
	int j = m + 1;
	int count = 0;
	while (i <= m && j <= end) {
		if (v[i] > v[j]) {
			count += (m - i + 1);
			j++;
		}
		else i++;
	}

	std::sort(v.begin() + start, v.begin() + end + 1);

	return left + right + count;
}

bool resuelveCaso() {
	int lon;
	std::cin >> lon;
	if (!std::cin) return false;

	std::vector <int> v(lon);
	for (int & n : v) std::cin >> n;

	std::cout << galactica(v, 0, v.size() - 1) << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos16.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}