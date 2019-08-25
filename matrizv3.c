#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizv3.h"
#include "toolsv3.h"

/*
Realiza a alocação dos espaços de memória

@param matrix, mymatriz, Estrutura
@obs
Devido a erros no valgrind foi utilizado calloc ao invés de malloc
Conditional jump or move depends on uninitialised value(s)
https://cs50.stackexchange.com/questions/28837/conditional-jump-or-move-depends-on-uninitialized-value

*/
int malocar(mymatriz *matrix) {
    int **newMatrix = NULL;

	printf("\nmalocar =[%d,%d]\n",matrix->lin, matrix->col);
	newMatrix = (int **) calloc(matrix->lin, sizeof(int *));
	//newMatrix = (int **) malloc(matrix->lin * sizeof(int *));
	if (!newMatrix) {
		printf("ERROR: Out of memory 1\n");
		return 1;
	}

  	for (int lin =0; lin < matrix->lin; lin++) {
			newMatrix[lin] = (int *) calloc(matrix->col, sizeof(int));
			//newMatrix[lin] = (int *) malloc(sizeof(int)*matrix->col);
			if (!newMatrix) {
				printf("ERROR: Out of memory 2\n");
				return 1;
			}
	}
    matrix->matriz = newMatrix;
	return 0;
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
	srand(wtime(NULL));

	// Percorre todas as linhas da matriz
	for (int lin=0; lin < matrix->lin; lin++) {
		// Percorre todas as Colunas da Matriz
		for (int col=0; col < matrix->col; col++) {

			// Verifica o valor passado por parâmetro
			switch (valor)
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

	if ( matrix->matriz == NULL ){
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}

	// Realiza uma impressão de primeira linha com posição das colunas
	for (int col=0; col < matrix->col; col++)
		printf("\t(%d)", col);

	// Pula linha
	printf("\n");

	// Percorre as linhas da Matriz
	for (int lin=0; lin < matrix->lin; lin++) {
		// Imprime no começo da linha a posição
		printf("(%d)", lin);
		// Percorre as colunas da Matriz
	  	for (int col=0; col < matrix->col; col++){
			// Imprime os valores contidos na Matriz
			printf("\t %d", matrix->matriz[lin][col]);
		}
		printf("\n");
	}
	printf("\n\n");
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
		for (int lin =0; lin < matrix->lin; lin++)
			free(matrix->matriz[lin]);

		// Libera a Matriz completa
		free(matrix->matriz);
	}

	return 0;
}

/*
Realiza a comparação de duas Matrizes
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
				printf("\nO elemento [%d,%d] é diferente nas matrizes analisadas!\n", lin, col);
				printf("Os valores são %d e %d\n", matrixA->matriz[lin][col], matrixB->matriz[lin][col]);
				return 1;
			}
		}
	}
	time2 = wtime();
	printf ("VERIFICADO: Matrizes identicas\n");
	printf ("Runtime: %f\n", time2 - time1);
	return 0;
}



