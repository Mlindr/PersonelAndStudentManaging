#include "Koulu.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::vector;
using std::ofstream; using std::ifstream;

//oletusrakentaja
Koulu::Koulu():nimi_(),koulutusohjelmat_()
{

}

//parametrirakentaja
Koulu::Koulu(string nimi):nimi_(nimi),koulutusohjelmat_()
{

}

//oletuspurkaja
Koulu::~Koulu()
{
}

//kopiorakentaja
Koulu::Koulu(const Koulu &kopio):nimi_(kopio.nimi_),koulutusohjelmat_(kopio.koulutusohjelmat_)
{

}

//Antaa koulun nimen
string Koulu::annaNimi()
{
	return nimi_;
}

//asettaa koulun nimen
void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

//etsii koulutusohjelman
int Koulu::etsiKoulutusohjelma() const
{
	string nimi;//alustuu aina uusiksi, ei tarvitse tyhjentää
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);//käyttäjän etsimä koulutusohjelman nimi

	try {
		//tarkistetaan ensin että on koulutusohjelmia lisätty
		if (koulutusohjelmat_.size() != 0) {
			//etsitään koulutusohjelma annetulla nimellä loopilla, joka pyörii vektorin koon verran
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {

				/*jos nimi vastaa koulutusohjelmat_ vectorin i elementin sisältämän Koulutusohjelma luokan olion kutsuttua
				luokkafunktiota(metodia) annaNimi,joka palauttaa koulutusohjelman nimen,palautetaan i:n arvo jolla voidaan indeksoida
				muissa Koulu luokan metodeissa ja suorittaa oikean koulutusohjelman nimen kanssa*/
				if (nimi == koulutusohjelmat_[i].annaNimi())
				{
					return i;//palauttaa löydetyn koulutusohjelman nimen 
				}//if

				//tai jos kaikki koulutusohjelmat on käyty läpi, annetaan takaisin -1
				else if (i == (koulutusohjelmat_.size() - 1)) {
					//i lähtee nollasta, siksi verrataan koulutoshjelmien koko -1 
					return -1;//palauttaa -1 jos ei löytynyt koulutusohjelmaa			
				}//else if
			}//for loop
		}//if

		/*jos ei ollut koulutusohjelmia lisättynä vielä palauttaa -1,
		joka ilmoittaa muissa metodeissa ettei koulutusohjelmaa ole löytynyt*/
		return -1;
	}//try
	catch (std::out_of_range &ex) {
		cout << "Virheellinen indeksointi" << endl;
	}//catch
	catch (...) {
		cout << "Tapahtui odottamaton virhe" << endl;
	}//catch
}

//lisaa koulutusohjelman
void Koulu::lisaaKoulutusohjelma()
{
	/*annetaan nimi joka annetaan parametrina kun luodaan olio käyttämällä parametrirakentajaa*/
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	/*Koulutusohjelma(nimi) luo uuden Koulutusohjelma olion parametrirakentajalla ja annettuna parametrina on nimi
	joka laitetaan vektorin sisälle eli vektoriin menee olio parametrilla nimi, joka on koulutusohjelman nimi*/
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
}

//tulostaa kaikki koulutusohjelmat
void Koulu::tulostaKoulutusohjelmat() const
{
	cout << "Koulutusohjelmat: " << endl;
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		cout << koulutusohjelmat_[i].annaNimi() << endl;//tulostaa olion annaNimi metodin palautetun sisällön
	}
}

//tulostaa koulutusohjelmien määrän
void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "Koulutusohjelmien m\x84\x84r\x84: " << koulutusohjelmat_.size() << endl;//tulostaa vektorin koon
}

//lisää opettajan tiettyyn koulutusohjelmaan
void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

	//indeksi=-1, jos ei löytynyt
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpettaja();//kutsutaan indeksoidun olion metodia lisaaOpettaja
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//tulostaa tietyn koulutusohjelman opettajat
void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

 	//indeksi=-1, jos ei löytynyt
	if (indeksi >= 0) {
		//käytetään vektorin koulutusohjelmat_ sisältämää oliota tulostakseen ohjelman ja opettajien nimet
		cout << koulutusohjelmat_[indeksi].annaNimi() << " koulutusohjelman opettajat: " << endl;
		koulutusohjelmat_[indeksi].tulostaOpettajat();//opettaja luokan metodi
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//lisää opiskelija tiettyyn koulutusohjelmaan
void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

	//indeksi=-1, jos ei löytynyt
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].lisaaOpiskelija();//vektorissa olevan olion metodilla lisaaOpiskelija lisataan opiskelija
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//tulostaa tietyn koulutusohjelman kaikki oppilaat
void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

	//indeksi=-1, jos ei löytynyt
	if (indeksi >= 0) {
		//tulostetaan koulutusohjelman nimi ja opiskelijoiden nimet hyödyntäen vektorissa olevan olion metodeja
		cout << koulutusohjelmat_[indeksi].annaNimi() << " koulutusohjelman opiskelijat: " << endl;
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();//opiskelija luokan metodi
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//poistaa koulutusohjelman
void Koulu::poistaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();//etsitään vektorista koulutusohjelma

	//jos koulutusohjelma on olemassa voidaan poistaa vektorista koulutusohjelma olio joka on indeksin kohdalla
	if (indeksi >= 0) {
		koulutusohjelmat_.erase(koulutusohjelmat_.begin()+indeksi);//vektorin alku(.begin)=0 + indeksi verran, poistetaan alkio
	}

	//jos koulutusohjelmaa ei löydy tai ei ole
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}

}

