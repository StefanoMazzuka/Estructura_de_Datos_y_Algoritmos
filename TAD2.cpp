/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

#include "Hour.h"
#include "Movie.h"

bool minMax(Movie const &a, Movie const &b) {
	if (a.get_end() == b.get_end())
		return a.get_title() < b.get_title();

	if (a.get_end() < b.get_end())
		return true;

	return false;
}

void resuelveCaso(int movies) {

	std::vector<Movie> v(movies);

	std::string title;
	bool err = false;
	for (int i = 0; i < movies; i++) {
		try {
			Hour hStart, hEnd;
			std::cin >> hStart >> hEnd;
			std::getline(std::cin, title);
			Movie movie(hStart + hEnd, title);
			v[i] = movie;
		}
		catch (std::invalid_argument &ia) {
			std::cout << ia.what() << '\n';
			err = true;
		}
	}

	if (!err) {
		std::sort(v.begin(), v.end(), minMax);

		for (int i = 0; i < movies; i++) {
			std::cout << v[i] << '\n';
		}
	}

	std::cout << "---" << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD2.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int movies;
	std::cin >> movies;
	while (movies != 0) {
		resuelveCaso(movies);
		std::cin >> movies;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}