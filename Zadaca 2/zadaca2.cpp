//U sustav za upravljanje epizodama TV serija trebate dodati klasu koja predstavlja opis epizode s podacima za broj epizode, trajanje epizode te naziv epizode.
//U klasu iz Zadaće 1 trebate kao atribut dodati još i objekt za opis.Implementirajte sve potrebne klase, njihove metode, kao i globalne funkcije kako bi se testni program u nastavku mogao ispravno izvesti.
//Kod sortiranja i ispisa koristiti odgovarajući preopterećeni operator. Sortirati uzlazno prema prvom slovu imena epizode.
#include <iostream>
#include<string>
#include<fstream>
#include "header.h"
int main()
{
	Description description(1, 45, "Pilot");
	std::cout << description << std::endl;
	Episode episode(10, 88.64, 9.78, description);
	std::cout << episode << std::endl;
	// Assume that the number of rows in the text file is always at least 10. 
	// Assume a valid input file.
	std::string fileName("shows.tv");
	const int COUNT = 10;

	std::ifstream input(fileName);
	Episode* episodes[COUNT];

	if (input.is_open() == false)
		return 1;

	for (int i = 0; i < COUNT; i++) {
		episodes[i] = new Episode();
		input >> *episodes[i];
	}
	input.close();
	std::cout << "Episodes:" << std::endl;
	print(episodes, COUNT);
	sort(episodes, COUNT);
	std::cout << "Sorted episodes:" << std::endl;
	print(episodes, COUNT);

	persistToFile("sorted.tv", episodes, COUNT);

	for (int i = 0; i < COUNT; i++) {
		delete episodes[i];
	}

	return 0;
}
