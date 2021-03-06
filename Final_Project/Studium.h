#ifndef STUDIUM_H
#define STUDIUM_H

#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "Vorlesung.h"

using namespace std;

class Studium{
    int Kennzahl;
    string Bezeichnung;
    string Institut;
    vector<Vorlesung> Inst_Vorlesungen;

    static vector<Studium *> stdStudien;

public:
    // Constructor
    explicit Studium(int kennzahl, string bez="UNKNOWN", string inst_bez="UNKNOWN"):Kennzahl{kennzahl}, Bezeichnung{move(bez)}, Institut{move(inst_bez)}{}

    // Destructor
    ~Studium()= default;

    // Getters
    int get_kennzahl() const{return Kennzahl;}
    string get_bez() const{return Bezeichnung;}
    string get_instbez() const {return Institut;}

    static Studium *get_stdStudium(const int &k);

    // Setters
    void set_bez(const string &bez){Bezeichnung=bez;}
    void set_instbez(const string &inst_bez){Institut=inst_bez;}
    void add_VO(const Vorlesung& VO){Inst_Vorlesungen.push_back(VO);}

    // Operator Overload : Compare Studium
    bool operator==(const Studium&s) const{
        return Kennzahl == s.Kennzahl && Bezeichnung == s.Bezeichnung && Institut == s.Institut;}

    // Check Duplicates
    static void check_unique(const Studium *s){
        for(auto i : stdStudien){
            if(*i == *s){delete i;}}
    }

    // Print Function
    void print() const{
        cout << "Kennzahl: " << get_kennzahl() << endl;
        cout << "Bezeichnung: " << get_bez() << endl;
        cout << "Institut: " << get_instbez() << endl;
        for (const Vorlesung& v: Inst_Vorlesungen){cout << '[' << v << ']' << endl;}
        cout << '\n';
    }

private:
    static void init_Studium()
    {
        if (stdStudien.empty())
        {
            struct StudInfo {const int kennzahl; string bez; string inst_bez;};
            StudInfo stdStudienInfo[] =
                    {{100, "Informatik","Institute for Computational Engineering"},
                    { 200,"Molekulare Biologie", "Institute of Microbiology and Genetics"},
                    { 300,"Betriebswirtschaft",  "Institute of Business and Management"},
                     { 300,"Betriebswirtschaft",  "Institute of Business and Management"}};

            for(auto &info:stdStudienInfo)
            {auto *new_Studium = new Studium(info.kennzahl);
                new_Studium->set_bez(info.bez);
                new_Studium->set_instbez(info.inst_bez);
                check_unique(new_Studium);
                stdStudien.push_back(new_Studium);}
        }
    }
};

#endif
