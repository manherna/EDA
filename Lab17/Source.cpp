// Grupo 14, Manuel Hernández
// Haremos una busqueda binaria sobre un vector de Horas, clase implementada por nosotros, para encontrar
// El tren que antes sale despues de la hora indicada.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;
class Horas {
public:
	//Metodos
	Horas() : h(0), m(0), s(0) {};
	Horas(int horas, int minutos, int segundos) {
		if (horas > 23 || minutos > 60 || segundos > 60) throw std::invalid_argument("ERROR");
		else if (horas < 0 || minutos < 0 || segundos < 0) throw std::invalid_argument("ERROR");
		else {
			h = horas;
			m = minutos;
			s = segundos;
			ts = h * 3600 + m * 60 + s;
		}
	};
	friend istream & operator >> (istream & in, Horas & h) {
		try {
			int aux1, aux2, aux3;
			char mander;
			in >> aux1 >> mander>> aux2 >> mander >> aux3;
			h = Horas(aux1, aux2, aux3);
			return in;
		}
		catch (invalid_argument & e) { throw e; }
	}
	friend ostream & operator << (ostream & os, Horas & h) {
		os << setw(2) << setfill('0') << h.h << ':' << setw(2) << setfill('0') << h.m << ':' << setw(2) << setfill('0') << h.s;
		return os;
	}
	bool operator < (Horas & hora) {
		return (ts < hora.ts);
	}
	bool operator ==(Horas & h) {
		return ts == h.ts;
	}
	//variables de la clase
	int h, m, s, ts;

};

// El orden de la solución es O(logN) dado que eliminamos, cada vez que llamamos a resolver, una mitad que no nos sirve.
bool resolver(vector<Horas> & datos, Horas consulta, Horas & sol, size_t ini, size_t fin) {
	if (datos[fin] < consulta)return false;
	else if (ini == fin) {
		if (consulta < datos[ini]) { sol = datos[ini]; return true; }
		else return false;
	}
	else {
		size_t m = (ini + fin) / 2;
		if (consulta == datos[m]) { sol = datos[m]; return true;}
		if (consulta < datos[m] )return(resolver(datos, consulta, sol, ini, m));
		else return resolver(datos, consulta, sol, m + 1, fin);
	}

}



bool resolver(vector<Horas> &datos, Horas const & consulta, Horas & sol) {
	size_t ini = 0;
	size_t fin = datos.size() - 1;
	return resolver(datos, consulta, sol, ini, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int aux1, aux2;
	cin >> aux1;
	cin >> aux2;
	if (aux1 == 0 || aux2 == 0)
		return false;
	else {
		vector<Horas> datos;
		Horas aux, auxh;
		for (int i = 0; i < aux1; i++) {
			cin >> aux;
			datos.push_back(aux);
		}
		for (int i = 0; i < aux2; i++) {
			try {
				cin >> aux;
				if (resolver(datos, aux, auxh))cout << auxh << '\n';
				else cout << "NO\n";
			}
			catch (invalid_argument & e) { cout << e.what() << '\n'; }
		}
		cout << "---\n";

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