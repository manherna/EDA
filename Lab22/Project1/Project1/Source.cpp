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
#include "Horas.h"
#include "SinglyLinkedList.h"

using namespace std;



// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(SinglyLinkedList <Horas> &datos, int aeliminar) {
	if (aeliminar >= datos.size()) {
		int aux = datos.size();
		for (int i = 0; i < aux; i++) {
			datos.pop_front();
		}
	}
	else {
		for (int i = 0; i < aeliminar; i++) {
			datos.eliminaMayor();
		}
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
	SinglyLinkedList <Horas> datos;
	Horas aux;
	for (int i = 0; i < aux1; i++) {
		cin >> aux;
		datos.push_front(aux);
	}
	resolver(datos, aux2);
	datos.print_list();
	 cout << '\n';
	// escribir sol


	return true;

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