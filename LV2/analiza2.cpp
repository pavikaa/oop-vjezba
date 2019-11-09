// Definirajte klasu koja predstavlja pravokutnik, omogućuje pristup atributima
// te nudi mogućnost računanja površine i opsega pravokutnika. Napisati
// funkciju koja uspoređuje tri pravokutnika po veličini i ispisuje površinu
// najvećeg. Povesti računa o enkapsulaciji.
#include <iostream>
using namespace std;
class Pravokutnik
{
double a,b;
public:
friend double usporedi(Pravokutnik,Pravokutnik,Pravokutnik);
Pravokutnik();
Pravokutnik(double,double);
void setA(double);
void setB(double);
double getA() const;
double getB() const;
double racunajPovrsinu();
double racunajOpseg();
void usporedi(Pravokutnik, Pravokutnik, Pravokutnik);
};
Pravokutnik::Pravokutnik()
{
        a=0.0;
        b=0.0;
}
Pravokutnik::Pravokutnik(double a, double b)
{
        this->a=a;
        this->b=b;
}
void Pravokutnik::setA(double a)
{
        this->a=a;
}
void Pravokutnik::setB(double b)
{
        this->b=b;
}
double Pravokutnik::racunajPovrsinu()
{
        return a*b;
}
double Pravokutnik::racunajOpseg()
{
        return 2*(a+b);
}
double usporedi(Pravokutnik a,Pravokutnik b,Pravokutnik c)
{
        if(a.racunajPovrsinu()>b.racunajPovrsinu()&&a.racunajPovrsinu()>c.racunajPovrsinu())
                return a.racunajPovrsinu();
        else if(b.racunajPovrsinu()>a.racunajPovrsinu()&&b.racunajPovrsinu()>c.racunajPovrsinu())
                return b.racunajPovrsinu();
        else
                return c.racunajPovrsinu();
}
int main()
{
        Pravokutnik a,b,c;
        a=Pravokutnik(7,12);
        b=Pravokutnik(3.7,2.6);
        c=Pravokutnik(9.12,6.1);
        b.racunajOpseg();
        cout<<"Povrsina najveceg pravokutnika je : "<<usporedi(a,b,c)<<"."<<endl;
}
