// Grupo 14, Manuel Hernández
// Para resolver el problema tendremos que mirar 1 por 1 cada nodo, viendo si este tiene hijos o no. Si es asi
// calcularemos la suma de éstos y comprobaremos si cumple la propiedad.

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
// El coste de esta función es de O(N), ya que hay que mirar todos los elementos para saber si se cumple la propiedad.
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
			int a, b;
			int nder = 0;
			int niz = 0;
			a = resolver(nodo.hijoIz(), niz, ok);
			b = resolver(nodo.hijoDr(), nder, ok);
			numNodos = niz + nder;
			numNodos++;
			int suma = (a + b + nodo.raiz());
			if (ok)ok = (suma >= numNodos);
			return suma;
		}
	}
}
solucion resolver(Arbin <int> const &datos) {
	solucion a;
	//Caso base arbol vacío.
		bool ok = true;
		int numNodos = 0;
		a.sumaNodos = resolver(datos, numNodos, ok);
		a.numNodos = numNodos;
		//Caso base numnodos = 1
		if(numNodos != 1)a.ok = ok;
		else a.ok = a.sumaNodos >= a.numNodos;
		return a;
	


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