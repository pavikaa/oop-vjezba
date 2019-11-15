#ifndef EPISODES_H
#define EPISODES_H
class Description
{
	friend std::ostream& operator<< (std::ostream&, const Description&);
	friend std::istream& operator>> (std::istream&, Description&);
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
	friend std::ostream& operator<< (std::ostream&, const Episode&);
	friend std::istream& operator>> (std::istream&, Episode&);
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
};
double generateRandomScore();
void print(Episode**, const int);
void persistToFile(std::string, Episode**, const int);
void sort(Episode**, const int);
void swap(Episode&, Episode&);
#endif
