#include "Henkilo.h"
#include <iostream>
#include <string>
using std::endl; using std::cout; using std::cin; using std::string; using std::getline;

//oletusrakentaja
Henkilo::Henkilo():etunimi_(),sukunimi_(),osoite_(),puhelinnumero_()
{

}

//kopiorakentaja
Henkilo::Henkilo(const Henkilo & alkup): etunimi_(alkup.etunimi_),sukunimi_(alkup.sukunimi_),osoite_(alkup.osoite_),
puhelinnumero_(alkup.puhelinnumero_)
{
	
}

//parametrirakentaja
Henkilo::Henkilo(string Etunimi, string Sukunimi, string Osoite, string Puhelinnumero):etunimi_(Etunimi),
sukunimi_(Sukunimi),osoite_(Osoite),puhelinnumero_(Puhelinnumero){

	
}

//oletuspurkaja
Henkilo::~Henkilo(){

}

//luo uuden olion joka sisältää kopiorakentajan tiedot
Henkilo & Henkilo::operator=(const Henkilo & sij)
{
	if (this != &sij) {
		etunimi_ = sij.etunimi_;
		sukunimi_ = sij.sukunimi_;
		osoite_ = sij.osoite_;
		puhelinnumero_ = sij.puhelinnumero_;
	}

	return *this;
}

//getterit
string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

//setterit
void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

//kysytään henkilön kaikki tiedot
void Henkilo::kysyTiedot()
{
	//kysytään kaikki tiedot käyttäjältä ja tallennetaan ne luokan sisäisiin muuttujiin
	cout << "anna etunimi: ";
	getline(cin, etunimi_);
	cout << "anna sukunimi: ";
	getline(cin, sukunimi_);
	cout << "anna osoite: ";
	getline(cin, osoite_);
	cout << "anna puhelinnumero: ";
	getline(cin, puhelinnumero_);

}

//tulostetaan henkilön kaikki tiedot
void Henkilo::tulosta() const
{
	cout << etunimi_ << " " << sukunimi_ << ", " << osoite_ << ", " << puhelinnumero_ << ", ";
}