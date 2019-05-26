#ifndef QUEUETAD10_H
#define QUEUETAD10_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD10 : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	// Esto sudar
	void print(std::ostream & o = std::cout) {
		for (int i = 0; i < this->size(); ++i) {
			int elem = this->front();
			this->pop();
			std::cout << elem << ' ';
			this->push(elem);
		}
		std::cout << '\n';
	}

	void add(QueueTAD10 q, int start) {
		if (start == 0) {
			Nodo * savedPosition = new Nodo(this->prim->elem, this->prim->sig);
			Nodo * current = new Nodo(q.prim->elem);
			this->prim = current;
			q.prim = q.prim->sig;
			this->nelems++;
			int length = q.size();
			for (int i = 1; i < length; ++i) {
				Nodo * newNode = new Nodo(q.prim->elem);
				q.prim = q.prim->sig;
				current->sig = newNode;
				current = current->sig;
				this->nelems++;
			}
			current->sig = savedPosition;
		}
		else if (start < this->nelems) {
			Nodo * current = new Nodo(this->prim->elem, this->prim->sig);
			this->prim = current;
			for (int i = 1; i < start; ++i) {
				current = current->sig;
			}

			Nodo * savedPosition = new Nodo(current->elem, current->sig);
			int length = q.size();
			for (int i = 0; i < length; ++i) {
				Nodo * newNode = new Nodo(q.prim->elem);
				q.prim = q.prim->sig;
				current->sig = newNode;
				current = current->sig;
				this->nelems++;
			}
			current->sig = savedPosition->sig;
		}
		else {
			int length = q.size();
			for (int i = 0; i < length; ++i) {
				Nodo * current = new Nodo(q.prim->elem);
				q.prim = q.prim->sig;
				this->ult->sig = current;
				this->ult = current;
				this->nelems++;
			}
		}
	}
};
#endif