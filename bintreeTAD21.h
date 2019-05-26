#ifndef BINTREE_TAD21_h
#define BINTREE_TAD21_h

#include <string>
#include "bintree_eda.h"

template <class T>
class bintreeTAD21 : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintreeTAD21() : bintree<T>() {}
	bintreeTAD21(bintreeTAD21<T> const& l, T const& e, bintreeTAD21<T> const& r) : bintree<T>(l, e, r) {}

	T getMin() {
		if (this->empty()) return 0;
		return getMinTree(this->raiz);
	}

	T getMinTree(Link node) {
		if (node->left == nullptr && node->right == nullptr) 
			return node->elem;

		T left = node->elem; 
		T right = node->elem;
		if (node->left != nullptr)
			left = getMinTree(node->left);
		if (node->right != nullptr) 
			right = getMinTree(node->right);

		return std::min(node->elem, std::min(left, right));
	}

private:

};

template <class T>
inline bintreeTAD21<T> leerArbolTAD21(T vacio) {
	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolTAD21(vacio);
		auto dr = leerArbolTAD21(vacio);
		return { iz, raiz, dr };
	}
}

#endif