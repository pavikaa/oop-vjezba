//Napiši predloške funkcija Max() i Min() koje kao parametre primaju
//jednodimenzionalna polja i broj elemenata u polju.Funkcije pronalaze i kao
//rezultat vraćaju najveći odnosno najmanji element polja.Funkciju testirati na
//tri dinamički alocirana polja različitog tipa.
#include<iostream>
#include<ctime>
#include<cstdlib>
template<class Tip>
Tip max(Tip* polje, int n)
{
	Tip maxElement = polje[0];
	for (int i = 1; i < n; i++)
	{
		if (polje[i] > maxElement)
			maxElement = polje[i];
	}
	return maxElement;
}
template<class Tip>
Tip min(Tip* polje, int n)
{
	Tip minElement = polje[0];
	for (int i = 1; i < n; i++)
	{
		if (polje[i] < minElement)
			minElement = polje[i];
	}
	return minElement;
}
template <class Tip>
void random(Tip* polje, int n)
{
	for (int i = 0; i < n; i++)
	{
		polje[i] = (Tip)rand()/150;
	}
}
int main()
{
	srand(time(NULL));
	int* polje1 = new int[8];
	random(polje1, 8);
	double* polje2 = new double[12];
	random(polje2, 12);
	float* polje3 = new float[10];
	random(polje3, 10);
	std::cout << "Max elementi polja su : " << max(polje1, 8) << " " << max(polje2, 12) << " " << max(polje3, 10) << std::endl;
	std::cout << "Min elementi polja su : " << min(polje1, 8) << " " << min(polje2, 12) << " " << min(polje3, 10) << std::endl;

}
