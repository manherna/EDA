// Grupo 14, Manuel Hernández
// Eliminamos el n numero de máximos segun nos pidan de una lista enlazada.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "SinglyLinkedList.h"
using namespace std;

class Horas {
public:
	//Metodos
	Horas() : h(0), m(0), s(0) {};
	Horas(int horas, int minutos, int segundos) {
		if (horas > 23 || minutos > 60 || segundos > 60) throw std::invalid_argument("ERROR");
		else if (horas < 0 || minutos < 0 || segundos < 0) throw std::invalid_argument("ERROR");
		else {
			h = horas;
			m = minutos;
			s = segundos;
			ts = h * 3600 + m * 60 + s;
		}
	};
	friend istream & operator >> (istream & in, Horas & h) {
		try {
			int aux1, aux2, aux3;
			char mander;
			in >> aux1 >> mander >> aux2 >> mander >> aux3;
			h = Horas(aux1, aux2, aux3);
			return in;
		}
		catch (invalid_argument & e) { throw e; }
	}
	friend ostream & operator << (ostream & os, Horas & h) {
		os << setw(2) << setfill('0') << h.h << ':' << setw(2) << setfill('0') << h.m << ':' << setw(2) << setfill('0') << h.s;
		return os;
	}
	bool operator < (Horas & hora) {
		return (ts < hora.ts);
	}
	bool operator > (Horas & hora) {
		return (ts > hora.ts);
	}
	bool operator ==(Horas & h) {
		return ts == h.ts;
	}
	//variables de la clase
	int h, m, s, ts;

};
// El orden de la solución es O(n*m), siendo n el numero de elementos del vector y m el numero de elementos a eliminar
void resolver(SinglyLinkedList<Horas> &datos, int eliminar) {
	for (int i = 0; i < eliminar; i++) {
		datos.elimina_max();
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux1, aux2;
	cin >> aux1;
	cin >> aux2;
	if (!std::cin)
		return false;

	SinglyLinkedList<Horas> datos;
	Horas aux;
	for (int i = 0; i < aux1; i++) {
		cin >> aux;
		datos.push_front(aux);
	}
	resolver(datos, aux2);
	if (!datos.isEmpty())datos.muestra_lista();
	cout << '\n';

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}