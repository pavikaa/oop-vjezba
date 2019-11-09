#ifndef HEADER_H
#define HEADER_H
class Description
{
	friend std::ostream& operator<< (std::ostream&, const Description&);
	friend std::istream& operator>> (std::istream&, Description&);
	int noEpisode;
	float length;
	std::string name;
public:
	Description();
	Description(int, float, std::string);
	~Description();
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
double gradeSum,maxScore;
public:
Episode();
Episode(int,double,double,Description);
~Episode();
void addDescription(int, float, std::string);
void addView(double);
double getMaxScore() const;
double getAverageScore() const;
int getViewerCount() const;
Description getDescription() const;
};
double generateRandomScore();
void print(Episode**,const int);
void persistToFile(std::string, Episode**,const int);
void sort(Episode**,const int);
void swap(Episode&, Episode&);
#endif
