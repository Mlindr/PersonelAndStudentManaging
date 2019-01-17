#include <iostream>
#include "Opiskelija.h"
#include <string>
using std::cin; using std::cout; using std::endl; using std::string; using std::getline;

/*Funktioiden nimet kertovat jo mitä tekevät*/
Opiskelija::Opiskelija():Henkilo(),opiskelijanumero_()
{
	
}

Opiskelija::Opiskelija(string etunimi,string sukunimi,string osoite,string puhelinnumero,string opiskelijanumero):
Henkilo(etunimi,sukunimi,osoite,puhelinnumero),opiskelijanumero_(opiskelijanumero)
{
	
}

Opiskelija::~Opiskelija()
{

}

Opiskelija & Opiskelija::operator=(const Opiskelija & sij)
{
	if (this != &sij) {
		Henkilo::operator=(sij);//kutsu kantaluokan sijoitusoperaattoria
		 opiskelijanumero_= sij.opiskelijanumero_;//sijoita luokan omat 
	}
	return *this;
}

Opiskelija::Opiskelija(const Opiskelija &kopio):Henkilo(kopio),opiskelijanumero_(kopio.opiskelijanumero_)
{
	
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	cout << opiskelijanumero_ << endl;
}
