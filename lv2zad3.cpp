// Napišite funkciju koja vraća indeks najmanjeg elementa jednodimenzionalnog
// polja cijelih brojeva te nakon toga preopteretite tu funkciju tako da radi i s
// poljima double tipa, poljima vektora (zadatak 2) i string objektima (4 funkcije).
// Funkcija ne treba podrazumijevati duljinu predanog joj polja.
#include <iostream>
#include <string>
using namespace std;
class Vector
{
	friend bool operator<(const Vector& ref1, const Vector& ref2);
	friend ostream& operator<<(ostream&, Vector&);
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

ostream& operator<<(ostream& izlaz, Vector& ref)
{
	izlaz << "Vektor je: " << ref.i << "i + " << ref.j << "j + " << ref.k << "k ." << endl;
	return izlaz;
}
bool operator<(const Vector& ref1, const Vector& ref2)
{
	return(ref1.i < ref2.i && ref1.j < ref2.j && ref1.k < ref2.k);
}
int function(int *polje,int n)
{
	int i;
	int najmanji = polje[0];
	int indeks = 0;
	for (i = 1;i<n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int function(double *polje,int n)
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
int function(Vector polje[],int n)
{
	int i;
	Vector najmanji = polje[0];
	int indeks = 0;
	for (i = 1;i<n; i++)
	{
		if (polje[i] < najmanji)
		{
			najmanji = polje[i];
			indeks = i;
		}
	}
	return indeks;
}
int function(string *polje)
{
	int i;
	string najmanji = polje[0];
	int indeks = 0;
	for (i = 0;polje[i]!="\0"; i++)
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
	int a[5] = {1,2,3,4,0};
	double b[5] = { 1.1,0.7,15,0.002,0.014 };
	Vector v1[3] = { Vector(1,2,3),Vector(2,3,4),Vector(0,0,0)};
	string c="sta je";
	cout << function(a, 5) << " " << function(b, 5) << " " << function(&c) << " " << function(v1,3) << endl;
	return 0;
}
