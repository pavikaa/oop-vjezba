// Napišite klasu „Kontakt“ koja predstavlja kontakt u telefonskom imeniku s
// podacima nužnim za održavanje takvog imenika (ime i prezime, telefonski broj,
// e-mail). Kreirajte polje objekata i u njega smjestite tri objekta stvorena
// parametarskim konstruktorom. Otvorite datoteku (ime se unosi s tipkovnice) i
// u nju korištenjem preopterećenog operatora za ispis upišite sadržaj ranije
// kreiranog polja. Za sve potrebe rada s nizovima znakova koristiti string klasu.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class kontakt
{
	friend ostream& operator<<(ostream&, kontakt&);
	string nameSurname, telephoneNumber, eMail;
public:
	kontakt();
	kontakt(string, string, string);
};
kontakt::kontakt()
{
	nameSurname = "ImePrezime";
	telephoneNumber = "0000000000";
	eMail = "email@mail.com";
}
kontakt::kontakt(string nameSurname, string telephoneNumber, string eMail)
{
	this->nameSurname = nameSurname;
	this->telephoneNumber = telephoneNumber;
	this->eMail = eMail;
}
ostream& operator<<(ostream& izlaz, kontakt& ref)
{
	izlaz << "Ime i prezime: " << ref.nameSurname << " Broj telefona: " << ref.telephoneNumber << " E-mail: " << ref.eMail << endl;
	return izlaz;
}
int main()
{
	int i;
	int const numOfContacts = 3;
	string nameSurname, telephoneNumber, eMail, name;
	kontakt kontakti[numOfContacts];
	for (i = 0; i < numOfContacts; i++)
	{
		cout << "Unesite ime i prezime " << i + 1 << ". kontakta: " << endl;
		getline(cin, nameSurname);
		cout << "Unesite telefonski broj: " << i + 1 << ". kontakta: " << endl;
		getline(cin, telephoneNumber);
		cout << "Unesite email: " << i + 1 << ". kontakta: " << endl;
		getline(cin, eMail);
		kontakti[i] = kontakt(nameSurname, telephoneNumber, eMail);
	}
	cout << "Kontakti ce se spremiti u datoteku. Navedite ime datoteke u koju zelite spremiti kontakte: " << endl;
	getline(cin, name);
	ofstream izlaznaDat(name);
	for (i = 0; i < numOfContacts; i++)
		izlaznaDat << kontakti[i] << "\n";
	izlaznaDat.close();
	return 0;
}
