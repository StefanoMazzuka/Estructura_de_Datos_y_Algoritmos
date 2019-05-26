/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>

bool isValid(const std::vector<int> &toys, const std::vector<int> &ages, int i, int k) {

	if (toys[k] > ages[i])
		return false;

	return true;
}

bool isSolution(std::vector<int> count, int m, int sum, int maxSum) {
	bool sol = true;

	for (int i = 0; i < count.size(); i++) {
		if (count[i] < m)
		return false;
	}

	if (sum < maxSum)
		return false;

	return sol;
}

//Coste O(i^k)
void toysSol(const std::vector<int> &toys, const std::vector<int> &ages, const std::vector<std::vector<int>> &satisfaction,
	std::vector<int> &count, int j, int n, int m, int sum, int &maxSum, int k) {
	for (int i = 0; i < n; i++) {
		count[i]++;
		sum += satisfaction[i][k];
		if (isValid(toys, ages, i, k)) {
			if (k == j - 1) {
				if (isSolution(count, m, sum, maxSum))
					maxSum = sum;
			}
			else toysSol(toys, ages, satisfaction, count, j, n, m, sum, maxSum, k + 1);
		}
		count[i]--;
		sum -= satisfaction[i][k];
	}
}

bool resuelveCaso() {

	int j, n, m;
	std::cin >> j >> n >> m;

	if (j == 0 && n == 0 && m == 0)
		return false;

	std::vector<int> toys(j);
	for (int& data : toys) std::cin >> data;

	std::vector<int> ages(n);
	for (int& data : ages) std::cin >> data;

	std::vector<std::vector<int>> satisfaction(n, std::vector<int>(j));
	for (int i = 0; i < n; i++)
	for (int& data : satisfaction[i]) std::cin >> data;

	std::vector<int> count(n);

	int maxSum = 0;
	toysSol(toys, ages, satisfaction, count, j, n, m, 0, maxSum, 0);
	std::cout << maxSum << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos51.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}