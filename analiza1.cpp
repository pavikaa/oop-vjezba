// Definirajte klasu koja predstavlja bankovni tekući račun s atributima za stanje,
// kamatu i limit, ima podrazumijevani i parametarski konstruktor, pristupne
// metode za postavljanje i dohvaćanje atributa, metode za uplatu i isplatu
// (voditi računa o limitu), metodu za pripis kamate te metodu za ispis stanja.
// Povesti računa o enkapsulaciji.
#include <iostream>
using namespace std;
class bankAccount
{
double stanje,kamata,limit;
public:
bankAccount();
bankAccount(double,double,double);
void setStanje(double);
void setKamata(double);
void setLimit(double);
double getStanje() const;
double getKamata() const;
double getLimit() const;
void uplata(double);
void isplata(double);
void stanjeRacuna();
void pripisKamate();
};
bankAccount::bankAccount()
{
        stanje=0.0;
        kamata=0.0;
        limit=0.0;
}
bankAccount::bankAccount(double stanje,double kamata, double limit)
{
        this->stanje=stanje;
        this->kamata=kamata;
        this->limit=limit;
}
void bankAccount::setStanje(double stanje)
{
        this->stanje=stanje;
}
void bankAccount::setKamata(double kamata)
{
        this->kamata=kamata;
}
void bankAccount::setLimit(double limit)
{
        this->limit=limit;
}
double bankAccount::getStanje() const
{
        return stanje;
}
double bankAccount::getKamata() const
{
        return kamata;
}
double bankAccount::getLimit() const
{
        return limit;
}
void bankAccount::uplata(double iznos)
{
        stanje+=iznos;
}
void bankAccount::isplata(double iznos)
{
        if(stanje-iznos<=-limit)
                cout<<"Nedozvoljena transakcija. Pokusavate isplatiti: "<<iznos<<" kn a na raspolaganju vam je: "<<stanje+limit<<" kn."<<endl;
        else
        {
                stanje-=iznos;
                cout<<"Isplaceno Vam je: "<<iznos<<" kn"<<endl;
        }
}
void bankAccount::stanjeRacuna()
{
        cout<<"Stanje vaseg racuna je : "<<stanje<<" kn. Dozvoljeni limit je : "<<limit<<" kn."<<endl;
}
void bankAccount::pripisKamate()
{
        if(stanje<0)
                stanje+=stanje*kamata/100;
}
int main()
{
        bankAccount a=bankAccount(1500,5,2000);
        a.isplata(500);
        a.isplata(4000);
        a.stanjeRacuna();
        a.pripisKamate();
        a.stanjeRacuna();
        a.isplata(2000);
        a.pripisKamate();
        a.stanjeRacuna();
}
