/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tSol {
	bool end;
	bool exist;
	int pos;
	int posStart;
	int posEnd;
	tSol(bool en, bool ex, int p, int ps, int pe) {
		end = en;
		exist = ex;
		pos = p;
		posStart = ps;
		posEnd = pe;
	}
};

// Coste O(LogN) donde N es son los elementos del vector 
tSol point(const std::vector<int> &v1, const std::vector<int> &v2, int start, int end) {
	if (start == end) {
		if (v1[start] == v2[start]) {
			tSol sol(true, true, start, start, end);
			return sol;
		}
		if (v1[start] > v2[start]) {
			tSol sol(true, false, 0, start - 1, end);
			return sol;
		}

		tSol sol(false, false, 0, start, end);
		return sol;
	}
	else if (start + 1 == end) {
		if (v1[start] == v2[start]) {
			tSol sol(true, true, start, start, end);
			return sol;
		}
		if (v1[end] == v2[end]) {
			tSol sol(true, true, end, start, end);
			return sol;
		}

		if (v1[start] < v2[start] && v1[end] > v2[end]) {
			tSol sol(true, false, 0, start, end);
			return sol;
		}

		if (v1[start] > v2[start]) {
			tSol sol(true, false, 0, start - 1, start);
			return sol;
		}

		tSol sol(false, false, 0, start, end);
		return sol;
	}

	int m = (start + end) / 2;

	tSol left = point(v1, v2, start, m);
	if (left.end) return left;

	tSol right = point(v1, v2, m + 1, end);
	if (right.end) return right;

	tSol sol(false, false, 0, start, end);
	return sol;
}

void resuelveCaso(int lon) {

	std::vector <int> v1(lon);
	for (int & n : v1) std::cin >> n;

	std::vector <int> v2(lon);
	for (int & m : v2) std::cin >> m;

	tSol sol = point(v1, v2, 0, lon - 1);
	if (sol.exist) std::cout << "SI" << " " << sol.pos << '\n';
	else if (sol.posStart == 0 && sol.posEnd == 0)
		std::cout << "NO" << " " << sol.posStart << " " << sol.posEnd + 1 << '\n';
	else if (sol.posStart == 0 && sol.posEnd == lon - 1)
		std::cout << "NO" << " " << sol.posEnd << " " << sol.posEnd + 1 << '\n';
	else std::cout << "NO" << " " << sol.posStart << " " << sol.posEnd << '\n';
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos49.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int lon;
	std::cin >> lon;
	while (lon > 0) {
		resuelveCaso(lon);
		std::cin >> lon;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}