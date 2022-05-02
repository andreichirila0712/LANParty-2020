#pragma once
#include "Lista.hpp"
#include "Coada.hpp"
#include "Stiva.hpp"
#include "BTS.hpp"

void citire_afisare(int&, Lista&, char* argv[]);
void afisare(Lista&, char* argv[]);
void cerinta2(Lista&, char* argv[], int);
int minim(Lista&);
int numarare(int numar_echipe);
void adauga_coada(Lista&, Coada&, char* argv[], BTS&);
void adaugare_stiva(Coada&, char* argv[], int&, BTS&);
void afisare_cerinta3(Coada&, char* argv[]);
void nume_functie(char* argv[], Coada&, Stiva&, int&, BTS&);
void reumplere_coada(Stiva&, char* argv[], int, int&, BTS&);
void arbore(Lista&, char* argv[]);
void cerinta_4(BTS&, char* argv[]);
void cerinta(Nod*, char* argv[]);
void test(Coada&, char* argv[]);
void umplere_arbore(BTS&, Stiva&, int&, char* argv[]);