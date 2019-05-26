#ifndef QUEUETAD16D_H
#define QUEUETAD16D_H

#include <iostream>
#include "queue_eda.h"
#include "Hour.h"

template <class T>
class QueueTAD16D : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream & o = std::cout) {
		for (int i = 0; i < this->size(); ++i) {
			Hour elem = this->front();
			this->pop();
			std::cout << elem << ' ';
			this->push(elem);
		}
		std::cout << '\n';
	}

	void deleteMins() {
		Nodo * a = this->prim;
		Nodo * b = a->sig;
		int length = this->nelems;
		for (int i = 1; i < length; ++i) {
			if (a->elem < b->elem || a->elem == b->elem) {
				a->sig = b;
				a = a->sig;
			}
			else this->nelems--;
			b = b->sig;
		}
		this->ult = b;
	}
};
#endif