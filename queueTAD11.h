#ifndef QUEUETAD11_H
#define QUEUETAD11_H

#include <iostream>
#include "queue_eda.h"

template <class T>
class QueueTAD11 : public queue<T> {
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

	void sort(QueueTAD11<int> q) {
		if (q.prim == nullptr)
			return;

		Nodo * start = this->prim;
		if (this->prim->elem > q.prim->elem) {
			start = q.prim;
			q.prim = q.prim->sig;
		}
		else this->prim = this->prim->sig;

		Nodo * n = start;
		int length = this->size() + q.size();
		for (int i = 1; i < length; ++i) {
			if (this->prim != nullptr && q.prim != nullptr && 
				this->prim->elem > q.prim->elem || 
				this->prim == nullptr && q.prim != nullptr) {
				n->sig = q.prim;
				q.prim = q.prim->sig;		
			}
			else if (this->prim != nullptr) {
				n->sig = this->prim;
				this->prim = this->prim->sig;
			}
			n = n->sig;
		}
		this->ult = n;
		this->nelems += q.size();
		this->prim = start;
	}
};
#endif