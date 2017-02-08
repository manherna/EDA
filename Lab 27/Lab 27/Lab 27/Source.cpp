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
#include <list>
#include <stack>
#include <string>
using namespace std;

// El coste de esta función es de O(n^2)
int resolver(list<string> & datos, list<string>const &orden, int coste) {
	int solucion, ordenados;
	stack<string> pila;
	solucion = 0;
	ordenados = 0;
	unsigned int vueltas = 0;
	//Iterador por la lista ya ordenada
	list<string>::const_iterator itor = orden.begin();
	//Iterador por la lista a ordenar
	list<string>::const_iterator itdat;
	//Iterador auxiliar 
	list<string>::const_iterator aux;
	while (ordenados != orden.size() && vueltas < orden.size()) {
		itdat = datos.begin();
		
		//String auxiliar para sacar el contenido de la pila
		string cuerda;
		while (itdat != datos.end()) {
			//Comprobamos si el primero de la lista es el siguiente.
			if (*itdat == *itor) {
				ordenados++; 
				itor++;
			}
			//si no, lo añadimos a la lista
			else {
				solucion += coste;
				pila.push(*itdat);
			}
			//Pasamos al elemento siguiente, eliminando el anterior
			aux = itdat;
			itdat++;
			aux = datos.erase(aux);	
		}
		//Comprobamos si el ultimo de la pila es el coche a introducir siguiente, si es asi lo metemos.
		while (!pila.empty() && pila.top() == *itor) {
		ordenados++;
		itor++;
		pila.pop();
	}
		//Volcamos la pila de nuevo a la lista
		while (!pila.empty()) {
			cuerda = pila.top();
			datos.push_front(cuerda);
			pila.pop();
		}
		vueltas++;
	}
	return solucion;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int ncoches, coste;
	cin >> ncoches;
	if (!std::cin)
		return false;
	cin >> coste;
	list<string> datos;
	list<string> orden;
	string aux;
	for (int i = 0; i < ncoches; i++) {
		cin >> aux;
		orden.push_front(aux);
	}
	for (int i = 0; i < ncoches; i++) {
		cin >> aux;
		datos.push_front(aux);
	}
	int sol = resolver(datos, orden, coste);
	cout << sol << '\n';
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