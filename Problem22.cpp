/*
Stefano Mazzuka
E36
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tSol {
	int winner;
	int count;
	tSol(int w, int c) {
		winner = w;
		count = c;
	}
};

//Coste O(nLogn)
tSol tennis(std::vector<int> &v, int start, int end, int &matches, int rounds) {
	if (start + 1 == end) {

		if (v[start] == 1 && v[end] == 0 ||
			v[start] == 0 && v[end] == 1) {
			tSol sol(1, 1);
			return sol;
		}

		if (v[start] == 0 && v[end] == 0) {
			tSol sol(0, 1);
			return sol;
		}

		matches++;
		tSol sol(1, 1);
		return sol;
	}

	int m = (start + end) / 2;
	tSol left = tennis(v, start, m, matches, rounds);
	tSol right = tennis(v, m + 1, end, matches, rounds);

	if (left.count == rounds)
		return left;

	if (left.winner == 1 && right.winner == 0 ||
		left.winner == 0 && right.winner == 1) {
		tSol sol(1, left.count + 1);
		return sol;
	}

	if (left.winner == 0 && right.winner == 0) {
		tSol sol(0, left.count + 1);
		return sol;
	}

	matches++;
	tSol sol(1, left.count + 1);
	return sol;
}

bool resuelveCaso() {

	int n, rounds;
	std::cin >> n >> rounds;
	if (!std::cin) return false;

	std::vector<int> v(n);

	std::string data;
	for (int i = 0; i < n; i++) {
		std::cin >> data;
		if (data != "NP")
			v[i] = 1;
		else v[i] = 0;
	}

	int matches = 0;
	tSol sol = tennis(v, 0, n - 1, matches, rounds);
	std::cout << matches << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos22.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}