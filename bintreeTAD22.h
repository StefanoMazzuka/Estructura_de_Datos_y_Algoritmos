#ifndef BINTREE_TAD22_h
#define BINTREE_TAD22_h

#include <string>
#include "bintree_eda.h"

struct tData {
	int leftAndRightPerimetre;
	int maxPerimetre;
	tData(int l, int m) {
		leftAndRightPerimetre = l;
		maxPerimetre = m;
	}
};

template <class T>
class bintreeTAD22 : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintreeTAD22() : bintree<T>() {}
	bintreeTAD22(bintreeTAD22<T> const& l, T const& e, bintreeTAD22<T> const& r) : bintree<T>(l, e, r) {}

	int getDiametre() {
		if (this->empty()) return 0;
		int maxDiametre;
		int diam = diametre(this->raiz, maxDiametre);
		return std::max(diam, maxDiametre);
	}

	int diametre(Link node, int &maxDiametre) {
		if (node == nullptr) {
			maxDiametre = 0;
			return 0;
		}

		int maxDleft, maxDright;
		int left = diametre(node->left, maxDleft);
		int right = diametre(node->right, maxDright);

		maxDiametre = std::max((left + right + 1), (std::max(maxDleft, maxDright)));
		return { (std::max(left, right) + 1) };
	}

private:

};

template <class T>
inline bintreeTAD22<T> leerArbolTAD22(T vacio) {
	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolTAD22(vacio);
		auto dr = leerArbolTAD22(vacio);
		return { iz, raiz, dr };
	}
}

#endif