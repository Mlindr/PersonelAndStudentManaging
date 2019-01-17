#pragma once
#include "Koulutusohjelma.h"
#include <string>
#include <vector>
using std::string; using std::vector;

class Koulu
{
public:

	//constructors/destructors
	Koulu();//oletusrakentaja
	Koulu(string nimi);//parametrillinen rakentaja
	~Koulu();//oletuspurkaja
	Koulu(const Koulu &);//kopiorakentaja

	//getter
	string annaNimi();//palauttaa luokan sis‰ll‰ olevan koulutusohjelman nimen

	//setter
	void asetaNimi(string nimi);//asettaa parametreiss‰ annetun koulutusohjelman nimen luokan string nimi_ muuttujaan

	//methods
	void lisaaKoulutusohjelma();//lis‰‰ koulutusohjelma olion vectoriin koulutusohjelmat_
	void tulostaKoulutusohjelmat() const;//tulostaa kaikkien koulutusohjelmien nimet
	void tulostaKoulutusohjelmienMaara() const;//tulostaa koulutusohjelmien m‰‰r‰n

	void lisaaKoulutusohjelmaanOpettaja();//kutsuu koulutusohjelmat_ sis‰ist‰ olion metodia lis‰t‰kseen opettajan
	void tulostaKoulutusohjelmanOpettajat() const;//tulostaa tietyn koulutusohjelman opettajat
	void lisaaKoulutusohjelmaanOpiskelija();//kutsuu koulutusohjelmat_ sis‰ist‰ olion metodia lis‰t‰kseen opiskelijan
	void tulostaKoulutusohjelmanOpiskelijat() const;//tulostaa koulutusohjelman opiskelijat
	void poistaKoulutusohjelma();//poistaa koulutusohjelma olion koulutusohjelmat_ vektorista
	void poistaOpettaja();//poistaa opettajan vektorin koulutusohjelmat_ sis‰lt‰m‰n olion vektorin opettajat_ sis‰lt‰ tiedot
	void poistaOpiskelija();//poistaa opiskelijan vektorin koulutusohjelmat_ sis‰lt‰m‰n olion vektorin opiskelijat_ sis‰lt‰ tiedot
	void paivitaKoulutusohjelma();//voidaan p‰ivitt‰‰ koulutusohjelman nimi
	void paivitaOpettaja();//p‰ivitt‰‰ opettajan tiedot
	void paivitaOpiskelija();//p‰ivitt‰‰ opiskelijan tiedot
	void tallennaTiedot() const;//tallentaa kaikki tiedot: koulutusohjelmat, opettajat ja oppilaat
	void lataaTiedot();//lukee kaikki tiedot eri tekstitiedostoihin: koulutusohjelmat.csv, opettajat.csv ja oppilaat.csv

private:

	int etsiKoulutusohjelma() const;//funktio jolla etsi‰ koulutusohjelma
	string nimi_;//k‰ytet‰‰n antamaan koulutusohjelman nimi
	vector<Koulutusohjelma>koulutusohjelmat_;//s‰ilytt‰‰ eri koulutusohjelmat, joista linkittyy opettajat ja opiskelijat
};

