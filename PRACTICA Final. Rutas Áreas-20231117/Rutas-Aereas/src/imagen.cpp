/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   imagen.cpp
 * Author: isaac
 * 
 * Created on 26 de noviembre de 2023, 12:58
 */

#include "imagen.h"
#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

void Imagen::copiar(const Imagen& I){
    if (this->nc < I.nc || this->nf < I.nf){
        cerr<<"No se puede copiar, espacio insuficiente en el destino"<<endl;
    }else{
        for (int i= 0; i < nf; i++){
            for(int j = 0 ; j < nc; j++){
                this->datos[i][j] = I.datos[i][j];
            }
        }
    }
}

void Imagen::Borrar(){
    if (datos != nullptr){
        delete []datos[0];
        delete []datos;
    }
}

void Imagen::Allocate(int nrows, int ncols){
    this->nf = nrows;
    this->nc = ncols;
  datos = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    datos[i]=new Pixel[nc];
    for (int j=0;j<nc;j++){
	datos[i][j].r=255;
	datos[i][j].g=255;
	datos[i][j].b=255;
	datos[i][j].transparencia=255;
    }
  }  
}

Imagen::Imagen(){
    nf = 0;
    nc = 0;
    datos = nullptr;
}

Imagen::Imagen(const Imagen& I){ //Este metodo debe ser revisado para ajustar los parametros de la copia
    this->nf = I.nf;
    this->nc = I.nc;
    this->copiar(I);
}


Imagen::Imagen(int f,int c){
  nf = f;
  nc = c;
  datos = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    datos[i]=new Pixel[nc];
    for (int j=0;j<nc;j++){
	datos[i][j].r=255;
	datos[i][j].g=255;
	datos[i][j].b=255;
	datos[i][j].transparencia=255;
    }
  }  
}

Imagen::~Imagen(){
    this->Borrar();
}


Imagen & Imagen::operator=(const Imagen & I){
    if (this != &I){
        this->Borrar();
        this->Allocate(I.nf,I.nc);
        this->copiar(I);
    }
    return *this;
}

Pixel & Imagen::operator()(int i,int j){
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return datos[i][j];
}

const Pixel & Imagen::operator()(int i,int j)const{
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return datos[i][j];
}


void Imagen::EscribirImagen(const char * nombre){
      unsigned char * aux = new unsigned char [nf*nc*3];
      unsigned char * m = new unsigned char [nf*nc];
      
      int total = nf*nc*3;
      for (int i=0;i<total;i+=3){
	    int posi = i /(nc*3);
	   int posj = (i%(nc*3))/3;
	    
	    aux[i]=datos[posi][posj].r;
	    aux[i+1]=datos[posi][posj].g;
	    aux[i+2]=datos[posi][posj].b;
	    m[i/3]=datos[posi][posj].transparencia;
	     
	 }    
	
      if (!EscribirImagenPPM (nombre, aux,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
      }
      delete[]aux;
      string n_aux = "mascara_";
      n_aux =n_aux+nombre;
      std::size_t found =n_aux.find(".ppm");
      if (found!=std::string::npos){
	n_aux =n_aux.substr(0,found);
      }
      n_aux =n_aux+".pgm";

      
      if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
      }	    
      delete []m;
  
} 


void Imagen::LeerImagen(const char * nombre,const string &nombremascara){
      int f,c;
      unsigned char * aux,*aux_mask ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f*c*3];
      LeerImagenPPM (nombre, f,c,aux);
      if (nombremascara!=""){
	int fm,cm;
	LeerTipoImagen(nombremascara.c_str(), fm, cm);
	aux_mask = new unsigned char [fm*cm];
	LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
      }
      else{
	aux_mask=0;
      }	
      
      
      Imagen I(f,c);
      int total = f*c*3;
      for (int i=0;i<total;i+=3){
	   int posi = i /(c*3);
	   int posj = (i%(c*3))/3;
	//   cout<<posi<<" " <<posj<<endl;
	     I.datos[posi][posj].r=aux[i];
	     I.datos[posi][posj].g=aux[i+1];
	     I.datos[posi][posj].b=aux[i+2];
	     if (aux_mask!=0)
	      I.datos[posi][posj].transparencia=aux_mask[i/3];
	     else
	       I.datos[posi][posj].transparencia=255;
	 }
      
      *this = I;   
      if (aux_mask!=0) delete[]aux_mask;
      delete []aux;
      
}

