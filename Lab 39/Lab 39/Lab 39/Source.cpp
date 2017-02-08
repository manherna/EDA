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

struct intervalo {
	int inicio;
	int fin;
};
bool interseccion(intervalo int1, intervalo int2)
{
	if (int2.inicio >= int1.inicio && int2.inicio <= int2.fin)return true;
	else if (int2.fin >= int1.inicio && int2.fin <= int1.fin)return true;
	else return false;

}
bool esValida(vector<intervalo>&sol, intervalo aux){
	bool vale = true;
	for (int i = 1; i < sol.size(); i++){
		if (interseccion(sol[i], aux))vale = false;
	}
	return vale;
}
bool esSol(vector<intervalo> const &sol, int r){
	if (sol.size() >= r)return true;
	else return false;
}
int solMax(int i,vector<intervalo> const &datos){
	int j = i;
	bool dale = true;
	while (j< datos.size() && dale){
		if (!interseccion(datos[i], datos[j]))dale = false;
	}
	return dale;

}
void resolver(vector <intervalo> const & datos, vector<intervalo> &sol, int r, int k, int solTot, int nSol){
	bool prim = k == 0;
	for (int i = 0; i < datos.size(); i++){
		intervalo aux = datos[i];
		if (esValida(sol, aux)){
			sol.push_back(aux);
			if (esSol(sol,r)){
				for (int i = 0; i < sol.size(); i++){
					cout << "[" << sol[i].inicio << ", " << sol[i].fin << "]";
				}
				cout << "\n";
			}
			else{
				resolver(datos, sol, r, k+1);
			}
		}
		sol.pop_back();
	}


}


// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(vector<intervalo> const &dato, int r) {
	vector<intervalo> sol;
	resolver(dato, sol, r);
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nConjuntos, rConjuntos;
	cin >> nConjuntos;
	cin >> rConjuntos;
	if (!std::cin)
		return false;
	vector<intervalo> datos (nConjuntos);
	
	int ini, fin;
	for (int i = 0; i < nConjuntos; i++){
		intervalo aux;
		cin >> ini;
		cin >> fin;
		aux.inicio = ini;
		aux.fin = fin;
		datos[i] = aux;
	}

	int sol = resolver(datos,rConjuntos);

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