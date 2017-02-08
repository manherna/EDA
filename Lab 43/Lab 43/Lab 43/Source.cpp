#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "Arbin.h"
using namespace std;

template <class T>
Arbin<T> leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T>	a1 = leerArbol(vacio);
	Arbin<T>	a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}
// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
struct solucion {
	bool ok;
	int sumaNodos;
	int numNodos;
};
int resolver(Arbin <int> const &nodo, int &numNodos, bool &ok) {
	if (nodo.esVacio())return 0;
	else {
		if (nodo.hijoIz().esVacio() && nodo.hijoDr().esVacio()) {
			numNodos++;
			return nodo.raiz();
		}
		else {
			numNodos++;
			int a, b;
			a = resolver(nodo.hijoIz(), numNodos, ok);
			b = resolver(nodo.hijoDr(), numNodos, ok);
			int suma = (a + b + nodo.raiz());
			if (ok)ok = (suma>= numNodos);
			return suma;
		}
	}
}
solucion resolver(Arbin <int> const &datos) {
	solucion a;
	if (datos.esVacio()) {	
		a.ok = false;
		a.numNodos = 0;
		a.sumaNodos = 0;
		return a;
	}
	else {
		bool ok = true;
		int numNodos = 0;
		int suma = 0;
		a.sumaNodos = (datos, numNodos, ok);
		a.numNodos = numNodos;
		a.ok = ok;
		return a;
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Arbin <int> datos;
	datos = leerArbol(-1);
	solucion sol = resolver(datos);
	if (sol.ok)cout << "SI\n";
	else cout << "NO\n";
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}