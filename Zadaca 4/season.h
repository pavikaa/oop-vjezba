#pragma once
#include<vector>
class Season
{
	std::vector<Episode> episodes;
	int noOfEpisodes;
public:
	Season(std::vector<Episode> ref) :noOfEpisodes(ref.size())
	{
		episodes = ref;
	}
	Season() :noOfEpisodes(0)
	{

	}
	~Season()
	{
		episodes.clear();
	}
	double getAverageRating() const;
	int getTotalViews() const;
	Episode& getBestEpisode() const;
	//Season(const Season& ref);
	const Episode& operator[](int)const;
	void add(Episode);
	int getNoOfEpisodes() const;
	void remove(std::string);

};
double generateRandomScore();
void print(Episode**, const int);
void persistToFile(std::string, Episode**, const int);
void sort(Episode**, const int);
void swap(Episode&, Episode&);
std::vector<Episode> loadEpisodesFromFile(std::string);