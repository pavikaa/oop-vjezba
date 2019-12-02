//Napisati klasu Trokut koje ima za parametre duljine stranica a, b i c.Klasa Trokut
//ima defaultni i parametarski konstruktor.U klasi postoje i metode povrsina() (za
//	bilo koji trokut!) i opseg() koje vraćaju površinu i opseg trokuta te metoda koja
//	provjerava je li trokut pravokutan(je / nije).Ukoliko se pokuša konstruirati objekt
//	klase koji ne može biti trokut(teorem o nejednakosti trokuta, npr. (1, 2, 3))
//	potrebno je dobaciti iznimku GeoIznimka, a u glavnom programu, prilikom
//	obrade iznimke, ispisati tekst "Trokut sa stranicama a,b,c nije moguć" gdje
//	umjesto a, b, c treba ispisati stvarne vrijednosti.Klasa GeoIznimka treba
//	sadržavati duljine stranica trokuta koji je napravio iznimku.U glavnom programu
//	kreirati dva trokuta - jedan sa defaultnim konstruktorom, drugi jednakostranični
//	sa duljinom stranice 4. Ispisati opseg za oba trokuta, te koji trokut ima veću
//	površinu odnosno da su površine jednake.
#include <iostream>
#include<cmath>
class GeoIznimka
{
public:
	double a, b, c;
	GeoIznimka() :a(1), b(1), c(1) {}
	GeoIznimka(double a, double b, double c) :a(a), b(b), c(c) {}
};
class Trokut
{
	double a, b, c;
public:
	Trokut():a(1),b(1),c(1){}
	Trokut(double a,double b,double c)
	{
		if ((a > b&& b > c&& a < c) || a == 0 || b == 0 || c == 0)
			throw(GeoIznimka(a, b, c));
		this->a = a;
		this->b = b;
		this->c = c;
	}
	double povrsina();
	double opseg();
	bool pravokutan();
};
double Trokut::povrsina()
{
	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
double Trokut::opseg()
{
	return a + b + c;
}
bool Trokut::pravokutan()
{
	return (pow(c, 2) == (pow(a, 2) + pow(b, 2)));
}
int main()
{
	Trokut prvi;
	Trokut drugi(4, 4, 4);
try
{
	Trokut treci(1, 0, 7);
}
catch (GeoIznimka &iznimka)
{
	std::cout << "Trokut sa stranicama " << iznimka.a << ", " << iznimka.b << ", " << iznimka.c << " nije moguc" << std::endl;
}
std::cout << "Opseg prvog trokuta: " << prvi.opseg() << ", opseg drugog trokuta: " << drugi.opseg() << std::endl;
if (prvi.povrsina() > drugi.povrsina())
std::cout << "Prvi trokut ima vecu povrsinu." << std::endl;
else if (prvi.povrsina() < drugi.povrsina())
std::cout << "Drugi trokut ima vecu povrsinu." << std::endl;
else
std::cout << "Povrsine su jednake." << std::endl;
	return 0;
}