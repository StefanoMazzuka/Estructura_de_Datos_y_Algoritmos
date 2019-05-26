#ifndef QUEUETAD12_H
#define QUEUETAD12_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD12 : public queue<T> {
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

	void find(int saved) {
		this->ult = this->prim;
		while (this->nelems != 1) {
			for (int i = 0; i < saved; ++i) {
				this->prim = this->prim->sig;
			}
			this->prim = 
		}
	}
};
#endif