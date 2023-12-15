/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Punto.cpp
 * Author: alvaro
 * 
 * Created on 29 de noviembre de 2023, 12:46
 */
#include "Punto.h"


using namespace std;
    
Punto::Punto() {
    latitud = longitud = 0;
}

Punto::Punto(double l, double L, const std::string & d){
    latitud = l; 
    longitud = L;
}


double Punto::GetLatitud() const{
    return latitud;
}

double Punto::GetLongitud() const{
    return longitud;
}

void Punto::SetLatitud(double l){
    latitud = l;
}

void Punto::SetLongitud(double l){
    longitud = l;
}

//aqui el criterio que he usado es 
//que la latitud tiene mas importancia??

bool Punto::operator<(const Punto & p) const {
  if (this->latitud < p.latitud) {
    return true;
  } else if (this->latitud == p.latitud) {
    return (this->longitud < p.longitud);
  } else {
    return false;
  }
}

bool Punto::operator==(const Punto & p) const {
  return (this->latitud == p.latitud && this->longitud == p.longitud);
}

const string Punto::to_string()const{
    string out;
    out+="(";
    out+=std::to_string(latitud);
    out+=",";
    out+=std::to_string(longitud);
    out+=")";
    return out;
}
//esto es muy cutre??
//No! pq ya esta mejorado

istream & operator>>(istream & is, Punto & p) {
    //La siguiente implementacion ignora el hecho de leer parentesis
    char car;
    string cadena;
    //is.get(car);
    is>>car;
    while(car != ' ' && car != ','){
        cadena+=car;
        //is.get(car);
        is>>car;
    }
    p.SetLatitud(stod(cadena));
    cout<<p.GetLatitud()<<endl;
    cadena.clear();
    //is.get(car);
    is>>car;
    while(car != ' ' && car != ',' && car != ')'){
        cadena+=car;
        //is.get(car);
        is>>car;
    }
    p.SetLongitud(stod(cadena));
    cout<<p.GetLongitud()<<endl;
//    string cadena;
//    getline(is,cadena,'(');
//    getline(is,cadena);
//    p.SetLatitud(stoi(cadena));
//    getline(is,cadena,',');
//    getline(is,cadena);
//    p.SetLongitud(stoi(cadena));

//  is>> parentesis >> p.latitud >> coma >> p.longitud >> parentesis;
//  is >> cadena;
//  cadena = cadena.substr(1,cadena.size()- 2);
//  istringstream ss(cadena);
//  ss >> p.latitud >> coma >> p.longitud ;
  
  return is;
}

ostream & operator<<(ostream & os, const Punto & p) {
  os << "(" << p.latitud << "," << p.longitud << ")";
  return os;
}
