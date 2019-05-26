/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
Creo un tSol con un isDegraded que valdrá true si es degradado
y un total que será la suma de sus valores.
*/
struct tSol {
	bool isDegraded;
	int total;
	tSol() {}
	tSol(bool isD, int t) {
		isDegraded = isD;
		total = t;
	}
};
// Coste O(log(N)) siendo N la longitud de v.
tSol degraded(std::vector<int> const& v, int start, int end) {

	if (start == end) {
		tSol sol(true, v[start]);
		return sol;
	}

	if (start + 1 == end) {
		if (v[start] < v[end]) {
			tSol sol(true, v[start] + v[end]);
			return sol;
		}
		else {
			tSol sol(false, 0);
			return sol;
		}
	}

	int m = (start + end) / 2;
	tSol solIz = degraded(v, start, m);
	if (solIz.isDegraded) {
		tSol solDr = degraded(v, m + 1, end);
		if (solDr.isDegraded) {
			if (solIz.total < solDr.total) {
				tSol sol(true, solIz.total + solDr.total);
				return sol;
			}
		}
	}

	tSol sol(false, 0);
	return sol;
}

bool resuelveCaso() {

	int n, m;
	std::cin >> n >> m;

	if (!std::cin) return false;

	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	int value;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> value;
			v[i][j] = value;
		}
	}

	int i = 0;
	bool isDegraded = true;
	while (i < n && isDegraded) {
		tSol sol = degraded(v[i], 0, m - 1);
		isDegraded = sol.isDegraded;
		i++;
	}

	if (isDegraded) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos14.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}