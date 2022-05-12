#ifndef PROFESSOR_H
#define PROFESSOR_H

#pragma once
#include "Person.h"
#include "Vorlesung.h"

class Professor : public Person{
    int Personalnummer;
    int Institut;
    vector<Vorlesung> haelt_VO;
public:
    static int ID;
    static int count;

    //Constructor
    Professor(string vor, string nach, int inst) : Person(move(vor), move(nach)), Institut{inst}{
        Personalnummer = ID++; count++;
    }
    Professor(string vor, string nach, string geb, int inst) : Person(move(vor), move(nach), move((geb))), Institut{inst}{
        Personalnummer = ID++; count++;
    }

    //Destructor
    virtual ~Professor(){count--;}

    //getter
    int get_personalnr() const {return Personalnummer;}
    int get_institut() const {return Institut;}

    //setter
    void add_VO(const Vorlesung& VO){haelt_VO.push_back(VO);}

    ostream& print(ostream& out) const{
        out << "Name: " << Person::get_Vorname() << ' ' << Person::get_Nachname() << endl;
        out << "Personalnummer: " << get_institut() << get_personalnr() << endl;
        out << "Hält Vorlesungen: " << endl;
        for (Vorlesung i: haelt_VO){out << '[' << i << ']' << endl;}
        return out;
    }
};

inline ostream& operator<<(ostream& o, const Professor& st){
    return st.print(o);}

#endif //PROFESSOR_H
