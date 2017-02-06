// Grupo 14, Manuel Hernández
// Eliminamos el elemento más próximo al propuesto. Si son iguales, eliminamos el menor.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "SinglyLinkedList.h"
using namespace std;


// La resolución del problema es, en peor caso, de O(n), dado que recorremos 
// la lista entera para eliminar el ultimo
void resolver(SinglyLinkedList<int> & datos, int dato) {
	datos.delete_closest(dato);
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
	int k;
	SinglyLinkedList<int>  datos;
	for (int i = 0; i < aux1; i++) {
		cin >> k;
		datos.push_front(k);
	}
	resolver(datos, aux2);
	datos.muestra_lista();
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