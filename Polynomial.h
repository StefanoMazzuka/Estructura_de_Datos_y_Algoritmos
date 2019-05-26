#ifndef POLUNOMIAL_H_
#define POLUNOMIAL_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Polynomial {

public:

	// Constructora
	Polynomial() {};

	std::vector<int> get_v() const { return this->v; };

	void addMonomial(int coefficient, int exponent) {
		this->v.push_back(coefficient);
		this->v.push_back(exponent);
	}

	int result(int data) {
		int length = v.size();
		int result = 0;
		for (int i = 0; i < length; i += 2) {
			result += v[i] * pow(data, v[i + 1]);
		}

		return result;
	}

private:
	std::vector<int> v;
};
#endif