/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pais.h
 * Author: alvaro
 *
 * Created on 29 de noviembre de 2023, 16:40
 */

#ifndef PAIS_H
#define PAIS_H

#include "Punto.h"

class Pais {  
    
private:
    
    /**
      @brief Punto donde se encuentra, nombre y bandera del Pais
    **/

    Punto p;
    string pais;
    string bandera;
    
public:
    
    /**
      @brief constructor por defecto
    **/
    
    Pais();
    
    /**
      @brief devuelve el Punto donde se encuentra el Pais
      @return Punto del pais
    **/
    
    Punto GetPunto()const;
    
    /**
      @brief devuelve el nombre del Pais
      @return Nombre del pais
    **/
    
    string GetPais()const;
    
    /**
      @brief devuelve la bandera del Pais
      @return Bandera del pais
    **/
    
    string GetBandera()const;
    
    /**
      @brief compara si un pais es menor que otro
      @param P Pais para comparar
      @return si el Pais es menor al del atributo
    **/
    
    bool operator<(const Pais &P) const;
    
    /**
      @brief compara si dos paises son iguales
      @param P Pais para comparar
      @return si el Pais es igual al del atributo
    **/
    
    bool operator==(const Pais &P) const;
    
    /**
      @brief compara si dos puntos del pais son iguales
      @param P Punto para comparar
      @return si el Punto del pais es igual al del atributo
    **/
    
    bool operator==(const Punto &P) const;

    /**
      @brief extrae los datos de un archivo de entrada
             y los introduce en un objeto de la clase
      @param Is archivo de entrada
      @param p Pais para introducir los datos
    **/
    
    friend istream & operator>>(istream & is, Pais & p);
    
    /**
      @brief extrae los datos de un objeto de la clase
             y los introduce en un archivo de salida
      @param os archivo de salida
      @param p Pais para extraer los datos
    **/
    
    friend ostream & operator<<(ostream & os, const Pais & p);

};


#endif /* PAIS_H */