//poistaa tietyn opettajan halutusta koulutusohjelmasta
void Koulu::poistaOpettaja() {

	int indeksi = etsiKoulutusohjelma();//etsitään koulutusohjelma

	if (indeksi >= 0) {
		/*kutsutaan koulutusohjelmat_ elementin sisällä olevaa Koulutusohjelma olion metodia poistaOpettaja()*/
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}

	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//poistaa tietyn opiskelijan halutusta koulutusohjelmasta
void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//etsitään koulutusohjelma

	if (indeksi >= 0) {
		/*kutsutaan koulutusohjelmat_ elementin sisällä olevaa Koulutusohjelma olion metodia poistaOpiskelija()*/
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}

	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//paivittaa koulutusohjelman nimen, koulutusohjelman opettajat ja oppilaat säilyvät mukana
void Koulu::paivitaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();//etsitään koulutusohjelma metodilla etsiKoulutusohjelma, joka palauttaa kokonaisluvun
	string nimi;

	//jos metodi ei löytänyt koulutusohjelmaa, indeksi=-1
	if (indeksi >= 0) {

		cout << "Anna uusi koulutusohjelman nimi: " << endl;
		getline(cin,nimi);//uusi koulutusohjelman nimi käyttäjältä
		koulutusohjelmat_[indeksi].asetaNimi(nimi);//asetetaan uusi  koulutusohjelman nimi
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//mahdollistaa opettajan tietojen päivittämisen
void Koulu::paivitaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();//etsitään koulutusohjelma vektorista

	//indeksi on -1 jos ei löytynyt koulutusohjelmaa 
	if (indeksi >= 0) {

		koulutusohjelmat_[indeksi].paivitaOpettaja();//koulutusohjelma luokan metodi paivitaOpettaja()
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}

}

//mahdollistaa opiskelijan tietojen päivittämisen
void Koulu::paivitaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//etsitään vektorista koulutusohjelmat_ koulutusohjelmaa

	//indeksi on -1 jos ei löytynyt koulutusohjelmaa
	if (indeksi >= 0) {

		koulutusohjelmat_[indeksi].paivitaOpiskelija();//koulutusohjelman metodi paivitaOpiskelija()
	}

	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}

}

//tallentaa tiedot vectoreista tekstitiedostoihin
void Koulu::tallennaTiedot() const
{
	//luodaan kirjoitus streamit ja asetetaan tiedostojen nimet johon kirjoitetaan
	ofstream tallennus_koulutusohjelmat;
	tallennus_koulutusohjelmat.open("koulutusohjelmat.csv");
	ofstream tallennus_opettajat;
	tallennus_opettajat.open("opettajat.csv");
	ofstream tallennus_opiskelijat;
	tallennus_opiskelijat.open("opiskelijat.csv");
	
	string koulutusohjelma;

	/*Koulutusohjelmien,opettajien ja oppilaiden tallennus on tehty erikseen,
	jotta virhetarkastelu olisi helpompaa.*/

	//Koulutusohjelmien tallennus
	if (tallennus_koulutusohjelmat.is_open()) {

		//niin monta kuin koulutusohjelmaa on
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {

			//koulutusohjelmien tallennus tapahtuu kutsumalla metodia annaNimi
			tallennus_koulutusohjelmat << koulutusohjelmat_[i].annaNimi() << endl;
		}
		tallennus_koulutusohjelmat.close();//sulje tiedosto
	}

	else {
		cout << "Koulutusohjelmien tallennus ep\x84onnistui" << endl;
	}

	//opettajien tallennus
	if (tallennus_opettajat.is_open()) {
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {

			//koulutusohjelma muuttujaan tallenetaan vektorin sisällä olevan koulutusohjelman olion nimi
			//tämä muuttuja annetaan parametreina jotta se voidaan tallentaa koulutusohjelman metodissa tallennaOpettajat
			koulutusohjelma = koulutusohjelmat_[i].annaNimi();

			//annetaan koulutusohjelman metodille tallennaOpettajat kirjoitus stream tallennus_opettajat referenssinä
			koulutusohjelmat_[i].tallennaOpettajat(tallennus_opettajat,koulutusohjelma);
		}
		tallennus_opettajat.close();//sulje tiedosto
	}

	else {
		cout << "Opettajien tallennus ep\x84onnistui" << endl;
	}

	//opiskelijoiden tallennus
	if (tallennus_opiskelijat.is_open()) {
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {

			//koulutusohjelma muuttujaan tallenetaan vektorin sisällä olevan koulutusohjelman olion nimi
			//tämä muuttuja annetaan parametreina jotta se voidaan tallentaa koulutusohjelman metodissa tallennaOpiskelijat
			koulutusohjelma = koulutusohjelmat_[i].annaNimi();

			//annetaan koulutusohjelman metodille tallennaOpiskelijat kirjoitus stream tallennus_opiskelijat referenssinä
			koulutusohjelmat_[i].tallennaOpiskelijat(tallennus_opiskelijat,koulutusohjelma);
		}
		tallennus_opiskelijat.close();//sulje tiedosto
	}

	else {
		cout << "Oppilaiden tallennus ep\x84onnistui" << endl;
	}
	cout << "Tallennus suoritettu!" << endl;//käyttäjä saa tiedon kun tallennus on suoritettu
}

