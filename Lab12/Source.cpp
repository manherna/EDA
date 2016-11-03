// 14, Manuel Hernández
// Solucionaremos el problema dividiendo en dos sistemáticamente el vector hasta
// que hallemos uno de los casos base por cada división. De ahí retornaremos valores
// según qué elementos sean menores o no.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(vector<int> const &datos, size_t &ini, size_t  &fin) {
	//Caso base 1: Inicio = fin, por tanto solo hay 1 elemento y retornamos.
	if (ini == fin) return datos[ini];
	//Caso base 22: Fin = inicio+1, hay 2 elementos y retornamos el menor de ellos.
	else if (fin == ini + 1) {
		return (datos[ini] < datos[fin]) ? datos[ini] : datos[fin];
	}
	else {
		//La declaración de variables es excesiva porque si en el metodo resolver intentamos poner
		// m-1, nos lo identifica como uint. Lo mismo ocurre en la función principal.
		size_t m = (ini + fin) / 2;
		size_t t = m - 1;
		int aux1 = resolver(datos, ini, t);
		int aux2 = resolver(datos, m, fin);

		return (aux1 < aux2) ? aux1 : aux2;
	}
}
//Función principal que resuelve el problema
int resolver(vector<int> const &datos) {
	size_t ini = 0;
	size_t fin = datos.size() - 1;

	return resolver(datos, ini, fin);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux;
	cin >> aux;
	if (!std::cin)
		return false;
	vector <int> datos(aux);
	for (int i = 0; i < aux; i++)cin >> datos[i];
	int sol = resolver(datos);
	cout << sol << '\n';
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