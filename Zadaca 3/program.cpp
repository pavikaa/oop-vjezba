//U sustav za upravljanje epizodama TV serija trebate dodati klasu koja predstavlja sezonu,
//a koja omogućuje čuvanje epizoda uporabom dinamički alociranog polja pokazivača.
//Sezona sama treba voditi računa o životnom ciklusu objekata koje čuva.
//Implementirajte sve potrebne klase, njihove metode, kao i globalne funkcije kako bi se testni program u nastavku mogao ispravno izvesti.
//Najbolja epizoda je ona koja ima najvišu maksimalnu ocjenu.
#include<iostream>
#include<string>
#include"classes.h"
int main()
{
	std::string fileName("shows.tv");
	const int COUNT = 10;
	Episode** episodes = loadEpisodesFromFile(fileName, COUNT);

	const Season* season = new Season(episodes, COUNT);
	Season* seasonCopy = new Season(*season);

	for (int i = 0; i < COUNT; i++) {
		delete episodes[i];
	}
	delete[] episodes;

	const Episode episode = (*season)[0];
	const Episode episodeCopy = (*seasonCopy)[0];

	std::cout << episode << std::endl;
	std::cout << episodeCopy << std::endl;

	if (episodeCopy == episode) {
		std::cout << "HW points++" << std::endl;
	}
	if (&seasonCopy[0] == &season[0]) {
		std::cout << "HW points--" << std::endl;
	}

	std::cout << "Report:" << "\n\t"
		<< "Avg rating: " << season->getAverageRating() << "\n\t"
		<< "Total viewers: " << season->getTotalViews() << "\n\t"
		<< "Best episode: " << season->getBestEpisode() << "\n\t"
		<< std::endl;

	delete season;
	delete seasonCopy;
}