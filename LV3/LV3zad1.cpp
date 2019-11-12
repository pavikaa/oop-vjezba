#include <iostream>
class prepaid_kartica
{
protected:
	float stanjeracuna;
public:
	prepaid_kartica();
	prepaid_kartica(float);
	virtual ~prepaid_kartica(){}
	void nadoplata(float);
	float stanje();
	virtual void SendSMS()=0;
};
prepaid_kartica::prepaid_kartica()
{
	stanjeracuna = 0.0;
}
prepaid_kartica::prepaid_kartica(float stanje)
{
	stanjeracuna = stanje;
}
void prepaid_kartica::nadoplata(float iznos)
{
	stanjeracuna += iznos;
}
float prepaid_kartica::stanje()
{
	return stanjeracuna;
}
class tele2_kartica :public prepaid_kartica
{
protected:
	float cijenaSMS;
public:
	tele2_kartica();
	tele2_kartica(float,float);
	virtual ~tele2_kartica(){}
	void SendSMS();

};
tele2_kartica::tele2_kartica()
{
	cijenaSMS = 0.0;
	stanjeracuna = 0;
}
tele2_kartica::tele2_kartica(float cijena,float stanje)
{
	cijenaSMS = cijena;
	stanjeracuna = stanje;
}
void tele2_kartica::SendSMS()
{
	stanjeracuna -= cijenaSMS;
}
int main()
{
	tele2_kartica kartica=tele2_kartica(0.75, 100);
	prepaid_kartica* p;
	p = &kartica;
	p->SendSMS();
	std::cout << "Stanje racuna je: " << p->stanje() << std::endl;
}