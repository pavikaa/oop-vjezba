#include <iostream>
#include<string>
#include<fstream>
#include <ctime>
#include <algorithm>
#include"description.h"
#include"episode.h"
#include"season.h"
#include"iprinter.h"
#include"exception.h"
//Description
int Description::getnoEpisode() const
{
	return this->noEpisode;
}
float Description::getLength() const
{
	return this->length;
}
std::string Description::getName() const
{
	return this->name;
}
void Description::setnoEpisode(int noEpisode)
{
	this->noEpisode = noEpisode;
}
void Description::setLength(float length)
{
	this->length = length;
}
void Description::setName(std::string name)
{
	this->name = name;
}

bool operator==(const Description& ref1, const Description& ref2)
{
	return(ref1.getLength() == ref2.getLength() && ref1.getName() == ref2.getName() && ref1.getnoEpisode() == ref2.getnoEpisode());
}
//Episode
void Episode::addView(double grade)
{
	this->gradeSum += grade;
	if (grade > this->maxScore)
	{
		this->maxScore = grade;
	}
	this->numOfViewers++;
}
double Episode::getMaxScore() const
{
	return this->maxScore;
}
double Episode::getAverageScore() const
{
	return this->gradeSum / this->numOfViewers;
}
int Episode::getViewerCount() const
{
	return this->numOfViewers;
}
Description Episode::getDescription() const
{
	return this->description;
}

std::ostream& operator<< (std::ostream& izlaz, const Description& ref)
{
	izlaz << ref.noEpisode << "," << ref.length << "," << ref.name;
	return izlaz;
}
std::ostream& operator<< (std::ostream& izlaz, const Episode& ref)
{
	izlaz << ref.numOfViewers << " ," << ref.maxScore << "," << ref.gradeSum << "," << ref.description;
	return izlaz;
}
std::istream& operator>> (std::istream& ulaz, Description& ref)
{
	char a;
	std::string name;
	ulaz >> ref.noEpisode >> a >> ref.length >> a;
	std::getline(ulaz, ref.name);
	return ulaz;
}
std::istream& operator>> (std::istream& ulaz, Episode& ref)
{
	char a;
	ulaz >> ref.numOfViewers >> a >> ref.gradeSum >> a >> ref.maxScore >> a >> ref.description;
	return ulaz;
}
void print(Episode** ref, const int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		std::cout << *ref[i] << std::endl;
	}

}
double generateRandomScore()
{
	return (double)rand() / RAND_MAX * (10.0);
}
void persistToFile(std::string name, Episode** episodes, const int COUNT)
{
	std::ofstream output(name);
	for (int i = 0; i < COUNT; i++) {
		output << *episodes[i] << "\n";
	}
	output.close();
}
void sort(Episode** episodes, const int COUNT)
{
	for (int i = 0; i < COUNT - 1; i++) {
		for (int j = 0; j < COUNT - 1 - i; j++) {
			if (*episodes[j] > * episodes[j + 1]) {
				swap(*episodes[j], *episodes[j + 1]);
			}
		}
	}
}

bool operator>(const Episode& ref1, const Episode& ref2)
{

	return(ref1.description.getName() > ref2.description.getName());
}
void swap(Episode& ref1, Episode& ref2)
{
	Episode temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
//Episode** loadEpisodesFromFile(std::string name,const int count)
//{
//	std::ifstream input(name);
//	if (input.is_open() == false)
//		exit(0);
//	Episode** episodes = new Episode * [count];
//	for (int i = 0; i < count; i++) {
//		episodes[i] = new Episode;
//		input >> *episodes[i];
//	}
//	input.close();
//	return episodes;
//}
std::vector<Episode> loadEpisodesFromFile(std::string name)
{
	std::ifstream input(name);
	if (input.is_open() == false)
		exit(0);
	std::string line;
	int counter=1;
	while (getline(input,line))
	{
		input >> line;
		if (line.find('\n'))
			counter++;
	}
	input.close();
	std::ifstream inputt(name);
	if (inputt.is_open() == false)
		exit(0);
	std::vector<Episode> episodes(counter);
	for(int i=0; i<counter;i++)
	inputt >> episodes[i];
	inputt.close();
	return episodes;
}
bool operator==(const Episode& ref1, const Episode& ref2)
{
	return(ref1.getAverageScore() == ref2.getAverageScore() && ref1.getDescription() == ref2.getDescription() && ref1.getMaxScore() == ref2.getMaxScore() && ref1.getViewerCount() == ref2.getViewerCount());
}
std::string Episode::getName() const
{
	return description.getName();
}
//Season
//double Season::getAverageRating() const
//{
//	double sum=0.0;
//	for (int i = 0; i < noOfEpisodes; i++)
//	{
//		sum += episodes[i]->getAverageScore();
//	}
//	return sum / noOfEpisodes;
//}
//int Season::getTotalViews() const
//{
//	int sum = 0;
//	for (int i = 0; i < noOfEpisodes; i++)
//		sum += episodes[i]->getViewerCount();
//	return sum;
//}
//Episode& Season::getBestEpisode() const
//{
//	Episode* bestEpisode = episodes[0];
//	for (int i = 1; i < noOfEpisodes; i++)
//	{
//		if (episodes[i]->getMaxScore() > bestEpisode->getMaxScore())
//			bestEpisode = episodes[i];
//	}
//	return *bestEpisode;
//}
//Season::Season(const Season& ref):noOfEpisodes(ref.noOfEpisodes)
//{
//	episodes = new Episode * [ref.noOfEpisodes];
//	for (int i = 0; i < noOfEpisodes; i++)
//	{
//		episodes[i] = new Episode();
//		*episodes[i] = *ref.episodes[i];
//	}
//}
//Season& Season::operator=(const Season& ref)
//{
//	if (&ref == this)
//		return *this;
//	this->noOfEpisodes = ref.noOfEpisodes;
//	this->episodes = new Episode * [noOfEpisodes];
//	for (int i = 0; i < noOfEpisodes; i++)
//	{
//		episodes[i] = new Episode();
//		this->episodes[i] = ref.episodes[i];
//	}
//	return *this;
//}
const Episode& Season::operator[](int i)const
{
	if (i > noOfEpisodes)
		exit(0);
	return this->episodes[i];
}

void Season::add(Episode ref)
{
	episodes.push_back(ref);
	noOfEpisodes++;
}
int Season::getNoOfEpisodes() const
{
	return noOfEpisodes;
}
void Season::remove(std::string name)
{
	bool check = false;
	for (int i = 0; i < noOfEpisodes; i++)
	{
		if (episodes[i].getName() == name)
		{
			check = true;
			episodes.erase(episodes.begin() + i);
			noOfEpisodes--;
		}
	}
	if (!check)
	{
		throw EpisodeNotFoundException(name);
	}
}

//EpisodeNotFoundException
std::string EpisodeNotFoundException::getName() const
{
	return name;
}
//Printer
FilePrinter::FilePrinter(std::string name)
{
	this->name = name;
}
void FilePrinter::print(Season ref)
{
	std::ofstream output(name, std::ios_base::app);
	for (int counter = 0; counter < ref.getNoOfEpisodes(); counter++)
	{
		output << ref[counter] << "\n";
	}
	output << "\n";
}
void ConsolePrinter::print(Season ref)
{
	for (int counter = 0; counter < ref.getNoOfEpisodes(); counter++)
	{
		std::cout << ref[counter] << "\n";
	}
	std::cout << "\n";
}