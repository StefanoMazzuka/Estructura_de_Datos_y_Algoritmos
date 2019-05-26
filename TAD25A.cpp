//*****************
// IMPORTANTE
//
// Stefano Mazzuka
// E36
// E19
//
//***************************************************

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tData {
	int age;
	int height;
	int isGen;
	tData() {
		age = 0;
		height = 0;
		isGen = false;
	}
	tData(int a, int h, int g) {
		age = a;
		height = h;
		isGen = g;
	}
};

// Aqui función del alumno

// COSTE CASO PEOR O(N) lineal donde N es el número de nodos (Hay que recorrerlos todos)
// COSTE CASO MEDIO O(LogN) donde N es el número de nodos
tData isGenealog(const bintree<int> &tree) {
	if (tree.empty()) return { -1, 0, true };

	tData left = isGenealog(tree.left());
	tData right = isGenealog(tree.right());

	tData data;
	data.age = tree.root();
	data.height = std::max(left.height, right.height) + 1;

	// Si ambos hijos son genealógicos continuo comprobando
	if (left.isGen && right.isGen) {
		// Si no tiene hijos, es genealógico
		if (left.age == -1 && right.age == -1) data.isGen = true;
		// Si solo tiene un hijo derecho y su edad es inferior a 18 de la del padre, es genealógico
		else if (left.age != -1 && right.age == -1 
			&& data.age - left.age >= 18) data.isGen = true;
		// Si tiene un hijo derecho y uno izquierdo, y la diferencia de edad entre los hijos como minimo 2 y
		// la diferencia de edad entre los hijos y el padre es como mínimo 18, es genealógico
		else if (left.age != -1 && right.age != -1 
			&& left.age - right.age >= 2 
			&& right.age <= data.age - 18 
			&& left.age <= data.age - 18) data.isGen = true;
		// En cualquier otro caso, no es genealógico
		else data.isGen = false;
	}

	return data;
}

void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);

	// LLamada a la funcion y escribir resultados
	// A rellenar por el alumno
	tData data = isGenealog(tree);

	if (data.isGen) std::cout << "SI " << data.height << '\n';
	else std::cout << "NO" << '\n';
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("TAD25A.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

	int numCasos; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) { resuelveCaso(); }

	// Para restablecer entrada. 

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
