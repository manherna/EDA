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
	Horas operator - (Horas &h);
	bool operator < (Horas const &h);

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
Horas Horas::operator - (Horas &h) {
	int s = 0;
	int m = 0; 
	int hor = 0;
	return Horas(getHoras() - h.getHoras(), getMinutos() - h.getMinutos(), getSegundos() - h.getSegundos());
}

bool Horas::operator < (Horas const &h) {
	int local, otro;
	local = horas * 3600 + minutos * 60 + segundos;
	otro = h.getHoras() * 3600 + h..getMinutos() * 60 + h.getSegundos();
	return local <= otro;
}
ostream& operator << (ostream & out, Horas &h){
	
	out << setfill('0') << setw(2) <<h.getHoras() << ":" << setfill('0') << setw(2) << h.getMinutos() << ":" << setfill('0') << setw(2) << h.getSegundos();
	return out;
}
istream& operator >> (istream & in, Horas& h) {
	char aux;
	in >> h.horas >> aux >> h.minutos >> aux >> h.segundos;
	//. (0 ≤ horas ≤ 23; 0 ≤ minutos,segundos ≤ 59)
	if (h.getHoras() > 23 || h.getHoras()<0 || h.getMinutos()>59 || h.getMinutos()<0 || h.getSegundos()>59 || h.getSegundos() < 0) throw std::invalid_argument("Hora mal introducida");
	return in;
}