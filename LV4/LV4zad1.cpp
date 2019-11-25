#include <iostream>
#include<cstdlib>
#include<ctime>
template <class Tip>
void swap(Tip* x, Tip* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
template <class Tip>
void sort(Tip* polje, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (polje[j] > polje[j + 1])
				swap(&polje[j], &polje[j + 1]);
}
template <class Tip>
void print(Tip* polje, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << polje[i] << std::endl;
	}
}
template <class Tip>
void random(Tip* polje, int n)
{
	for (int i = 0; i < n; i++)
	{
		polje[i]=(Tip)rand();
	}
}
int main()
{
	srand(time(NULL));
	int n = 5;
	int* p1 = new int[n];
	double* p2 = new double[n];
	char* p3 = new char[n];
	random(p1,n);
	random(p2,n);
	random(p3,n);
	print(p1, n);
	std::cout << std::endl;
	print(p2, n);
	std::cout << std::endl;
	print(p3, n);
	std::cout << std::endl;
	sort(p1, n);
	sort(p2, n);
	sort(p3, n);
	print(p1, n);
	std::cout << std::endl;
	print(p2, n);
	std::cout << std::endl;
	print(p3, n);
	delete [] p1;
	delete [] p2;
	delete [] p3;
	return 0;
}