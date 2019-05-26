/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
IDEA:
*/
// Coste O  2*logN*N
int searchLeft(std::vector<int> const& v, int start, int end, int theSuspect) {
	if (start == end) return start;

	int m = (start + end) / 2;
	if (v[m] < theSuspect) return searchLeft(v, m + 1, end, theSuspect);
	return searchLeft(v, start, m, theSuspect);
}

int searchRight(std::vector<int> const& v, int start, int end, int theSuspect) {
	if (start == end) return start;

	else if (start + 1 == end)  {
		if (v[end] == theSuspect) return end;
		else return start;
	}

	int m = (start + end) / 2;
	if (v[m] > theSuspect) return searchRight(v, start, m - 1, theSuspect);
	return searchRight(v, m, end, theSuspect);
}

bool resuelveCaso() {

	int N, theSuspect;
	std::cin >> N >> theSuspect;

	if (!std::cin) return false;

	std::vector<int> v(N);
	int value;
	for (size_t i = 0; i < N; i++) {
		std::cin >> value;
		v[i] = value;
	}

	int start = searchLeft(v, 0, N - 1, theSuspect);
	if (v[start] != theSuspect) std::cout << "NO EXISTE" << '\n';
	else {
		int end = searchRight(v, 0, N - 1, theSuspect);

		if (start == end) std::cout << start << '\n';
		else std::cout << start << " " << end << '\n';
	}

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos11.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}