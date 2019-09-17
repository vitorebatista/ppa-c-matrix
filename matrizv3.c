#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizv3.h"
#include "toolsv3.h"

/*
Realiza a alocação dos espaços de memória

@param matriz, mymatriz, Estrutura
@obs
Devido a erros no valgrind foi utilizado calloc ao invés de malloc
Conditional jump or move depends on uninitialised value(s)
https://cs50.stackexchange.com/questions/28837/conditional-jump-or-move-depends-on-uninitialized-value

*/
int malocar(mymatriz *matriz)
{
	int **newMatrix = NULL;

	printf("\nmalocar =[%d,%d]\n", matriz->lin, matriz->col);
	newMatrix = (int **)calloc(matriz->lin, sizeof(int *));
	//newMatrix = (int **) malloc(matrix->lin * sizeof(int *));
	if (!newMatrix)
	{
		printf("ERROR: Erro ao inicializar matriz [1]\n");
		return -4;
	}

	for (int lin = 0; lin < matriz->lin; lin++)
	{
		newMatrix[lin] = (int *)calloc(matriz->col, sizeof(int));
		//newMatrix[lin] = (int *) malloc(sizeof(int)*matriz->col);
		if (!newMatrix)
		{
			printf("ERROR: Erro ao inicializar matriz [2]\n");
			return -4;
		}
	}
	matriz->matriz = newMatrix;
	return 0;
}

/*
Gera valores dentro de uma matriz já alocada

@param *matriz, struct, Estrutura 
@param valor, int, Menor ideia do que pode ser este parâmetro

*/
int mgerar(mymatriz *matriz, int valor)
{

	int value = 0; // Controlador de valor

	if (matriz->matriz == NULL)
	{
		printf("\nERRO: Matriz não alocada \n\n");
		return -3;
	}

	/* srand(wtime(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função wtime(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
    ref: http://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/
    */
	srand(wtime(NULL));

	// Percorre todas as linhas da matriz
	for (int lin = 0; lin < matriz->lin; lin++)
	{
		// Percorre todas as Colunas da Matriz
		for (int col = 0; col < matriz->col; col++)
		{

			// Verifica o valor passado por parâmetro
			switch (valor)
			{
			case -9999: // Menor ideia do que pode ser este valor negativo
				value = rand() % 100;
				break;
			case 0: // valor=0 para zera os valores
				value = 0;
				break;
			default: //
				value = valor;
				break;
			}

			// Atribui o valor a posição da Matriz
			matriz->matriz[lin][col] = value;
		}
	}
	return 0;
}

/*
Imprime os valores da Matriz
*/
int mimprimir(mymatriz *matriz)
{

	if (matriz->matriz == NULL)
	{
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}

	// Realiza uma impressão de primeira linha com posição das colunas
	for (int col = 0; col < matriz->col; col++)
		printf("\t(%d)", col);

	// Pula linha
	printf("\n");

	// Percorre as linhas da Matriz
	for (int lin = 0; lin < matriz->lin; lin++)
	{
		// Imprime no começo da linha a posição
		printf("(%d)", lin);
		// Percorre as colunas da Matriz
		for (int col = 0; col < matriz->col; col++)
		{
			// Imprime os valores contidos na Matriz
			printf("\t %d", matriz->matriz[lin][col]);
		}
		printf("\n");
	}
	printf("\n\n");
	return 0;
}

/*
Gera valores zerados em uma matriz já alocada
*/
int mzerar(mymatriz *matriz)
{
	if (matriz->matriz == NULL)
	{
		printf("\nERRO: Matriz não alocada \n\n");
		exit(1);
	}
	// Chama a geração Zerando os valores
	return mgerar(matriz, 0);
}

/*
Imprime os valores da matriz
*/
int mliberar(mymatriz *matriz)
{

	// Só necessita liberar Matrizes alocadas
	if (matriz->matriz)
	{
		// Libera as posições de cada Linha
		for (int lin = 0; lin < matriz->lin; lin++)
			free(matriz->matriz[lin]);

		// Libera a Matriz completa
		free(matriz->matriz);
	}

	return 0;
}

