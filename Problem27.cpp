/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

struct tSol {
	std::vector<int> v;
	int bestTime;
};

bool isValid(std::vector<int> accumulated, int k, int currentTime) {
	return currentTime <= accumulated[k];
}

bool isSolution(int bestTime, int currentTime) {
	return bestTime > currentTime;
}

//Coste O(m^n)
void optimizeTimes(std::vector<std::vector<int>> employees, std::vector<int> sol, 
	std::vector<int> accumulated, int numEmployees, int k, int& bestTime, int currentTime) {

	for (int i = k; i < numEmployees; i++) {
		sol[k] = employees[k][i];
		currentTime += sol[k];

		if (isValid(accumulated, k, currentTime)) {
			if (k == numEmployees - 1) {
				if (isSolution(bestTime, currentTime))
					bestTime = currentTime;
			}
			
			else optimizeTimes(employees, sol, accumulated, numEmployees, k + 1, bestTime, currentTime);
		}

		currentTime -= employees[k][i];
	}
}

void resuelveCaso(int numEmployees) {

	std::vector<int> minValues(numEmployees);
	std::vector<std::vector<int>> employees(numEmployees, std::vector<int>(numEmployees));
	int time;
	int minTime = std::numeric_limits<int>::max();
	for (int i = 0; i < numEmployees; i++) {
		for (int j = 0; j < numEmployees; j++) {
			std::cin >> time;
			employees[i][j] = time;
			if (time < minTime) {
				minValues[i] = time;
				minTime = time;
			}
		}
		minTime = INT_MAX;
	}

	std::vector<int> accumulated(numEmployees);
	accumulated[numEmployees - 1] = minValues[numEmployees - 1];
	for (int i = numEmployees - 2; i >= 0; i--) {
		accumulated[i] = minValues[i] + accumulated[i + 1];
	}

	std::vector<int> sol(numEmployees);
	int bestTime = INT_MAX;
	optimizeTimes(employees, sol, accumulated, numEmployees, 0, bestTime, 0);

	std::cout << bestTime << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos27.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numEmployees;
	std::cin >> numEmployees;
	while (numEmployees != 0) {
		resuelveCaso(numEmployees);
		std::cin >> numEmployees;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}