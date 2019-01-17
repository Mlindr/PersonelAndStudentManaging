#include "Koulutusohjelma.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector; using std::getline;
using std::ofstream; using std::ifstream;

//oletusrakentaja
Koulutusohjelma::Koulutusohjelma() :nimi_(), opiskelijat_(), opettajat_()
{
}

//oletuspurkaja
Koulutusohjelma::~Koulutusohjelma()
{

}

//parametrirakentaja
Koulutusohjelma::Koulutusohjelma(string nimi) : nimi_(nimi), opiskelijat_(), opettajat_()
{

}

//getter
string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

//setter
void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

/*methods lisaa yhden opettajan vectoriin*/
void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja lisaOpettaja;//luodaan opettaja olio
	lisaOpettaja.kysyTiedot();//kysytään tiedot opettaja luokasta
	opettajat_.push_back(lisaOpettaja);//tallennetaan vektoriin opettajat_ opettaja olio

}

//lisaa opiskelijan
void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija lisaOpiskelija;//luodaan opiskelija olio
	lisaOpiskelija.kysyTiedot();//kysytään opiskelijan tiedot opiskelija luokasta
	opiskelijat_.push_back(lisaOpiskelija);//tallennetaan opiskelijat_ vektoriin opiskelija olio
}

//tulostaa opettajat
void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++) {

		opettajat_[i].tulosta();
	}
}

//tulostaa opiskelijat
void Koulutusohjelma::tulostaOpiskelijat() const
{

	for (unsigned int i = 0; i < opiskelijat_.size(); i++) {

		//tulosta täytyy olla const toimiakseen
		opiskelijat_[i].tulosta();
	}
}

//etsii halutun opettajan tunnuksen avulla 
int Koulutusohjelma::etsiOpettaja() const
{
	string tunnus;//alustuu aina uusiksi, ei tarvitse tyhjentää
	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus);//käyttäjä antaa etsimänsä tunnuksen

	//tarkistetaan ensin että on opettajia lisätty
	if (opettajat_.size() != 0) {
		//etsitään opettaja annetulla tunnuksella loopilla, joka pyörii vektorin koon verran
		for (unsigned int i = 0; i < opettajat_.size(); i++) {

			/*jos nimi vastaa opettajat_ vectorin i elementin sisältämän Opettaja luokan olion kutsuttua
			luokkafunktiota(metodia) annaTunnus,joka palauttaa tunnuksen nimen,palautetaan i:n arvo jolla voidaan indeksoida
			muissa koulutusohjelman luokan metodeissa ja suorittaa oikean opettajan tunnuksen kanssa*/
			if (tunnus == opettajat_[i].annaTunnus())
			{
				return i;//palauttaa löydetyn tunnuksen nimen 
			}

			//tai jos kaikki opettajat on käyty läpi, annetaan takaisin -1
			else if (i == (opettajat_.size() - 1)){
				//i lähtee nollasta, siksi verrataan opettajien koko -1 
					return -1;//palauttaa -1 jos ei löytynyt opettajaa
			}
		}
	}
	//jos ei ollut opettajia lisättynä vielä
	return -1;//palauttaa -1, joka ilmoittaa muissa metodeissa ettei koulutusohjelmaa ole löytynyt
}

//etsii halutun opsikelijan opiskelijanumeron avulla
int Koulutusohjelma::etsiOpiskelija() const
{
	string opiskelijanumero;//alustuu aina uusiksi, ei tarvitse tyhjentää
	cout << "Anna opiskelijan opiskelijanumero: ";
	getline(cin, opiskelijanumero);//käyttäjä antaa etsimänsä opiskelijanumeron

	//tarkistetaan ensin että on opiskelijoita lisätty
	if (opiskelijat_.size() != 0) {
		//etsitään opiskelija annetulla opiskelijanumerolla loopilla, joka pyörii vektorin koon verran
		for (unsigned int i = 0; i < opiskelijat_.size(); i++) {

			/*jos nimi vastaa opiskelijat_ vectorin i elementin sisältämän Opiskelija luokan olion kutsuttua
			luokkafunktiota(metodia) annaOpiskelijanumero,joka palauttaa opiskelijanumeron nimen,palautetaan i:n arvo 
			jolla voidaan indeksoida muissa koulutusohjelman luokan metodeissa ja suorittaa oikean opiskelijan opiskelijanumeron
			kanssa*/
			if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero())
			{
				return i;//palauttaa löydetyn opiskelijan nimen 
			}

			//tai jos kaikki opiskelijat on käyty läpi, annetaan takaisin -1
			else if (i == (opiskelijat_.size() - 1)) {
				//i lähtee nollasta, siksi verrataan opiskelijoiden koko -1 
					return -1;//palauttaa -1 jos ei löytynyt opiskelijaa
			}
		}
	}
	//jos ei ollut opiskelijoita lisättynä vielä
	return -1;//palauttaa -1, joka ilmoittaa muissa metodeissa ettei opiskelijaa ole löytynyt
}

