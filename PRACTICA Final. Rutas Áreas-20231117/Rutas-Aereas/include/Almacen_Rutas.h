/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen_Rutas.h
 * Author: alvaro
 *
 * Created on 3 de diciembre de 2023, 20:08
 */

#ifndef ALMACEN_RUTAS_H
#define ALMACEN_RUTAS_H
#include "Ruta.h"
#include "Pais.h"
#include "Punto.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <map>
#include <utility>



class Almacen_Rutas{
private :
    
    /**
      @brief conjunto de rutas que tiene el almacen
    **/

    map<string,Ruta> rutas;

public:
    
    /**
      @brief constructor por defecto
    **/
    
    Almacen_Rutas();
    
    /**
      @brief inserta una Ruta en el conjunto
      @param R Ruta a insertar
    **/

    void Insertar(const Ruta & R);

    /**
      @brief borra una Ruta del conjunto
      @param R Ruta a borrar
    **/
    
    void Borrar(const Ruta &R);

    /**
      @brief borra una Ruta del conjunto
      @param a Ruta a borrar
    **/    
    
    Ruta GetRuta(const string &a);

    class iterator{
    private:
        
        /**
          @brief iterador de rutas para el conjunto
        **/

        map<string,Ruta>::iterator p;
        
    public:
        
        /**
          @brief constructor por defecto
        **/
        
        iterator();

        /**
          @brief compara si dos iteradores son iguales
          @param i iterador a comparar
          @return si los iteradores tienen el mismo valor
        **/
        
        bool operator==(const iterator &i)const;

        /**
          @brief compara si dos iteradores son diferentes
          @param i iterador a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!= (const iterator & i)const;

        /**
          @brief devuelve el valor que tiene el iterador
          @return valor del iterador
        **/
        
        pair<const string,Ruta>& operator*();

        /**
          @brief amplia el valor del iterador en un punto
          @return iterador
        **/
        
        iterator operator++();

        /**
          @brief disminuye el valor del iterador en un punto
          @return iterador
        **/
        
        iterator operator--();

        friend class Almacen_Rutas;	
    };

    class const_iterator{
    private:
        
        /**
          @brief iterador constante para el conjunto de rutas
        **/
        
        map<string,Ruta>::const_iterator p;
        
    public:
        
        /**
          @brief constructor por defecto
        **/
        
        const_iterator();
        
        /**
          @brief compara si dos iteradores constantes son iguales
          @param i iterador constante a comparar
          @return si los iteradores tienen el mismo valor
        **/
        
        bool operator==(const iterator &i)const;

        /**
          @brief compara si dos iteradores constantes son diferentes
          @param i iterador constante a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!= (const iterator & i)const;

        /**
          @brief devuelve el valor que tiene el iterador constante
          @return valor del iterador constante
        **/
        
        const pair<const string, Ruta> & operator*()const;

        /**
          @brief amplia el valor del iterador constante en un punto
          @return iterador constante
        **/
        
        const_iterator operator++();

        /**
          @brief disminuye el valor del iterador cosntante en un punto
          @return iterador constante
        **/
        
        const_iterator operator--();

        friend class Almacen_Rutas;	
    };

    /**
      @brief devuelve el valor del inicio del iterador
      @return valor del inicio
    **/
    
    iterator begin();

    /**
      @brief devuelve el valor del inicio del iterador constante
      @return valor del inicio
    **/
    
    const_iterator begin() const;

    /**
      @brief devuelve el valor del final del iterador
      @return valor del final
    **/
    
    iterator end();
    
    /**
      @brief devuelve el valor del final del iterador constante
      @return valor del final
    **/
    
    const_iterator end() const;
    
    /**
      @brief devuelve una cadena con el contenido del objeto
      @return cadena con el contenido del objeto
    **/

    string to_String()const;

    /**
      @brief extrae los datos de un archivo de entrada
             y los introduce en un objeto de la clase
      @param is archivo de entrada
      @param AR Almacen_Rutas para introducir los datos
    **/
    
    friend istream & operator>>(istream & is, Almacen_Rutas & AR);

    /**
      @brief extrae los datos de un objeto de la clase
             y los introduce en un archivo de salida
      @param os archivo de salida
      @param AR Almacen_Rutas para extraer los datos
    **/
    
    friend ostream & operator<<(ostream & os, const Almacen_Rutas & R);



};

#endif /* ALMACEN_RUTAS_H */

