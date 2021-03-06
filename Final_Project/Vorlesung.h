#ifndef VORLESUNG_H
#define VORLESUNG_H

#pragma once
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Vorlesung {
public:
    enum class Semester {WS, SS};
    enum class Type{VO, ILV, UE};
    static int belegt;

    // Constructor
    explicit Vorlesung(int inst, Semester ws_ss=Semester::WS, int vonummer=99, string voname="UNKNOWN", Type type=Type::VO, int max=100): Institut{inst}, ws_or_ss{ws_ss}, VO_Nummer{vonummer}, VO_Name{move(voname)}, VO_Typ{type}, max_Studenten{max}{
        current_Studenten = max;}

    // Destructor
    ~Vorlesung()= default;

    // Getter
    string get_semester() const{
        switch(ws_or_ss){
            case Semester::WS: return "WS";
            case Semester::SS: return "SS";
        }}
    int get_vonummer() const {return VO_Nummer;}
    string get_voname() const {return VO_Name;}
    string get_type() const{
        switch(VO_Typ){
            case Type::VO: return "VO";
            case Type::ILV: return "ILV";
            case Type::UE: return "UE";
        }}
    int get_institut() const{return Institut;}
    int get_max() const {return max_Studenten;}
    int get_current() const{return current_Studenten;}

    // Setter
    void set_semester(Semester ws_ss){ws_or_ss = ws_ss;}
    void set_vonummer(int vonummer){VO_Nummer=vonummer;}
    void set_voname(string voname){VO_Name=move(voname);}
    void set_max(int m){max_Studenten=m; current_Studenten=m;}

    // Print VO
    ostream& print(ostream& out) const{
        out << get_semester() << " " << get_institut() << get_vonummer() << " - " << get_voname() << " " << get_type();
        return out;}

   // Print Capacity
   void print_capacity() const{
        cout << "Freie/Maximale Plätze: [ " << get_current() << " / " << get_max() << " ]" << endl;
    }

   // Operator Overload : Compare VOs
   bool operator==(const Vorlesung&v) const{
        return VO_Nummer == v.VO_Nummer;}

    // Count Student Entries
    void new_entry(){--current_Studenten; ++belegt;}
    void delete_entry(){++current_Studenten; --belegt;}

    // Check if max capacity is reached
    bool is_full() const{
        if (!current_Studenten){
            return true;}
        return false;}

private:
    Semester ws_or_ss;
    int Institut;
    int VO_Nummer;
    string VO_Name;
    Type VO_Typ;
    int max_Studenten;
    int current_Studenten;
};

inline ostream& operator<<(ostream& o, const Vorlesung& vo){
    return vo.print(o);
}

#endif
