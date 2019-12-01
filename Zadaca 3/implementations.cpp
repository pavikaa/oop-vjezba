#include <iostream>
#include<string>
#include<fstream>
#include <time.h>
#include "classes.h"
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
Description& Description::operator=(const Description& ref)
{
	this->noEpisode = ref.noEpisode;
	this->length = ref.length;
	this->name = ref.name;
	return *this;
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
	ulaz >> ref.numOfViewers >> a >> ref.maxScore >> a >> ref.gradeSum >> a >> ref.description;
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
Episode** loadEpisodesFromFile(std::string name,const int count)
{
	
	std::ifstream input(name);
	Episode** episodes=new Episode*[count];

	if (input.is_open() == false)
		exit(0);

	for (int i = 0; i < count; i++) {
		episodes[i] = new Episode();
		input >> *episodes[i];
	}
	input.close();
	return episodes;
}
bool operator==(const Episode& ref1, const Episode& ref2)
{
	return(ref1.getAverageScore() == ref2.getAverageScore() && ref1.getDescription() == ref2.getDescription() && ref1.getMaxScore() == ref2.getMaxScore() && ref1.getViewerCount() == ref2.getViewerCount());
}
Episode& Episode::operator=(const Episode& ref)
{
	if (&ref == this)
		return *this;
	this->description = ref.description;
	this->gradeSum = ref.gradeSum;
	this->maxScore = ref.maxScore;
	this->numOfViewers = ref.numOfViewers;
	return *this;
}
//Season
double Season::getAverageRating() const
{
	double sum=0.0;
	for (int i = 0; i < noOfEpisodes; i++)
	{
		sum += episodes[i]->getAverageScore();
	}
	return sum / noOfEpisodes;
}
int Season::getTotalViews() const
{
	int sum = 0;
	for (int i = 0; i < noOfEpisodes; i++)
		sum += episodes[i]->getViewerCount();
	return sum;
}
Episode& Season::getBestEpisode() const
{
	Episode* bestEpisode = episodes[0];
	for (int i = 1; i < noOfEpisodes; i++)
	{
		if (episodes[i]->getMaxScore() > bestEpisode->getMaxScore())
			bestEpisode = episodes[i];
	}
	return *bestEpisode;
}
Episode& Season::operator[](int i)const
{
	if (i >= noOfEpisodes)
		exit(0);
	return *this->episodes[i];
}
Season::Season(const Season& ref)
{
	this->noOfEpisodes = ref.noOfEpisodes;
	this->episodes = new Episode * [noOfEpisodes];
	for (int i = 0; i < noOfEpisodes; i++)
	{
		this->episodes[i] = ref.episodes[i];
	}
}