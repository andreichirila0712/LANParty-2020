#include "BTS.hpp"

BTS::BTS()
{
	this->root = nullptr;
}

int BTS::isEmpty()
{
	return this->root == nullptr;
}

void BTS::insert(Echipa echipa)
{
	Nod* n = new Nod;
	Nod* parent;
	n->left = nullptr;
	n->right = nullptr;
	n->info = echipa;
	parent = nullptr;

	if (isEmpty())
	{
		this->root = n;
	}
	else
	{
		Nod* ptr;
		ptr = this->root;

		while (ptr != nullptr)
		{
			parent = ptr;
			if (echipa.getPuncte() < ptr->getPct())
				ptr = ptr->left;
			else if (echipa.getPuncte() > ptr->getPct())
				ptr = ptr->right;
			else if (echipa.getNumeEchipa().compare(parent->getNume()) < 0)
				ptr = ptr->left;
			else if (echipa.getNumeEchipa().compare(ptr->getNume()) > 0)
				ptr = ptr->right;
		}

		if (echipa.getPuncte() < parent->getPct())
			parent->left = n;
		else if (echipa.getPuncte() > parent->getPct())
			parent->right = n;
		else if (echipa.getNumeEchipa().compare(parent->getNume()) < 0)
			parent->left = n;
		else if (echipa.getNumeEchipa().compare(parent->getNume()) > 0)
			parent->right = n;
	}
}

void BTS::in_order_trav()
{
	in_order(this->root);
}

void BTS::in_order(Nod* ptr)
{
	if (ptr != nullptr)
	{
		in_order(ptr->right);
		std::cout << ptr->getInfo() << std::endl;
		in_order(ptr->left);
	}
}

void BTS::pre_order_trav()
{
	pre_order(this->root);
}

void BTS::pre_order(Nod* ptr)
{
	if (ptr != nullptr)
	{
		std::cout << ptr->info << std::endl;
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}

void BTS::post_order_trav()
{
	post_order(this->root);
}

void BTS::post_order(Nod* ptr)
{
	if (ptr != nullptr)
	{
		post_order(ptr->left);
		post_order(ptr->left);
		std::cout << ptr->info << std::endl;
	}
}

Nod* BTS::getRoot()
{
	return this->root;
}