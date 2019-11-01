// Napiši klasu koja predstavlja vektor u trodimenzionalnom prostoru sa
// atributima za i, j, k komponente. Za navedenu klasu napišite podrazumijevani i
// parametarski konstruktor te preopteretite 4 operatora za tu klasu (1
// aritmetički, 1 relacijski, 1 U/I te operator = (pridruživanja)). U glavnoj funkciji
// testirajte sve operatore koje ste preopteretili (u slučaju da niste preopteretili
// << ispišite rezultirajuće vektore odgovarajućom metodom za ispis).
#include <iostream>
using namespace std;
class Vector
{
	friend Vector operator+(const Vector&, const Vector&);
	friend bool operator==(const Vector&, const Vector&);
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

Vector operator+(const Vector& v1, const Vector& v2)
{
	return Vector((v1.i + v2.i), (v1.j + v2.j), (v1.k + v2.k));
}
bool operator==(const Vector& v1, const Vector& v2)
{
	return(v1.i == v2.i && v1.j == v2.j && v1.k == v2.k);
}
ostream& operator<<(ostream& izlaz, Vector& ref)
{
	izlaz << "Vektor je: " << ref.i << "i + " << ref.j << "j + " << ref.k << "k ." << endl;
	return izlaz;
}
int main()
{
	Vector v1 = Vector(1, 2, 3);
	Vector v2 = Vector(3, 7, 4);
	Vector v3 = Vector(4, 9, 7);
	Vector v4;
		cout << v1;
		v4 = v1 + v2;
		if (v4 == v3)
			cout << "Vektori su jednaki." << endl;
		else
			cout << "Vektori nisu jednaki." << endl;
	return 0;
}
