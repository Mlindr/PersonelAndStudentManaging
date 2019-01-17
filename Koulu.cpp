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
	string nimi;//alustuu aina uusiksi, ei tarvitse tyhjent��
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);//k�ytt�j�n etsim� koulutusohjelman nimi

	try {
		//tarkistetaan ensin ett� on koulutusohjelmia lis�tty
		if (koulutusohjelmat_.size() != 0) {
			//etsit��n koulutusohjelma annetulla nimell� loopilla, joka py�rii vektorin koon verran
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {

				/*jos nimi vastaa koulutusohjelmat_ vectorin i elementin sis�lt�m�n Koulutusohjelma luokan olion kutsuttua
				luokkafunktiota(metodia) annaNimi,joka palauttaa koulutusohjelman nimen,palautetaan i:n arvo jolla voidaan indeksoida
				muissa Koulu luokan metodeissa ja suorittaa oikean koulutusohjelman nimen kanssa*/
				if (nimi == koulutusohjelmat_[i].annaNimi())
				{
					return i;//palauttaa l�ydetyn koulutusohjelman nimen 
				}//if

				//tai jos kaikki koulutusohjelmat on k�yty l�pi, annetaan takaisin -1
				else if (i == (koulutusohjelmat_.size() - 1)) {
					//i l�htee nollasta, siksi verrataan koulutoshjelmien koko -1 
					return -1;//palauttaa -1 jos ei l�ytynyt koulutusohjelmaa			
				}//else if
			}//for loop
		}//if

		/*jos ei ollut koulutusohjelmia lis�ttyn� viel� palauttaa -1,
		joka ilmoittaa muissa metodeissa ettei koulutusohjelmaa ole l�ytynyt*/
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
	/*annetaan nimi joka annetaan parametrina kun luodaan olio k�ytt�m�ll� parametrirakentajaa*/
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	/*Koulutusohjelma(nimi) luo uuden Koulutusohjelma olion parametrirakentajalla ja annettuna parametrina on nimi
	joka laitetaan vektorin sis�lle eli vektoriin menee olio parametrilla nimi, joka on koulutusohjelman nimi*/
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
}

//tulostaa kaikki koulutusohjelmat
void Koulu::tulostaKoulutusohjelmat() const
{
	cout << "Koulutusohjelmat: " << endl;
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		cout << koulutusohjelmat_[i].annaNimi() << endl;//tulostaa olion annaNimi metodin palautetun sis�ll�n
	}
}

//tulostaa koulutusohjelmien m��r�n
void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << "Koulutusohjelmien m\x84\x84r\x84: " << koulutusohjelmat_.size() << endl;//tulostaa vektorin koon
}

//lis�� opettajan tiettyyn koulutusohjelmaan
void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

	//indeksi=-1, jos ei l�ytynyt
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

 	//indeksi=-1, jos ei l�ytynyt
	if (indeksi >= 0) {
		//k�ytet��n vektorin koulutusohjelmat_ sis�lt�m�� oliota tulostakseen ohjelman ja opettajien nimet
		cout << koulutusohjelmat_[indeksi].annaNimi() << " koulutusohjelman opettajat: " << endl;
		koulutusohjelmat_[indeksi].tulostaOpettajat();//opettaja luokan metodi
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//lis�� opiskelija tiettyyn koulutusohjelmaan
void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//koulutusohjelma palauttaa for loopin i:n arvon, josta tulee indeksi

	//indeksi=-1, jos ei l�ytynyt
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

	//indeksi=-1, jos ei l�ytynyt
	if (indeksi >= 0) {
		//tulostetaan koulutusohjelman nimi ja opiskelijoiden nimet hy�dynt�en vektorissa olevan olion metodeja
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
	int indeksi = etsiKoulutusohjelma();//etsit��n vektorista koulutusohjelma

	//jos koulutusohjelma on olemassa voidaan poistaa vektorista koulutusohjelma olio joka on indeksin kohdalla
	if (indeksi >= 0) {
		koulutusohjelmat_.erase(koulutusohjelmat_.begin()+indeksi);//vektorin alku(.begin)=0 + indeksi verran, poistetaan alkio
	}

	//jos koulutusohjelmaa ei l�ydy tai ei ole
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}

}

