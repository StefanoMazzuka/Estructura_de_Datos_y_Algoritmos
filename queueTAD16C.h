#ifndef QUEUETAD16C_H
#define QUEUETAD16C_H

#include <iostream>
#include "queue_eda.h"
#include "Hour.h"

template <class T>
class QueueTAD16C : public queue<T> {
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

	void deleteEvens() {
		Nodo * aux = this->prim;
		while (aux->sig != nullptr && aux->sig->sig != nullptr) {
			this->nelems--;
			aux->sig = aux->sig->sig;
			aux = aux->sig;
		}
		if (aux->sig != nullptr)
			this->nelems--;
		this->ult = aux;
	}
};
#endif