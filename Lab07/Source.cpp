// Grupo 14, Manuel Hernández
// Para solucionar el problema, iremos linea por linea.
// Leeremos la linea color a color. Si caemos en blanco acumularemos el numero de blancos que llevemos leidos
// Si este supera al anteriormente acumulado, lo sustituiremos y pasaremos, cuando termine dicha franja blanca,
// a calcular su primer y yltimo elemento

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdint.h>
using namespace std;
bool primero = true;

//La resolución tiene coste lineal, pues solo recorremos una vez cada vector de colores que se nos envía.
int resolver(vector<string> const &pixels, int &ultpos) {
	int maxreps = 0;
	int primpos = 0;
	int aux = 0;
	ultpos = -1;
	for (unsigned int i = 0; i<pixels.size(); i++) {
		if (pixels[i] == "FFFFFF") {
			aux++;
			if (aux > maxreps) {
				maxreps = aux;
				if (i == (pixels.size() - 1)) { ultpos = i; }
				else if (pixels[i + 1] != "FFFFFF") { ultpos = i; }
			}
		}
		else {
			aux = 0;
		}
	}
	primpos = (ultpos + 1) - maxreps;
	return primpos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int m, n, ultpos;
	cin >> m;
	if (!cin)
		return false;
	else {
		if(!primero)cout << '\n';
		cin >> n;
		vector<string> pixels(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)cin >> pixels[j];
			int primpos = resolver(pixels, ultpos);
			cout << primpos << ' ' << ultpos <<'\n';
			
		}
		primero = false;
		return true;
	}
	// escribir sol




}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());
		


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}