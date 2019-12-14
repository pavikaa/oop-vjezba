#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
namespace Marko
{
	class Complex
	{
		friend bool operator==(const Complex&, const Complex&);
		friend bool operator<(const Complex&,const Complex&);
		friend bool operator!=(const Complex&, const Complex&);
		friend bool operator>(const Complex&, const Complex&);
		friend bool operator<=(const Complex&, const Complex&);
		friend bool operator>=(const Complex&, const Complex&);
		double Re, Im;
	public:
		Complex():Re(0),Im(0){}
		Complex(double Re, double Im):Re(Re),Im(Im){}
		void setRe(double);
		void setIm(double);
		double getRe() const;
		double getIm() const;
		double modul() const;
	};
	void Complex::setRe(double Re)
	{
		this->Re = Re;
	}
	void Complex::setIm(double Im)
	{
		this->Im = Im;
	}
	double Complex::getRe() const
	{
		return Re;
	}
	double Complex::getIm() const
	{
		return Im;
	}
	double Complex::modul() const
	{
		return sqrt(pow(Re, 2) + pow(Im, 2));
	}
	bool operator==(const Complex& ref1,const Complex& ref2)
	{
		return ref1.modul() == ref2.modul();
	}
	bool operator<(const Complex& ref1,const Complex& ref2)
	{
		return ref1.modul() < ref2.modul();
	}
	bool operator!=(const Complex& ref1, const Complex& ref2)
	{
		return !(ref1 == ref2);
	}
	bool operator>(const Complex& ref1, const Complex& ref2)
	{
		return(ref2 < ref1);
	}
	bool operator<=(const Complex& ref1, const Complex& ref2)
	{
		return(ref1 < ref2 || ref1 == ref2);
	}
	bool operator>=(const Complex& ref1, const Complex& ref2)
	{
		return(ref1 > ref2 || ref1 == ref2);
	}
}
namespace Pavicic
{
	class Complex
	{
		friend bool operator==(const Complex&, const Complex&);
		friend bool operator<(const Complex&, const Complex&);
		friend bool operator!=(const Complex&, const Complex&);
		friend bool operator>(const Complex&, const Complex&);
		friend bool operator<=(const Complex&, const Complex&);
		friend bool operator>=(const Complex&, const Complex&);
		double Re, Im;
	public:
		Complex() :Re(0), Im(0) {}
		Complex(double Re, double Im) :Re(Re), Im(Im) {}
		void setRe(double);
		void setIm(double);
		double getRe() const;
		double getIm() const;
	};
	void Complex::setRe(double Re)
	{
		this->Re = Re;
	}
	void Complex::setIm(double Im)
	{
		this->Im = Im;
	}
	double Complex::getRe() const
	{
		return Re;
	}
	double Complex::getIm() const
	{
		return Im;
	}
	bool operator==(const Complex& ref1, const Complex& ref2)
	{
		return (ref1.getRe() == ref2.getRe())||(ref1.getIm() == ref2.getIm());
	}
	bool operator<(const Complex& ref1, const Complex& ref2)
	{
		if (ref1.getRe() == ref2.getRe())
			return (ref1.getIm() < ref2.getIm());
		else
			return (ref1.getRe() < ref2.getRe());
	}
	bool operator!=(const Complex& ref1, const Complex& ref2)
	{
		return !(ref1 == ref2);
	}
	bool operator>(const Complex& ref1, const Complex& ref2)
	{
		return(ref2 < ref1);
	}
	bool operator<=(const Complex& ref1, const Complex& ref2)
	{
		return(ref1 < ref2 || ref1 == ref2);
	}
	bool operator>=(const Complex& ref1, const Complex& ref2)
	{
		return(ref1 > ref2 || ref1 == ref2);
	}
}
void swap(Marko::Complex* x, Marko::Complex* y)
{
	Marko::Complex temp = *x;
	*x = *y;
	*y = temp;
}
void swap(Pavicic::Complex* x, Pavicic::Complex* y)
{
	Pavicic::Complex temp = *x;
	*x = *y;
	*y = temp;
}
void sort(Marko::Complex* polje, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (polje[j] > polje[j + 1])
				swap(&polje[j], &polje[j + 1]);
}
void sort(Pavicic::Complex* polje, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (polje[j] > polje[j + 1])
				swap(&polje[j], &polje[j + 1]);
}

int main()
{
	srand(time(NULL));
	Marko::Complex polje[10];
	Pavicic::Complex polje2[10];
	for (int i = 0; i < 10; i++)
	{
		int x = rand();
		int y = rand();
		polje[i] = Marko::Complex(x, y);
		polje2[i] = Pavicic::Complex(x, y);
	}
	sort(polje, 10);
	sort(polje2, 10);
	for (int i = 0; i < 10; i++)
		std::cout << polje[i].getRe() << " + " << polje[i].getIm() <<"i"<< std::endl;
	std::cout << std::endl;
	for(int i=0;i<10;i++)
		std::cout << polje2[i].getRe() << " + " << polje2[i].getIm() << "i" << std::endl;
	return 0;
}
