#ifndef FUNCTIONS_H
#define FUNCTIONS_H
class Episode
{
private:
int numOfViewers;
double gradeSum,maxScore;
public:
Episode();
Episode(int,double,double);
~Episode();
void addView(double);
double getMaxScore() const;
double getAverageScore() const;
int getViewerCount() const;
};
double generateRandomScore();
#endif
