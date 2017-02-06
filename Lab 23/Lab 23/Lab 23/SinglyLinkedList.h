#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class SinglyLinkedList {
public:
	// Constructor sin parámetros
	SinglyLinkedList() : _ini(nullptr) {}
    
	// Constructor copia
	SinglyLinkedList(SinglyLinkedList const& other) {
		_ini = copia(other._ini);
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
        }
        return *this;
    }
    
	// Operador de comparacion
	bool operator== (SinglyLinkedList<T> const& rhs) const {
		Nodo* aux1 = _ini; Nodo* aux2 = rhs._ini;
		while (aux1 != nullptr && aux2 != nullptr && aux1->_elem == aux2->_elem){
			aux1 = aux1->_sig;
			aux2 = aux2->_sig;
		}
		return (aux1 == nullptr && aux2 == nullptr);
	}
    
	// Añadir un nodo por el comienzo de la lista
	void push_front(T const& e) {
		Nodo * nuevo = new Nodo(e, _ini);
        _ini = nuevo;
	}
    
	// Elimina el nodo del comienzo de la lista
	void pop_front() {
		if (_ini == nullptr) throw std::invalid_argument("lista vacia");
		Nodo *aux = _ini;
		_ini = _ini->_sig;
		delete aux;
	}
	bool isEmpty() {
		if (_ini == nullptr) return true;
		else return false;
	}
	void elimina_max() {
		if (!isEmpty()) {
			Nodo * act, * prev, * max, * prevmax;
			act = _ini;
			prev = nullptr;
			max = act;
			prevmax = nullptr;
			while (act != nullptr)
			{
				if (act->_elem > max->_elem) {
					max = act;
					prevmax = prev;
				}
				prev = act;
				act = act->_sig;
			}
			if (max == _ini)_ini = _ini->_sig;
			else {
				prevmax->_sig = max->_sig;
			}
		}
	}
	void delete_closest(T aelim) {
		if (!isEmpty()) {
			Nodo * act = _ini;
			Nodo *prev = nullptr;
			while (act != nullptr) {
				if (act->_sig != nullptr) {
					if (calculaDif(act->_elem, aelim) > calculaDif(act->_sig->_elem, aelim)) {
						prev = act;
						act = act->_sig;
					}
					else {
						if (act != _ini) {
							prev->_sig = act->_sig;
							act = nullptr;
						}
						else {
							_ini = _ini->_sig;
							act = nullptr;
						}
					}
				}
				else {
					if (act == _ini) {
						_ini = nullptr;
					}
					else {
						prev->_sig = nullptr;
					}
					act = nullptr;
				}
			}
		}
	}
	T calculaDif( T el1, T el2) {
		T aux1 = el1 - el2;
		T aux2 = el2 - el1;
		return (aux1 > aux2) ? aux1 : aux2;
	}
	void muestra_lista() {
		Nodo* aux = _ini;
		while (aux != nullptr) {
			std::cout << aux->_elem << ' ';
			aux = aux->_sig;
		}
	}

    
private:
    
	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente.
	 */
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
