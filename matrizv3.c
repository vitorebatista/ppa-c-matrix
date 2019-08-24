#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizv3.h"
#include "toolsv3.h"

/*
Realiza a alocação dos espaços de memória

@param matrix, mymatriz, Estrutura
*/
int malocar(mymatriz *matrix) {
    int **newMatrix = NULL;

	newMatrix = (int **) malloc(matrix->lin * sizeof(int *));
	if (!newMatrix) {
		printf("ERROR: Out of memory\n");
		return NULL;
	}

  	for (int i =0; i < matrix->lin; i++) {
			newMatrix[i] = (int *) malloc(sizeof(int)*matrix->col);
			if (!newMatrix) {
				printf("ERROR: Out of memory\n");
				return NULL;
			}
	}
    matrix->matriz = newMatrix;
	return 1;
}

/*
Gera valores dentro de uma matriz já alocada

@param *matrix, struct, Estrutura 
@param valor, int, Menor ideia do que pode ser este parâmetro

*/
int mgerar(mymatriz *matrix, int valor){
	
	int value = 0;// Controlador de valor
	
	if ( matrix->matriz == NULL ){
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}

    /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
    ref: http://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/
    */
	srand(time(NULL));

	// Percorre todas as linhas da matriz
	for (int lin=0; lin < matrix->lin; nCntLin++) {
		// Percorre todas as Colunas da Matriz
		for (int col=0; col < matrix->col; col++) {

			// Verifica o valor passado por parâmetro
			switch (nValor)
			{
				case -9999: // Menor ideia do que pode ser este valor negativo
					value = rand() % 100;
					break;
				case 0: // valor=0 para zera os valores
					value = 0;
					break;
				default:// 
					value = valor;
					break;
			}
			
			// Atribui o valor a posição da Matriz
			matrix->matriz[lin][col] = value;
		}
	}
	return 0;
}


/*
Imprime os valores da Matriz
*/
int mimprimir(mymatriz *matrix){
    int col=0;
    int lin=0;

	if ( matrix->matriz == NULL ){
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}

	// Realiza uma impressão de primeira linha com posição das colunas
	for (col=0; col < matrix->col; col++)
		printf("\t(%d)", col);

	// Pula linha
	printf("\n");

	// Percorre as linhas da Matriz
	for (lin=0; lin < matrix->lin; lin++) {
		// Imprime no começo da linha a posição
		printf("(%d)", lin);
		// Percorre as colunas da Matriz
	  	for (col=0; col < matrix->col; col++){
			// Imprime os valores contidos na Matriz
			printf("\t%d", matrix->matriz[lin][col]);
		}
		printf("\n");
	}
	return 0;
}


/*
Gera valores zerados em uma matriz já alocada
*/
int mzerar (mymatriz *matrix){
	if ( matrix->matriz == NULL ){
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}
	// Chama a geração Zerando os valores
	return mgerar(matrix, 0);
}


/*
Imprime os valores da matriz
*/
int mliberar (mymatriz *matrix) {
	
	// Só necessita liberar Matrizes alocadas
	if (matrix->matriz) {
		// Libera as posições de cada Linha
		for (int lin =0; lin < matrix->lin; i++)
			free(matrix->matriz[lin]);

		// Libera a Matriz completa
		free(matrix->matriz);
	}

	return NULL;
}

/*
function comparar_matriz
Realiza a comparação de duas Matrizes

@return int, Sempre 0

@param **aMatrizA, pointer, Ponteiro que representa a Matriz A
@param **aMatrizB, pointer, Ponteiro que representa a Matriz B
@param nLinha, int, Numero de Linhas da Matriz
@param nColuna, int, Numero de Colunas da Matriz
*/
int mcomparar (mymatriz *matrixA, mymatriz *matrixB){
	double time1, time2;

	if ( matrixA->matriz == NULL ){
		printf("\nERRO: Matriz A não alocada \n\n");
		exit(1);
	}

	if ( matrixB->matriz == NULL ){
		printf("\nERRO: Matriz B não alocada \n\n");
		exit(1);
	}

	time1 = wtime();
	for (int lin=0; lin < matrixA->lin; lin++) {
	  for (int col=0; col < matrixA->col; col++){
			if (matrixA->matriz[lin][col] != matrixB->matriz[lin][col]) {
				printf("O elemento [%d,%d] é diferente nas matrizes analisadas!\n", lin,col);
				return 1;
			}
		}
	}
	time2 = wtime();
	printf ("VERIFICADO: Matrizes identicas\n");
	printf ("Runtime: %f\n", time2 - time1);
	return 0;
}



