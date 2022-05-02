#pragma once
#include "Nod.hpp"

class Coada {
protected:
	Nod* rear, * front;
public:
	Coada();
	~Coada();
	void qInsert(Nod);
	void qDelete();
	Nod* getFront();
	Nod* getRear();
	friend std::ostream& operator<<(std::ostream&, Coada&);
	void inversare();
};