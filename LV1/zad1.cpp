// Napišite klasu Die koja predstavlja kockicu za igru (npr. jamb). Za tu klasu
// kreirajte defaultni i parametarski konstruktor, metode za postavljanje i
// pristupanje vrijednosti kockice te metodu za bacanje kockice (rezultat bacanja
// određuje se slučajno!). Napraviti polje kockica i baciti sve kockice. Napisati
// funkciju koja provjerava je li bačen jamb.
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int randomValue();
class Die
{
int value;
public:
friend void isYamb(Die* kockice, int n);
Die();
Die(int vrijednost);
void setValue(int a);
};
void Die::setValue(int vrijednost)
{
								value = vrijednost;
}
Die::Die()
{
								setValue(1);
}
Die::Die(int vrijednost)
{
								setValue(vrijednost);
}
int randomValue()
{
								return (1 + (double)rand() / RAND_MAX * 5);
}
void isYamb(Die* kockice, int n)
{
								int i, check, is = 0;
								check = kockice[0].value;
								for (i = 1; i < n; i++)
								{
																if (kockice[i].value != check)
																{
																								is++;
																}

								}
								if (is > 0)
																cout << "Niste dobili jamb" << endl;
								else
																cout << "Dobili ste jamb" << endl;
}
int main()
{
								srand(time(NULL));
								int numOfDice, i;
								cout << "Unesite broj kockica" << endl;
								cin >> numOfDice;
								Die* kockice = new Die[numOfDice];
								for (i = 0; i < numOfDice; i++)
								{
																kockice[i].setValue(randomValue());
								}
								isYamb(kockice, numOfDice);
								return 0;
}
