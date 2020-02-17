#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "load_functions.h"
#include "zmienne.h"
using namespace std;

vector<string> offer_load()
{
    ifstream in4("oferta.txt");
    istream_iterator<string> start(in4), end;
    vector<string> offer(start, end);
    in4.close();
    return offer;
}

void amount_load()
{
    ifstream in7("amount.txt");
    string line;
    int temp =0;
    for(size_t i =0; i < oferta.size();i++)
    {
        vector<int> ilosc;
            getline(in7, line);
            stringstream iss(line);
            while(iss >> temp)
            {
                ilosc.push_back(temp);
            }
            Ilosc.push_back(ilosc);
    }
    in7.close();
}

void price_load()
{
    ifstream in5("price.txt");
    string line;
    int temp =0;
    for(size_t i =0; i < oferta.size();i++)
    {
        vector<int> cena;
        getline(in5, line);
        stringstream iss(line);
        while(iss >> temp)
        {
            cena.push_back(temp);
        }
        Ceny.push_back(cena);
    }
    in5.close();
}

void model_load()
{
    ifstream in6("model.txt");
    string line, temp;
    for(size_t i =0; i < oferta.size();i++)
    {
        vector<string> model;
            getline(in6, line);
            stringstream iss(line);
            while(iss >> temp)
            {
                model.push_back(temp);
            }
            Modele.push_back(model);
    }
    in6.close();
}

int rezerw_number()
{
    int liczba = 0;
    string line;
    ifstream rez("zarezerwowane.txt");
    while(getline(rez, line))
    {
        liczba++;
    }
    rez.close();
    return liczba;
}

vector<int> start_date_read()
{
    int l_lini, temp =0;
    string line;
    l_lini = rezerw_number();
    ifstream in1("zarezerwowane.txt");
    vector<int> startDate;
    for(int i =0; i < l_lini;i++)
        {
            getline(in1, line);
            stringstream iss(line);
            iss >> temp;
            startDate.push_back(temp);
        }


    in1.close();
    return startDate;
}

vector<int> end_date_read()
{
    int l_lini, temp =0;
    string line;
    l_lini = rezerw_number();
    ifstream in2("zarezerwowane.txt");
    vector<int> endDate;
    for(int i =0; i < l_lini;i++)
        {
            getline(in2, line);
            stringstream iss(line);
            for(int i =0; i<2; i++)
            {
                iss >> temp;
            }
            endDate.push_back(temp);
        }


    in2.close();
    return endDate;
}

vector<string> car_read()
{
    int l_lini;
    string line, temp;
    l_lini = rezerw_number();
    ifstream in3("zarezerwowane.txt");
    vector<string> samochod;
    for(int i =0; i < l_lini;i++)
        {
            getline(in3, line);
            stringstream iss(line);
            for(int i =0; i<3; i++)
            {
                iss >> temp;
            }
            samochod.push_back(temp);
        }


    in3.close();
    return samochod;
}

vector<string> name_read()
{
    int l_lini;
    string line, temp;
    l_lini = rezerw_number();
    ifstream in7("zarezerwowane.txt");
    vector<string> imie;
    for(int i =0; i < l_lini;i++)
        {
            getline(in7, line);
            stringstream iss(line);
            for(int i =0; i<4; i++)
            {
                iss >> temp;
            }
            imie.push_back(temp);
        }

    in7.close();
    return imie;
}

vector<string> surname_read()
{
    int l_lini;
    string line, temp;
    l_lini = rezerw_number();
    ifstream in8("zarezerwowane.txt");
    vector<string> nazwisko;
    for(int i =0; i < l_lini;i++)
        {
            getline(in8, line);
            stringstream iss(line);
            for(int i =0; i<5; i++)
            {
                iss >> temp;
            }
            nazwisko.push_back(temp);
        }

    in8.close();
    return nazwisko;
}
