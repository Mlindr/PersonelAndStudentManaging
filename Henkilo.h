#pragma once
#include <string>

using std::string;

class Henkilo{

public:


	//constructors and destructors
	Henkilo();//oletusrakentaja
	Henkilo(const Henkilo & alkup);//kopiorakentaja
	Henkilo(string Etunimi, string Sukunimi, string Osoite, string Puhelinnumero);//parametrirakentaja
	~Henkilo();//oletuspurkaja
	Henkilo & operator=(const Henkilo &sij);//oletusrakentajalle operaattorilla kopiorakentaja
	

	//getters
	//metodit jotka eiv�t muuta luokan muutujia
	string annaEtunimi() const;//antaa takaisin etunimen
	string annaOsoite() const;//antaa takaisin osoitteen
	string annaPuhelinnumero() const;//antaa takaisin puhelinnumeron
	string annaSukunimi() const;//antaa takaisin sukunimen

	//setters
	//ottavat vastaan string parametrin ja asettavat sen luokan muutujiin
	void asetaEtunimi(string);
	void asetaSukunimi(string);
	void asetaOsoite(string);
	void asetaPuhelinnumero(string);

	//methods
	void kysyTiedot();//kysyy henkil�n tiedot eli kaikki luokan sis�iset muuttujat
	void tulosta() const;//tulostaa kaikki luokan sis�iset muuttujat

private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};

