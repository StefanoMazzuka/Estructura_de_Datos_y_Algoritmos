#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <stdexcept>
#include <algorithm>

class Complex {

public:

	Complex() {};
	Complex(float real, float imaginary) : real(real), imaginary(imaginary) {};

	float get_real() const { return this->real; };
	float get_imaginary() const { return this->imaginary; };

	Complex operator+(Complex const &c) const {
		Complex result(this->real + c.get_real(),
			this->imaginary + c.get_imaginary());

		return result;
	}

	Complex operator*(Complex const &c) const {
		Complex result(this->real * c.get_real() - this->imaginary * c.get_imaginary(), 
			this->real * c.get_imaginary() + c.get_real() * this->imaginary);

		return result;
	}

	float modul() {
		return sqrt(this->real * this->real + 
			this->imaginary * this->imaginary);
	}
private:
	float real;
	float imaginary;
};
#endif