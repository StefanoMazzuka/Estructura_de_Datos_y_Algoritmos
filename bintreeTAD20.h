#ifndef BINTREE_TAD20_h
#define BINTREE_TAD20_h

#include "bintree_eda.h"

template <class T>
class bintreeTAD20 : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintreeTAD20() : bintree<T>() {}
	bintreeTAD20(bintreeTAD20<T> const& l, T const& e, bintreeTAD20<T> const& r) : bintree<T>(l, e, r) {}

	int showFrontiers() {
		return showFrontiersTree(this->raiz);
	}

	int showFrontiersTree(Link node) {
		if (node == nullptr) return 0;

		int left = showFrontiersTree(node->left);
		int right = showFrontiersTree(node->right);
		if (left + right == 0) std::cout << node->elem << ' ';

		return 1;
	}

private:

};

template <class T>
inline bintreeTAD20<T> leerArbolTAD20(T vacio) {
	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolTAD20(vacio);
		auto dr = leerArbolTAD20(vacio);
		return { iz, raiz, dr };
	}
}

#endif