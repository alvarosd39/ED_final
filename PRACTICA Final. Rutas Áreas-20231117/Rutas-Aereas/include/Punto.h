/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Punto.h
 * Author: alvaro
 *
 * Created on 29 de noviembre de 2023, 12:46
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifndef PUNTO_H
#define PUNTO_H

using namespace std;
class Punto {
    
private:
    
    /**
      @brief latitud y longitud en la que se encuentra
    **/
    
    double latitud, longitud;

public:
    
    /**
      @brief constructor por defecto
    **/
    
    Punto();
    
    /**
      @brief constructor con atributos
      @param l latitud
      @param L longitud
    **/
    
    Punto(double l, double L, const string & d);
    
    /**
      @brief devuelve la latitud 
      @return latitud del punto
    **/
    
    double GetLatitud() const;
    
    /**
      @brief devuelve la longitud
      @return longitud del punto
    **/
    
    double GetLongitud() const;
    
    /**
      @brief establece la latitud del punto
      @param l latitud
    **/
    
    void SetLatitud(double l);
    
    /**
      @brief establece la longitud del punto
      @param l longitud
    **/
    
    void SetLongitud(double l);

    /**
      @brief compara si un punto es menor que otro
      @param p Punto para comparar
      @return si el Punto es menor al del atributo
    **/
    
    bool operator<(const Punto & p)const;
    
    /**
      @brief compara si dos puntos son iguales
      @param p Punto para comparar
      @return si el Punto es igual al del atributo
    **/

    bool operator==(const Punto & p)const;
    
    
    /**
      @brief extrae los datos de un archivo de entrada
             y los introduce en un objeto de la clase
      @param is archivo de entrada
      @param p Punto para introducir los datos
    **/

    friend istream & operator>>(istream & is, Punto & p);

    /**
      @brief extrae los datos de un objeto de la clase
             y los introduce en un archivo de salida
      @param os archivo de salida
      @param p Punto para extraer los datos
    **/
    
    friend ostream & operator<<(ostream & os, const Punto & p);
    
    /**
      @brief devuelve una cadena con el contenido del objeto
      @return cadena con el contenido del objeto
    **/
    
    const string to_string()const;
    
};


#endif /* PUNTO_H */

