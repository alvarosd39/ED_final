/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen_Rutas.cpp
 * Author: alvaro
 * 
 * Created on 3 de diciembre de 2023, 20:08
 */

#include <string>

#include"Almacen_Rutas.h"

using namespace std;

Almacen_Rutas::Almacen_Rutas() {
    
}

void Almacen_Rutas::Insertar(const Ruta & R){
    Ruta aux(R);
    this->rutas.insert(pair<string,Ruta>(aux.GetCode(),aux));
}

void Almacen_Rutas::Borrar(const Ruta &R){
    this->rutas.erase(R.GetCode());
}

Ruta Almacen_Rutas::GetRuta(const string &a){
    return this->rutas.at(a);
}

//-----------------------------
//Métodos iterator
//-----------------------------

Almacen_Rutas::iterator::iterator(){}

bool Almacen_Rutas::iterator::operator==(const iterator &i)const{
    return (p == i.p);
}

bool Almacen_Rutas::iterator::operator!= (const iterator & i)const{
    return (p!=i.p);
}

pair<const string,Ruta>& Almacen_Rutas::iterator::operator*(){
    return *p;
}

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator++(){
    ++p;
    return *this;
}

Almacen_Rutas::iterator Almacen_Rutas::iterator::operator--(){
    --p;
    return *this;
}

//------------------------
// Metodos const_iterator
//------------------------

Almacen_Rutas::const_iterator::const_iterator(){}

bool Almacen_Rutas::const_iterator::operator==(const iterator &i)const{
    return (p == i.p);
}

bool Almacen_Rutas::const_iterator::operator!= (const iterator & i)const{
    return (p!=i.p);
}

const pair<const string,Ruta>& Almacen_Rutas::const_iterator::operator*()const{
    return *p;
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator++(){
    ++p;
    return *this;
}

Almacen_Rutas::const_iterator Almacen_Rutas::const_iterator::operator--(){
    --p;
    return *this;
}


//------------------------------
//Resto de metodos Almacen_Rutas
//------------------------------

Almacen_Rutas::iterator Almacen_Rutas::begin(){
    Almacen_Rutas::iterator i;
    i.p = rutas.begin();
    return i;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin()const{
    const_iterator i;
    i.p = rutas.begin();
    return i;
}


Almacen_Rutas::iterator Almacen_Rutas::end(){
    Almacen_Rutas::iterator i;
    i.p = rutas.end();
    return i;
}

Almacen_Rutas::const_iterator Almacen_Rutas::end()const{
    const_iterator i;
    i.p = rutas.end();
    return i;
}

string Almacen_Rutas::to_String()const{
    string out;
    out+="#Rutas\n";
    map<string,Ruta>::const_iterator i = rutas.begin();
    for(;i != rutas.end();++i){
        out+=i->second.to_String();
        out+="\n";
//        out+= i->first;
//        out+=" ";
//        out+=i->second.Get_size();
//        out+= " ";
//        for(Ruta::const_iterator iR = i->second.begin(); iR != i->second.begin(); ++iR){
//            out+=(*iR).to_string();
//        }
    }
    return out;
}

istream & operator>>(istream & is, Almacen_Rutas & AR){
    string cadena;
    
    getline(is,cadena);
    cout<<cadena<<endl;
    if(cadena != "#Rutas"){
        cerr<<"Error al leer el archivo con las rutas";
        exit(0);
    }else{
        while(!is.eof()){
            Ruta ruta_aux;
            is >> ruta_aux;
            AR.Insertar(ruta_aux);
        }
    }
    cout<<"*******Termina la lectura*******"<<endl;
    return is;
}

ostream & operator<<(ostream & os, const Almacen_Rutas & AR){
    os<<AR.to_String();
    return os;
}