// Grupo 14, Manuel Hernández
// Para resolverlo hallaremos el mayor de los números de la derecha y el menor de los de la izquierda.
// Los comparamos, si el maxmenores es mayor el menmayores, no está ordenado correctamente
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;



// Como solo recorremos el vector 1 vez, el coste será O(n)
string resolver(vector<int> const &nums, unsigned int p) {
	int maxmenores = nums[0];
	bool ordenado = true;
	if (p < nums.size() - 1) {
		int menmayores = nums[p + 1];
		for (unsigned int i = 1; i <= p; i++) {
			if (nums[i] > maxmenores)maxmenores = nums[i];
		}
		unsigned int j = p + 1;

		while (ordenado && j < nums.size()) {
			if (nums[j] < menmayores)menmayores = nums[j];
			if (menmayores <= maxmenores)ordenado = false;
			j++;
		}
	}
	string kek;
	if (ordenado)kek = "SI";
	else kek = "NO";
	return kek;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int aux = 0;
	unsigned int p = 0;
	cin >> aux;
	cin >> p;
	vector<int> numeros(aux);
	for (int i = 0; i < aux; i++)cin >> numeros[i];
	string sol = resolver(numeros, p);
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