//poistaa halutun opettajan tunnuksen avulla 
void Koulutusohjelma::poistaOpettaja()
{
	int indeksi = etsiOpettaja();//etsiOpettaja palauttaa kokonaisluvun joka vastaa etsittyä opettajaa vektorissa

	if (indeksi >= 0) {
		/*Poistetaan opettajat_ vektorista Opettaja olio, joka löytyy paikasta 0+indeksi*/
		opettajat_.erase(opettajat_.begin() + indeksi);
	}

	else {
		cout << "Opettajaa ei l\x94ytynyt annetulla tunnuksella" << endl;
	}
}

//poistaa halutun opsikelijan opiskelijanumeron avulla
void Koulutusohjelma::poistaOpiskelija()
{
	int indeksi = etsiOpiskelija();//etsiOpiskelija palauttaa kokonaisluvun joka vastaa etsittyä opiskelijaa vektorissa

	if (indeksi >= 0) {
		/*Poistetaan opiskelijat_ vektorista Opiskelija olio, joka löytyy paikasta 0+indeksi*/
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
	}

	else {
		cout << "Opiskelijaa ei l\x94ytynyt annetulla opiskelijanumerolla" << endl;
	}
}

//päivittää halutun opettajan tunnuksen avulla 
void Koulutusohjelma::paivitaOpettaja()
{
	int indeksi = etsiOpettaja();//etsitään opettaja tunnuksen avulla
	string paivitettavaOsa, etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus, opetusala;
	//jos annetulla tunnuksella ei löytynyt opettajaa, indeksi on -1
	if (indeksi >= 0) {
		while (paivitettavaOsa != "L" && paivitettavaOsa != "l") {

			cout << "Anna paivitettava tieto: \n"
				"1)etunimi\n"
				"2)sukunimi\n"
				"3)osoite\n"
				"4)puhelinnumero\n"
				"5)palkka\n"
				"6)tunnus\n"
				"7)opetusala\n"
				"L)Lopeta\n"
				"Valinta: ";

			getline(cin, paivitettavaOsa);
			//tyhjennä terminaali
			system("CLS");

			if (paivitettavaOsa == "1") {

				cout << "Anna uusi etunimi: ";
				getline(cin, etunimi);

				opettajat_[indeksi].asetaEtunimi(etunimi);
			}
			if (paivitettavaOsa == "2") {

				cout << "Anna uusi sukunimi: ";
				getline(cin, sukunimi);

				opettajat_[indeksi].asetaSukunimi(sukunimi);
			}
			if (paivitettavaOsa == "3") {

				cout << "Anna uusi osoite: ";
				getline(cin, osoite);

				opettajat_[indeksi].asetaOsoite(osoite);
			}
			if (paivitettavaOsa == "4") {

				cout << "Anna uusi puhelinnumero: ";
				getline(cin, puhelinnumero);

				opettajat_[indeksi].asetaPuhelinnumero(puhelinnumero);
			}
			if (paivitettavaOsa == "5") {

				cout << "Anna uusi palkka: ";
				getline(cin, palkka);

				opettajat_[indeksi].palkanTarkistus(palkka);

			}
			if (paivitettavaOsa == "6") {

				cout << "Anna uusi tunnus: ";
				getline(cin, tunnus);

				opettajat_[indeksi].asetaTunnus(tunnus);
			}
			if (paivitettavaOsa == "7") {

				cout << "Anna uusi opetusala: ";
				getline(cin, opetusala);

				opettajat_[indeksi].asetaOpetusala(opetusala);
			}
		}
	}

		else {
			cout << "Opettajaa ei l\x94ytynyt annetulla tunnuksella" << endl;
		}

}

