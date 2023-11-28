/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <cstddef>
#include <cmath>
#include "imageES.h"
#include "image.h"
#include "imageIO.h"

using namespace std;


/********************************
      FUNCIONES PRIVADAS
********************************/
void Image::Allocate(int nrows, int ncols, byte *buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char * file_path){
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    byte * buffer = ReadPGMImage(file_path, rows, cols);
    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(rows, cols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    int fila = 0;
    while(k > cols){      // Este bucle calcula la fila y la columna 
        k = k - cols;     // del pixel al que se quiere acceder
        fila++;
    }
    
    set_pixel(fila,k-1,value);
    
    //img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)
    int fila = 0;
    while(k > cols){      // Este bucle calcula la fila y la columna 
        k = k - cols;     // del pixel al que se quiere acceder
        fila++;
    }
    
    return get_pixel(fila,k-1);
    
    //return img[0][k];
}

// Métodos para almacenar y cargar imagenes en disco
bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    // byte * p = img[0];
    byte * p = new byte[rows * cols];
    
    int index =0;                          //Si cabia la representación en memoria
    for(int i = 0; i < rows;i++){          //y no estan los bytes en unsoo array contiguos
        for(int j = 0; j < cols; j++){     //estos bubles recorreran el array 2D y escribiran
            p[index] = img[i][j];          //todo en un solo array contiguo en memoria
            index++;
        }
    }
    return WritePGMImage(file_path, p, rows, cols);
}

void Image::Invert(){
    const int MAX = 255;
    for(int i=0; i<get_rows(); i++){
        for(int j=0; j<get_cols(); j++){
            set_pixel(i , j , MAX - get_pixel(i,j));
        }
    }
}


// APARTADO 1


Image Image::Crop(int nrow, int ncol, int height, int width) const{
    
    //verificamos que los parametros sean correctos
    assert(nrow<=rows && ncol<=cols);
    
    //creamos la imagen nueva
    Image crop(height,width);
    
    //copiamos los pixeles seleccionados en la nueva imagen
    for(int i=0; i<height;i++ ){
        for(int j=0 ; j< width; j++ ){
            crop.set_pixel(i,j,this->get_pixel(i+nrow,j+ncol));
        }
    }
    
    return crop;
}


// APARTADO 2


Image Image::Zoom2X() const{
    
    //creamos la nueva imagen con el zoom aplicado
    int colum=0, fila=0;
    
    Image zoom( 2 * get_rows()- 1, 2 * get_cols() - 1);
    
    byte interpolador_byte;
    
    // copiamos los pixeles que no cambian
    for(int i = 0 ; i < zoom.get_rows() ; i += 2 ){
        for(int j = 0 ; j < zoom.get_cols() ; j += 2 ){
            zoom.set_pixel(i,j,this->get_pixel(fila,colum));
            colum++;
        }
        fila++;
        colum=0;
    }
    //hacemos la media en en los elementos de las columnas impares y filas pares
    for(int i = 0 ; i < zoom.get_rows() ; i += 2 ){
        for(int j = 1 ; j < zoom.get_cols()-1 ; j += 2 ){
            interpolador_byte = media_pixel(zoom.get_pixel(i,j-1), zoom.get_pixel(i, j + 1));
            zoom.set_pixel(i,j,interpolador_byte);
        }
    }
    
    //hacemos la media en los elementos de filas impares
    for(int i = 1 ; i < zoom.get_rows()-1 ; i += 2 ){
        for(int j = 0 ; j < zoom.get_cols() ; j++ ){
            interpolador_byte = media_pixel(zoom.get_pixel(i-1,j), zoom.get_pixel(i+1,j));
            zoom.set_pixel(i,j,interpolador_byte);
        }
    }
    
    return zoom;
}


byte Image::media_pixel( const byte pixel1, const byte pixel2) const{
    double valor;
    //hacemos la media
    valor = (pixel1 + pixel2) / 2;
    
    //llamamos a redondeo
    return redondeo(valor);
}


byte Image::redondeo(double valor) const{
    byte resultado;
    int aux=valor;

    if (valor - aux >= 0.5 ) {
        // Si el valor termina en .5, redondea hacia arriba
        resultado = std::ceil(valor);
        
    } else {
        
        // Sino usa round para redondear normalmente
        resultado = std::round(valor);
    }
    return resultado; 
}


// APARTADO 3


Image Image::Subsample(int factor) const{
    //comprobamos que las los valores son correctos
    assert(factor < rows || factor < cols || factor >= 0);
    
    //comprobamos que el factor de reduccion sea valido para la imagen
    //assert(rows % factor == 0 && rows % factor == 0);
    
    Image icono(rows/factor,cols/factor);
    int fila=0, colum=0;
    
    for(int i=0; i<icono.get_rows(); i++){
        for(int j=0; j<icono.get_cols(); j++){
            icono.set_pixel(i,j,media_pro(fila,colum,factor));
            colum=colum+factor;
        }
        fila=fila+factor;
        colum=0;
    }
    
    return icono;
}


byte Image::media_pro(int fila, int col, int factor) const{
    byte resultado;
    double suma;
    for(int i=fila; i<fila + factor; i++){
        for(int j=col; j<col + factor; j++){
            suma+=this->get_pixel(i,j);
        }
    }
    suma= suma/(factor*factor);
    resultado=suma;
    return redondeo(resultado);
}



// APARTADO 4


void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2) {
    
    double valor1 = out1 / in1 ;
    
    double valor2 = (out2 - out1) / (in2 - in1);
    
    double valor3 = (255 - out2) / (255 - in2);
    
    
    byte resul;
    
    for (int i = 0; i < get_rows() * get_cols(); i++) {
        
        byte pixel = get_pixel(i);
        
        if(pixel >= 0 && pixel < in1)
            
            resul = redondeo( valor1 * pixel );
            
        else if( pixel >= in1 && pixel < in2)
                
            resul = redondeo( out1 + ( valor2 * ( pixel - in1 ) ) );
                
        else
            
            resul = redondeo( out2 + ( valor3 * ( pixel - in2 ) ) );
        
        
        set_pixel(i, resul);
        
    }


}