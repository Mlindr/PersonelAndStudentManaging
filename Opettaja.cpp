#include <iostream>
#include "Opettaja.h"
#include <string>
using std::cin; using std::cout; using std::endl; using std::string; using std::getline;

/*Funktioiden nimet kertovat jo mitä tekevät*/
Opettaja::Opettaja():Tyontekija(),opetusala_()
{

}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus,
	string opetusala) : Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus), opetusala_(opetusala)
{
	
}

Opettaja::Opettaja(const Opettaja &kopio):Tyontekija(kopio),opetusala_(kopio.opetusala_)
{

	
}

Opettaja::~Opettaja()
{

}

Opettaja &Opettaja::operator=(const Opettaja &sij) {
	
	if (this != &sij) {

		Tyontekija::operator=(sij);
		opetusala_ = sij.opetusala_;
	}

	return *this;
}

string Opettaja::annaOpetusala() const{

	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala) {

	opetusala_ = opetusala;
}

void Opettaja::kysyTiedot() {

	Tyontekija::kysyTiedot();

	cout << "anna opetusala: ";
	getline(cin, opetusala_);

}

void Opettaja::tulosta() const{

	Tyontekija::tulosta();

	cout << opetusala_ << endl;

}

string Opettaja::annaTunnus() const
{
	return Tyontekija::annaTunnus();
}