//päivittää halutun opsikelijan opiskelijanumeron avulla
void Koulutusohjelma::paivitaOpiskelija()
{
	int indeksi = etsiOpiskelija();
	string paivitettavaOsa, etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero;

	if (indeksi >= 0) {
		while (paivitettavaOsa != "L" && paivitettavaOsa != "l") {

			cout << "Anna paivitettava tieto: \n"
				"1)etunimi\n"
				"2)sukunimi\n"
				"3)osoite\n"
				"4)puhelinnumero\n"
				"5)opiskelijanumero\n"
				"Valinta: ";

			getline(cin, paivitettavaOsa);
			//tyhjennä terminaali
			system("CLS");

			if (paivitettavaOsa == "1") {

				cout << "Anna uusi etunimi: ";
				getline(cin, etunimi);

				opiskelijat_[indeksi].asetaEtunimi(etunimi);
			}
			if (paivitettavaOsa == "2") {

				cout << "Anna uusi sukunimi: ";
				getline(cin, sukunimi);

				opiskelijat_[indeksi].asetaSukunimi(sukunimi);
			}
			if (paivitettavaOsa == "3") {

				cout << "Anna uusi osoite: ";
				getline(cin, osoite);

				opiskelijat_[indeksi].asetaOsoite(osoite);
			}
			if (paivitettavaOsa == "4") {

				cout << "Anna uusi puhelinnumero: ";
				getline(cin, puhelinnumero);

				opiskelijat_[indeksi].asetaPuhelinnumero(puhelinnumero);
			}
			if (paivitettavaOsa == "5") {

				cout << "Anna uusi palkka: ";
				getline(cin, opiskelijanumero);

				opiskelijat_[indeksi].asetaOpiskelijanumero(opiskelijanumero);
			}
		}
	}
		else {
			cout << "Opiskelijaa ei l\x94ytynyt annetulla opiskelijanumerolla" << endl;
		}

	}

//metodia jolla tallennetaan opettajat Koulu luokasta käsin
void Koulutusohjelma::tallennaOpettajat(ofstream &tallennus_opettajat,string &koulutusohjelma) const
{
	
	try {
		//jos vektori ei ole tyhjä
		if (opettajat_.size() > 0) {
			for (unsigned int i = 0; i < opettajat_.size(); i++) {

				//kutsutaan kaikki opettajalle mahdolliset getterit ja tallennetaan tiedot
				//yhden tiedon jälkeen lisätään ";" jotta tiedot voidaan eritellä
				tallennus_opettajat << koulutusohjelma << ";"
					<< opettajat_[i].annaEtunimi() << ";"
					<< opettajat_[i].annaSukunimi() << ";"
					<< opettajat_[i].annaOsoite() << ";"
					<< opettajat_[i].annaPuhelinnumero() << ";"
					<< opettajat_[i].annaPalkka() << ";"
					<< opettajat_[i].annaTunnus() << ";"
					<< opettajat_[i].annaOpetusala() << endl;
			}
		}
	}
	catch (...) {
		cout << "Jotain meni vikaan tallentaessa opettajia" << endl;
	}
}

//metodia jolla tallennetaan opiskelijat Koulu luokasta käsin
void Koulutusohjelma::tallennaOpiskelijat(ofstream &tallennus_opiskelijat,string &koulutusohjelma) const
{
	try {
		//jos vektori ei ole tyhjä
		if (opiskelijat_.size() > 0) {
			for (unsigned int i = 0; i < opiskelijat_.size(); i++) {

				//kutsutaan kaikki mahdolliset getterit opiskelijalle ja tallennetaan tiedot
				//yhden tiedon jälkeen lisätään ";" jotta tiedot voidaan eritellä
				tallennus_opiskelijat << koulutusohjelma << ";"
					<< opiskelijat_[i].annaEtunimi() << ";"
					<< opiskelijat_[i].annaSukunimi() << ";"
					<< opiskelijat_[i].annaOsoite() << ";"
					<< opiskelijat_[i].annaPuhelinnumero() << ";"
					<< opiskelijat_[i].annaOpiskelijanumero() << endl;
			}
		}
	}
	catch (...) {
		cout << "Jotain meni vikaan tallentaessa opiskelijoita" << endl;
	}
}

//metodia jolla ladataan opettajat Koulu luokasta käsin
void Koulutusohjelma::lataaOpettajat(string &etunimi, string &sukunimi, string &osoite, string &puhelinnumero, string &palkka, string &tunnus, string &opetusala)
{
	double palkka_muunnos;
	std::stringstream(palkka) >> palkka_muunnos;//muutetaan merkkijonoinen palkka double muuttujaksi

	//luodaan olio vectoriin opettajat_ käyttämällä opettaja luokan parametrirakentajaa
	opettajat_.push_back(Opettaja(etunimi, sukunimi, osoite, puhelinnumero, palkka_muunnos, tunnus, opetusala));
}

//metodia jolla ladataan opiskelijat Koulu luokasta käsin
void Koulutusohjelma::lataaOpiskelijat(string &etunimi, string &sukunimi, string &osoite, string &puhelinnumero, string &opiskelijanumero)
{

	//luodaan olio vectoriin opiskelijat_ käyttämällä Opiskelija luokan parametrirakentajaa
	opiskelijat_.push_back(Opiskelija(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero));


}
