#include <iostream>
#include<string>
#include<fstream>
#include <time.h>
#include "episodes.h"
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
