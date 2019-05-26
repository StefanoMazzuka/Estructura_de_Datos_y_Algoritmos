#ifndef QUEUETAD16B_H
#define QUEUETAD16B_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD16B : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream & o = std::cout) {
		for (int i = 0; i < this->size(); ++i) {
			int elem = this->front();
			this->pop();
			std::cout << elem << ' ';
			this->push(elem);
		}
		std::cout << '\n';
	}

	void sol() {
		Nodo * aux = this->prim;
		this->prim = invert(aux);
	}

	Nodo * invert(Nodo * node) {
		// Es el ultimo
		if (node->sig == nullptr) return node;
		// Son los dos ultimos
		if (node->sig->sig == nullptr) {
			Nodo * aux = node->sig;
			aux->sig = node;
			node->sig = nullptr;
			this->ult = node;
			return aux;
		}
		Nodo * saved = node->sig->sig;
		Nodo * aux = node->sig;
		aux->sig = node;
		node->sig = invert(saved);
		return aux;
	}
};
#endif