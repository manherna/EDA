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
#include <stack>
#include <string>


using namespace std;

bool esabierta(string const &subcadena, char & tipo){
	//Comprobaciones
	if (subcadena == "<b>"){
		tipo = 'b';
		return true;
	}
	else if (subcadena == "<p>"){
		tipo = 'p';
		return true;
	}
	else if (subcadena == "<i>"){
		tipo = 'i';
		return true;
	}
	else if (subcadena == "<q>"){
		tipo = 'q';
		return true;
	}
	else {
		tipo = ' ';
		return false;
	}

}
bool escerrado(string const &subcadena, char& tipo){
	if (subcadena == "</b>"){
		tipo = 'b';
		return true;
	}
	else if (subcadena == "</p>"){
		tipo = 'p';
		return true;
	}
	else if (subcadena == "</i>"){
		tipo = 'i';
		return true;
	}
	else if (subcadena == "</q>"){
		tipo = 'q';
		return true;
	}
	else {
		tipo = ' ';
		return false;
	}
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(string const datos, int &parr, int &neg, int &curs, int &cit) {
	parr = 0;
	neg = 0;
	curs = 0;
	cit = 0;
	stack <char> pila;
	unsigned int i = 6;
	char b;
	bool error = false;
	while (i < datos.size() - 7 && !error)
	{
		//Es un menor? Puede ser una etiqueta
		if (datos[i] == '<') {
			//Si hay una barra sabemos que puede ser una etiqueta cerrada
			if (datos[i + 1] == '/') {
				//Comprobamos si es de cierre. Si lo es, comparamos con lo ultimo de la pila.
				if (escerrado(datos.substr(i, 4), b)) {
					//Si no es igual a la cima, estamos cerrando una etiqueta posterior a la actual,
					//ergo el texto está mal formateado. Error a true.
					if (pila.size() == 0)
						return false;
					else if (b != pila.top()) {
						error = true;
					}
					//Si el cerrado es del mismo tipo, estamos cerrando una etiqueta buena asi que
					//eliminamos la cima y saltamos a i+4
					else {
						//Si realmente es un cierre, queremos saber que cierre es. 
						//Sumamos 1 al tipo que corresponda
						switch (b) {
						case 'b':
							neg++;
							break;
						case 'p':
							parr++;
							break;
						case 'i':
							curs++;
							break;
						case 'q':
							cit++;
							break;
						default:
							break;

						}
						i += 4;
						pila.pop();
					}
				}
			}
			else {
				//si es una etiqueta de apertura, añadiremos dicha etiqueta a la pila
				if (esabierta(datos.substr(i, 3), b)) {
					pila.push(b);
					i += 3;
				}
				else i++;
			}
		}
		else i++;
		
	}
	if (pila.size() != 0) error = true;
	return !error;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string datos;
	getline(cin, datos);

	if (!std::cin)
		return false;

	int p, n, c, cit;
	bool sol = resolver(datos, p, n, c, cit);

	if (sol)
		cout << "SI " << p << " " << n << " " << c << " " << cit << "\n";
	else cout << "NO\n";

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