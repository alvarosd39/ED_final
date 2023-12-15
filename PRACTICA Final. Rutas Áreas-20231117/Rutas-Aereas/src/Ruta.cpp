/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Ruta.cpp
 * Author: isaac
 * 
 * Created on 30 de noviembre de 2023, 21:59
 */


#include"Ruta.h"

using namespace std;

Ruta::Ruta(list<Punto> puntos, string code){
    this->puntos =  puntos;
    this->code = code;
}

Ruta::Ruta(const Ruta& otra){
    this->puntos = list<Punto>(otra.puntos);
    this->code = otra.code;
}

Ruta::Ruta(){
    code="";
}

void Ruta::Insertar(const Punto & n){
    this->puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    this->puntos.remove(n);
}

string Ruta::GetCode()const{
    return this->code;
}

void Ruta::SetCode(const string & code){
    this->code = code;
}

bool Ruta::operator==(const Ruta & R)const{
    return (this->code == R.code && this->puntos == R.puntos);
}

const int Ruta::Get_size()const{
    return puntos.size();
}

//El criterio para implementar este método ha sido el número de puntos "puntos.size()"
// que tiene cada lista, podría modificarse para tener en cuenta la distancia entre puntos
bool Ruta::operator<(const Ruta & R)const{
    return (this->puntos.size() < R.puntos.size());
}

Ruta::iterator::iterator(){}


bool Ruta::iterator::operator==(const iterator & i)const{
    return (p == i.p);
}

bool Ruta::iterator::operator!=(const iterator & i)const{
    return (this->p != i.p);
}

Ruta::iterator & Ruta::iterator::operator++(){
    ++p;
    return *this;
}

Punto & Ruta::iterator::operator*(){
    return *p;
}

Ruta::iterator & Ruta::iterator::operator--(){
    --p;
    return *this;    
}

//----------------------
//Metodos const_iterator
//----------------------
Ruta::const_iterator::const_iterator(){}


bool Ruta::const_iterator::operator==(const const_iterator & i)const{
    return (p == i.p);
}

bool Ruta::const_iterator::operator!=(const const_iterator & i)const{
    return (this->p != i.p);
}

Ruta::const_iterator & Ruta::const_iterator::operator++(){
    ++p;
    return *this;
}

const Punto & Ruta::const_iterator::operator*(){
    return *p;
}

Ruta::const_iterator & Ruta::const_iterator::operator--(){
    --p;
    return *this;    
}

Ruta::iterator Ruta::begin(){
    Ruta::iterator i;
    i.p = puntos.begin();
    return i;
}

Ruta::const_iterator Ruta::begin()const{
    Ruta::const_iterator i;
    i.p = puntos.begin();
    return i;
}

Ruta::iterator Ruta::end(){
    Ruta::iterator i;
    i.p = puntos.end();
    return i;
}

Ruta::const_iterator Ruta::end()const{
    Ruta::const_iterator i;
    i.p = puntos.end();
    return i;
}

Ruta::iterator Ruta::find(const Punto &p){
    list<Punto>::iterator aux;
    aux = std::find(puntos.begin(),puntos.end(),p);
    
    if(aux == puntos.end())
        return end();
    else{
        iterator i;
        i.p = aux;
        return i;
    }
}

string Ruta::to_String()const{
    string out;
    out+=code+" "+std::to_string(puntos.size());
    for(Punto p:puntos){
        out+=" ";
        out+=p.to_string();
    }
    return out;
}

//La funcionalidad de este operador debe ser revisada, puede haber problemas en getline
istream & operator>>(istream & is, Ruta & R){
    string cadena;
    Ruta ruta_aux;
    int num_puntos;
    
    //getline(is,cadena,' ');
    is>>cadena;
    cout<<cadena<<endl;
    if (cadena[0] != 'R'){
        cerr<<"No ha sido posible leer la ruta"<<endl;
        exit(0);
    }else{
        ruta_aux.SetCode(cadena);
        //getline(is,cadena,' ');         //En este putno habria que sinronizar las lecturas de punto y ruta
        is>>cadena;
        cout<<cadena<<endl;
        num_puntos = stoi(cadena);
        for(int i =0; i < num_puntos ;i++){
            cout<<"Empezamos a leer el punto "<<i<<endl;
            getline(is,cadena,'(');
            Punto p_aux;
            is >> p_aux;
            ruta_aux.Insertar(p_aux);
            //cout<<"Terminamos de leer el punto"<<endl;
        }
        getline(is,cadena);
    }
    R = ruta_aux;
    return is;
}

//La funcinalidad de este operador depende del operador << de Punto
ostream & operator <<(ostream & os, const Ruta & R){
    os<<R.GetCode()<<" "<<R.puntos.size();
    for (Punto p:R.puntos){
        os<<" "<<p;
    }
    return os;

}
