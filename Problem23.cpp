/*
Stefano Mazzuka
E36
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tSol {
	int weight;
	int balanced;
	tSol() { weight = 0; balanced = false; }
	tSol(int w, int b) {
		weight = w;
		balanced = b;
	}
};

<<<<<<< HEAD
//Coste O(nLogn)
tSol movil() {
	int p1, d1, p2, d2;
	std::cin >> p1 >> d1 >> p2 >> d2;

	if (p1 > 0 && p2 > 0) {
		if (p1 * d1 == p2 * d2) {
			tSol sol(p1 + p2, true);
			return sol;
		}
		else {
			tSol sol(p1 + p2, false);
			return sol;
		}
	}

	tSol left;
	tSol right;
	if (p1 == 0) {
		left = movil();
	}

	if (p2 == 0) {
		right = movil();
	}

	if (left.weight * d1 == right.weight * d2 && 
		left.balanced && right.balanced) {
		tSol sol(left.weight + right.weight, true);
		return sol;
	}

	tSol sol(left.weight + right.weight, false);
	return sol;
}

void resuelveCaso() {

	tSol sol = movil();

	if (sol.balanced) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

=======
//Coste O(n)
bool movil(int &p) {
	
	int p1, d1, p2, d2;
	std::cin >> p1 >> d1 >> p2 >> d2;

	bool left = true;
	if (p1 == 0) left = movil(p1);

	bool right = true;
	if (p2 == 0) right = movil(p2);

	if (p1 * d1 == p2 * d2 && left && right) {
		p = p1 + p2;
		return true;
	}

	return false;
}

void resuelveCaso() {
	int p = 0;
	if (movil(p)) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos23.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCases;
	std::cin >> numCases;
	while (numCases > 0) {
		resuelveCaso();
		numCases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}