void Imagen::PutImagen(int posi, int posj, const Imagen& I, Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
      for (int j=0;j<I.nc;j++)
	if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
	if (I.datos[i][j].transparencia!=0){
	  if (tippegado==OPACO)
	    datos[i+posi][j+posj]=I.datos[i][j];
	  else{
	    datos[i+posi][j+posj].r=(datos[i+posi][j+posj].r+I.datos[i][j].r)/2;
	    datos[i+posi][j+posj].g=(datos[i+posi][j+posj].r+I.datos[i][j].g)/2;
	    datos[i+posi][j+posj].b=(datos[i+posi][j+posj].r+I.datos[i][j].b)/2;
	  }  
	  
	}  
	}
}

//ESte metodo ajusta mejor el tamñaño de las imagenes pequeñas pero pierde fidelidad en el proceso
Imagen Imagen::Zoom3x(){
    int colum=0 , fila=0;
    
    Imagen zoom(3*num_filas()-2, 3 * num_cols()-2);
    
    Pixel interpolador;
    
    for(int i =0; i< zoom.nf ; i += 3){
        for (int j = 0; j< zoom.nc ; j+=3){
            zoom(i,j)=this->datos[fila][colum];
            colum++;
        }
        fila++;
        colum=0;
    }
    
    for(int i = 0 ; i < zoom.num_filas() ; i += 3 ){
        for(int j = 1 ; j < zoom.num_cols()-1 ; j += 3 ){
            interpolador = Media_Pixel(zoom(i,j-1), zoom(i, j + 2));
            zoom(i,j) = interpolador;
            zoom(i,j+1) = interpolador;
        }
    }
    
    for(int i = 1 ; i < zoom.num_filas()-1 ; i += 2 ){
        for(int j = 0 ; j < zoom.num_cols() ; j++ ){
            interpolador = Media_Pixel(zoom(i-1,j), zoom(i+2,j));
            zoom(i,j) = interpolador;
            zoom(i+1,j) = interpolador;
        }
    }
    
    return zoom;
}


Imagen Imagen::Zoom2x() const{
    
    //creamos la nueva imagen con el zoom aplicado
    int colum=0, fila=0;
    
    Imagen zoom( 2 * num_filas()- 1, 2 * num_cols() - 1);
    
    Pixel interpolador;
    
    // copiamos los pixeles que no cambian
    for(int i = 0 ; i < zoom.num_filas() ; i += 2 ){
        for(int j = 0 ; j < zoom.num_cols() ; j += 2 ){
            zoom(i,j)=this->datos[fila][colum];
            colum++;
        }
        fila++;
        colum=0;
    }
    cout<<"Despues del primer for"<<endl;
    //hacemos la media en en los elementos de las columnas impares y filas pares
    for(int i = 0 ; i < zoom.num_filas() ; i += 2 ){
        for(int j = 1 ; j < zoom.num_cols()-1 ; j += 2 ){
            interpolador = Media_Pixel(zoom(i,j-1), zoom(i, j + 1));
            zoom(i,j) = interpolador;
        }
    }
    
    //hacemos la media en los elementos de filas impares
    for(int i = 1 ; i < zoom.num_filas()-1 ; i += 2 ){
        for(int j = 0 ; j < zoom.num_cols() ; j++ ){
            interpolador = Media_Pixel(zoom(i-1,j), zoom(i+1,j));
            zoom(i,j) = interpolador;
        }
    }
    cout<<"Despues del zoom"<<endl;
    return zoom;
}

Pixel Imagen::Media_Pixel(const Pixel p1, const Pixel p2)const{
    Pixel pout;
    
    pout.b = round((p1.b + p2.b) /2);
    pout.r = round((p1.r + p2.r) /2);
    pout.g = round((p1.g + p2.g) /2);
    pout.transparencia = p1.transparencia;
    
    return pout;
}

unsigned char Imagen::redondeo(double valor)const{
    unsigned char resultado;
    int aux=valor;

    if (valor - aux >= 0.5 ) {
        // Si el valor termina en .5, redondea hacia arriba
        resultado = ceil(valor);
        
    } else {
        
        // Sino usa round para redondear normalmente
        resultado = round(valor);
    }
    return resultado;
}
