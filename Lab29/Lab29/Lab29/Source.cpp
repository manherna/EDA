// Grupo 14, Manuel Hernández
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Arbin.h"
using namespace std;

// El coste de la solución es lineal, pues hay que mirar todos los nodos
// para asegurarse de cual es la frontera total.

string resolver(Arbin<char> datos) {
	if (datos.esVacio())return "";
	else {
		if (!datos.hijoDr().esVacio() || !datos.hijoIz().esVacio()) {
			string aux1 = resolver(datos.hijoDr());
			string aux2 = resolver(datos.hijoIz());
			return aux1 + aux2;
		}
		else {
			string s = "";
			s.push_back(datos.raiz());
			return s;
		}
	}
}
template <class T>
Arbin<T> leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	return Arbin<T>(leerArbol(vacio), raiz, leerArbol(vacio));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	string sol;
	Arbin <char> datos;
	datos = leerArbol('.');
	sol = resolver(datos);
	if(sol != "")cout << sol << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
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