/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Paises.h
 * Author: alvaro
 *
 * Created on 30 de noviembre de 2023, 13:25
 */

#ifndef PAISES_H
#define PAISES_H

#include "Pais.h"
#include "Punto.h"
#include <set>
#include <iostream>

class Paises {
private:
    
    /**
      @brief conjunto de Paises
    **/
    
    set<Pais> datos;
    
public:
    
    /**
      @brief constructor por defecto
    **/
    
    Paises();
    
    /**
      @brief inserta un Pais en el conjunto
      @param P Pais a insertar
    **/
    
    void Insertar(const Pais & P);
    
    /**
      @brief borra una Pais del conjunto
      @param P Pais a borrar
    **/
    
    void Borrar(const Pais & P);
        
    class iterator{
    private:
        
        /**
          @brief iterador de rutas para el conjunto
        **/

        set<Pais>::iterator p;
        
    public:
        
        /**
          @brief constructor por defecto
        **/
        
        iterator();
        
        /**
          @brief disminuye el valor del iterador en un punto
          @return iterador
        **/
        
        iterator & operator--() ;
        
        /**
          @brief amplia el valor del iterador en un punto
          @return iterador
        **/
        
        iterator & operator++();
        
        /**
          @brief devuelve el valor que tiene el iterador
          @return valor del iterador
        **/
        
        const Pais & operator*() ;
        
        /**
          @brief compara si dos iteradores son iguales
          @param other iterador a comparar
          @return si los iteradores tienen el mismo valor
        **/
        
        bool operator==(const iterator &other) const;
        
        
        /**
          @brief compara si dos iteradores son diferentes
          @param other iterador a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!=(const iterator &other) const;
        
        friend class Paises;
    };
    
    class const_iterator{
    private:
       
        /**
          @brief iterador constante de rutas para el conjunto
        **/
        
        set<Pais>::const_iterator p;
        
    public:

        /**
          @brief constructor por defecto
        **/
        
        const_iterator() ;
        
        /**
          @brief disminuye el valor del iterador cosntante en un punto
          @return iterador constante
        **/
        
        const_iterator & operator--() ;
        
        /**
          @brief amplia el valor del iterador constante en un punto
          @return iterador constante
        **/
        
        const_iterator & operator++();
        
        /**
          @brief devuelve el valor que tiene el iterador constante
          @return valor del iterador constante
        **/
        
        const Pais& operator*() const;
        
        /**
          @brief compara si dos iteradores constantes son iguales
          @param other iterador constante a comparar
          @return si los iteradores tienen el mismo valor
        **/
        
        bool operator==(const const_iterator &other) const;
        
        /**
          @brief compara si dos iteradores constantes son diferentes
          @param other iterador constante a comparar
          @return si los iteradores no tienen el mismo valor
        **/
        
        bool operator!=(const const_iterator &other) const;
        
        friend class Paises;
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
      @brief busca el Pais en el conjunto de Paises
      @return valor del iterador donde se encuentra el Pais
    **/
   
    iterator find(const Pais & P);
    
    /**
      @brief busca el Punto en el conjunto de Paises
      @return valor del iterador donde se encuentra el Punto
    **/
    
    iterator find(const Punto & P);
        
    /**
      @brief extrae los datos de un archivo de entrada
             y los introduce en un Pais
      @param is archivo de entrada
      @param R Paises para introducir los datos
    **/
    
    friend istream & operator>>(istream & is, Paises & R);
    
    /**
      @brief extrae los datos de un objeto de la clase
             y los introduce en un Pais
      @param os archivo de salida
      @param R Paises para extraer los datos
    **/
    
    friend ostream & operator<<(ostream & os, const Paises & R);
};

#endif /* PAISES_H */

