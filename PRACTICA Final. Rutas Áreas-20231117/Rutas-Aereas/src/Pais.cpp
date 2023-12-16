/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pais.cpp
 * Author: alvaro
 * 
 * Created on 29 de noviembre de 2023, 16:40
 */

#include "Pais.h"
#include "Punto.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


Pais::Pais(){
    pais = "";
    bandera = "";
}

Punto Pais::GetPunto()const{
    return p;
}

string Pais::GetPais()const{
    return pais;
}

string Pais::GetBandera()const {
    return bandera;
}

bool Pais::operator<(const Pais &P) const{
    return (this->p < P.p);
}

bool Pais::operator==(const Pais &P) const{
    return (this->p == P.p);
}

bool Pais::operator==(const Punto &P) const{
    return (this->p == P);
}

istream & operator>>(istream & is, Pais & P){
    double latitud, longitud;
    is >> latitud >> longitud >> P.pais >> P.bandera;
    P.p.SetLatitud(latitud);
    P.p.SetLongitud(longitud);
    return is;
}

ostream & operator<<(ostream & os, const Pais & P){
    os << P.p.GetLatitud() << P.p.GetLongitud() << P.pais << P.bandera;
    return os;
}
