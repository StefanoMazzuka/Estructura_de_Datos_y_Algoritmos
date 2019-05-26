// Stefano Mazzuka
// E36

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

// función que resuelve el problema
// COSTE O(n) siendo n el número de elementos del vector
int resolver(const std::vector<piedrasPreciosas> &v, int numGems, int lengthSeq,
	int numType1, int numType2, piedrasPreciosas type1, piedrasPreciosas type2) {

	int contType1 = 0;
	int contType2 = 0;
	for (int i = 0; i < lengthSeq; i++) {
		if (v[i] == type1)
			contType1++;
		else if (v[i] == type2)
			contType2++;
	}

	int sol = 0;
	if (contType1 >= numType1 && contType2 >= numType2)
		sol++;

	int start = 0;
	for (int i = lengthSeq; i < numGems; i++) {
		if (v[start] == type1)
			contType1--;
		else if (v[start] == type2)
			contType2--;
		start++;
		if (v[i] == type1)
			contType1++;
		else if (v[i] == type2)
			contType2++;
		if (contType1 >= numType1 && contType2 >= numType2)
			sol++;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int numGems;
	int lengthSeq;
	int numType1, numType2;
	piedrasPreciosas type1, type2;
	std::cin >> numGems >> lengthSeq >> type1 >> numType1 >> type2 >> numType2;

	std::vector<piedrasPreciosas> v(numGems);
	for (piedrasPreciosas& i : v) std::cin >> i;

	// escribir sol
	std::cout << resolver(v, numGems, lengthSeq, numType1, numType2, type1, type2) << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos41.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	while (numCasos > 0) {
		resuelveCaso();
		numCasos--;
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}