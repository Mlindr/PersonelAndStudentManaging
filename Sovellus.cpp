#include "Sovellus.h"
#include <iostream>
#include <string>
using std::endl; using std::cout; using std::cin; using std::string; using std::getline;

Sovellus::Sovellus()
{
}

Sovellus::~Sovellus()
{
}

Sovellus::Sovellus(const Sovellus &)
{
}

void Sovellus::aja()
{
	Koulu tamk("TAMK");//luodaan olio "tamk" luokasta "Koulu", jolle annetaan nimi "TAMK"

	while (valinta_ != "0") {

		valinta_ = tulostaValikko();

		//tyjennet‰‰n terminaalin ikkuna
		system("CLS");

		//koulutusohjelman lis‰ys
		if (valinta_ == "1")
		{
			tamk.lisaaKoulutusohjelma();//funktio: lisaa koulutusohjelma
		}

		//koulutusohjelmien tulostus
		if (valinta_ == "2")
		{
			tamk.tulostaKoulutusohjelmat();// funktio: tulosta koulutusohjelmat
			system("pause");
		}

		//koulutusohjelmien m‰‰r‰n tulostus
		if (valinta_ == "3")
		{
			tamk.tulostaKoulutusohjelmienMaara();//funktio: tulosta koulutusohjelmien m‰‰r‰
			system("pause");
		}

		//lisaa opettaja koulutusohjelmaan
		if (valinta_ == "4")
		{
			tamk.lisaaKoulutusohjelmaanOpettaja();//funktio: lis‰‰ opettaja valittuun koulutusohjelmaan
		}

		//tulosta koulutusohjelman opettajat
		if (valinta_ == "5")
		{
			tamk.tulostaKoulutusohjelmanOpettajat();//funktio: tulosta valitun koulutusohjelman opettajat
			system("pause");
		}

		//lisaa opiskelija koulutusohjelmaan
		if (valinta_ == "6")
		{
			tamk.lisaaKoulutusohjelmaanOpiskelija();//funktio: lis‰‰ opiskelija valittuun koulutusohjelmaan
		}

		//tulosta koulutusohjelman opiskelijat
		if (valinta_ == "7")
		{
			tamk.tulostaKoulutusohjelmanOpiskelijat();//funktio: tulosta valitun koulutusohjelman opiskelijat
			system("pause");
		}

		if (valinta_ == "8")
		{
			tamk.poistaKoulutusohjelma();//funktio: poistaa halutun koulutusohjelman
		}

		if (valinta_ == "9")
		{
			tamk.poistaOpettaja();//funktio: poista tunnusta vastaavan opettajan
		}

		if (valinta_ == "10")
		{
			tamk.poistaOpiskelija();//funktio: poista opiskelijanumeroo vastaavan opiskelijan
		}

		if (valinta_ == "11")
		{
			tamk.paivitaKoulutusohjelma();//funktio paivittaa koulutusohjelman nimen
		}

		if (valinta_ == "12")
		{
			tamk.paivitaOpettaja();
			system("CLS");
		}

		if (valinta_ == "13")
		{
			tamk.paivitaOpiskelija();
			system("CLS");
		}

		if (valinta_ == "14")
		{
			tamk.lataaTiedot();
			system("pause");
		}

		if (valinta_ == "15")
		{
			tamk.tallennaTiedot();
			system("pause");
		}

	}//loopin loppu
	
}

string Sovellus::tulostaValikko()
{
	string valinta;

	cout << "\n**********************************************\n"
		"1)Lis\x84\x84 koulutusohjelma\n"
		"2)Tulosta koulutusohjelmien nimet\n"
		"3)Tulosta koulutusohjelmien m\x84\x84r\x84\n"
		"4)Lis\x84\x84 koulutusohjelmaan opettaja\n"
		"5)Tulosta koulutusohjelman opettajat\n"
		"6)Lis\x84\x84 koulutusohjelmaan opiskelija\n"
		"7)Tulosta koulutusohjelman opiskelijat\n"
		"8)Poista koulutusohjelma\n"
		"9)Poista Opettaja\n"
		"10)Poista Opiskelija\n"
		"11)P\x84ivit\x84 koulutusohjelman nimi\n"
		"12)P\x84ivit\x84 Opettajan tiedot\n"
		"13)P\x84ivit\x84 Opiskelijan tiedot\n"
		"14)Lue tiedot\n"
		"15)Tallenna tiedot\n"
		"0)Lopeta\n"
		"**********************************************\n";

	//k‰ytt‰j‰n antama valinta
	cout << "Valinta: ";
	getline(cin, valinta);

	return valinta;
}
