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
#include <list>

using namespace std;

class Persona {
public:
	int get_edad() { return edad; }
	string get_nombre() { return nombre; }
	friend istream & operator >> (istream & is, Persona &p) {
		is >> p.edad;
		char aux;
		is.get(aux);
		getline(is, p.nombre);
		return is;
}
private:
	int edad;
	string nombre;
};
// El coste de esta funcion el de O(n), dado que tenemos que recorrer toda la lista para saber si hay gente no apta.
void resolver(std::list<Persona> & datos, int min, int max) {
	Persona aux;
	list<Persona>::iterator it = datos.begin();
	while(it != datos.end()) {
		aux = *it;
		if ((aux.get_edad() < min || aux.get_edad() > max)) {
			it = datos.erase(it);
		}
		else  it++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux1, edmin, edmax;
	cin >> aux1;
	if (aux1 == 0)
		return false;
	cin >> edmin;
	cin >> edmax;
	Persona aux;
	std::list<Persona> datos;
	for (int i = 0; i < aux1; i++) {
		cin >> aux;
		datos.push_front(aux);
	}
	resolver(datos, edmin, edmax);
	std::list<Persona>::const_reverse_iterator it = datos.crbegin();
	for (;it != datos.crend(); it++) {
		aux = *it;
		cout << aux.get_nombre() << '\n';
	}
	cout << "---\n";
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