#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "employee_functions.h"
#include "zmienne.h"
#include "load_functions.h"
#include "save_functions.h"
using namespace std;

void sprawdzenie()
{
    vector<int> zajstartDate = start_date_read();
    vector<int> zajendDate = end_date_read();
    vector<string> zajsamochod = car_read();

    cout << "Wynajete samochody: " << endl;

    for ( size_t i =0; i< zajsamochod.size(); i++)
    {
        cout << "Od: " << zajstartDate[i]<< " Do: " << zajendDate[i] << " - " << zajsamochod[i]<< endl;
    }
}

void zarzadzanie()
{
    vector<int> zajstartDate = start_date_read();
    vector<int> zajendDate = end_date_read();
    vector<string> zajsamochod = car_read();
    vector<string> imie = name_read();
    vector<string> nazwisko = surname_read();
    size_t koniec, iter;

    cout << "Wynajete samochody: " << endl;

    for (iter =0; iter< zajsamochod.size(); iter++)
    {
        cout <<(iter+1) << "." << "Od: " << zajstartDate[iter]<< " Do: " << zajendDate[iter] << " - " << zajsamochod[iter]<< " Przez: " << imie[iter] << " " << nazwisko[iter] << endl;
    }

    cout << "Zakonczenie ktorego wynajmu potwierdzasz?";
    while( !(cin >> koniec))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

    while(koniec > iter)
    {
        cout << "Niepoprawny wybor\n";
    }

    zajstartDate.erase(zajstartDate.begin()+koniec-1);
    zajendDate.erase(zajendDate.begin()+koniec-1);
    zajsamochod.erase(zajsamochod.begin()+koniec-1);
    imie.erase(imie.begin()+koniec-1);
    nazwisko.erase(nazwisko.begin()+koniec-1);

    fstream zarezerwowane;
    zarezerwowane.open("zarezerwowane.txt", ios:: out | ios :: trunc);
    for(size_t i =0; i < zajendDate.size(); i++)
    {
        zarezerwowane << zajstartDate[i] << " " << zajendDate[i] << " " << zajsamochod[i] << " " << imie[i] << " " << nazwisko[i] << " " << endl;
    }
    zarezerwowane.close();
}

void dodanie()
{
    string marka, model, potwierdzenie;
    vector<string> tempN;
    vector<int> tempC;
    vector<int> tempL;
    int cena,liczba, exit = 1;

    while(exit == 1)
    {
        cout << "Nazwa marki, ktora chcesz dodac: ";
        cin >> marka;
        cout << endl;
        auto oferta_itr = find(oferta.begin(), oferta.end(), marka);
        int oferta_index = distance(oferta.begin(), oferta_itr);

        if(oferta_itr != oferta.end())
        {
            cout << "Nazwa modelu, ktory chcesz dodac: ";
            cin >>model;
            cout << endl;
            auto model_itr = find(Modele[oferta_index].begin(), Modele[oferta_index].end(), model);
            int model_index = distance(Modele[oferta_index].begin(), model_itr);

            if(model_itr != Modele[oferta_index].end())
            {
                cout << "Aktualna liczba sztuk: "<< Ilosc[oferta_index][model_index] <<endl;
                cout << "Ile chcesz dodac?" <<endl;
                while( !(cin >> liczba))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
                Ilosc[oferta_index][model_index] =+ liczba;
                cout << "Dodano" <<endl;
            }

            else
            {
                Modele[oferta_index].push_back(model);
                cout << "Podaj jego cene: ";
                while( !(cin >> cena))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
                cout << endl;
                Ceny[oferta_index].push_back(cena);
                cout << "Podaj liczbe sztuk: ";
                while( !(cin >> liczba))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
                cout << endl;
                Ilosc[oferta_index].push_back(liczba);
                cout << "Dodano"<<endl;
            }
        }

        else
        {
            oferta.push_back(marka);
            cout << "Nazwa modelu, ktory chcesz dodac: ";
            cin >>model;
            cout << endl;
            tempN.push_back(model);
            Modele.push_back(tempN);
            cout << "Podaj jego cene: ";
            while( !(cin >> cena))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
            cout << endl;
            tempC.push_back(cena);
            Ceny.push_back(tempC);
            cout << "Podaj liczbe sztuk: ";
            while( !(cin >> liczba))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
            cout << endl;
            tempL.push_back(liczba);
            Ilosc.push_back(tempL);
            cout << "Dodano"<<endl;
        }

        cout << "Czy chcesz dodac jeszcze cos? tak/nie" <<endl;
        cin >> potwierdzenie;
        if (potwierdzenie != "tak")
        {
            exit = 0;
        }
    }
}
