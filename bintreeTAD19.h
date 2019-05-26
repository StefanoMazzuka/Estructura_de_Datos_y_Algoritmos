#ifndef BINTREE_TAD19_h
#define BINTREE_TAD19_h

#include "bintree_eda.h"

struct tData {
	int nNodes;
	int nLeafs;
	int height;
	tData() {
		nNodes = 0;
		nLeafs = 0;
		height = 0;
	}
	tData(int n, int l, int h) {
		nNodes = n;
		nLeafs = l;
		height = h;
	}
};

template <class T>
class bintreeTAD19 : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintreeTAD19() : bintree<T>() {}
	bintreeTAD19(bintreeTAD19<T> const& l, T const& e, bintreeTAD19<T> const& r) : bintree<T>(l, e, r) {}

	tData getData() {
		return getDataTree(this->raiz);
	}

	tData getDataTree(Link node) {
		if (node == nullptr) return {0, 0, 0};
		
		tData data;
		tData left = getDataTree(node->left);
		tData right = getDataTree(node->right);
		data.nNodes = left.nNodes + right.nNodes +1;
		data.height = 1 + std::max(left.height, right.height);
		if (left.height == 0 && right.height == 0) data.nLeafs = 1;
		else data.nLeafs = left.nLeafs + right.nLeafs;

		return data;
	}

private:

};

template <class T>
inline bintreeTAD19<T> leerArbolTAD19(T vacio) {
	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolTAD19(vacio);
		auto dr = leerArbolTAD19(vacio);
		return { iz, raiz, dr };
	}
}

#endif