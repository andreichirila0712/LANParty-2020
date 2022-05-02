#include "Coada.hpp"

Coada::Coada()
{
	this->rear = nullptr;
	this->front = nullptr;
}

Coada::~Coada()
{
	while (this->front != nullptr)
	{
		Nod* temp = front;
		this->front = this->front->next;
		delete temp;
	}
}

void Coada::qInsert(Nod n)
{
	Nod* temp = new Nod(n);
	if (this->rear == nullptr)
	{
		this->front = this->rear = temp;
		return;
	}
	this->rear->next = temp;
	this->rear = temp;
}

void Coada::qDelete()
{
	if (this->front == nullptr)
		return;
	Nod* temp = this->front;
	this->front = this->front->next;
	if (this->front = nullptr)
		this->rear = nullptr;

	delete(temp);
}

Nod* Coada::getFront()
{
	return this->front;
}

Nod* Coada::getRear()
{
	return this->rear;
}

std::ostream& operator<<(std::ostream& os, Coada& coada)
{
	std::ofstream g("test_coada.out");
	Nod* p = coada.getFront();

	while (p)
	{
		g << p->getInfo();
		p = p->getNext();
		g << std::endl;
	}

	return os;
}

void Coada::inversare()
{
	Nod* temp = this->front;
	Nod* nextNod = nullptr;
	Nod* revNod = nullptr;

	while (temp != nullptr)
	{
		this->front = temp;
		nextNod = temp->next;
		temp->next = revNod;
		revNod = temp;
		temp = nextNod;
	}
}
