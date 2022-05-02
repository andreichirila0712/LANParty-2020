#pragma once
#include "Player.hpp"

class Echipa {
private:
	std::string nume_echipa;
	int nr_jucatori;
	Player* data;
public:
	Echipa();
	Echipa(std::string, int, Player*);
	int getNrEchipe() const;
	int getNrJucatori() const;
	std::string getNumeEchipa();
	friend std::ostream& operator<<(std::ostream& os, const Echipa&);
	friend class nod;
	double getPuncte();
	void crestePuncte();
};