/*
Realiza a comparação de duas Matrizes
*/
int mcomparar(mymatriz *mat_a, mymatriz *mat_b)
{
	//double time1, time2;

	if (mat_a->matriz == NULL)
	{
		printf("\nERRO: Matriz A não alocada \n\n");
		return -3;
	}

	if (mat_b->matriz == NULL)
	{
		printf("\nERRO: Matriz B não alocada \n\n");
		return -3;
	}

	if ((mat_a->lin != mat_b->lin) || (mat_a->col != mat_b->col))
	{
		printf("\nAs matrizes não são do mesmo tamanho\n");
		return -2;
	}

	//time1 = wtime();
	for (int lin = 0; lin < mat_a->lin; lin++)
	{
		for (int col = 0; col < mat_a->col; col++)
		{
			if (mat_a->matriz[lin][col] != mat_b->matriz[lin][col])
			{
				printf("\nO elemento [%d,%d] é diferente nas matrizes analisadas!\n", lin, col);
				printf("Os valores são %d e %d\n", mat_a->matriz[lin][col], mat_b->matriz[lin][col]);
				return -1;
			}
		}
	}
	//time2 = wtime();
	printf("Matrizes são idênticas!! :) \n");
	//printf("Tempo de processamento: %f\n", time2 - time1);
	return 0;
}

int gerar_submatriz(int **mat_origem, matriz_bloco_t *submatriz, bloco_t *bloco)
{

	int posCol = 0;
	int posLin = 0;

	for (int lin = bloco->lin_inicio; lin < bloco->lin_fim; lin++)
	{
		for (int col = bloco->col_inicio; col < bloco->col_fim; col++)
		{
			submatriz[0].matriz[posLin][posCol] = mat_origem[lin][col];
			posCol += 1;
		}
		posLin += 1;
		posCol = 0;
	}
	return 0;
}

matriz_bloco_t **particionar_matriz(int **matriz, int mat_lin, int mat_col, int orientacao, int divisor)
{
	matriz_bloco_t **aSubMat = malloc(divisor * sizeof(matriz_bloco_t *));

	int nTamLim = orientacao == 1 ? mat_col : mat_lin;
	int nTamCar = 1;
	int nResto = 0;
	int nUseRes = 0;
	int nLastEnd = 0;

	// Define uma Distribuição de Carga Simples
	// Enquanto o tamanho de cada carga multiplicado pela
	// quantidade de processamentos for menor que o limite
	// alimenta a carga
	while ((nTamCar * divisor) <= nTamLim)
	{
		nTamCar += 1;
	}

	// Retorna ao estado anterior a superação do limite
	nTamCar -= 1;

	// Verifica se há "resto" de alocação
	if (nTamCar * divisor < nTamLim)
	{
		nResto = nTamLim - (nTamCar * divisor);
	}

	// Se carga estiver zerada, há mais processamentos que limites
	if (nTamCar == 0)
	{
		printf("Há mais processamentos do que submatrizes, favor rever quantidade de processos.\n");
		exit(1);
	}
	else
	{
		for (int nSubMat = 0; nSubMat < divisor; nSubMat++)
		{

			// Distribui o resto de carga
			if (nResto != 0)
			{
				nUseRes = 1;
				nResto -= 1;
			}
			else
			{
				nUseRes = 0;
			}

			bloco_t *blocoX = malloc(sizeof(bloco_t));
			// Gera o Bloco para busca da SubMatriz
			blocoX->col_inicio = 0;
			blocoX->col_fim = mat_col;
			blocoX->lin_inicio = 0;
			blocoX->lin_fim = mat_lin;
			if (orientacao == 1)
			{
				blocoX->col_inicio = nLastEnd;
				blocoX->col_fim = nLastEnd + nTamCar + nUseRes;
			}
			else
			{
				blocoX->lin_inicio = nLastEnd;
				blocoX->lin_fim = nLastEnd + nTamCar + nUseRes;
			}
			nLastEnd += nTamCar + nUseRes;
			int **matrizX;
			if (orientacao == 1)
			{
				matrizX = alocar_matriz(mat_lin, nTamCar + nUseRes);
				zerar_matriz(matrizX, mat_lin, nTamCar + nUseRes);
			}
			else
			{
				matrizX = alocar_matriz(nTamCar + nUseRes, mat_col);
				zerar_matriz(matrizX, nTamCar + nUseRes, mat_col);
			}

			gerar_submatriz(matriz, matrizX, blocoX);

			// Gera o Bloco correto
			blocoX->col_inicio = 0;
			blocoX->col_fim = mat_col;
			blocoX->lin_inicio = 0;
			blocoX->lin_fim = mat_lin;
			if (orientacao == 1)
			{
				blocoX->col_fim = nTamCar + nUseRes;
			}
			else
			{
				blocoX->lin_fim = nTamCar + nUseRes;
			}

			aSubMat[nSubMat] = (matriz_bloco_t *)malloc(sizeof(matriz_bloco_t));
			aSubMat[nSubMat]->bloco = blocoX;
			aSubMat[nSubMat]->matriz = matrizX;
		}
	}

	return aSubMat;
}

matriz_bloco_t **constroi_submatrizv2(int mat_lin, int mat_col, int divisor)
{
	return 0;
}