//poistaa tietyn opettajan halutusta koulutusohjelmasta
void Koulu::poistaOpettaja() {

	int indeksi = etsiKoulutusohjelma();//etsit��n koulutusohjelma

	if (indeksi >= 0) {
		/*kutsutaan koulutusohjelmat_ elementin sis�ll� olevaa Koulutusohjelma olion metodia poistaOpettaja()*/
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}

	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//poistaa tietyn opiskelijan halutusta koulutusohjelmasta
void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//etsit��n koulutusohjelma

	if (indeksi >= 0) {
		/*kutsutaan koulutusohjelmat_ elementin sis�ll� olevaa Koulutusohjelma olion metodia poistaOpiskelija()*/
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}

	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//paivittaa koulutusohjelman nimen, koulutusohjelman opettajat ja oppilaat s�ilyv�t mukana
void Koulu::paivitaKoulutusohjelma()
{
	int indeksi = etsiKoulutusohjelma();//etsit��n koulutusohjelma metodilla etsiKoulutusohjelma, joka palauttaa kokonaisluvun
	string nimi;

	//jos metodi ei l�yt�nyt koulutusohjelmaa, indeksi=-1
	if (indeksi >= 0) {

		cout << "Anna uusi koulutusohjelman nimi: " << endl;
		getline(cin,nimi);//uusi koulutusohjelman nimi k�ytt�j�lt�
		koulutusohjelmat_[indeksi].asetaNimi(nimi);//asetetaan uusi  koulutusohjelman nimi
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}
}

//mahdollistaa opettajan tietojen p�ivitt�misen
void Koulu::paivitaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();//etsit��n koulutusohjelma vektorista

	//indeksi on -1 jos ei l�ytynyt koulutusohjelmaa 
	if (indeksi >= 0) {

		koulutusohjelmat_[indeksi].paivitaOpettaja();//koulutusohjelma luokan metodi paivitaOpettaja()
	}
	else {
		cout << "Koulutusohjelmaa ei l\x94ytynyt" << endl;
	}

}

//mahdollistaa opiskelijan tietojen p�ivitt�misen
void Koulu::paivitaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();//etsit��n vektorista koulutusohjelmat_ koulutusohjelmaa

	//indeksi on -1 jos ei l�ytynyt koulutusohjelmaa
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

			//koulutusohjelma muuttujaan tallenetaan vektorin sis�ll� olevan koulutusohjelman olion nimi
			//t�m� muuttuja annetaan parametreina jotta se voidaan tallentaa koulutusohjelman metodissa tallennaOpettajat
			koulutusohjelma = koulutusohjelmat_[i].annaNimi();

			//annetaan koulutusohjelman metodille tallennaOpettajat kirjoitus stream tallennus_opettajat referenssin�
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

			//koulutusohjelma muuttujaan tallenetaan vektorin sis�ll� olevan koulutusohjelman olion nimi
			//t�m� muuttuja annetaan parametreina jotta se voidaan tallentaa koulutusohjelman metodissa tallennaOpiskelijat
			koulutusohjelma = koulutusohjelmat_[i].annaNimi();

			//annetaan koulutusohjelman metodille tallennaOpiskelijat kirjoitus stream tallennus_opiskelijat referenssin�
			koulutusohjelmat_[i].tallennaOpiskelijat(tallennus_opiskelijat,koulutusohjelma);
		}
		tallennus_opiskelijat.close();//sulje tiedosto
	}

	else {
		cout << "Oppilaiden tallennus ep\x84onnistui" << endl;
	}
	cout << "Tallennus suoritettu!" << endl;//k�ytt�j� saa tiedon kun tallennus on suoritettu
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

	/*EOF=End Of File, peek()=kurkista mik� on seuraava merkki
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

		//etsit��n opettajan koulutusohjelma ja kutsutaan koulutusohjelma vectorin sis�ll� olevan
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

		//etsit��n opiskelija koulutusohjelma ja kutsutaan koulutusohjelma vectorin sis�ll� olevan
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