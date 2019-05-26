/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>

<<<<<<< HEAD
bool isValid(std::vector<int> accumulated, int k, int currentTime) {
	return currentTime <= accumulated[k];
}

bool isSolution(int bestTime, int currentTime) {
	return bestTime > currentTime;
}

//Coste O(m^n)
void coats(std::vector<std::vector<int>> employees, std::vector<int> sol,
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
	int minTime = INT_MAX;
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
=======
bool isValid(std::vector<int> const& sol, std::vector<int> const& rain,
	std::vector<int> const& coats, int k, int i, std::vector<int> const& contCoats) {
	
	// El abrigo tiene que soportar la lluvia.
	if (coats[sol[k]] < rain[k])
		return false;

	if (k > 0) {
		// No se usa un abrigo dos días seguidos.
		if (sol[k - 1] == sol[k])
			return false;

		// El abrigo que más haya usado no supere en dos días 
		// o más a un tercio de los días que van transcirridos.
		if (contCoats[i] > 2 + (k / 3))
			return false;
	}

	return true;
}

bool isSolution(std::vector<int> const& sol) {
	return sol[0] != sol[sol.size() - 1];
}

//Coste O(m^n) donde m son el número de abrigos y n los días.
void coatsCombinations(std::vector<int> sol, std::vector<int> const& rain,
	std::vector<int> const& coats, std::vector<int> contCoats, int n, int a, int k, int& numCoats) {
	for (int i = 0; i < a; i++) {
		sol[k] = i;
		contCoats[i]++;

		if (isValid(sol, rain, coats, k, i, contCoats)) {
			if (k == n - 1) {
				if (isSolution(sol))
					numCoats++;
			}
			else coatsCombinations(sol, rain, coats, contCoats, n, a, k + 1, numCoats);
		}
		contCoats[i]--;
	}
}

void resuelveCaso(int n, int a) {

	std::vector<int> rain(n);
	for (int& value : rain) std::cin >> value;

	std::vector<int> coats(a);
	for (int& value : coats) std::cin >> value;

	std::vector<int> sol(n);
	std::vector<int> contCoats(a);

	int numCoats = 0;
	coatsCombinations(sol, rain, coats, contCoats, n, a, 0, numCoats);

	if (numCoats > 0) std::cout << numCoats << '\n';
	else std::cout << "Lo puedes comprar" << '\n';
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos29.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
<<<<<<< HEAD
	int numEmployees;
	std::cin >> numEmployees;
	while (numEmployees != 0) {
		resuelveCaso(numEmployees);
		std::cin >> numEmployees;
=======
	int n, a;
	std::cin >> n >> a;
	while (n != 0 && a != 0) {
		resuelveCaso(n, a);
		std::cin >> n >> a;
>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
<<<<<<< HEAD
=======

>>>>>>> 0fb7c0f4b4f2ba1038c740fff7c80adf4b2cb187
}