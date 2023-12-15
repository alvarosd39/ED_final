/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   Prueba.cpp
 * Author: isaac
 *
 * Created on 6 de diciembre de 2023, 11:44
 */

#include <cstdlib>
#include<iostream>
#include "Almacen_Rutas.h"
#include "Paises.h"
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Almacen_Rutas AR;
    Paises PS;
    
    if(argc != 2)
        cerr<<"Número invalido de argumentos"<<endl;
    
    ifstream file(argv[1]);
    
    if (!file){
        cerr<<"Error al abrir el archivo"<<endl;
    }else{
        cout<<"Empieza la lectura"<<endl;
        file>>PS;
        cout<<"Despues de la lectura"<<endl;
    }
    file.close();
    cout<<PS<<endl;

    
//    if (!file){
//        cerr<<"Error al abrir el archivo"<<endl;
//    }else{
//        cout<<"Empieza la lectura"<<endl;
//        file>>AR;
//        cout<<"Despues de la lectura"<<endl;
//    }
//    file.close();
//    
//    cout<<AR<<endl;
//    
//    cout<<"Despues de to_String"<<endl;
    return 0;
}

