/*Napiši predložak klase UređeniPar() koja predstavlja uređeni par dvaju
objekata.Podatkovni članovi su dva dinamički alocirana objekta, a klasa mora
imati konstruktore(default, parametarski i kopije), destruktor, operator = i
operatore usporedbe.U glavnoj funkciji testirati funkcionalnost klase za tri
različita tipa podatka*/
#include<iostream>

template <class Tip>
class UredeniPar
{
	Tip* objekt1;
	Tip* objekt2;
public:
	UredeniPar() :objekt1(new Tip), objekt2(new Tip) {}
	UredeniPar(Tip objekt1,Tip objekt2):objekt1(new Tip(objekt1)),objekt2(new Tip(objekt2)){}
	UredeniPar(const UredeniPar& ref)
	{
		this->objekt1 = new Tip;
		this->objekt2 = new Tip;
		*objekt1 = *ref.objekt1;
		*objekt2 = *ref.objekt2;
	}
	~UredeniPar()
	{
		delete objekt1;
		delete objekt2;
	}
	UredeniPar& operator=(const UredeniPar& ref)
	{
		if (this != &ref)
		{
			this->objekt1 = new Tip;
			this->objekt2 = new Tip;
			*objekt1 = *ref.objekt1;
			*objekt2 = *ref.objekt2;
		}
		return *this;
	}
	friend bool operator== (const UredeniPar& ref1, const UredeniPar& ref2)
	{
		return ((*ref1.objekt1 == *ref2.objekt1) && (*ref1.objekt2 == *ref2.objekt2));
	}
	friend bool operator!= (const UredeniPar& ref1, const UredeniPar& ref2)
	{
		return !(ref1==ref2);
	}
};

int main()
{
	UredeniPar<int> prvi(2, 5);
	UredeniPar<int> drugi(prvi);
	std::cout << (prvi == drugi) << std::endl;
	UredeniPar<int>treci(1, 4);
	UredeniPar<int>cetvrti(2, 2);
	UredeniPar<int>peti;
	peti = cetvrti;
	std::cout << (peti != treci) << std::endl;
}