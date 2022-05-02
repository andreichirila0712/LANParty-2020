#include "Nod.hpp"

Nod::Nod()
{
	this->right = NULL;
	this->left = NULL;
	this->next = NULL;
}

Nod::Nod(Echipa info, Nod* next)
{
	this->info = info;
	this->next = next;
}

Echipa Nod::getInfo()
{
	return this->info;
}

void Nod::setInfo(Echipa info)
{
	this->info = info;
}

Nod* Nod::getNext()
{
	return this->next;
}

Echipa Nod::operator==(Nod& n)
{
	return this->info = n.info;
}

std::string Nod::getNume()
{
	return this->info.getNumeEchipa();
}

double Nod::getPct()
{
	return this->info.getPuncte();
}

void Nod::setNext(Nod* next)
{
	this->next = next;
}

float Nod::crestePct()
{
	return (this->info.getPuncte() + 1);
}

Nod* Nod::getRight()
{
	return this->right;
}

Nod* Nod::getLeft()
{
	return this->left;
}