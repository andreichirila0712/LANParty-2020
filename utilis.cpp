#include "utilis.hpp"

void citire_afisare(int& numar_echipe, Lista& L, char* argv[])
{
	std::ifstream date(argv[2]);
	int numar_jucatori, puncte;
	std::string nume_echipa, nume_jucator, prenume_jucator;
	Player* jucator;

	date >> numar_echipe;
	int* medie_punctaj = new int[numar_echipe];

	for (int i = 0; i < numar_echipe; i++)
	{
		date >> numar_jucatori;
		std::getline(date, nume_echipa);
		int lungime = nume_echipa.size() - 1;

		if (lungime >= 0 && nume_echipa[lungime] == ' ')
		{
			lungime--;
			nume_echipa = nume_echipa.substr(0, lungime + 1);
		}

		jucator = new Player[numar_jucatori];

		for (int j = 0; j < numar_jucatori; j++)
		{
			date >> nume_jucator;
			date >> prenume_jucator;
			date >> puncte;

			medie_punctaj[j] = medie_punctaj[i] + puncte / numar_jucatori;
			Player player(nume_jucator, prenume_jucator, puncte);
			jucator[j] = player;
		}

		L.addElement(Nod(Echipa(nume_echipa, numar_jucatori, jucator)));
		std::cout << L;
	}

	afisare(L, argv);
	date.close();
}

void afisare(Lista& M, char* argv[])
{
	M.inversare();
	Nod* p = M.getFirst();
	
	std::ofstream rez(argv[3]);

	while (p)
	{
		rez << p->getNume().erase(0, 1);
		p = p->getNext();
		rez << std::endl;
	}
	rez.close();
}

int minim(Lista& M)
{
	Nod* p = M.getFirst();
	double minim = p->getPct();
	int poz_min, poz_init = 1;
	p = p->getNext();

	while (p != nullptr)
	{
		if (minim >= p->getPct())
		{
			minim = p->getPct();
			poz_min = poz_init;
		}
		p = p->getNext();
		poz_init++;
	}
	
	return poz_min;
}
int numarare(int numar_echipe)
{
	int nr_adaugat;

	for (int i = numar_echipe; i >= 1; i--)
	{
		if ((i & (i - 1)) == 0)
		{
			nr_adaugat = i;
			break;
		}
	}

	return nr_adaugat;
}

void cerinta2(Lista& M, char* argv[], int numar_echipe)
{
	M.inversare();
	int numar_adaugat;
	int minimul;

	numar_adaugat = numarare(numar_echipe);

	while (numar_echipe > numar_adaugat)
	{
		minimul = minim(M);
		M.stergere(M.getElementAt(minimul));
		numar_echipe--;
	}

	afisare(M, argv);
}

void adauga_coada(Lista& M, Coada& C, char* argv[], BTS& arb)
{
	Nod* p = M.getFirst();

	while (p)
	{
		C.qInsert(p->getInfo());
		p = p->getNext();
	}

	int contor = 0;

	adaugare_stiva(C, argv, contor, arb);
}

void aduagare_stiva(Coada& C, char* argv[], int& contor, BTS& arb)
{
	int contor2 = 0;
	C.inversare();
	Stiva Invinsi, Castigatori;
	Nod* c = C.getFront();
	Nod* aux = c->getNext();

	double medie1, medie2;

	while (c)
	{
		medie1 = c->getPct();
		medie2 = aux->getPct();

		if (medie1 >= medie2)
		{
			Invinsi.push(aux->getInfo());
			c->getInfo().crestePuncte();
			Castigatori.push(c->getInfo());
			contor2++;
		}
		else
		{
			Invinsi.push(c->getInfo());
			aux->getInfo().crestePuncte();
			Castigatori.push(aux->getInfo());
			contor2++;
		}

		if (aux->getNext() != nullptr)
		{
			c = aux->getNext();
		}
		else break;

		if (c->getNext() != nullptr)
		{
			aux = c->getNext();
		}
		else break;
	}

	contor++;
	
	if (contor2 == 8)
	{
		Nod* g = Castigatori.getTop();

		while (g)
		{
			arb.insert(g->getInfo());
			g = g->getNext();
		}
	}

	nume_functie(argv, C, Castigatori, contor, arb);
}

void nume_functie(char* argv[], Coada& C, Stiva& Ca, int& indice, BTS& arb)
{
	C.inversare();
	std::ofstream rez(argv[3], std::ios::app);
	rez << std::endl << "--- ROUND NO:" << indice << std::endl;
	Nod* c1 = C.getFront();
	Nod* aux = c1->getNext();
	int nr_e = 1;

	while (c1)
	{
		rez << std::left << std::setw(33) << c1->getNume().erase(0, 1) << "-";
		rez << std::right << std::setw(33) << aux->getNume().erase(0, 1) << std::endl;

		if (aux->getNext() != nullptr)
		{
			c1 = aux->getNext();
		}
		else break;

		if (c1->getNext() != nullptr)
		{
			aux = c1->getNext();
		}
		else break;
		
		nr_e++;
	}

	reumplere_coada(Ca, argv, nr_e, indice, arb);
	rez.close();
}

void reumplere_coada(Stiva& Castigatori, char* argv[], int nr_echipe, int& contor, BTS& arb)
{
	std::ofstream rez(argv[3], std::ios::app);
	rez << std::endl << "WINNERS OF ROUND NO:" << contor << std::endl;
	Castigatori.inversare();

	Nod* s = Castigatori.getTop();

	while (s)
	{
		rez << std::left << std::setw(34) << s->getNume().erase(0, 1) << "-  " << std::fixed << std::setprecision(2) << s->getPct() << std::endl;
		s = s->getNext();
	}

	nr_echipe = nr_echipe / 2;

	Coada C;
	Nod* as = Castigatori.getTop();

	while (as)
	{
		C.qInsert(as->getInfo());
		as = as->getNext();
	}

	if (nr_echipe >= 1)
	{
		adaugare_stiva(C, argv, contor, arb);
	}

	rez.close();
}

void cerinta_4(BTS& arb, char* argv[])
{
	std::ofstream rez(argv[3], std::ios::app);
	rez << std::endl << "TOP 8 TEAMS:" << std::endl;
	rez.close();

	Nod* a = arb.getRoot();
	cerinta(a, argv);
}

void cerinta(Nod* a, char* argv[])
{
	std::ofstream rez(argv[3], std::ios::app);

	if (a != nullptr)
	{
		cerinta(a->getRight(), argv);
		rez << std::left << std::setw(34) << a->getNume().erase(0, 1) << "-  " << a->getPct() << std::endl;
		cerinta(a->getLeft(), argv);
	}

	rez.close();
}