/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Ruta.h
 * Author: isaac
 *
 * Created on 30 de noviembre de 2023, 21:43
 */

#ifndef RUTA_H
#define RUTA_H

#include<list>
#include<string>
#include<algorithm>
#include"Punto.h"
#include<iostream>

using namespace std;

class Ruta{
    
private:
    
    /**
      @brief conjunto de Puntos
    **/
    
    list<Punto> puntos;
    
    /**
      @brief codigo de identificacion de la ruta
    **/
    
    string code;
    
public:
    
    /**
      @brief constructor con atributos
      @param puntos lista de la que estraer los Puntos
      @param code codigo de la ruta
    **/
    
    Ruta(list<Punto> puntos, string code);
    
    /**
      @brief constructor de copia
      @param otra Ruta para copiar los atributos
    **/
    
    Ruta(const Ruta &otra);
    
    /**
      @brief constructor por defecto
    **/
    
    Ruta();
    
    /**
      @brief inserta Puntos en la lista de Puntos
      @param n Punto para insertar en la lista
    **/
    
    void Insertar(const Punto & n);
    
    /**
      @brief borra Puntos de la lista de Puntos
      @param n Punto para borrar de la lista
    **/
    
    void Borrar(const Punto &n);
    
    /**
      @brief devuelve el codigo de la ruta 
      @return codigo de la ruta
    **/
    
    string GetCode()const;
    
    /**
      @brief establece el codigo de la ruta 
    **/
    
    void SetCode(const string & code);
    
    
    /**
      @brief compara si dos rutas son iguales
      @param R ruta a comparar
      @return si las rutas son iguales
    **/
    
    bool operator==(const Ruta & R)const;
    
    /**
      @brief compara una ruta es menor que otra
      @param R ruta a comparar
      @return si la ruta es menor que la dada
    **/
    
    bool operator<(const Ruta & R)const;
        
    class iterator{
    private:
        
        /**
          @brief iterador constante de Puntos para el conjunto
        **/
        
        list<Punto>::iterator p;
    public:
        
        /**
          @brief constructor por defecto
        **/
        
        iterator();
        
        /**
          @brief compara si dos iteradores son iguales
          @param other iterador a comparar
          @return si los iteradores tienen el mismo valor
        **/

        bool operator==(const iterator & i)const;
        
        /**
          @brief compara si dos iteradores son diferentes
          @param other iterador a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!=(const iterator & i)const;
        
        /**
          @brief amplia el valor del iterador en un punto
          @return iterador
        **/
        
        iterator & operator++();
        
        /**
          @brief devuelve el valor que tiene el iterador
          @return valor del iterador
        **/
        
        Punto & operator*();
        
        /**
          @brief disminuye el valor del iterador en un punto
          @return iterador
        **/
        
        iterator & operator--();
        
        friend class Ruta;
    };
    
    class const_iterator{
    private:
        
        /**
          @brief iterador constante de rutas para el conjunto
        **/
        
        list<Punto>::const_iterator p;
        
    public:
        
        /**
          @brief constructor por defecto
        **/
        
        const_iterator();
        
        /**
          @brief compara si dos iteradores constantes son iguales
          @param other iterador constante a comparar
          @return si los iteradores tienen el mismo valor
        **/
        
        bool operator==(const const_iterator & i)const;
        
        /**
          @brief compara si dos iteradores constantes son diferentes
          @param other iterador constante a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!=(const const_iterator & i)const;
        
        /**
          @brief amplia el valor del iterador constante en un punto
          @return iterador constante
        **/
        
        const_iterator & operator++();
        
        /**
          @brief devuelve el valor que tiene el iterador constante
          @return valor del iterador constante
        **/
        
        const Punto & operator*();
        
        /**
          @brief disminuye el valor del iterador cosntante en un punto
          @return iterador constante
        **/
        
        const_iterator & operator--();
        
        friend class Ruta;
        
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
      @brief busca el Punto en la ruta 
      @return valor del Punto donde se encuentra la Ruta
    **/
    
    iterator find(const Punto &p);
    
    /**
      @brief devuelve el tamaño de la Ruta
      @return tamaño de la Ruta
    **/
    
    const int Get_size()const;
    
    /**
      @brief devuelve una cadena con el contenido del objeto
      @return cadena con el contenido del objeto
    **/
    
    string to_String()const;
    
    /**
      @brief extrae los datos de un archivo de entrada
             y los introduce en una Ruta
      @param Is archivo de entrada
      @param R Ruta para introducir los datos
    **/
    
    friend istream & operator>>(istream & is, Ruta & R);
    
    /**
      @brief extrae los datos de una Ruta
             y los introduce en un archivo de salida
      @param os archivo de salida
      @param R Ruta para extraer los datos
    **/
    
    friend ostream & operator <<(ostream & os, const Ruta & R);
};

#endif /* RUTA_H */
