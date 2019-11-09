#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
Episode::Episode()
{
        this->numOfViewers=0;
        this->gradeSum=0.0;
        this->maxScore=0.0;
}
Episode::Episode(int numOfViewers,double gradeSum, double maxScore)
{
        this->numOfViewers=numOfViewers;
        this->gradeSum=gradeSum;
        this->maxScore=maxScore;
}
Episode::~Episode()
{

}
double generateRandomScore()
{
        return (double)rand()/RAND_MAX*(10.0);
}
void Episode::addView(double grade)
{
        this->gradeSum+=grade;
        if (grade>this->maxScore)
        {this->maxScore=grade;}
        this->numOfViewers++;
}
double Episode::getMaxScore() const
{
        return this->maxScore;
}
double Episode::getAverageScore() const
{
        return this->gradeSum/this->numOfViewers;
}
int Episode::getViewerCount() const
{
        return this->numOfViewers;
}
int main()
{
        srand((unsigned)time(NULL));
        Episode *ep1, *ep2;
        ep1 = new Episode();
        ep2 = new Episode(10, 64.39, 8.7);
        int viewers = 10;
        for (int i = 0; i < viewers; i++) {
                ep1->addView(generateRandomScore());
                std::cout <<i+1<<". "<< ep1->getMaxScore() << std::endl;
        }
        if (ep1->getAverageScore() > ep2->getAverageScore()) {
                std::cout << "Viewers: " << ep1->getViewerCount() << std::endl;
        }
        else {
                std::cout << "Viewers: " << ep2->getViewerCount() << std::endl;
        }
        delete ep1;
        delete ep2;
}
