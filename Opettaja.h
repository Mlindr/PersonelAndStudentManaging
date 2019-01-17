#pragma once
#include "Tyontekija.h"
#include <string>
using std::string;

class Opettaja :
	public Tyontekija{

		public:

			//constructors/Destructors
			Opettaja();//oletusrakentaja
			Opettaja(string,string,string,string,double,string,string);//parametrirakentaja
			Opettaja(const Opettaja &);//kopiorakentaja
			~Opettaja();//oletuspurkaja
			Opettaja & operator=(const Opettaja &sij);

			//getters
			//funktio antaa takaisin tietoja returnilla
			string annaOpetusala() const;
			string annaTunnus() const;

			//setters
			//ottaa parametrin sis‰‰n ja asettaa sen luokan sis‰iseksi muuttujaksi
			void asetaOpetusala(string);

			//methods
			void kysyTiedot();//kysyt‰‰n tiedot
			void tulosta() const;//tulostetaan tiedot

		private:
			string opetusala_;//opettajan opetusala

	};

