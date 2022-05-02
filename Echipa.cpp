#include "Echipa.hpp"

Echipa::Echipa()
{
	this->nume_echipa = "";
	this->nr_jucatori = 0;
}

Echipa::Echipa(std::string nume_echipa, int nr_jucatori, Player* data)
{
	this->nume_echipa = nume_echipa;
	this->nr_jucatori = nr_jucatori;
	this->data = data;
}

std::ostream& operator<<(std::ostream& os, const Echipa& e)
{
	os << e.nume_echipa << " " << e.nr_jucatori << std::endl;
	for (int i = 0; i < e.nr_jucatori; i++)
		os << e.data[i];
	return os;
}

int Echipa::getNrJucatori() const
{
	return this->nr_jucatori;
}

std::string Echipa::getNumeEchipa()
{
	return this->nume_echipa;
}

double Echipa::getPuncte()
{
	double medie = 0;
	for (int i = 0; i < nr_jucatori; i++)
		medie = medie + data[i].getPunctaj();
	
	return (double)medie / nr_jucatori;
}

void Echipa::crestePuncte()
{
	for (int i = 0; i < nr_jucatori; i++)
		data[i].crestePunctaj();
}