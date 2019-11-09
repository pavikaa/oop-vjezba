// Napišite funkciju koja vraća indeks najmanjeg elementa jednodimenzionalnog
// polja cijelih brojeva te nakon toga preopteretite tu funkciju tako da radi i s
// poljima double tipa, poljima vektora (zadatak 2) i string objektima (4 funkcije).
// Funkcija ne treba podrazumijevati duljinu predanog joj polja.
#include <iostream>
#include <string>
#include<cmath>
using namespace std;
class Vector
{
	friend bool operator<(Vector& ref1,Vector& ref2);
	double i, j, k;
public:
	Vector();
	Vector(double, double, double);
	Vector& operator=(const Vector& ref)
	{
		i = ref.i;
		j = ref.j;
		k = ref.k;
		return *this;
	}
	double modul();
};
Vector::Vector()
{
	i = 0.0;
	j = 0.0;
	k = 0.0;
}
Vector::Vector(double i, double j, double k)
{
	this->i = i;
	this->j = j;
	this->k = k;
}
double Vector::modul()
{
	return(sqrt(i*i +j*j +k*k));
}
bool operator<(Vector& ref1,Vector& ref2)
{
	return(ref1.modul()<ref2.modul());
}
int function(int* polje, int n)
{
	int i;
	int najmanji = polje[0];
	int indeks = 0;
	for (i = 1; i < n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int function(double* polje, int n)
{
	int i;
	double najmanji = polje[0];
	int indeks = 0;
	for (i = 1; i < n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int function(Vector polje[], int n)
{
	int i;
	Vector najmanji = polje[0];
	int indeks = 0;
	for (i = 1; i < n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int function(string* polje,int n)
{
	int i;
	string najmanji = polje[0];
	int indeks = 0;
	for (i = 0; i<n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int main()
{
	int a[5] = { 1,2,3,4,0 };
	double b[5] = { 1.1,0.7,15,0.002,0.014 };
	Vector v1[3] = { Vector(1,2,3),Vector(2,3,4),Vector(0,0,0) };
	string c[4] = { "Recenica recenica","a"," jedan dva tri","abcd"};
	cout << function(a, 5) << " " << function(b, 5) << " " << function(c,4) << " " << function(v1, 3) << endl;
	return 0;
}
