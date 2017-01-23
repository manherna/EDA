// Grupo 14, Manuel Hern�ndez
// Comentario general sobre la solucio�n,
// explicando co�mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
class comparador {
public:
	bool operator()(const jugador &p1, const jugador& p2) {
		if (p1.punt < p2.punt) return true;
		else if (p1.punt == p2.punt) {
			if (p1.alias < p2.alias) return true;
			else return false;
		}
		else return false;
	}
};
std::istream& operator >> (std::istream& entrada, jugador& j) {
	entrada >> j.alias >> j.punt;
	return entrada;
}



// funcio�n que resuelve el problema
// comentario sobre el coste, O(f(N))
Solucion resolver(Datos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio�n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	if (!std::cin)
		return false;

	Solucion sol = resolver(datos);

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
	//system("PAUSE");
#endif

	return 0;
}