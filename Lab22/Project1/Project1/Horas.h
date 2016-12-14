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
	Horas operator + (Horas &h);
	Horas operator - (Horas&h);
	bool operator < (Horas&h);

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
Horas::~Horas() {

}
//Definición de operadores de la clase horas
Horas Horas::operator + (Horas &h){
	return Horas(h.getHoras() + getHoras(), h.getMinutos() + getMinutos(), h.getSegundos() + getSegundos());
}
Horas Horas::operator - (Horas&h) {
	int s = 0;
	int m = 0; 
	int hor = 0;
	return Horas(getHoras() - h.getHoras(), getMinutos() - h.getMinutos(), getSegundos() - h.getSegundos());
}

bool Horas::operator < (Horas &h) {

	if (getHoras() >= h.getHoras()) return false;
	else if (getMinutos() >= h.getMinutos()) return false;
	else if (getSegundos() >= h.getSegundos()) return false;
	else
		return true;
}

ostream& operator << (ostream & out, Horas &h){
	
	out << setfill('0') << setw(2) <<h.getHoras() << ":" << setfill('0') << setw(2) << h.getMinutos() << ":" << setfill('0') << setw(2) << h.getSegundos();
	return out;
}
istream& operator >> (istream & in, Horas &h) {
	in >> h.horas >> h.minutos >> h.segundos;
	return in;

}