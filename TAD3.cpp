/*
Stefano Mazzuka
*/

#include <iostream>
#include <fstream>

#include "Complex.h"

bool mandelbrot(Complex count, Complex const& c, int i) {
	if (count.modul() > 2) return false;
	if (i < 0) return true;

	i--;
	mandelbrot(count * count + c, c, i);
}

void resuelveCaso() {

	float real, imaginary, i;
	std::cin >> real >> imaginary >> i;

	Complex c(real, imaginary);
	Complex count(0, 0);

	if (mandelbrot(count, c, i)) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("TAD3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int nCases;
	std::cin >> nCases;
	while (nCases > 0) {
		resuelveCaso();
		nCases--;
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}