#pragma once
#include "Nod.hpp"

class Lista {
protected:
	Nod* first;
	Nod* last;
public:
	Lista();
	~Lista();
	int isEmpty();
	void addElement(Nod n);
	Nod* getFirst();
	Nod* getLast();
	Nod* getElementAt(int index);
	void inversare();
	void stergere(Nod*);
	Nod* stergere_cap(Nod*);
	friend std::ostream& operator<<(std::ostream&, Lista&);
};