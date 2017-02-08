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

// El coste de esta solucion es de O(N^M)
void escribesol(vector<char> const & sol) {
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << ' ';
	}
	cout << '\n';
}
bool esvalida(vector<char> const& sol, vector <bool> &marcas, int k) {
	if (k > 0) {
		if (marcas[sol[k] - 'a'] == false && sol[k] > sol[k - 1])return true;
		else return false;
	}
	else return true;
}
void resolver(vector<char> &sol, vector <bool>& marcas, int n, int k) {
	for (char i = 'a'; i < n + 'a'; i++) {
		sol[k] = i;
		if (esvalida(sol, marcas, k) ){
			marcas[i - 'a'] = true;
			if (sol.size() == k+1)escribesol(sol);
			else resolver(sol, marcas, n, k+1);
			marcas[i - 'a'] = false;
		}
	}
}

void resolver(int n, int m) {
	vector<char> sol (m);
	vector<bool> marcas('z' - 'a', false);
	resolver(sol, marcas, n, 0);
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

	resolver(aux1, aux2);

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