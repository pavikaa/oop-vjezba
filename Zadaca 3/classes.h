#ifndef CLASSES_H
#define CLASSES_H
class Description
{
	friend std::ostream& operator<< (std::ostream&, const Description&);
	friend std::istream& operator>> (std::istream&, Description&);
	friend bool operator==(const Description&, const Description&);
	int noEpisode;
	float length;
	std::string name;
public:
	Description() :noEpisode(0), length(0.0), name("Pilot") {}
	Description(int noEpisode, float length, std::string name) :noEpisode(noEpisode), length(length), name(name) {}
	~Description() {}
	void setnoEpisode(int);
	void setLength(float);
	void setName(std::string);
	int getnoEpisode() const;
	float getLength() const;
	std::string getName() const;
	Description& operator=(const Description&);
};
class Episode
{
	friend  bool operator>(const Episode&, const Episode&);
	friend bool operator==(const Episode&, const Episode&);
	friend std::ostream& operator<< (std::ostream&, const Episode&);
	friend std::istream& operator>> (std::istream&, Episode&);
	friend Episode** loadEpisodesFromFile(std::string, const int);
private:
	Description description;
	int numOfViewers;
	double gradeSum, maxScore;
public:
	Episode() : numOfViewers(0), gradeSum(0.0), maxScore(0.0) {}
	Episode(int numOfViewers, double gradeSum, double maxScore, Description description) : numOfViewers(numOfViewers), gradeSum(gradeSum), maxScore(maxScore) {}
	~Episode() {}
	void addView(double);
	double getMaxScore() const;
	double getAverageScore() const;
	int getViewerCount() const;
	Description getDescription() const;
	Episode& operator=(const Episode&);
};
class Season 
{
	Episode** episodes;
	int noOfEpisodes;
public:
	Season(Episode** episodes,int noOfEpisodes):noOfEpisodes(noOfEpisodes)
	{
		this->episodes = new Episode*[noOfEpisodes];
		for (int i = 0; i < noOfEpisodes; i++)
		{
			episodes[i] = new Episode;
			this->episodes[i] = episodes[i];
		}
	}
	Season() :noOfEpisodes(0)
	{
		this->episodes = new Episode*;
	}
	~Season()
	{
		for (int i = 0; i < noOfEpisodes; i++)
			delete episodes[i];
		delete[]*episodes;
	}
	double getAverageRating() const;
	int getTotalViews () const;
	Episode& getBestEpisode () const;
	Season(const Season& ref);
	 Episode& operator[](int)const;
};
double generateRandomScore();
void print(Episode**, const int);
void persistToFile(std::string, Episode**, const int);
void sort(Episode**, const int);
void swap(Episode&, Episode&);
Episode** loadEpisodesFromFile(std::string, const int);
#endif
