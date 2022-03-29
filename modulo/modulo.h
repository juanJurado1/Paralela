/*********************************************
 	* Universidad Sergio Arboleda
	* Fecha: 01 de marzo de 2022
	* Autora: Juan Jurado
	* Materia: Computacion Paralela
	* Tema: Implementación Posix (Library)
	* interfaz del modulo para multiplicar 2 matrices sin variables globales.
	* Se requiere que el diseño sea modular.
	* El modulo implementará los hilos que harán el cálculo del producto
**********************************************/
#ifndef MODULO_C_H_INCLUDE
#define MODULO_C_H_INCLUDE


void sampleStart();
void sampleEnd();
double randNumber();
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr);
void printMatrix(int SZ, double *M);
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr);
void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr);
double ** ReservaMEM(int size);
void IniciarMatriz(double **Ma, double **Mb, double **Mc, int size);
void printMatrizH(double **M, int size);
void *multMM(void *arg);

struct data {
    int size, nTh;
    int *idTh;
    double **MA, **MB, **MC;
};

#endif
