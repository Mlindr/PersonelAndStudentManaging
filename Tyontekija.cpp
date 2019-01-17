#include "Tyontekija.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cin; using std::cout; using std::endl; using std::string; using std::getline;

/*Funktioiden nimet kertovat jo mit‰ tekev‰t*/
//oletusrakentaja
Tyontekija::Tyontekija(): Henkilo(),palkka_(),tunnus_()
{
	
}

//parametrirakentaja
Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero,
	double palkka, string tunnus): Henkilo(etunimi,sukunimi,osoite,puhelinnumero),palkka_(palkka),tunnus_(tunnus)
{
	
}

//kopiorakentaja
Tyontekija::Tyontekija(const Tyontekija &alkup): Henkilo(alkup),palkka_(alkup.palkka_),tunnus_(alkup.tunnus_)
{
	
}

//oletuspurkaja
Tyontekija::~Tyontekija()
{

}

Tyontekija &Tyontekija::operator=(const Tyontekija & sij)
{
	if (this != &sij) {
		Henkilo::operator=(sij);
		palkka_ = sij.palkka_;
		tunnus_ = sij.tunnus_;
	}

	return *this;
}

void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

double Tyontekija::annaPalkka() const
{
	return palkka_;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

void Tyontekija::kysyTiedot()
{

	Henkilo::kysyTiedot();//k‰ytet‰‰n Henkilo luokan metodia, jolla saadaan nimi,sukunimi,jne...

	//kysyt‰‰n k‰ytt‰j‰lt‰ palkka
	cout << "anna palkka: ";
	string palkka;
	getline(cin, palkka);
	palkanTarkistus(palkka);

	//kysyt‰‰n k‰ytt‰j‰lt‰ tunnus
	cout << "anna tunnus: ";
	getline(cin, tunnus_);
}

void Tyontekija::tulosta() const
{
	//tulostetaan henkilon tulostus eli nimi,jne.. sek‰ lis‰t‰‰n niiden tulostuksien per‰‰n palkan ja tunnuksen tulostus
	Henkilo::tulosta();
	cout << palkka_ << ", " << tunnus_ << ", ";
}

void Tyontekija::palkanTarkistus(string palkka)
{
	//tehd‰‰n tyyppimuutoksen tarkistus, jos ei ollut double syˆte string sis‰‰n->v‰‰r‰ syˆte->pyyd‰ uusi palkka
	while (!(std::stringstream(palkka) >> palkka_)) {
		cout << "V\x84\x84r\x84 sy\x94te, anna uusi palkka(pelk\x84t numeroarvot): ";
		getline(cin, palkka);
	}
}