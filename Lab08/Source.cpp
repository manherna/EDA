// Grupo 14, Manuel Hernández
// Leeremos las dos cadenas de texto: los datos y el patrón. A continuación iremos mirando carácter a caracter de datos (primer bucle, for)
// Si son iguales a los del patron (segundo bucle, while) Si es así, nuestro booleano seguirá a true y al finalizar el bucle while
// Sumaremos 1 al contador, que retornaremos al final del metodo. 
// Para hacer la comparación utilizaremos la funcion tolower()
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;




// función que resuelve el problema
// El coste de la función es de O(n*m), siendo n la longitud del string de datos y m la longitud del patron.
int resolver(string const &datos, string const &patron) {
	int cont = 0;
	unsigned int j;
	bool iguales = true;
	char aux1, aux2;
	for (unsigned int i = 0; i < datos.length();i++) {
		j = 0;
		iguales = true;
		while(j< patron.length()&& iguales){
			aux1 = patron[j];
			aux2 = datos[i + j];
			if (tolower(aux1) != tolower(aux2)) iguales = false;
			j++;
		}
		if (iguales)cont++;
	}
	return cont;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string datos, patron;
	// leer los datos de la entrada
	
	getline(cin, datos);
	getline(cin, patron);
	if (!std::cin)
		return false;
	int sol = resolver(datos, patron);

	// escribir sol
	cout << sol << '\n';

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