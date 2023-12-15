/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Image.h
 * Author: isaac
 *
 * Created on 26 de noviembre de 2023, 0:56
 */

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include "imagenES.h"

enum Tipo_Pegado {OPACO, BLENDING};

const int MAX_FILAS_REFER = 125,
          MAX_COLUM_REFER = 83;
using namespace std;

struct Pixel{
    unsigned char r,g,b;
    unsigned char transparencia;
};

class Imagen{
private:
    
    /**
     @brief puntero a la imagen almacenada
     */
    
    Pixel **datos;
    
    /**
     @brief número de filas y colunas de la matriz donde se almacena la imagen
     */
    int nf, nc;
    
    /*
     * Metodo privado usado para liberar la memoria
     */
    
    void Borrar();
    
    /*
     *Metodo privado utilizado para copiar y ralojar una imagen  I
     */
    
    void copiar(const Imagen &I);
    
    /**
     * Funcion auxiliar para crear el espacio de memoria para una imagen
     */
    
    void Allocate(int nrows,int ncols);
    
    
public:
    
    /**
     * @brief constructor sin parametros
     * @post crea un objeto imagen sin datos asociados 
     */
    
    Imagen();
    
    /**
     * @brief constructor con parametros 
     * @param f numero de filas que tendra la matriz asociada a la imagen
     * @param c numero de columnas que tendra la matriz asoiada a la imagen
     */
    
    Imagen(int f,int c);
    
    /**
     * @brief Constructor de copia del tipo Imagen
     * @param I referencia a l aimagen original que se quiere copiar
     * @return El objeto imagen creado
     */
    
    Imagen(const Imagen & I);
    
    /**
     * @brief Operdor = del tipo imagen
     * @param I Imagen rhs a la cuals se quiere igualar
     * @return Devuelve una refererncia a la imagen resultado de la igualacion
     */
    
    Imagen& operator=(const Imagen & I);
    
    /**
     * @brief Libera la memoria de @p datos de Imagen
     */
    
    ~Imagen();
    
    /**
     *@brief operador de acceso () (set,get)
     *@param i fila del elemento al que se quiere acceder 
     *@param j columna del elemeto al que se quiere acceder
     *@return una referencia a Pixel
     */
    
    Pixel& operator ()(int i, int j);
    
    /**
     * @brief oparador de consulta () (get)
     * @param i fila del elemento al que se quiere acceder
     * @param j columna del elemento al que se quiere acceder
     * @return una referencia constante a Pixel
     */
    
    const Pixel& operator()(int i , int j)const;
    
    /**
     * @brief guarda una omagen en disco 
     * @param nombre ruta sonde se almacenara la imagen
     * @pre @p nombre debe ser el nombre de una ruta valida
     */
    
    void EscribirImagen(const char *nombre);
    
    /**
     * @brief Lee una imagen de tipo PPM desde el disco
     * @param nombre ruta donde se encuentra la imagen
     * @param nombremascara ruta donde se encuntra la imagen de la mascara 
     */
    
    void LeerImagen(const char *nombre, const string& nombremascara=" ");
    
    /**
     * @brief devuelve el numero de filas constante
     * @return numero de filas
     */
        
    int num_filas()const {return nf;}
    
    /**
     * @brief devuelve el numero de columnas constante
     * @return numero de columnas
     */
    
    int num_cols()const {return nc;}
    
    /**
     * @brief junta dos imagenes en la posicion indicada en los 
     *        atributos y con el tipo de pegado indicado
     * @param posi posicion de la fila
     * @param posj posicion de la columna
     * @param I Imagen que pegar sobre la otra
     * @param tippegado tipo de pegado
     */
    
    void PutImagen(int posi, int posj,const Imagen &I, Tipo_Pegado tippegado=OPACO);
    
    /**
     * @brief amplia la imagen al doble de tamaño
     * @return imagen ampliada
     */
    
    Imagen Zoom2x() const;
    
    /**
     * @brief hace el zoom a una imagen muy pequeña 
     *        (pero pierde fiabilidad con respecto al Zoom2x)
     * @return imagen ampliada
     */
    
    Imagen Zoom3x();
    
    /**
     * @brief hace la media de dos pixeles
     * @param p1 pixel con el que hacer la media
     * @param p2 pixel con el que hacer la media
     * @return pixel con la media hecha
     */
    
    Pixel Media_Pixel(const Pixel p1, const Pixel p2)const;
    
    /**
     * @brief redondea un valor a la alza cuando vale 
     *        0.5 o mas y a la baja cuando vale 0.4 o menos
     * @param valor valor para redondear
     * @return valor redondeado
     */
    
    unsigned char redondeo(double valor)const;
    
};

#endif /* IMAGE_H */
