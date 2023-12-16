/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

#include "Paises.h"

using namespace std;

Paises::Paises(){
}

void Paises::Insertar(const Pais & P){
    datos.insert(P);
}

void Paises::Borrar(const Pais & P){
    datos.erase(P);
}

Paises::iterator::iterator(){}

Paises::iterator& Paises::iterator::operator++() {
  ++p;
  return *this;
}

Paises::iterator& Paises::iterator::operator--() {
  --p;
  return *this;
}

const Pais& Paises::iterator::operator*() {
  return *p;
}

bool Paises::iterator::operator==(const iterator &other) const {
  return p == other.p;
}

bool Paises::iterator::operator!=(const iterator &other) const {
  return p != other.p;
}

//Metodos de const_iterator

Paises::const_iterator::const_iterator(){}

Paises::const_iterator& Paises::const_iterator::operator++() {
  ++p;
  return *this;
}

Paises::const_iterator& Paises::const_iterator::operator--() {
  --p;
  return *this;
}

const Pais& Paises::const_iterator::operator*() const {
  return *p;
}

bool Paises::const_iterator::operator==(const const_iterator &other) const {
  return p == other.p;
}

bool Paises::const_iterator::operator!=(const const_iterator &other) const {
  return p != other.p;
}


Paises::iterator Paises::begin(){
    Paises::iterator i;
    i.p = datos.begin();
    return i;
}

Paises::const_iterator Paises::begin() const{
    Paises::const_iterator i;
    i.p = datos.cbegin();
    return i;
}

Paises::iterator Paises::end(){
    Paises::iterator i;
    i.p = datos.end();
    return i;
}

Paises::const_iterator Paises::end() const{
    Paises::const_iterator i;
    i.p = datos.cend();
    return i;
}

Paises::iterator Paises::find(const Pais & P){
    set<Pais>::iterator aux;
    aux = datos.find(P);
    
    if(aux == datos.end()){
        return end();
    }else{
        iterator i;
        i.p = aux;
        return i;
    }
}

Paises::iterator Paises::find(const Punto & P) {
    bool encontrado = false;
    iterator i = begin();
    for(;i!=end() && !encontrado;++i){
        if ((*i).GetPunto() == P ){
            return i;
            encontrado = true;
        }
    }
    return end();
}

// ESTO DUDOSO pq ns si cadena almacena exactamente ese string

istream & operator>>(istream & is, Paises & R){
    string cadena,aux3;
    char aux2;
    is>>aux2;
    is>>aux3;
    getline(is , cadena);
    if(aux2 != '#' && aux3 != "Latitud"){
        cerr<<"Error al leer el archivo"<<endl;
        exit(0);
    }else{
        while (!is.eof()) {
            Pais pais;

            // Leer los datos del país
            is >> pais;
            // Insertar el país en la colección
            R.datos.insert(pais);
        }
    }
    return is;

}

ostream & operator<<(ostream & os, const Paises & R){
    os << "#Latitud Longitud País Bandera";    
    set<Pais>::iterator it = R.datos.begin();
    
    for(; it != R.datos.end();++it){
        os<<*it;
    }
    return os;
}
