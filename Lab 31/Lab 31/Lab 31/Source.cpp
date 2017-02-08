// Grupo 14, Manuel Hernández
// Comentario general sobre la solucio´n,
// explicando co´mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Arbin.h"
#include <string>

using namespace std;
template <class T>
Arbin<T>leerArbol(T const&	vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return Arbin<T>();
	Arbin<T>a1 = leerArbol(vacio);
	Arbin<T>a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}
template <class T>
bool resolver(Arbin<T> raiz, T &min, T &max, T limiz, T limder) {
	if (!raiz.esVacio()) {
		bool a1, a2, a3;
		a3 = true;
		T aux = raiz.raiz();

		//Calculamos minimo y maximo
		//está mal
		if (aux > limiz && aux < limder) {
			a3 = true;
		}
		else if(aux<limiz && aux < limder){
			if (aux < min) { min = aux; a3 = true; }
			else a3 = false;
		}
		else if (aux > limiz && aux > limder) {
			if (aux > max) { max = aux; a3 = true; }
			else a3 = false;
		}
		a1 = resolver(raiz.hijoIz(), min, max, limiz, aux);
		a2 = resolver(raiz.hijoDr(), min, max, aux, limder);
		return a1 && a2 && a3;
	}
	else return true;
}


// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
template <class T>
bool resolver(Arbin<T>const &datos, T &min, T &max) {
	if (datos.esVacio()) { return false; };
	min = datos.raiz();
	max = datos.raiz();
	T iz = datos.raiz();
	T dr = datos.raiz();
	return resolver(datos, min, max, --iz, ++dr);
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int aux;
	cin >> aux;
	if (!std::cin)
		return false;
	string sol;
	if (aux == 0) {
		int min, max;
		Arbin <int>k = leerArbol<int>(-1);
		if (resolver(k, min, max))cout << min << ' ' << max << ' ' << "SI" << '\n';
		else if (k.esVacio())cout << -1 << ' ' << -1 << ' ' << "NO" << '\n';
		else cout << min << ' ' << max << ' ' << "NO" << '\n';
	}
	else {
		char min, max;
		Arbin <char>k = leerArbol('.'); 
		resolver(k, min, max);	
		if (resolver(k, min, max))cout << min << ' ' << max << ' ' << "SI" << '\n';
		else if (k.esVacio())cout << '.' << ' ' << '.' << ' ' << "NO" << '\n';
		else cout << min << ' ' << max << ' ' << "NO" << '\n';
	}
	
	

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