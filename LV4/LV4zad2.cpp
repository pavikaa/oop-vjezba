//Napišite predložak klase Stack, koja će predstavljati LIFO stog.Kao pohrana se
//koristi dinamički alocirano polje, nužno je implementirati odgovarajuće
//konstruktore.Implementirati standardne metode stoga za umetanje, vađenje i
//zavirivanje u gornju vrijednost na stogu.U glavnoj funkciji napraviti tri stoga,
//jedan zapremnine 10 za spremanje realnih brojeva, drugi zapremnine 5 za
//spremanje cijelih brojeva, a treći kao kopiju prvog.U glavnoj funkciji testirati sva
//tri stoga njihovim popunjavanjem sa 7 nasumično generiranih vrijednosti.
//Poštivati pravila enkapsulacije
#include <iostream>
#include<cstdlib>
#include<ctime>
template <class Tip>
class Stack
{
	int size;
	int brElementa=0;
	Tip* polje;
public:
	Stack():size(0)
	{
		polje = new Tip[0];
	}
	Stack(int a) :size(a)
	{
		polje = new Tip[a];
	}
	~Stack()
	{
		delete[] polje;
	}
	Stack(const Stack& ref)
	{
		size = ref.size;
		brElementa = ref.brElementa;
		polje = new Tip[size];
		for (int i = 0; i < size; i++)
		{
			polje[i] = ref.polje[i];
		}
	}
	Stack& operator=(const Stack& ref)
	{
		if (this != &ref)
		{
			size = ref.size;
			brElementa = ref.brElementa;
			delete[]polje;
			polje = new Tip[size];
			for (int i = 0; i < size; i++)
			{
				polje[i] = ref.polje[i];
			}
		}
		return *this;
	}
	void push(Tip a)
	{
		if (brElementa < size)
		{
			polje[brElementa] = a;
			brElementa++;
		}
		else
			std::cout << "Zauzet je maksimalan broj elemenata." << std::endl;

	}
	void pop()
	{
		brElementa--;
	}
	Tip peek()
	{
		return polje[brElementa-1];
	}
};
int main()
{
	srand(time(NULL));
	Stack<int> s1(10);
	Stack<float> s2(5);
	Stack<int> s3;
	for (int i = 0; i < 7; i++)
	{
		s1.push((int)rand());
		std::cout << s1.peek() << std::endl;;
		s2.push((float)rand());
		std::cout << s2.peek()<<std::endl;
	}
	s3 = s1;
	return 0;
}
