#ifndef QUEUETAD8A_H
#define QUEUETAD8A_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD8A : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream & o = std::cout) {
		std::cout << this->nelems << '\n';
		for (int i = 0; i < this->size(); ++i) {
			int elem = this->front();
			this->pop();
			std::cout << elem << ' ';
			this->push(elem);
		}
		std::cout << '\n';
	}

	void duplicate() {
		Nodo * newNode = new Nodo(this->prim->elem);
		if (this->prim->sig != NULL)
			newNode->sig = this->prim->sig;
		else this->ult = newNode;
		this->prim->sig = newNode;
		this->nelems++;
		Nodo * current = newNode->sig;

		while (current != NULL) {
			Nodo * newNode = new Nodo(current->elem);
			if (current->sig != NULL)
				newNode->sig = current->sig;
			else this->ult = newNode;
			current->sig = newNode;
			this->nelems++;
			current = newNode->sig;
		}
	}

	void addBack(int n) {
		Nodo * newNode = new Nodo(n);
		if (this->ult == NULL) { 
			this->ult = newNode; 
			this->prim = newNode;
		}
		else {
			this->ult->sig = newNode;
			this->ult = newNode;
		}
		this->nelems++;
	}

	void remove(int n) {
		for (int i = 0; i < n; i++) {
			this->prim = this->prim->sig;
			this->nelems--;
		}
	}
};
#endif