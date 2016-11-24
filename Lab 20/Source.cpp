// Grupo 14, Manuel Hernández
// En cada caso a resolver, llamaremos a duplicar lista, 
// que nos duplicará cada nodo en la lista dada. Luego la imprimiremos en pantalla.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "SinglyLinkedList.h"

using namespace std;



// Problema de coste lineal, ya que el metodo de duplicar 
// recorre toda la lista de principio a fin
void resolver(SinglyLinkedList<int>&  datos) {
	datos.duplicate_list();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int primero, actual;
	cin >> primero;
	cin >> actual;
	if (primero == 0)
		return false;
	else {
		SinglyLinkedList<int> list;
		list.push_front(primero);
		while (actual != 0) {
			list.push_front(actual);
			cin >> actual;
		}

		resolver(list);
		list.print_list();
		cout << '\n';

		return true;
	}
	}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
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