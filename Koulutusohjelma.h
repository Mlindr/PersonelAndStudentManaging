#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"
#include <string>
#include <vector>
#include <fstream>
using std::string; using std::vector; using std::ofstream; using std::ifstream;

class Koulutusohjelma
{
public:
	Koulutusohjelma();//oletusrakentaja
	Koulutusohjelma(string nimi);//parametrirakentaja
	~Koulutusohjelma();//oletuspurkaja

	//getter
	string annaNimi() const;

	//setter
	void asetaNimi(string nimi);

	//methods
	void lisaaOpettaja();//lisaa opettaja olio opettajat_ vektoriin
	void lisaaOpiskelija();//lisaa opiskelija olio opiskelijat_ vektoriin
	void tulostaOpettajat() const;//tulosta opettajat_ sis‰lt‰m‰t olioiden metodeja k‰ytt‰en opettajat 
	void tulostaOpiskelijat() const;//tulosta opiskelijat_ sis‰lt‰m‰t olioiden metodeja k‰ytt‰en opiskelijat 
	int etsiOpettaja() const;//etsit‰‰n opettaja
	int etsiOpiskelija() const;//etsit‰‰n opiskelija
	void poistaOpettaja();//poista opettaja olio vektorista
	void poistaOpiskelija();//poista opiskelija olio vektorista
	void paivitaOpettaja();//paivita vektorin opettajat_ olion sis‰lt‰mi‰ tietoja
	void paivitaOpiskelija();//paivita vektorin opiskelijat_ olion sis‰lt‰mi‰ tietoja 
	void tallennaOpettajat(ofstream &tallennus_opettajat,string &koulutusohjelma) const;//tallentaa opettajien tiedot
	void tallennaOpiskelijat(ofstream &tallennus_opiskelijat,string &koulutusohjelma) const;//tallentaa opiskelijoiden tiedot
	void lataaOpettajat(string &etunimi, string &sukunimi, string &osoite, string &puhelinnumero, string &palkka, string &tunnus, string &opetusala);//luo opettaja olio opettajat_ vektorin sis‰lle
	void lataaOpiskelijat(string &etunimi, string &sukunimi, string &osoite, string &puhelinnumero, string &opiskelijanumero);//luo opsikelija olio opiskelijat_ vektorin sis‰lle

private:
	string nimi_;
	vector<Opiskelija>opiskelijat_;//vektori jonka sis‰‰n tallennetaan Opiskelija luokan olioita
	vector<Opettaja>opettajat_;//vketori jonka sis‰‰n tallennetaan Opettaja luokan olioita
};
