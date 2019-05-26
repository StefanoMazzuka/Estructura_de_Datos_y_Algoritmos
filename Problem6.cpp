/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Solucion recursiva final de O(logN)
int whoScapes(std::vector<int> const& v, int start, int end) {
	if (start == end) { 
		if (v[start] == start) return start + 1;
		return start;
	}

	int m = (start + end) / 2;
	if (v[m] == m) return whoScapes(v, m + 1, end);
	else return whoScapes(v, start, m);
}
void resuelveCaso() {
	char startChar, endChar;
	std::cin >> startChar >> endChar;
	int start = startChar - 'a', end = endChar - 'a';

	std::vector<int> v(27);
	std::string letters;
	std::cin.ignore();
	std::getline(std::cin, letters);
	int pos = start;
	for (size_t i = 0; i < letters.size(); i += 2) {
		v[pos] = (letters[i] - 'a');
		pos++;
	}

	char sol = (whoScapes(v, start, end - 1)) + 'a';
	std::cout << sol << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos6.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numInputs;
	std::cin >> numInputs;
	for (size_t i = 0; i < numInputs; i++) {
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}