/*****************************************
 * Fecha 15-03-2022
 * Autor: Juan Jurado
 * Materia: Computación Paralela y Distribuida
 * Tema: Implementación Posix (LIbrary)
*****************************************/

#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>




int main(int argc, char* argv[]){

	if(argc !=3){
		printf("./Exe N<dimMatriz> Nth<numHilos> \n\n");
		return -1;
	}

	/* Se capturan las variables size y número de hilos */
	int N 	 = atof(argv[1]);
	int Nthreads = atof(argv[2]);
	
	/* Se crea el pool de hilos */
	pthread_t *hilosExec;
	/*Se reserva memoria para los hilos*/
	hilosExec = (pthread_t *)malloc(Nthreads *sizeof(pthread_t));
	
	/* Creación y reserva de Mem para cada Matriz */
	double **Ma = ReservaMEM(N);
	double **Mb = ReservaMEM(N);
	double **Mc = ReservaMEM(N);

	IniciarMatriz(Ma,Mb,Mc,N);
	
    	struct data *params = (struct data *)malloc(sizeof(struct data));
    
	if(N < 4){
		printf("Matriz A: \n");
		printMatrizH(Ma,N);
		printf("Matriz B: \n");
		printMatrizH(Mb,N);
	}
	
	sampleStart();
	/*Se reparte la tarea a cada hilo ,al usar la función
	* funcion pthread_create(&tinfo[tnum].thread_id,&attr,
				  &thread_start,&tinfo[tnum]); */
	for (int i = 0; i < Nthreads; ++i){
        	int *idThread = (int *)malloc(sizeof(int));
        	*idThread = i;

        	/* Estructura para enviar varias variables a los hilos */
        	/* Asignación de variables a la estructura*/
        	params->size = N;
        	params->nTh  = Nthreads;
        	params->MA   = Ma;
        	params->MB   = Mb;
        	params->MC   = Mc;
        	params->idTh = idThread;

        	pthread_create(&hilosExec[i], NULL, multMM, (void *)params);
    }
    
	/*Se espera a que todos los hilos terminen */

	for(int i=0; i <Nthreads; ++i){
		pthread_join(hilosExec[i], NULL);
	}

	sampleEnd();
	free(hilosExec);
		
	if(N < 4){
		printf("Matriz C \n");
		printMatrizH(Mc,N);
	}
	
	
	
	return 0;
}


