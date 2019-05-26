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

	int n, l;
	std::cin >> n >> l;

	if (n == 0 && l == 0) return false;

	std::vector<int> v(n);
	for (int& data : v) std::cin >> data;

	int j = n - 1;
	int pos = j;
	int count = 1;
	int total = 0;
	std::vector<int> sol;
	for (int i = n - 2; i >= 0; i--) {
		if (v[j] + 1 == v[i] || v[j] - 1 == v[i] || v[j] == v[i]) {
			count++;
		}
		else {
			if (count >= l) {
				total++;
				sol.push_back(i + 1);
			}
			count = 1;
		}
		if (i == 0) {
			if (count >= l) {
				total++;
				sol.push_back(i);
			}
			count = 1;
		}
		j--;
	}

	std::cout << total << " ";
	if (total != 0)
	for (int i = sol.size() - 1; i >= 0; i--)
		std::cout << sol[i] << " ";
	std::cout << '\n';

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos50.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}