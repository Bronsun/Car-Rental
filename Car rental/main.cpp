
// This software was created by Michał Kubas and Mateusz Broncel.


#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "save_functions.h"
#include "load_functions.h"
#include "zmienne.h"
#include "employee_functions.h"
using namespace std;

vector<string> oferta;
vector<vector<string> > Modele;
vector<vector<int> > Ceny;
vector<vector<int> > Ilosc;
Dane dane;

// --------------Pozyskanie dzisiejszej daty---------------------------
struct Data
{
    int dzien, miesiac, rok;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

int liczba_dni(Data dt1, Data dt2)
{
    long int n1 = dt1.rok*365 + dt1.dzien;
    for (int i=0; i<dt1.miesiac - 1; i++)
        n1 += monthDays[i];

    long int n2 = dt2.rok*365 + dt2.dzien;
    for (int i=0; i<dt2.miesiac - 1; i++)
        n2 += monthDays[i];

    return (n2 - n1);
}

time_t t = time(0);
struct tm * now = localtime(&t);

int day = now->tm_mday;
int month = now->tm_mon + 1;
int year = now->tm_year + 1900;
//-----------------------------------------------------------------


int main()
{
while(1)
{
oferta = offer_load();
price_load();
model_load();
amount_load();

string wybor, zgoda, legitHaslo = "1234", haslo;
int cena, potwierdzenie, wejsciowy, klient_pracownik=1, pracownik;

while (klient_pracownik == 1)
{
    cout << "Witamy, jestes:" <<endl;
    cout << "1.Klientem"<<endl;
    cout << "2.Pracownikiem"<<endl;
    cout << "3.Wyjdz z programu"<<endl;
    while( !(cin >> wejsciowy))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << endl;

    if (wejsciowy == 2)
    {
        cout <<"Podaj haslo: " << endl;
        for(int i = 0; i <3; i++)
        {
            cin >> haslo;
            cout << endl;
            if(haslo == legitHaslo)
            {
                potwierdzenie = 2;
                klient_pracownik=0;
                break;
            }
            else
            {
                cout <<"Zle haslo" <<endl;
            }
        }
    }
    else if (wejsciowy == 1)
    {
        potwierdzenie = 1;
        klient_pracownik =0;
    }
    else if (wejsciowy == 3)
    {
        return(0);
    }
}

while(potwierdzenie == 2)
{
    cout << "Co chcesz zrobic:" <<endl;
    cout << "1.Potwierdzic zwrot samochodu" << endl;
    cout << "2.Sprawdzic aktualnie wynajete samochody" <<endl;
    cout << "3.Dodac samochod do oferty" <<endl;
    cout << "4.Usunac samochod z oferty" <<endl;
    cout << "5.Sprawdzic aktualna oferte" <<endl;
    cout << "6.Wylogowac" <<endl;
    cout << "7.Wyjsc" << endl;
    cin >> pracownik;

    switch(pracownik)
    {
        case 1:
        {
            zarzadzanie();
            cout << "Cos jeszcze? tak/nie"<<endl;
            cin >> zgoda;

            if (zgoda == "nie")
            {
                potwierdzenie = 0;
            }
            else if(zgoda != "tak" || zgoda != "nie")
            {
                        cout << "Bledny wybor\n";
                    break;
            }
            break;
        }

        case 2:
        {
            sprawdzenie();
            cout << "Cos jeszcze? tak/nie"<<endl;
            cin >> zgoda;

            if (zgoda == "nie")
            {
                potwierdzenie = 0;
            }
            else if(zgoda != "tak" || zgoda != "nie")
            {
                        cout << "Bledny wybor\n";
                    break;
            }
            break;
        }

        case 3:
        {
            dodanie();
            cout << "Cos jeszcze? tak/nie"<<endl;
            cin >> zgoda;

            if (zgoda == "nie")
            {
                potwierdzenie = 0;
            }
            else if(zgoda != "tak" || zgoda != "nie")
            {
                        cout << "Bledny wybor\n";
                    break;
            }
            offer_save();
            model_save();
            amount_save();
            price_save();
            break;
        }

        case 4:
        {
            size_t model, marka;
            cout << "Marki do wyboru:" << endl;

            for(size_t i =0; i < oferta.size(); i++ )
            {
                cout <<"\t" << (i+1) << "." << oferta[i] << endl;
            }

                while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

            while(marka > oferta.size() || marka == 0)
            {
                cout << "Niepoprawny wybor\n";
                                while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
            }

            for(size_t i = 0; i < oferta.size(); i++)
            {
                if(i==marka-1)
                {
                    for(size_t i = 0; i< Modele[marka-1].size(); i++)
                    {
                        cout << "\t" << (i+1) << "." << Modele[marka-1][i] << " " << "Ilosc: " << Ilosc[marka-1][i] << endl;
                    }
                    cout <<"Jaki model Cie interesuje?" <<endl;
                                    while( !(cin >> model))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

                    while(model > Modele[marka-1].size() || model ==0)
                    {
                        cout << "Niepoprawny wybor\n";
                                        while( !(cin >> model))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
                    }
                }
            }

            if(Ilosc[marka-1][model-1]==1)
            {
                Modele[marka-1].erase (Modele[marka-1].begin()+model-1);
                Ceny[marka-1].erase (Ceny[marka-1].begin()+model-1);
                Ilosc[marka-1].erase (Ilosc[marka-1].begin() + model-1);

                if(Modele[marka-1].empty() == true )
                {
                    oferta.erase(oferta.begin()+marka-1);
                }
            }
            else
            {
                Ilosc[marka-1][model-1]--;
            }
            cout << "Usunieto!" <<endl;
            offer_save();
            model_save();
            amount_save();
            price_save();
            cout << "Cos jeszcze? tak/nie"<<endl;
            cin >> zgoda;

            if (zgoda == "nie")
            {
                potwierdzenie = 0;
            }
            break;
        }

        case 5:
        {
            size_t marka;
            cout << "Marki do wyboru:" << endl;

            for(size_t i =0; i < oferta.size(); i++ )
            {
                cout <<"\t" << (i+1) << "." << oferta[i] << endl;
            }

                            while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

            while(marka > oferta.size() || marka == 0)
            {
                cout << "Niepoprawny wybor\n";
                                while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
            }

            for(size_t i = 0; i < oferta.size(); i++)
            {
                if(i==marka-1)
                {
                    for(size_t i = 0; i< Modele[marka-1].size(); i++)
                    {
                        cout << "\t" << (i+1) << "." << Modele[marka-1][i] <<" " << "Ilosc: " << Ilosc[marka-1][i] << endl;
                    }
                }
            }
            cout << "Cos jeszcze? tak/nie"<<endl;
            cin >> zgoda;

            if (zgoda == "nie")
            {
                potwierdzenie = 0;
            }
            break;
        }

        case 6:
        {
            potwierdzenie = 1;
            break;
        }

        case 7:
        {
            potwierdzenie = 0;
            break;
        }

        default:
        {
            cout <<"Niepoprawny wybor\n" <<endl;
            break;
        }
    }
}


while(potwierdzenie == 1)
{

    size_t model, marka;
    cout << "Marki do wyboru:" << endl;

    for(size_t i =0; i < oferta.size(); i++ )
    {
        cout <<"\t" << (i+1) << "." << oferta[i] << endl;
    }

                    while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

    while(marka > oferta.size() || marka == 0)
    {
        cout << "Niepoprawny wybor\n";
                        while( !(cin >> marka))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    }

    for(size_t i = 0; i < oferta.size(); i++)
    {
        if(i==marka-1)
        {
            for(size_t i = 0; i< Modele[marka-1].size(); i++)
            {
                cout << "\t" << (i+1) << "." << Modele[marka-1][i] << endl;
            }
            cout <<"Jaki model Cie interesuje?" <<endl;
                            while( !(cin >> model))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }

            while(model > Modele[marka-1].size() || model ==0)
            {
                cout << "Niepoprawny wybor\n";
                                while( !(cin >> model))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
            }
        }
    }

    wybor = Modele[marka-1][model-1];
    cena = Ceny[marka-1][model-1];

    Data start;
    Data koniec;

    cout << "Od kiedy chcesz wypozyczyc?\n";
    cout << "Wpisz Dzien: ";
                    while( !(cin >> start.dzien))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << "Wpisz Miesiac: ";
                    while( !(cin >> start.miesiac))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << "Wpisz Rok: ";
                    while( !(cin >> start.rok))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << endl;

    while ((start.dzien>31 && start.miesiac==1)|| (start.dzien>28 && start.miesiac==2) ||
           (start.dzien>31 && start.miesiac==3) || (start.dzien>30 && start.miesiac==4) ||
           (start.dzien>31 && start.miesiac==5) || (start.dzien>30 && start.miesiac==6) ||
           (start.dzien>31 && start.miesiac==7) || (start.dzien>31 && start.miesiac==8) ||
           (start.dzien>30 && start.miesiac==9) || (start.dzien>31 && start.miesiac==10) ||
           (start.dzien>30 && start.miesiac==11) || (start.dzien>31 && start.miesiac==12) ||
           start.miesiac>12 || start.rok<year || (start.miesiac<month && start.dzien<day && start.rok<=year) ||
           (start.dzien>=day && start.miesiac<month&& start.rok==year)|| (start.dzien<day && start.miesiac<=month && start.rok<=year))
    {
        cout << "Nieprawidlowa data rozpoczecia, sproboj jeszcze raz\n";
        cout << "Wpisz Dzien: ";
                        while( !(cin >> start.dzien))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << "Wpisz Miesiac: ";
                        while( !(cin >> start.miesiac))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << "Wpisz Rok: ";
        while( !(cin >> start.rok))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << endl;
    }
    cout <<"Prawidlowa data rozpoczecia\n\n";
    cout << "Do kiedy chcesz wypozyczyc?\n";
    cout << "Wpisz Dzien: ";
    while( !(cin >> koniec.dzien))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << "Wpisz Miesiac: ";
    while( !(cin >> koniec.miesiac))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << "Wpisz Rok: ";
    while( !(cin >> koniec.rok))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
    cout << endl;

    while ((koniec.dzien>31 && koniec.miesiac==1)|| (koniec.dzien>28 && koniec.miesiac==2) ||
           (koniec.dzien>31 && koniec.miesiac==3) || (koniec.dzien>30 && koniec.miesiac==4) ||
           (koniec.dzien>31 && koniec.miesiac==5) || (koniec.dzien>30 && koniec.miesiac==6) ||
           (koniec.dzien>31 && koniec.miesiac==7) || (koniec.dzien>31 && koniec.miesiac==8) ||
           (koniec.dzien>30 && koniec.miesiac==9) || (koniec.dzien>31 && koniec.miesiac==10) ||
           (koniec.dzien>30 && koniec.miesiac==11) || (koniec.dzien>31 && koniec.miesiac==12) ||
           (koniec.miesiac>12) || (start.miesiac>koniec.miesiac&&koniec.rok<=start.rok) || (start.rok>koniec.rok) || (start.dzien>koniec.dzien && start.miesiac>=koniec.miesiac && start.rok>=koniec.rok) )
    {
        cout << "Nieprawidlowa data zakonczenia, sproboj jeszcze raz\n";
        cout << "Wpisz Dzien: ";
        while( !(cin >> koniec.dzien))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << "Wpisz Miesiac: ";
        while( !(cin >> koniec.miesiac))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << "Wpisz Rok: ";
        while( !(cin >> koniec.rok))
    {
        cin.clear();
        cin.sync();
        cout << "Bledny wybor\n";
    }
        cout << endl;
    }
    cout << "Prawidlowa data zakonczenia\n";

    int startDate1 = (start.rok * 10000) + (start.miesiac * 100) + start.dzien;
    int endDate1 = (koniec.rok * 10000) + (koniec.miesiac * 100) + koniec.dzien;

    int temp = 0, status = 1;
    int rozmiar = start_date_read().size();
    int tab[rozmiar];

    for(int i =0; i <= rozmiar ; i++)
    {
        if ((((startDate1 > start_date_read()[i] && startDate1 > end_date_read()[i]) && (endDate1 > start_date_read()[i] && endDate1 > end_date_read()[i])) ||
             (wybor != car_read()[i])) || (((startDate1 < start_date_read()[i] && startDate1 < end_date_read()[i]) && (endDate1 < start_date_read()[i] && endDate1 < end_date_read()[i])) ||
            (wybor != car_read()[i])))
        {
            tab[i] = 1;
        }
        else
        {
            tab[i] = 0;
        }
    }

    for( int a = 0; a <=rozmiar; a ++)
    {
        if (tab[a] == 0)
        {
            temp++;
        }
    }

    if (temp >= Ilosc[marka-1][model-1])
    {
        status = 0;
    }

    if (status == 1)
    {
        int cena_calkowita = liczba_dni(start, koniec)*cena;

        cout << "Calkowita cena wynosi: " << cena_calkowita << endl;
        cout << "Czy sie zgadzasz? tak/nie" <<endl;
        cin >> zgoda;

            if (zgoda == "tak")
            {
                cout << "Teraz poprosze o Twoje dane" <<endl;
                cout << "Imie: ";
                cin >> dane.imie;
                cout << endl;
                cout << "Nazwisko: ";
                cin >> dane.nazwisko;
                cout << endl;
                cout << "Pesel: ";
                cin >> dane.pesel;
                cout << endl;
                cout <<"Dziekujemy za skorzystanie z naszych uslug\n\n";
                date_save(startDate1, endDate1, wybor, dane.imie, dane.nazwisko);
                zapis_dane(wybor, start.dzien, start.miesiac, start.rok, koniec.dzien, koniec.miesiac, koniec.rok, cena_calkowita);
                potwierdzenie = 0;
            }
            else
            {
                cout << "Sproboj jeszcze raz\n\n";
            }
    }
    else
    {
        cout << "Termin zajety, sprobuj inny samochod\n\n";
    }

}

}
}
