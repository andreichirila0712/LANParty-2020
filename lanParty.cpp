#include "utilis.hpp"

int main(int argc, char* argv[])
{
	std::ifstream cerinte(argv[1]);
	int numar_echipe;
	Lista L, castigatori;
	Coada  C;
	BTS A;

	for (int i = 0; i < 5; i++)
	{
		int task;
			cerinte >> task;
		switch (i)
		{
		case 0:
		{
			if (task == 1)
				citire_afisare(numar_echipe, L, argv);
			break;
		}
		case 1:
		{
			if (task == 1)
				cerinta2(L, argv, numar_echipe);
			break;
		}
		case 2:
		{
			if (task == 1)
				adauga_coada(L, C, argv, A);
			break;
		}
		case 3:
		{
			if (task == 1)
				cerinta_4(A, argv);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	cerinte.close();
	return 0;
}

