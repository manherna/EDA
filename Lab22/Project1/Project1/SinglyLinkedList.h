#pragma once
#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>


template <class T>
class SinglyLinkedList {
public:
	// Constructor sin parámetros
	SinglyLinkedList() : _ini(nullptr), tam(0){}

	// Constructor copia
	SinglyLinkedList(SinglyLinkedList const& other) {
		_ini = copia(other._ini);
		tam = other.size();
	}

	// destructor
	~SinglyLinkedList() {
		libera(_ini);
		_ini = nullptr;
	}

	// Operador de asignación
	SinglyLinkedList<T> &operator=(SinglyLinkedList<T> const& other) {
		if (this != &other) {
			libera(_ini);
			_ini = copia(other._ini);
			tam = other.size();
		}
		return *this;
	}

	// Operador de comparacion
	bool operator== (SinglyLinkedList<T> const& rhs) const {
		Nodo* aux1 = _ini; Nodo* aux2 = rhs._ini;
		while (aux1 != nullptr && aux2 != nullptr && aux1->_elem == aux2->_elem) {
			aux1 = aux1->_sig;
			aux2 = aux2->_sig;
		}
		return (aux1 == nullptr && aux2 == nullptr);
	}

	// Añadir un nodo por el comienzo de la lista
	void push_front(T const& e) {
		Nodo * nuevo = new Nodo(e, _ini);
		_ini = nuevo;
		tam++;
	}

	// Elimina el nodo del comienzo de la lista
	void pop_front() {
		if (_ini == nullptr) throw std::invalid_argument("lista vacia");
		Nodo *aux = _ini;
		_ini = _ini->_sig;
		delete aux;
		tam--;
	}
	//DuplicaLista
	void duplicate_list () {
		Nodo * aux = _ini;
		Nodo* aux2;
		while (aux != nullptr) {
			aux2 = aux->_sig;
			Nodo * nuevo = copia(aux2);
			aux->sig = nuevo;
			tam++;
		}
		aux = nullptr;
		aux2 = nullptr;
	}
	void print_list() {
		Nodo * aux = _ini;
		while (aux != nullptr) {
			cout << aux->_elem << " ";
			aux = aux->_sig;
		}
	}
	int size() {
		return tam;
	}
	//Método para eliminar el mayor de la lista. Coste lineal
	void eliminaMayor(){
		Nodo * actual = _ini;
		Nodo * previo = nullptr;


		while (actual != nullptr) {
			//Caso de que el mayor sea el primero.
			if (actual == _ini) {
				if (_ini->_sig->_elem < _ini->_elem) {
					_ini = _ini->_sig;
					actual = _ini;
					previo = nullptr;
					tam--;
				}
			}
			else {
				if (actual->_sig->_elem < actual->_elem) {
					previo->_sig = actual->_sig;
					actual = actual->_sig;
					tam--;
				}
				else {
					previo = actual;
					actual = actual->_sig;
				}
			}
		

		}
	}
	//Metodo para invertir la lista
	void invert() {
		Nodo * aux = _ini->_sig;
		Nodo * aux2 = aux->_sig;
		_ini->_sig = nullptr;
		while (aux != nullptr) {
			aux->_sig = _ini;
			_ini = aux;
			aux = aux2;
			if(aux!= nullptr)aux2 = aux->_sig;
		}
	}





private:

	/**
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente.
	*/
	int tam;
	class Nodo {
	public:
		Nodo() : _sig(nullptr) {}
		Nodo(const T &elem) : _elem(elem), _sig(nullptr) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	// Puntero al primer elemento
	Nodo *_ini;

	// libera todos los nodos de la lista
	void libera(Nodo *ini) {
		while (ini != nullptr) {
			Nodo *aux = ini;
			ini = ini->_sig;
			delete aux;
		}
	}

	// Copia el parámetro en la lista.
	// La lista debe estar vacia.
	Nodo* copia(Nodo* other) {
		if (other == nullptr) return nullptr;
		else if (other->_sig == nullptr) {
			Nodo* nuevo = new Nodo(other->_elem);
			return nuevo;
		}
		else {
			Nodo* aux = copia(other->_sig);
			Nodo* nuevo = new Nodo(other->_elem, aux);
			aux = nuevo;
			return aux;
		}
	}

};

#endif // _SINGLY_LINKED_LIST_H
