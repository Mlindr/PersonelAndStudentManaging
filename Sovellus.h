#pragma once
#include <string>
#include "Koulu.h"
using std::string;

class Sovellus
{
public:

	//rakentaja ja purkajat
	Sovellus();
	~Sovellus();
	Sovellus(const Sovellus &);

	//metodit
	void aja();//aja ohjelmaa(kasa if lauseita)
	string tulostaValikko();//tulosta k�ytt�j�lle valikko

private:

	string valinta_;

};

