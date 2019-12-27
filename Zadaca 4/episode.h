#pragma once
#include<vector>
class Episode
{
	friend  bool operator>(const Episode&, const Episode&);
	friend bool operator==(const Episode&, const Episode&);
	friend std::ostream& operator<< (std::ostream&, const Episode&);
	friend std::istream& operator>> (std::istream&, Episode&);
	friend std::vector<Episode> loadEpisodesFromFile(std::string);
private:
	Description description;
	int numOfViewers;
	double gradeSum, maxScore;
public:
	Episode() : numOfViewers(0), gradeSum(0.0), maxScore(0.0) {}
	Episode(int numOfViewers, double gradeSum, double maxScore, Description description) : numOfViewers(numOfViewers), gradeSum(gradeSum), maxScore(maxScore), description(description) {}
	~Episode() {}
	void addView(double);
	double getMaxScore() const;
	double getAverageScore() const;
	int getViewerCount() const;
	Description getDescription() const;
	std::string getName() const;

};