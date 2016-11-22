#include <iostream>
using namespace std;

class Horas
{
public:
	Horas(int h, int m, int s);
	Horas();
	~Horas();
	int getHoras(){ return horas; };
	int getMinutos(){ return minutos; };
	int getSegundos(){ return segundos; };

	int setHoras(int aux);
	int setMinutos(int aux);
	int setSegundos(int aux);

	friend ostream& operator << (ostream & out, Horas &h);
	friend istream& operator >> (istream & in, Horas &h);


private:
	int horas, minutos, segundos;
};


Horas::Horas(int h, int m, int s){
	segundos = s % 60;
	minutos = 0;
	minutos += s / 60;

	minutos += m % 60;
	horas = 0;

	horas += m / 60;
	horas += h;

}
Horas::Horas(){

	segundos = 0;
	minutos = 0;
	horas = 0;

}

ostream& operator << (ostream & out, Horas &h){
	out << h.getHoras() << ":" << h.getMinutos() << ":" << h.getSegundos();
	return out;
}
istream& operator >> (istream & in, Horas &h) {
	in >> h.horas >> h.minutos >> h.segundos;
	return in;

}