#ifndef QUEUETAD9_H
#define QUEUETAD9_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD9 : public queue<T> {
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

	void invert() {
		if (this->size() > 1) {
			T n = this->front();
			this->pop();
			invert();
			this->push(n);
		}
	}
};
#endif