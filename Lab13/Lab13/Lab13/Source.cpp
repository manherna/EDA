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

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(vector<int> const & datos, size_t ini, size_t fin, int & suma) {
	if (ini == fin) {
		suma = datos[ini];
		return true;
	}
	else if (ini + 1 == fin) {
		suma = datos[ini] + datos[fin];
		return datos[ini] < datos[fin];
	}
	else {
		size_t m = (ini + fin) / 2;
		int siz, sder;
		bool ordiz = resolver(datos, ini, m, siz);
		bool order = resolver(datos, m + 1, fin, sder);
		suma = siz+sder;
		return (ordiz && order && siz < sder);
	}

}
bool resolver(vector<int> datos) {
	size_t ini = 0;
	size_t fin = datos.size() - 1;
	int suma;
	return resolver(datos, ini, fin, suma);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux1, aux2;
	cin >> aux1;
	cin >> aux2;

	if (!std::cin)
		return false;
	bool sol = true;
	for (int i = 0; i < aux1; i++) {
		vector<int> aux = vector<int>();
		for (int j = 0; j < aux2; j++) {
			int auxx;
			cin >> auxx;
			aux.push_back(auxx);
		}
		if (!resolver(aux) && sol == true)
			sol = false;
	}

	if (sol)cout << "SI\n";
	else cout << "NO\n";
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