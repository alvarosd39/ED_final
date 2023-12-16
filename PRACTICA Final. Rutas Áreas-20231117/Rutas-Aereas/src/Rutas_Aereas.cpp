/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   newmain.cpp
 * Author: isaac
 *
 * Created on 14 de diciembre de 2023, 10:56
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "Almacen_Rutas.h"
#include "Paises.h"
#include "Punto.h"
using namespace std;

// Función para realizar la rotación de una imagen

Imagen Rota(const Imagen & Io,double angulo){
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {
	    inter=rcorners[count]*coseno+ccorners[count]*seno;
	   
	    if(inter<new_row_min)
		    new_row_min=inter;
	    if(inter>new_row_max)
		    new_row_max=inter;
	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;
	   
	    if(inter1<new_col_min)
		    new_col_min=inter1;	
	    if(inter1>new_col_max)
		    new_col_max=inter1;
   }
    
    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);
   
    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++)
      {
	for(int cols=0;cols<newimgcols;cols++)
	{
	   float oldrowcos=((float)rows+new_row_min)*cos(-rads);
	   float oldrowsin=((float)rows+new_row_min)*sin(-rads);
	   float oldcolcos=((float)cols+new_col_min)*cos(-rads);
	   float oldcolsin=((float)cols+new_col_min)*sin(-rads);
	   float old_row=oldrowcos+oldcolsin;
	   float old_col=-oldrowsin+oldcolcos;
	   old_row=ceil((double)old_row);
	   old_col=ceil((double)old_col);
	   if((old_row>=0)&&(old_row<Io.num_filas())&&
	      (old_col>=0)&&(old_col<Io.num_cols()))
	   {
	      Iout(rows,cols)=Io(old_row,old_col);
              
	   }
	   else
	     Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
	}
    }
    return Iout;
}

//Función para pintar una imagen
void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
      int fila,col;
      if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
	 if (c1!=c2){
	   double a,b;
	   a= double(f2-f1)/double(c2-c1);
	   b= f1-a*c1;
	   col = (int)(c1+c2)/2;
	   fila = (int)rint(a*col+b);
	 }  
	 else{
	   col = c1;
	   fila = (f1+f2)/2;
	 }  
	  
	  
	  double angulo = atan2((f2-f1),(c2-c1));
	  Imagen Irota=Rota(avion,angulo);
	
	  I.PutImagen(fila,col,Irota);//pensar si debe ser opaco o blending
	  
	   angulo = atan2((f2-fila),(c2-col));
	  Irota=Rota(avion,angulo);
	
	  I.PutImagen(f2,c2,Irota);//pensar si debe ser opaco o blending
	  angulo = atan2((fila-f1),(col-c1));
	  Irota=Rota(avion,angulo);
	
	  I.PutImagen(f1,c1,Irota);//pensar si debe ser opaco o blending
	 
      
      }
     
}


/*
 * 
 */
int main(int argc, char** argv) {
    
    
    if (argc!=7){
    cout<<"Los parametros son :"<<endl;
    cout<<"1.-Fichero de texto con los paises"<<endl;
    cout<<"2.-Imagen del mapa en formato .ppm"<<endl;
    cout<<"3.-Direccion (Path) de las banderas"<<endl;
    cout<<"4.-Fichero de texto con las rutas"<<endl;
    cout<<"5.-Imagen del avión a pintar en el mapa en formato .ppm"<<endl;
    cout<<"6.-Mascara del avion en formato .pgm"<<endl;
    return 0;
    }
    
    Paises AP;
    Almacen_Rutas AR;
    Imagen mapa,
           avion,
           bandera;
    string dir_banderas;
    
    //Se crean los objetos stream que se van a leer
    ifstream file(argv[1]); 
    if (!file){
        cerr<<"Error al abrir el archivo"<<endl;
        exit(0);
    }else{
        file>>AP;
    }
    file.close();
    
    file.open(argv[4]);
    if (!file){
        cerr<<"Error al abrir el archivo"<<endl;
        exit(0);
    }else{
        file>>AR;
    }
    file.close();
    
    mapa.LeerImagen(argv[2]);
    dir_banderas = argv[3];
    avion.LeerImagen(argv[5],argv[6]);
    
    cout<<"Las rutas: "<<endl<<AR;
    cout<<"Dime el codigo de una ruta"<<endl;
    string a;
    cin>>a;
    Ruta R=AR.GetRuta(a);
    
    cout<<AR<<endl;
    
    Ruta::iterator it = R.begin();
    Ruta::iterator it2 = R.begin();
    ++it2;
    while(it2 != R.end()){
        int c1 = (mapa.num_cols()/360.0) * (180 + (*it).GetLongitud());
        int f1 = (mapa.num_filas() / 180.0) * (90 - (*it).GetLatitud());
        int c2 = (mapa.num_cols()/360.0) * (180 + (*it2).GetLongitud());
        int f2 = (mapa.num_filas() / 180.0) * (90 - (*it2).GetLatitud());
        Pintar(f1,f2,c1,c2,mapa,avion,avion.num_filas(),avion.num_cols());
        ++it;
        ++it2;
    }
    
    Paises::iterator it3 =AP.begin();
    
    while(it3 != AP.end()){
        int c = (mapa.num_cols() / 360.0) * (180 + (*it3).GetPunto().GetLongitud());
        int f = (mapa.num_filas() / 180.0) * (90 - (*it3).GetPunto().GetLatitud());
    }
    
    return 0;
}