//lataa tiedot vectoreihin tekstitiedostoista
void Koulu::lataaTiedot()
{
	ifstream lataus_koulutusohjelmat;
	lataus_koulutusohjelmat.open("koulutusohjelmat.csv");

	ifstream lataus_opettajat;
	lataus_opettajat.open("opettajat.csv");

	ifstream lataus_opiskelijat;
	lataus_opiskelijat.open("opiskelijat.csv");

	string etunimi, sukunimi, osoite, puhelinnumero, s_palkka, tunnus, opetusala,data,koulutusohjelma, palkka, opiskelijanumero;

	/*EOF=End Of File, peek()=kurkista mikä on seuraava merkki
	getline(avattu tiedoston nimi, mihin muuttujaan tallennetaan, mihin saakka luetaan(\n=seuraava rivi))*/

	//koulutusohjelmien lataaminen
	while (lataus_koulutusohjelmat.peek() != EOF)
	{
		getline(lataus_koulutusohjelmat, data,'\n');
		koulutusohjelmat_.push_back(Koulutusohjelma(data));
	}
	lataus_koulutusohjelmat.close();
	
	//opettajien lataaminen
	while (lataus_opettajat.peek() != EOF) {

		//ladataan tekstitiedostosta yhden opettajan kaikki tiedot
		getline(lataus_opettajat, koulutusohjelma, ';');
		getline(lataus_opettajat, etunimi, ';');
		getline(lataus_opettajat, sukunimi, ';');
		getline(lataus_opettajat, osoite, ';');
		getline(lataus_opettajat, puhelinnumero, ';');
		getline(lataus_opettajat, palkka, ';');
		getline(lataus_opettajat, tunnus, ';');
		getline(lataus_opettajat, opetusala, '\n');

		//etsitään opettajan koulutusohjelma ja kutsutaan koulutusohjelma vectorin sisällä olevan
		//koulutusohjelma olion metodia ladakseen opettaja koulutusohjelman luokan opettajat_ vectoriin
		for (unsigned int i = 0; i < (koulutusohjelmat_.size() - 1); i++) {
			try {
				if (koulutusohjelmat_[i].annaNimi() == koulutusohjelma) {
					koulutusohjelmat_[i].lataaOpettajat(etunimi,sukunimi,osoite,puhelinnumero,palkka,tunnus,opetusala);
				}//if
			}//try
			catch (std::out_of_range &ex) {
				cout << "Virheellinen indeksointi" << endl;
			}//catch
			catch (...) {
				cout << "Tapahtui virhe ladatessa opettajia"  << endl;
			}//catch
		}//for
	}//while
	lataus_opettajat.close();

	//opiskelijoiden lataaminen
	while (lataus_opiskelijat.peek() != EOF) {

		getline(lataus_opiskelijat, koulutusohjelma, ';');
		getline(lataus_opiskelijat, etunimi, ';');
		getline(lataus_opiskelijat, sukunimi, ';');
		getline(lataus_opiskelijat, osoite, ';');
		getline(lataus_opiskelijat, puhelinnumero, ';');
		getline(lataus_opiskelijat, opiskelijanumero, '\n');

		//etsitään opiskelija koulutusohjelma ja kutsutaan koulutusohjelma vectorin sisällä olevan
		//koulutusohjelma olion metodia ladakseen opiskelija koulutusohjelman luokan opiskelijat_ vectoriin
		for (unsigned int i = 0; i < (koulutusohjelmat_.size() - 1); i++) {
			try {
				if (koulutusohjelmat_[i].annaNimi() == koulutusohjelma) {
					koulutusohjelmat_[i].lataaOpiskelijat(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero);
				}//if
			}//try
			catch (std::out_of_range &ex) {
				cout << "Virheellinen indeksointi" << endl;
			}//catch
			catch (...) {
				cout << "Tapahtui virhe ladatessa opiskelijoita" << endl;
			}//catch

		}//for loop
	}//while

	lataus_opiskelijat.close();

	cout << "Tiedot ladattu!" << endl;
}