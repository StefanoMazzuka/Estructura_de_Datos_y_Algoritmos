#ifndef MYSET_H_
#define MYSET_H_

/*
E36
Stefano Mazzuka
*/

# include <iostream>
# include <cstddef> // size_t
# include <stdexcept> // std :: domain_error
# include <utility> // std :: moveclass set
# include <algorithm>
# include <vector>

template <typename T>
class myset {
public:
	myset(size_t k); // constructor
	myset(myset<T> const &other); // constructor por copia
	myset<T> & operator=(myset<T> const &other); // operador de asignación
	~myset(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase();
	bool empty() const;
	size_t size() const;
	void show();
private:
	bool isEmpty;
	size_t contador;
	size_t capacidad;
	T * datos; // sin repeticiones
	void amplia();
	void libera();
	void copia(myset<T> const &other);
};
// Constructor
template <typename T>
myset<T>::myset(size_t k) : isEmpty(true), contador(0), capacidad(k + 1), datos(new T[capacidad]) {}
// Destructor
template <typename T>
myset<T>::~myset() { libera(); }
// Op. privada que libera la memoria dinamica
template <typename T>
void myset<T>::libera() { delete[] datos; }
// constructor por copia
template <typename T>
myset<T>::myset(myset<T> const &other) {
	copia(other);
}
// operador de asignación
template <typename T>
myset<T> &myset<T>::operator=(myset<T> const &other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}
// Op. privada que copia el contenido de un vector
template <typename T>
void myset<T>::copia(myset<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}
// Operacion para añadir elementos
template <typename T>
void myset<T>::insert(T e) {
	if (!contains(e)) {
		if (contador == capacidad) erase();
		datos[contador] = e;
		++contador;
		std::sort(datos, datos + contador);
	}
}
// Op. privada que amplia la memoria del vector
template <typename T >
void myset<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}
// Operacion que comprueba si un elemento pertenece al conjunto
template <typename T >
bool myset<T>::contains(T e) const {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}
// Operacion que elimina un elemento del conjuto
// Lanza una excepcion si el elemento no esta
template <typename T>
void myset<T>::erase() {
	--contador;
	for (size_t i = 0; i < contador; i++){
		datos[i] = datos[i + 1];
	}
}
// Comprueba si el conjunto esta vacio
template <typename T>
bool myset<T>::empty() const {
	return isEmpty;
}
// Obtiene el numero de elementos del conjunto
template <typename T>
size_t myset<T>::size() const {
	return contador;
}

template <typename T>
void myset<T>::show() {
	for (size_t i = 1; i < contador; i++) {
		std::cout << datos[i] << ' ';
	}
}
#endif