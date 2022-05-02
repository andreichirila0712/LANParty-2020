#include "Stiva.hpp"

Stiva::Stiva()
{
	this->size = 0;
	this->top = nullptr;
}

void Stiva::push(Nod n)
{
	Nod* temp;
	temp = new Nod(n);
	if (!temp)
	{
		std::cout << "Stack overflow!";
		exit(1);
	}

	temp->info = n.info;
	temp->next = this->top;
	this->top = temp;
	size++;
}

Nod Stiva::pop()
{
	Nod* temp;
	Echipa e;
	temp = this->top;
	e = temp->info;
	this->top = this->top->next;
	free(temp);
	
	return e;
}

Nod* Stiva::getTop()
{
	return this->top;
}

int Stiva::isEmpty()
{
	return this->top == nullptr;
}

std::ostream& operator<<(std::ostream& os, Stiva& stiva)
{
	std::ofstream g("test_stiva.out");
	Nod* s = stiva.getTop();
	while (s)
	{
		g << s->getInfo();
		s = s->getNext();
		g << std::endl;
	}

	return os;
}

void Stiva::inversare()
{
	Nod* temp = this->top;
	Nod* nextNod = nullptr;
	Nod* revNod = nullptr;

	while (temp != nullptr)
	{
		this->top = temp;
		nextNod = temp->next;
		temp->next = revNod;
		revNod = temp;
		temp = nextNod;
	}

}

int Stiva::getSize()
{
	return this->size;
}