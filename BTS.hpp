#pragma once
#include "Nod.hpp"

class BTS {
protected:
	Nod* root;
public:
	BTS();
	int isEmpty();
	void insert(Echipa);
	void in_order_trav();
	void in_order(Nod*);
	void pre_order_trav();
	void pre_order(Nod*);
	void post_order_trav();
	void post_order(Nod*);
	Nod* getRoot();
};