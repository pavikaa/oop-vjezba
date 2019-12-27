//Umjesto pokazivača i dinamički alociranog polja u klasi koja predstavlja sezonu potrebno je rabiti std::vector.
//Omogućite dodavanje novih epizoda na kraj sezone te uklanjanje epizoda iz sezone po imenu.
//U slučaju da kod brisanja ne postoji epizoda s navedenim imenom, baciti kao iznimku objekt vlastite klase izvedene
//iz klase runtime_error.Kreirajte sučelje(engl.interface) IPrinter s metodom za ispis koje omogućuje ispis sezone
//na željeni način(vidjeti primjer izlaza).Implementirati dva printera, po jedan konzolni i datotečni.Preko pokazivača 
//tipa sučelja ispisati cijelu sezonu.Implementirajte sve potrebne klase, njihove metode, kao i globalne funkcije kako bi
//se testni program u nastavku mogao ispravno izvesti.
#include<iostream>
#include<string>
#include"description.h"
#include"episode.h"
#include"season.h"
#include"iprinter.h"
#include"exception.h"
#include<vector>
int main()
{
	IPrinter* printer = new ConsolePrinter();
	//IPrinter* printer = new FilePrinter("name.txt");

	std::string fileName("shows.tv");
	std::vector<Episode> episodes = loadEpisodesFromFile(fileName);
	Season* season = new Season(episodes);

	printer->print(*season);
	season->add(Episode(10, 84.56, 9.88, Description(11, 45, "Christmas special")));
	printer->print(*season);
	try {
		season->remove("Pilot");
		season->remove("Nope.");
	}
	catch (const EpisodeNotFoundException & ex) {
		std::cout << ex.what() << ", Name: " << ex.getName() << "\n\n";
	}
	printer->print(*season);
	delete printer;
	delete season;
}