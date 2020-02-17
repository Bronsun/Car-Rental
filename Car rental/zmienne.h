#include <iostream>

#ifndef ZMIENNE_H_INCLUDED
#define ZMIENNE_H_INCLUDED

using namespace std;

 struct Dane
{
    string imie;
    string nazwisko;
    string pesel;
};
#endif // STRUKT_H_INCLUDED

extern vector<string> oferta;
extern vector<vector<string> > Modele;
extern vector<vector<int> > Ceny;
extern vector<vector<int> > Ilosc;
extern Dane dane;

