#pragma once
#include "Henkilo.h"
#include <string>
using std::string;

class Opiskelija :
	public Henkilo//periytyy henkilosta(kantaluokka)
{
public:

	//constructors/destructors
	Opiskelija();//oletusrakentaja
	Opiskelija(string,string,string,string,string);//parametrirakentaja
	~Opiskelija();//oletuspurkaja
	Opiskelija(const Opiskelija &);//kopiorakentaja
	Opiskelija & operator=(const Opiskelija &sij);

	//getters
	//antaa opiskelijanumeron
	string annaOpiskelijanumero() const;

	//setters
	//aseta string parametri opiskelijanumeroksi
	void asetaOpiskelijanumero(string);

	//methods
	void kysyTiedot();
	void tulosta() const;

private:
	string opiskelijanumero_;
};

