/* Se implementa paso a paso benchmark Multiplicaión de Matrices
	Algoritmo clásico ( filas x columnas) de matrices
	de igual dimensión*/

int main(int argc, char *argv[]) {
	
	/* Se calcula la dimensión de la matriz*/
	int N = (int) atof(argv[1]);
	//printf("Valor ingresado %d", N);
	
	/* Apuntamos los vectores (creación) al espacio de memoeria reservado, con dimension NxN*/
	double *Ma, *Mb, *Mr; // * el asterísco se refiere al puntero de memoria
	Ma = MEM_CHUNK;//Ma tiene el espacio de memoria de mem_chunk
	Mb = Ma + N*N;//Ma
	Mr = Mb + N*N;
	
	initMatrix(N, Ma, Mb, Mr);
	
	SampleStart();
	matrixMM(N, Ma, Mb, Mr);
	SampleEnd();
	
	
	return 0;
}
