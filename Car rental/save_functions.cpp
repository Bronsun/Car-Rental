#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "save_functions.h"
#include "zmienne.h"
using namespace std;

void date_save(int startDate, int endDate, string Samochod, string imie, string nazwisko)
{
    fstream samochod;
    samochod.open("zarezerwowane.txt", ios:: out | ios :: app);
    samochod << startDate << " " << endDate << " " << Samochod << " " << imie << " " << nazwisko << endl;
    samochod.close();
}

void offer_save()
{
    fstream offer;
    offer.open("oferta.txt", ios:: out | ios:: trunc);
    for(size_t i = 0; i < oferta.size(); i++)
    {
        offer << oferta[i] << endl;
    }
    offer.close();
}

void amount_save()
{
    fstream amount;
    amount.open("amount.txt", ios:: out | ios :: trunc);
    for(size_t i =0; i < Ilosc.size(); i++)
    {
        for(size_t k=0; k<Ilosc[i].size(); k++)
        {
            amount << Ilosc[i][k] << " ";
        }

        amount << "\n";
    }
    amount.close();
}

void price_save()
{
    fstream price;
    price.open("price.txt", ios:: out | ios :: trunc);
    for(size_t i =0; i < Ceny.size(); i++)
    {
        for(size_t k=0; k<Ceny[i].size(); k++)
        {
            price << Ceny[i][k] << " ";
        }

        price << "\n";
    }
    price.close();
}

void model_save()
{
    fstream model;
    model.open("model.txt", ios:: out | ios :: trunc);
    for(size_t i =0; i < Modele.size(); i++)
    {
        for(size_t k=0; k<Modele[i].size(); k++)
        {
            model << Modele[i][k] << " ";
        }

        model << "\n";
    }
    model.close();
}

void zapis_dane (string samochod, int start_d, int start_m, int start_r, int end_d, int end_m, int end_r, int kwota)
{
    fstream plik;
    plik.open("booking.txt", ios:: out | ios::trunc);
    plik<<"\n--------------DANE:---------------------\n";
    plik<<"\t\t\tImie: ";
    plik<<dane.imie;
    plik<<"\n";
    plik<<"\t\t\tNazwisko: ";
    plik<<dane.nazwisko;
    plik<<"\n";
    plik<<"\t\t\tPesel: ";
    plik<<dane.pesel ;

    plik<<"\n-----------SAMOCHOD:--------------------\n";
    plik<<samochod;
    plik<<"\tod: ";
    plik<<start_d;
    plik<<".";
    plik<<start_m;
    plik<<".";
    plik<<start_r;
    plik<<"\tdo: ";
    plik<<end_d;
    plik<<".";
    plik<<end_m;
    plik<<".";
    plik<<end_r;
    plik<<endl;
    plik<<"Kwota do zaplaty: ";
    plik<<kwota;
    plik.close();
}
