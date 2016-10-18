// Grupo 14, Manuel Hernández
// Para solucionar el problema, iremos linea por linea. Una vez dentro habremos de fijarnos en varias cosas:
// ¿Es blanca la posicion en la que estamos? Si es así debemos comprobar si es la primera despues de un no-blanco.
// Después, iremos acumulando hasta saber que la secuencia de blancos en que estamos es la mayor hasta ahora leida.
// También debemos saber cuando acabamos, para ello nos fijaremos en una posicion mas del (hasta ahora) ultimo blanco. Si es no-blanco, almacenaremos la
// posición como última. (Nota, si es el ultimo elemento, sabemos que no hay más y lo guardaremos).

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

// El coste de resolución estará en O(f(N)), pues solo recorremos el vector una vez. Coste lineal.
int resolver(vector<string> const &pixels, int &ultpos) {
	int maxreps = 0;
	int primpos = 0;
	int aux = 0;
	int aux2 = 0;
	ultpos = -1;
	for(unsigned int i = 0; i<pixels.size(); i++){
		if (pixels[i] == "FFFFFF") {
			if ((i > 0 && pixels[i - 1] != "FFFFFF") || (i == 0)) {
				aux2 = i;
			}

			aux++;
			if (aux >= maxreps) {
				maxreps = aux;
				primpos = aux2;
				if ((i < (pixels.size() - 1u) && pixels[i + 1] != "FFFFFF" )|| (i == (pixels.size() - 1))) { ultpos = i; }
			}
		}
		else {
			aux = 0;
		}
	}
	return primpos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(int &aux, vector<string> &pixels) {
	// leer los datos de la entrada
	int ultimapos;
	
	for (int i = 0; i < aux; i++) cin >> pixels[i];

	int primerapos = resolver(pixels, ultimapos);
	cout << primerapos << " " << ultimapos;
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
	int aux;
	std::cin >> numCasos;
	cin >> aux;
	vector<string> pixels(aux);
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso(aux, pixels);
		if (i != numCasos - 1) cout << '\n';
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}