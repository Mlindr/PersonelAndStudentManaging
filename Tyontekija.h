#pragma once
#include "Henkilo.h"
#include <string>
using std::string;

class Tyontekija :
	public Henkilo
{
public:

	//rakentajat ja purkajat
	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus);
	Tyontekija(const Tyontekija &alkup);
	~Tyontekija();
	Tyontekija & operator=(const Tyontekija &sij);

	//setters
	//aseta tietoja näillä
	void asetaPalkka(double palkka);
	void asetaTunnus(string tunnus);

	//getters
	//palauttaa funktiosta returnilla
	double annaPalkka() const;
	string annaTunnus() const;

	//methods
	void kysyTiedot();
	void tulosta() const;
	void palkanTarkistus(string palkka);//tarkistetaan että palkka ei ole mitä tahansa

private:
	double palkka_;
	string tunnus_;
};

