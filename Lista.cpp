#include "Lista.hpp"

Lista::Lista()
{
	this->first = nullptr;
	this->last = nullptr;
}

Lista::~Lista()
{
	Nod* f = this->first;
	Nod* q;
	
	while (f != nullptr)
	{
		q = f;
		f = f->next;
		delete q;
	}

	this->first = this->last = nullptr;
}

int Lista::isEmpty()
{
	return this->first == nullptr;
}

void Lista::addElement(Nod n)
{
	Nod* p;
	p = new Nod(n.info, 0);
	
	if (isEmpty())
	{
		this->first = this->last = p;
	}
	else
	{
		this->last->next = p;
		this->last = p;
	}
}

Nod* Lista::getFirst()
{
	return this->first;
}

Nod* Lista::getLast()
{
	return this->last;
}

Nod* Lista::getElementAt(int index)
{
	Nod* p;
	int i;

	for (i = 0, p = this->first; i < index && p != nullptr; p = p->next)
		return p;
}

std::ostream& operator<<(std::ostream& os, Lista& lista)
{
	std::ofstream g("date.out");
	Nod* p = lista.getFirst();
	
	while (p)
	{
		g << p->getInfo();
		p = p->getNext();
		g << std::endl;
	}
	
	return os;
}

void Lista::inversare()
{
	Nod* temp = this->first;
	Nod* nextNod = nullptr;
	Nod* revNod = nullptr;

	while (temp != nullptr)
	{
		this->first = temp;
		nextNod = temp->next;
		temp->next = revNod;
		revNod = temp;
		temp = nextNod;
	}
}

Nod* Lista::stergere_cap(Nod* first)
{
	if (first == nullptr)
	{
		return nullptr;
	}
	else
	{
		Nod* temp = first;
		first = first->next;
		delete temp;
		return first;
	}
}

void Lista::stergere(Nod* nodeToDelete)
{
	Nod* current = this->first;
	Nod* previous = nullptr;
	
	if (this->first == nodeToDelete)
	{
		this->first = nodeToDelete->next;
		delete nodeToDelete;
		return;
	}
	
	while (current != nodeToDelete)
	{
		previous = current;
		current = current->next;
	}

	previous->next = current->next;
	delete nodeToDelete;
}


