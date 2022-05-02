#pragma once
#include "Echipa.hpp"

class Nod
{
	Nod* next;
	Nod* left;
	Nod* right;
	Echipa info;
public:
	Nod();
	Nod* getNext();
	void setNext(Nod* next);
	Nod* getRight();
	Nod* getLeft();
	Nod(Echipa, Nod* next = 0);
	Echipa getInfo();
	void setInfo(Echipa info);
	Echipa operator==(Nod&);
	std::string getNume();
	double getPct();
	float crestePct();
	friend class Coada;
	friend class Stiva;
	friend class BTS;
	friend class Lista;

};