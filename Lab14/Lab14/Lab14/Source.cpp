// Grupo 14, Manuel Hernández
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
class jugador {
public:
	jugador() : alias(""), punt(0) { };
	jugador(string id, int puntuacion) : alias(id), punt(puntuacion) { };
	~jugador() {};

	friend std::istream& operator >> (std::istream& entrada, jugador& j) {
		entrada >> j.alias >> j.punt;
		return entrada;
	}
	string alias;
	int punt;

};

class comparador {
public:
	bool operator() (const jugador &p1, const jugador& p2) {
		if (p1.punt < p2.punt) return false;
		else if (p1.punt == p2.punt) {
			if (p1.alias < p2.alias) return true;
			else return false;
		}
		else return true;
	}
};






bool resolver(vector<jugador> const& datos, string const busqueda, int & pos, int & punt, size_t ini, size_t fin) {
	if (ini == fin) {
		if (busqueda == datos[ini].alias) { pos = ini + 1; punt = datos[ini].punt; return true; }
		else return false;
	}
	else {
		size_t m = (ini + fin) / 2;
		if(datos[m]. alias == busqueda){ pos = m + 1; punt = datos[m].punt; return true; }
		else return(resolver(datos, busqueda, pos, punt, ini, m) || resolver(datos, busqueda, pos, punt, m + 1, fin));
	}

}
// funcio´n que resuelve el problema
// El coste de la función es NlogN+MlogN, siendo M el numero de elementos a buscar. Por tanto está en O(NlogN)
vector<int> resolver(vector<jugador> & datos, vector<string> const & consultas) {
	std::sort(datos.begin(), datos.end(), comparador());
	size_t ini = 0;
	size_t fin = datos.size()-1;
	vector<int> sol;
	for (unsigned int i = 0; i < consultas.size(); i++) {
		string busqueda = consultas[i];
		int pos, punt;
		if (resolver(datos, busqueda, pos, punt, ini, fin)) {
			sol.push_back(punt);
			sol.push_back(pos);
		}
		else {
			sol.push_back(-1);
			sol.push_back(-1);
		}
	}
	return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux1, aux2;
	cin >> aux1;
	cin >> aux2;
	if (!std::cin)
		return false;
	vector<jugador> datos;
	vector<string> consultas;
	jugador auxx;
	string aux;
	for (int i = 0; i < aux1; i++) {
		cin >> auxx;
		datos.push_back(auxx);
	}
	for (int i = 0; i < aux2; i++) {
		cin >> aux;
		consultas.push_back(aux);
	}
	vector<int> sol;
	sol = resolver(datos, consultas);

	for (unsigned int i = 0; i < sol.size(); i += 2) {
		if(sol [i+1]!= -1)
		cout << sol[i] << " " << sol[i + 1]<< '\n';
		else cout << "NO\n";
	}
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