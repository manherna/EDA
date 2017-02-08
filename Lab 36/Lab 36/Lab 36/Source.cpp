// Grupo 14, Manuel Hernández
// Probaremos todas las posibles combinaciones entre los funcionarios
//´Así sabremos el tiempo mínimo de realización del trabajo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>


using namespace std;
bool esValida(vector<bool>const &marcas, int i) 
{
	return !marcas[i];
}
bool esSol(int k, int N) 
{
	return k == N - 1;
}
bool bestSol(int solActual, int mejorSol) 
{
	return solActual < mejorSol;
}


// El coste de esta función es de O(N^2), dado que hay que probar todas las posibles combinaciones.
void resolver(vector < vector<int> > const &datos, vector<bool> &marcas, int k, int &sol, int &mejorSol) {
	for (int i = 0; i < datos.size(); i++) {
		sol += datos[i][k];
		if (esValida(marcas, i)) {
			if (esSol(k, datos[i].size())) {
				if(bestSol(sol, mejorSol))
				{
					mejorSol = sol;
				}
			}
			else {
				marcas[i] = true;
				resolver(datos, marcas, k + 1, sol, mejorSol);
				marcas[i] = false;
			}
		}
		sol -= datos[i][k];
	}
}
int resolver(vector < vector<int> > datos) {
	vector<bool> marcas(datos.size(), false);
	int sol = 0;
	int mejorSol = INT32_MAX;
	resolver(datos, marcas, 0, sol, mejorSol);
	return mejorSol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)
		return false;
	else {
		int aux;
		vector < vector<int> > datos(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> aux;
				datos[i][j] = aux;
			}
		}
		int sol = resolver(datos);
		cout << sol << '\n';
		// escribir sol

		return true;
	}
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