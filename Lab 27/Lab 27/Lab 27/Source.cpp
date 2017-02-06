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

// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(list<string> & datos, list<string>const &orden, int coste) {
	int solucion, ordenados;
	stack<string> pila;
	solucion = 0;
	ordenados = 0;
	list<string>::const_iterator itor = orden.begin();
	while (ordenados != orden.size()) {
		list<string>::const_iterator itdat = datos.begin();
		list<string>::const_iterator aux;
		string cuerda;
		while (itdat != datos.end()) {
			//Comprobamos si el primero de la lista es el siguiente.
			if (*itdat != *itor) {
				//Si no lo es:
				//Miramos si la cabeza de pila es la siguiente, si es así lo pasamos y seguimos mirando en la pila
				if(!pila.empty())cuerda = pila.top();
				while (cuerda == *itor) {
					itor++;
					ordenados++;
					pila.pop();
					if (!pila.empty())cuerda = pila.top();
					else cuerda = "";
				}
				pila.push(*itdat);
				solucion += coste;
			}
			else {
				itor++;
				ordenados++;
			}
			//Eliminamos de todas formas el elemento, ya que: o se ha metido en la pila, o ha pasado al ferry
			aux = itdat;
			itdat++;
			aux = datos.erase(aux);
		}
		//Volcamos la pila de nuevo a la lista
		while (!pila.empty()) {
			cuerda = pila.top();
			datos.push_front(cuerda);
			pila.pop();
		}
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