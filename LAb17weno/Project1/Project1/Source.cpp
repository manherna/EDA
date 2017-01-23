// Grupo XYZ, Fulano y Mengano
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



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
/*Horas  resolver(vector<Horas>  const &datos) {
	Horas  kek;


	return kek;
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {/*
	// leer los datos de la entrada
	int aux1, aux2;
	cin >> aux1;
	cin >> aux2;

	if (aux1 == 0 && aux2 == 0)
		return false;

	vector<Horas>  datos(aux1);
	Horas  sol = resolver(datos);

	cout << sol;
	// escribir sol

	return true;
	*/

	Horas heh = Horas(15, 35, 00);
	Horas hoh = Horas(04, 45, 00);
	cout << heh - hoh << "  ";
	return false;
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