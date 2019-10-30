//Napiši klasu „Complex“ koja predstavlja kompleksan broj.Klasa treba sadržavati
//atribute koji predstavljaju realni i imaginarni dio kompleksnog broja, defaultni i
//parametarski konstruktor, pristupne metode, metodu koja vraća modul
//kompleksnog broja te prijateljsku funkciju zbroji() koja će zbrojiti dva kompleksna
//broja(funkcija ništa ne ispisuje!) na temelju predanih joj referenci na dva
//kompleksna broja.Testirati sve od kreiranog u main() funkciji.
#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
friend Complex zbroji(Complex&, Complex&);
int a, b;
public:
Complex();
Complex(int a, int b);
int getA();
int getB();
void modul();
};
Complex::Complex()
{
								a = 0;
								b = 0;
}
Complex::Complex(int a, int b)
{
								this->a = a;
								this->b = b;
}
int Complex::getA()
{
								return a;
}
int Complex::getB()
{
								return b;
}
void Complex::modul()
{
								cout << "Modul je: " << (double)sqrt(a * a + b * b) << endl;
}
Complex zbroji(Complex& ref1, Complex& ref2)
{
								return Complex((ref1.getA() + ref2.getA()), (ref1.getB() + ref2.getB()));
}
int main()
{
								Complex c1, c2;
								int a, b;
								cout << "Unesite realni i imaginarni dio kompleksnog broja: " << endl;
								cout << "Realni: " << endl;
								cin >> a;
								cout << "Imaginarni: " << endl;
								cin >> b;
								c1 = Complex(a, b);
								cout << "Unesite realni i imaginarni dio drugog kompleksnog broja: " << endl;
								cout << "Realni: " << endl;
								cin >> a;
								cout << "Imaginarni: " << endl;
								cin >> b;
								c2 = Complex(a, b);
								c1.modul();
								Complex c3;
								c3 = zbroji(c1, c2);
								cout << "Zbroj je: " << (c3.getA()) << " + " << (c3.getB()) << "i " << endl;
								return 0;
}
