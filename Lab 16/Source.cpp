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
#include <string>
using namespace std;

// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))

bool resolver(vector <int> const & datos, const int numero, int &elem, size_t ini, size_t fin) {
	if (ini == fin) {
		if (datos[ini] == ini + numero) { elem = datos[ini]; return true; }
		else return false;
	}
	else {
		size_t m = (ini + fin) / 2;
		if (m + numero <= datos[m])return resolver(datos, numero, elem, ini, m);
		else return resolver(datos, numero, elem, m + 1, fin);
	}
}

string resolver(vector<int>const &datos, const int numero) {
	size_t ini = 0;
	size_t fin = datos.size() - 1;
	int num;
	if (resolver(datos, numero, num, ini, fin))return to_string(num);
	else return "NO";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int elems, num, aux;
	cin >> elems;
	cin >> num;
	vector<int> datos;
	for (int i = 0; i<elems; i++)
	{
		cin >> aux;
		datos.push_back(aux);
	}
string sol = resolver(datos, num);
cout << sol << '\n';
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