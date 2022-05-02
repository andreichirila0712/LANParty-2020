#pragma once
#include "Nod.hpp"

class Stiva {
protected:
	int size;
	Nod* top;
public:
	Stiva();
	void push(Nod);
	int isEmpty();
	Nod pop();
	Nod* getTop();
	friend std::ostream& operator<<(std::ostream&, Stiva&);
	void inversare();
	int getSize();
};